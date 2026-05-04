#include <stdio.h>
#include <stdlib.h>
int main()
{   
    int N,i,x;
    scanf("%d",&N);
    char*prime=(char*)malloc((N+1)*sizeof(char));
    
    FILE *fp = fopen("primes.txt", "w"); // 创建文本文件
    if (!fp) {
        printf("无法创建文件 primes.txt\n");
        return 1;
    }

    for (i=0;i<=N;i++){
        prime[i]=1;
    }
    prime[0] = 0;
    prime[1] = 0;
    
    for (i=2;i*i<=N;i++){
        if (prime[i]){
            for (x=i*i;x<=N;x+=i)
            prime[x]=0;
        }
    }
    for (i=0;i<=N;i++){
        if (prime[i]) fprintf(fp, "%lld ", n);
    }
    fclose(fp);
    free (prime);
}