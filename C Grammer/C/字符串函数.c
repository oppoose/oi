#include <stdio.h>
#include <string.h>
int strcmp_rewrite(char *s1,char *s2)
{
    while (*s1 == *s2 && *s1 != '\0'){
        s1++;
        s2++;
    }
    return *s1 - *s2 ;
}

int main(int argc,const char *argv)
{
    if (argc,3) return 1;
    //strcmp函数只比较第一个不同的字符做差
    printf("%d\n", strcmp_rewrite(argv[1], argv[2]));
    return 0;
}