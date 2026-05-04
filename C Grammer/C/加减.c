#include <stdio.h>
#include <Windows.h>

int main()
{
    int price = 0;   /*你是一个一个一个一个一个一个注释啊啊啊啊啊啊*/
    
    int change = 0;

    printf("请您输入");
    
    scanf("%d,%d",&price,&change);

    int x = price - change;

    //x += x +10;

    printf("找您%d\n",x);

    return 0;
}