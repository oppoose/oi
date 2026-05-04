#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <quickpower.h>

int main() {
    
    static char str[500001];
    fgets(str, sizeof(str), stdin);
    
    int len = strlen(str);
    if(len > 0 && str[len-1] == '\n') str[len-1] = '\0';  // 去掉换行

    char *words[100000]; // 存放单词指针
    int count = 0;
    char *p = str;
    while(*p) {                         //*p条件为真说明没到字符串末尾,即*p!='\0'
        while(*p && isspace(*p)) p++;  // 跳过空格
        if(*p) {
            words[count++] = p;         // 记录单词开始位置
            while(*p && !isspace(*p)) p++; // 移动到单词末尾
            if(*p) *p++ = '\0';         // 断开单词,变成独立字符串
        }
    }

    for(int i = count-1; i >= 0; i--) {
        printf("%s", words[i]); //%s后面需要加字符串的地址
        if(i > 0) printf(" ");
    }
    printf("\n");
    return 0;
}
