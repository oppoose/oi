#include <stdio.h>
#include <stdlib.h>

typedef struct a{
    double volume;
    int index;
} Bubble;

// 比较函数，用于 qsort，从大到小排序
int cmp(const void *a, const void *b) {
    Bubble *x = (Bubble *)a;
    Bubble *y = (Bubble *)b;
    if (x->volume != y->volume)
        return (x->volume < y->volume) ? 1 : -1; // 从大到小
    else
        return x->index - y->index; // 体积相同按编号升序
}

int main() {
    int N;
    scanf("%d", &N);
    Bubble bubbles[N]; //结构体也可以用数组,
    for (int i = 0; i < N; i++) {
        double r;
        scanf("%lf", &r);
        bubbles[i].volume = 1.33 * 3.14 * r * r * r; // 访问结构体成员都有以下格式 1.成员名2.指针->成员名3.数组名[下标].成员名4.指针数组名[下标]->成员名5.
        bubbles[i].index = i + 1;
    }

    qsort(bubbles, N, sizeof(Bubble), cmp);

    for (int i = 0; i < N; i++) {
        printf("%.2lf %d\n", bubbles[i].volume, bubbles[i].index);
    }

    return 0;
}