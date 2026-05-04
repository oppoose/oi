//以下三种写法都可以定义字符串(字符串数组),但指针b的字符串不能写,只读,相当于定义的是字符常量,
//另一个有趣的现象,当你的两个字符串指针指向的字符串相同时,那他们指针是一样的
//char  b[] = "hello";
//char *b   = "hello";
//char *a   = "hello";

//char  b[6]= "hello";//b[0]='h',b[1]='e' ......b[5]='\0'

//printf("%c",b[5]);

//%c专门用来输出单个字符的---printf("%c",b[3]) scanf("%c",&b[2])

//%s输出字符串使用时直接printf("%s",b)就行
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

int main()
{
    char word[8];
    scanf("%7s\n",word);//%7s意思是最多读取七个字符,%7d也类似

    char b[] = "abcde";
    char a[] = "baaaa";
    printf("%d\n",strcmp(b,a));//strcmp函数只比较第一个不同的字符做差

    
}