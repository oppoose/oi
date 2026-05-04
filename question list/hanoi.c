#include <stdio.h>
#include <time.h>
void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%c->%c\n", a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    printf("%c->%c\n", a, c);
    hanoi(n - 1, b, a, c);
}
int main()
{
    int n;
    scanf("%d", &n);
    clock_t start,end;
    start = clock();
    hanoi(&n, 'A', 'B', 'C');
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", time_taken);
    return 0;
}