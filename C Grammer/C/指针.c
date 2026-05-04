#include <stdio.h>
#include <stdlib.h>
void f(int *a);//括号里写(int a[])也可以
int main()
{
    int i = 1;
    printf("%p\n",&i);
    int *p = &i;
    printf("%p\n",p);
    printf("%p\n",p+1);//下个数据在哪,类比数组位置是int就+4是char就+1
    printf("%d\n",p+1-p);//你这样写不是对两个指针的数量做差,首先存在截断问题,其次指针做差会自动除掉字符类型的长度(sizeof(int)),最后只得到元素间隔,如数组一样,我们如下可以这样操作
    printf("%td\n",(char*)(p+1)-(char*)p);
    //printf("%d",p);//不可以,数据类型都不一样,原类型是int*,输出为int值是会发生截断,
    printf("%p",(int*)p);

    p = (int*)malloc(100);//malloc是void*变量所以要使用时类型转化 int *p = malloc(....)也是一种写法,但在C++中不能用
    //int*类型只是代表指针指向的变量为int类型,实际上p还是八字节,类型转化时(int)才是四字节例子如下
    //p = 00007FFEEFBFF45C   // 64位指针
    //(int)p = EFBFF45C      // 只剩低 32 位，高位 00007FFE 被截掉

    free (p);
    
    return 0;
}
//64位电脑的指针都是8字节的,输出的十六个16进制的数字每两个代表一个字节,8bit拆成4+4每四个比特转化成一个十六进制的数字
//如果一个指针p,他作为一个八字节数,强制输出为(int)p,就会发生截断丢失前四位