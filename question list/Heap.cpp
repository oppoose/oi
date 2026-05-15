#include <bits/stdc++.h>
using namespace std;
#define ll long long
int heap[1000];
int heapsize = 0;
void push(int x){
    heap[++heapsize] = x;
    int i = heapsize;
    while(i>1 && heap[i] < heap[i/2]){
            swap(heap[i],heap[i/2]);
            i/=2;
    }
}
int pop(){
    int i = 1;
    int ret = heap[1];
    int smallest = 1;
    heap[1] = heap[heapsize--];
    while(1){
        int l = i*2, r = i*2+1;
        if(l <= heapsize &&heap[l] < heap[smallest]) smallest = l;
        if(r <= heapsize &&heap[r] < heap[smallest]) smallest = r;

        if(smallest == i) break;
        
        swap(heap[smallest],heap[i]);

        i = smallest;
    }
    return ret;
}
int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    for (int i = 0; i < M; i++) {
        int a;
        scanf("%d", &a);
        int smallest = pop();
        smallest += a;
        push(smallest);
    }

    printf("%d\n", pop());
    return 0;
}
