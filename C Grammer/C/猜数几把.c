#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{   
    int nb;
    int n;
    srand(time(0));
    int b = rand() %100;
    

    //printf("%d",b);
    int a;
    printf("请输入你要猜的数，一百以内的\n");
    do{
        scanf("%d",&a);
        n++;
        if (a>b){
            printf("大了,再猜\n");
        }
        else if(a<b){
            printf("小了,再猜\n");
        }
    }
    while (a!=b);
    printf("猜对了！这个数就是%d,你一共猜了%d次",b,n);




    return 0;

}