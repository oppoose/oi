/*#include <stdio.h>

int main()
{
    int p =11;

    printf("%d",p/3);

    return 0;

    向下取整，结果为三
}*/
#include <stdio.h>
int main()
{
    //printf("请输入身高单位英尺加英寸，输入时请按照空格隔开");
    
    int inch;
    scanf("%f",inch);
    
    //double foot;

    //for(inch=1;inch<10000;inch++)

    //printf("身高是%f米\n",(inch + foot/12)*0.3048);

    printf("%f",1.0/inch);


    return  0;
}