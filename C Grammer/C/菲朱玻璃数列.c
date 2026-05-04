/*#include <stdio.h>
int main()
{
    int x=1;
    int y=2;
    while (x<1000000000){
        printf("%d %d ",x,y);
        x+=y;
        y+=x;        
    }

    return 0;
}
int最大整数值小，修改为如下*/
#include <stdio.h>

int main() 
{
    long long x = 1;
    long long y = 2;

    while (x < 10000000000000000LL) {
        printf("%lld %lld ",x,y);
        x += y;
        y += x;        
    }

    return 0;
}
