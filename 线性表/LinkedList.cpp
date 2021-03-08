#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node* Llist;
void init(Llist *phead){
    *phead=NULL;            //注意这个地方应为*phead表示头指针，phead是头指针的地址
}
int getLength(Llist phead){
    int length = 0;                 
    while (phead)              //此处传入的只是head的值，所以跳出该函数后并不改变head值
    {
        length++;
        phead = phead->next;
    }
    return length;
}
void printList(Llist phead){
    while (phead)
    {
        printf("%d ",phead->data);
        phead = phead->next;
    }
}
Llist createList(int x){
    Llist p = (Llist)malloc(sizeof(struct Node));
    p->next = NULL;
    p->data = x;
    return p;
}
int insert(Llist *phead,int k,int x){
    int count=1;
    Llist p =* phead;
    if(k<1){         //链表从1开始计节点数，插入位置为count，则需要找到count-1的位置
        printf("插入位置错误！\n");
        return 0;
    }else if(k==1){
        Llist s = createList(x);
        s->next = *phead;
        *phead = s;
        return 1;
    }else{
        while (p && count<k-1)
        {
            p = p->next;
            count++;
        }
        if(p){
            Llist ph = createList(x);        //插入节点
            ph->next = p->next;
            p->next = ph;
            return 1;
        }
        else{
            return 0;
        }
    }
}
int main(){
    Llist head;
    init(&head);                //此处需要修改头指针的值，令其为NULL，所以传入指针（引用）
    insert(&head,1,11);
    insert(&head,1,22);
    insert(&head,2,33);
    insert(&head,4,22);
    insert(&head,6,33);
    int l = getLength(head);    //此处不需要修改头指针的值，所以传入值即可（对象）
    printf("链表长度为%d\n",l);
    printf("链表各个元素为：");
    printList(head);
    getchar();
}