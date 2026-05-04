#include <stdio.h>
#include <math.h>
int main()
{
    int n,m,a,original,i,temp;
    
    scanf("%d",&i);
    
    for(n=pow(10,i-1);n<pow(10,i);n++){
        int n_power=0,sum=0;
        int count=1;
        m=n;
        original=m;
        temp=n;
        while(temp>0){
            temp/=10;
            count*=10;
            n_power++;
        }
        count/=10;
        for(;count>0;count/=10){
            a=m/count;
            m%=count;
            sum+=pow(a,n_power);
        }
        if(sum==original){
            printf("%d ",original);
        }
    }

    return 0;
}