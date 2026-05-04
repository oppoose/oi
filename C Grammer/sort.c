#include <stdio.h>

int main(){
    int t;
    double a[n], temp;
    scanf("%d", &t);
//冒泡
    for(int i=0;i<n;i++) scanf("%lf",&a[i]);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
                if((t==0 && a[i]>a[j]) || (t==1 && a[i]<a[j])){
                temp = a[i]; a[i] = a[j]; a[j] = temp;
            }
        }
    }
//对j后面的交换





//插入
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
// 取下一个元素 key

// 从右向左扫描已排好部分

// 所有比 key 大的都挪一格

// key 插入空出来的位置






//选择
    for (i = 0; i < n - 1; i++) {
    minPos = i;
    for (j = i + 1; j < n; j++)
        if (a[j] < a[minPos])
            minPos = j;
    swap(a[i], a[minPos]);
}
//第 i 轮，从 a[i..n-1] 中找最小元素位置 minPos

//把 a[i] 和 a[minPos] 交换

//前 i+1 项从此有序


    printf("%.2f %.2f %.2f", a[0], a[1], a[2]);//n个
}