#include <stdio.h>
#include <stdlib.h>
/* typedef struct {
    int *array;
    int size;
}* Array;
 */


typedef struct {
    int *array;
    int size;
} Array;


//这两种不同的写法代表的意思是不同的,上面加*的指的是这个定义的东西的
//类型是指针,如(int *) (double *)无非是变成了(struct {...} *) 
//tpyedef 原类型 新类型

//生成数组
Array array_create(int init_size){
    Array a;
    a.array = (int *)malloc(sizeof(int)*init_size);//array已经是一个指针类型无需加*
    //array指向这块内存
    a.size = init_size;  
    return a;
}

void array_free(Array *a)
{
    free(a->array);
    a->size = 0;
    a->array = NULL;
}
//增长方案
void array_inflate(Array *a,int more_size){
    int *p = (int*)malloc(sizeof(int)*(a->size+more_size));
    for(int i=0;i<a->size;i++){
        p[i] = a->array[i];
    }
    free (a->array);
    a->array = p;//将重新申请内存赋给数组
    a->size = a->size+more_size;//
}





