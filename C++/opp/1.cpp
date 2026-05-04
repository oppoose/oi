#if !defined __CIRCLE__H__
#define __CIRCLE__H__
#include <iostream>
using namespace std;
class Circle
{public:
//带默认参数的构造函数
Circle(double a = 5.0, double b = 5.0, double c = 5.0)
{ x = a;
y = b;
if (c>0) r = c;
else r = 5.0;
}


//复制构造函数
Circle(Circle &c)
{ x = c.x;
y = c.y;
r = c.r;
}
void draw(){
    cout << "Draw a circle at ("
    << x << ","<<y
<< "), with radius " << r
<< "." << endl;
}
private:
double x, y; //x、y坐标
double r;
//半径
};
#endif
