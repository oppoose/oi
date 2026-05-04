#include <stdio.h>
#include <math.h>

int main() {
    //int x1,y1,x2,y2,x3,y3;
    while(1){ 
/*    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
        if(x1==114) break;
    int aXb = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
    int double_area = (aXb>0)?aXb:-aXb;

    if (aXb==0) {
        printf("Impossible");
        return 0;
    } */
    double x1,y1,x2,y2,x3,y3;
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
        if (fabs(x1-114)<1e-8) break;
    double cross = (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
    if(fabs(cross)<1e-8){
        printf("Impossible");
        return 0;
    }

    double L = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
              + sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3))
              + sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    //海伦公式
    double a = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    double b = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    double c = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
    double s = (a+b+c)/2.0;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));

    printf("叉乘答案 L = %lf, A = %lf\n", L, fabs(cross)/2.0);
    printf("海伦答案 L = %lf, A = %lf\n", L, area);}
    return 0;
}



/*
#include <stdio.h>
#include <math.h>

int main(){
    double x1,y1,x2,y2,x3,y3;
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);

    double cross = (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
    if(fabs(cross)<1e-8){
        printf("Impossible");
        return 0;
    }

    double L = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))
             + sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3))
             + sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));

    double area = fabs(cross)/2.0;
    printf("L = %.2f, A = %.2f", L, area);
}


#include <stdio.h>
#include <math.h>

int main() {
    double x1,y1,x2,y2,x3,y3;
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);

    double a = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    double b = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    double c = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));

    double s = (a+b+c)/2.0;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));

    if(area < 1e-8){
        printf("Impossible");
        return 0;
    }

    double L = a+b+c;
    printf("L = %.2f, A = %.2f", L, area);
}





#include <stdio.h>
#include <math.h>

int main(){
    double x1,y1,x2,y2,x3,y3;
    
    double aXb = (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
    double area = (aXb>0)?aXb:-aXb;
    
    if(area<1e-8){
        printf("Impossible");
        return 0;
    }

    double L = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))
             + sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3))
             + sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));

    printf("L = %.2f, A = %.2f", L, area/2.0);
}
*/