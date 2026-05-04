#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int candidate = 0, count = 0;
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if(count == 0) {
            candidate = num;
            count = 1;
        } else if(candidate == num) {
            count++;
        } else {
            count--;
        }
    }
    printf("%d", candidate);
}
// 数组 [2,2,1,1,2]

// 先拿两个不同的元素：2和1抵消 → 剩下 [2,1,2]

// 再拿两个不同的：2和1抵消 → 剩下 [2]
// 最后剩下的就是多余一半数元素。

