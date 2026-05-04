#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*int main()
{

    char x[100000];
    char y[100000];
    // 读取字符串x和y
    scanf("%s",x);
    getchar(); // 消耗换行符,但这样没法在字符串中加入空格所以略去不用
    fgets(x, sizeof(x), stdin);
    fgets(y, sizeof(y), stdin);//看一下fget和scanf的区别
    size_t len;
    len = strlen(y);
    for(int i=0;i<100000;i++){
        int cnt=0;
        for(int j=0;j<len;j++){
            if(x[i+j]!=y[j]){
                break;
            }
            else{
                cnt++;
            }
            if (cnt == len){
                printf("%d ",i);
            }     
            }
        }
    return 0;
} */





// 生成 next 数组（部分匹配表）
void buildNext(const char *pat, int *next, int m) {
    int j = 0;      // 前缀长度
    next[0] = 0;    // 第一个位置没有前后缀

    for (int i = 1; i < m; i++) {
        while (j > 0 && pat[i] != pat[j]) {
            j = next[j - 1]; // 回退
        }
        if (pat[i] == pat[j]) {
            j++;
        }
        next[i] = j;
    }
}

// KMP 搜索
void KMP(const char *text, const char *pat) {
    int n = strlen(text);
    int m = strlen(pat);
    int *next = (int *)malloc(sizeof(int) * m);
    buildNext(pat, next, m);

    int j = 0;
    int found = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pat[j]) {
            j = next[j - 1];
        }
        if (text[i] == pat[j]) {
            j++;
        }
        if (j == m) {
            printf("%d ", i - m + 1); // 输出位置（从0开始）
            found = 1;
            j = next[j - 1]; // 继续寻找下一个
        }
    }

    if (!found) {
        printf("-1");
    }

    free(next);
}

int main() {
    char s1[10005], s2[10005];
    fgets(s1, sizeof(s1), stdin); // 读模式串
    fgets(s2, sizeof(s2), stdin); // 读主串

    // 去掉末尾换行符
    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;

    KMP(s2, s1);
    return 0;
}
