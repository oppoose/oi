/* #include <stdio.h>
int main()
{
    int a;
    int b=0,c=0,sum=0;
    scanf("%d",&a);
    b=a;
    while(b>0){
        c = b%10;
        sum = sum*10+c;
        b /= 10;
    }
    printf("%d",sum);
    return 0;
} */
/* #include <stdio.h>
int sigma (int n){
    if(n==1){
        return 1;
    }
    else return n+sigma(n-1);
}

int main()
{
    int a=sigma(100);
    printf("%d",a);
    return 0;
}
 */
