#include <stdio.h>
int main()
{
    enum C = {ol,ik,uj};//这样的定义其实就是让这些字符串的值为0，1，2，也可以指定值如ol=1，jk=5，uj=7    注 类型还是int
    //自然可以被用到case语句中 
    
/*
enum COLOR { RED, YELLOW, GREEN };

int main(int argc, char const *argv[])
{
    int color = -1;
    char *colorName = NULL;

    printf("输入你喜欢的颜色的代码: ");
    scanf("%d", &color);

    switch (color) {
    case RED: 
        colorName = "red"; 
        break;
    case YELLOW: 
        colorName = "yellow"; 
        break;
    case GREEN: 
        colorName = "green"; 
        break;
    default: 
        colorName = "unknown"; 
        break;
    }

    printf("你喜欢的颜色是=%s\n", colorName);

    return 0;
}
*/




}