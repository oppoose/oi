#include <stdio.h>
#include <string.h>

int main() {
    char str[80];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if(str[len-1] == '\n') str[len-1] = '\0';  // 去掉换行

    int flag[128] = {0}; // ASCII标记数组
    for(int i = 0; str[i]; i++)
        flag[(int)str[i]] = 1;

    for(int i = 0; i < 128; i++)
        if(flag[i])
            printf("%c", i);
    printf("\n");
    return 0;
}
