#include <stdio.h>

struct point{
    int x;
    int y;
    int z;
}p1;//这样和定义和 struct point p1;是一样的

//当我们定义了一个这样的p1时，可以用p1.x去代指p1这个结构中x的值

//定义p1后，我们可以这样赋值struct point p1={1,2,3}; or  struct point p1={.x=1,.y=2,.z=3};没有被赋值的会默认为零（{.x=1,.z=3}),也可以这样（如下）
int main()
{   
    struct point p1;
    p1 = (struct point){1,2,3};
    printf("%d",p1.z);
}
//对取地址运算来说&p1.x是先对p1.x后取地址
//假如我们有struct point p,*r
//其中r为p指针，r=&p;
//那我们可以用r->x来代指p.x