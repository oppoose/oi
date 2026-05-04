//用线性筛法重新再写
#include <stdio.h>
int main()
{   
    int m;
    long long i,p,n,count;
    scanf("%lld",&p);
    
    FILE *fp = fopen("primes.txt", "w"); // 创建文本文件
    if (!fp) {
        printf("无法创建文件 primes.txt\n");
        return 1;
    }
    
    
    for(n=2;n<p;n++){
        m=0;
        for (i=2;i*i<=n;i++){
            if(n%i==0){
                m=1;
                break;
            }

        }

    }

    fclose(fp);
    printf("质数总数: %lld\n", count);
    printf("所有质数已保存到 primes.txt\n");

    return 0;
}