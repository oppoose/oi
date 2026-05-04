#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *next;//里面存留的只是一个八位地址而非下一个结构，下一个结构中的指针也只是一个八位地址
    //不过只是这个八位地址能够去引导其指向下一个Node
} Node;

void add (Node *,int number){
    
}

int main(int argc, char const *argv[]) {
    Node *head = NULL;
    Node *tail = NULL;
    int number;

    do {
        scanf("%d", &number);
        if (number != -1) {
            //创建新节点
            //指针的前缀只是告诉这个指针要指向什么样的东西，是一种模式，无论什么指针都是八位，Node大小只有十二位
            Node *p = (Node*)malloc(sizeof(Node)); 
            p->value = number;
            p->next = NULL;

            // 找到链表的最后一个节点
            //Node *last = head; //指针传递,head所指也为last所指,不是指针指针（如果是应该加&）
            if (head == NULL){
                head = p;
                tail = p;
            } else {
                tail->next = p;
                tail = p;
            }
        }
    } while (number != -1);


    //head -> [10 | next] -> [20 | next] -> [30 | NULL]
    // 打印链表，检查结果
    Node *cur = head;
    while (cur) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free (tmp);//指针指向的是同一块内存，你free(tmp)就是free了这一块内存
    }
    head = NULL;
    printf("\n");
    
    
    return 0;
}
