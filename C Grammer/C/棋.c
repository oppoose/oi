#include <stdio.h>
int main()
{   
    int i,j;
    //const int X = 1;
    //const int Y = 0;
    int sum_i = 0;
    int sum_j = 0;
    int result  = 0;
    char a[3][3];
    for (i=0;i<=2;i++){
        for (j=0;j<=2;j++){
            scanf("%d",&a[i][j]);
        }
    }


//检查条件
    for (i=0;i<=2;i++){
        sum_i = 0;sum_j = 0;
        for (j=0;j<=2;j++){
            sum_i += a[i][j];
            sum_j += a[j][i];
            if (sum_i == 3|| sum_j == 3){
                result = 0;
            }
            if (sum_i ==0 || sum_j == 0){
                result = 0;
            }
        }

    }
    
}