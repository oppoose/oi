#include <stdio.h>
int main()
{
    int a,original;

    int num,b=0;
    scanf("%d",&a);
    original=a;
    do
    {
        num=a%10;
        b=num+b*10;
        a=a/10;
    }while(a>=1);

    //printf("%d",original);
    if(b == original){
        printf("%d这个数是回文数",original);
    }
    else {
        printf("%d这个数不是回文数",original);
    }
    return 0;
}