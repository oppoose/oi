#include <stdio.h>
#include <stdlib.h>
typedef struct list{
    int value;
    struct list *next;
}ll;

int main(){
    int n;
    int cnt = 0;
    ll *tail = NULL,*head = NULL;
    while(cnt++){

        scanf("%d",&n);
        ll *p = (ll*)(malloc(sizeof(ll) ) );

        if(n == -1) break;
        p->value = n;
        p->next = NULL;
        if(head == NULL){
            head = p;
            tail = p;
        }
        if(tail != NULL){
            tail->next= p;
            tail = p;
        }

        
    }
}