#include <graphics.h>  
#include <conio.h>
#include <stdio.h>
#define BLOCK_SIZE 20 // 每个小格子的长宽大小 
#define HEIGHT 30 // 高度上一共30个小格子
#define WIDTH 40 //  宽度上一共40个小格子 

// 全局变量定义
int Blocks[HEIGHT][WIDTH] = {0}; //  二维数组，用于记录所有的游戏数据
char moveDirection;  //  小蛇移动方向
int food_i,food_j; //  食物的位置
int isFailure = 0; //  是否游戏失败

int head_i;
int head_j;

int getMaxValue() {
    int maxVal = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (Blocks[i][j] > maxVal) {
                maxVal = Blocks[i][j];
            }
        }
    }
    return maxVal;
}

void moveSnake(){
    if (isFailure) return;
    // 寻找蛇头位置
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (Blocks[i][j] == 1) {
                head_i = i;
                head_j = j;
                break;
            }
        }
    }
    // 根据移动方向，计算蛇头的新位置
    int new_head_i = head_i, new_head_j = head_j;
    if (moveDirection == 'a') new_head_j--;        // 左
    else if (moveDirection == 'd') new_head_j++;   // 右
    else if (moveDirection == 'w') new_head_i--;   // 上
    else if (moveDirection == 's') new_head_i++;   // 下
    // 判断是否撞墙或撞到自己
    if (new_head_i < 0 || new_head_i >= HEIGHT ||
        new_head_j < 0 || new_head_j >= WIDTH ||
        Blocks[new_head_i][new_head_j] > 0) {
        isFailure = 1;
        return;
    }
    // 判断是否吃到食物
    int ateFood = 0;
    if (new_head_i == food_i && new_head_j == food_j) {
        ateFood = 1;
    }
    // 更新二维数组，蛇身长度加1
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (Blocks[i][j] > 0) {
                Blocks[i][j]++;
            }
        }
    }
    // 更新蛇头位置
    Blocks[new_head_i][new_head_j] = 1;
    // 如果没有吃到食物，删除蛇尾
    if (!ateFood) {
        // 寻找蛇尾位置并删除
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (Blocks[i][j] == getMaxValue()) {
                    Blocks[i][j] = 0;
                }
            }
        }
    }
    else {
        // 吃到食物后，重新生成食物位置
        int valid = 0;
        while (!valid) {
            food_i = rand() % (HEIGHT - 5) + 2;
            food_j = rand() % (WIDTH - 5) + 2;
            // 确保食物不在蛇身上
            valid = 1;
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    if (Blocks[i][j] > 0 && i == food_i && j == food_j) {
                        valid = 0;
                        break;
                    }
                }
                if (!valid) break;
            }
        }
    }
    
}
 

void startup()  //  初始化函数
{
	int i;
	Blocks[HEIGHT/2][WIDTH/2] = 1; // 画面中间画蛇头，数字为1
	for (i=1;i<=4;i++) //  向左依次4个蛇身，数值依次为2,3,4,5
		Blocks[HEIGHT/2][WIDTH/2-i] = i+1;
	moveDirection = 'd';	 //  初始向右移动
	food_i = rand()%(HEIGHT-5) + 2; //  初始化随机食物位置
	food_j = rand()%(WIDTH-5) + 2; //  
	initgraph(WIDTH*BLOCK_SIZE,HEIGHT*BLOCK_SIZE); //  新开画面
	setlinecolor(RGB(200,200,200)); // 设置线条颜色
	BeginBatchDraw(); // 开始批量绘制
}

void show()  // 绘制函数
{
	cleardevice(); // 清屏
	int i,j;
	for (i=0;i<HEIGHT;i++) //  对二维数组所有元素遍历
	{ 
		for (j=0;j<WIDTH;j++)
		{
			if (Blocks[i][j]>0) // 元素大于0表示是蛇，这里让蛇的身体颜色色调渐变
				setfillcolor(HSVtoRGB(Blocks[i][j]*10,0.9,1));
			else 
				setfillcolor(RGB(150,150,150)); // 元素为0表示为空，颜色为灰色
			// 在对应位置处，以对应颜色绘制小方格
			fillrectangle(j*BLOCK_SIZE,i*BLOCK_SIZE,
						(j+1)*BLOCK_SIZE,(i+1)*BLOCK_SIZE); 
		}
	}
	setfillcolor(RGB(0,255,0)); //  食物为绿色
	//  绘制食物小方块
	fillrectangle(food_j*BLOCK_SIZE,food_i*BLOCK_SIZE,
				(food_j+1)*BLOCK_SIZE,(food_i+1)*BLOCK_SIZE);
	if (isFailure) //  如果游戏失败
	{
		setbkmode(TRANSPARENT); // 文字字体透明    
		settextcolor(RGB(255,0,0));// 设定文字颜色
		settextstyle(80, 0, _T("宋体")); //  设定文字大小、样式
		outtextxy(240,220,_T("游戏失败")); //  输出文字内容
	}
	FlushBatchDraw(); // 批量绘制
}	

void updateWithoutInput() // 与输入无关的更新函数
{
	if (isFailure) //  如果游戏失败，函数返回
		return;
	static int waitIndex = 1; // 静态局部变量，初始化时为1
	waitIndex++; // 每一帧+1
	if (waitIndex==10) // 如果等于10才执行，这样小蛇每隔10帧移动一次
	{
		moveSnake(); //  调用小蛇移动函数
		waitIndex = 1; // 再变成1
	}
}

void updateWithInput()  // 和输入有关的更新函数
{
	if(_kbhit() && isFailure==0)  //  如果有按键输入，并且不失败
	{
		char input = _getch(); //  获得按键输入
		if (input=='a' || input=='s' || input=='d' || input=='w') // 如果是asdw 
		{
			moveDirection = input;  // 设定移动方向
			moveSnake(); // 调用小蛇移动函数
		}
		
	}
}

int main() //  主函数
{
	startup();  // 初始化函数，仅执行一次	
	while (1)   // 一直循环
	{
		show();  // 进行绘制
		updateWithoutInput(); // 和输入无关的更新 
		updateWithInput();    // 和输入有关的更新
	}
	return 0;
}
