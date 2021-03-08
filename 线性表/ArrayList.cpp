/*因为顺序表最开始被初始化为空，lenth初始化为1，所以往里面插入元素时，lenth随之加1，导致
data[0]对应的lenth是1，这也更符合人类的计数习惯。而面对一个非空的顺序表时，其data[0]对应
的lenth可能也被设置为0，在编写程序时需要注意这一点，具体问题具体分析。*/
#include<stdio.h>
#define MAX 10
struct SList
{
    int data[MAX];
    int lenth;
};
void init(struct SList* p){
    p->lenth = 0;
}
void printList(const struct SList* p){
    for (int i = 0; i < p->lenth; i++)
        printf("%d ", p->data[i]);
    putchar('\n');
}
void insert(struct SList *p,int k,int s){
    int i;
    if (p->lenth == MAX){
        printf("表满\n"); 
        return;
    }
    if(k<1 || k>p->lenth+1){
        printf("插入位置错误\n");
        return;
    }
    for (i = p->lenth; i >= k-1; i--){
        p->data[i] = p->data[i-1];
    }
    p->data[k-1]=s;
    p->lenth++;
    return;
}
void deleted(SList *p, int x, int *b){
    if(x<1 || x>p->lenth){
        printf("需要删除的第%d号元素不存在",x);
        return;
    }
    *b = p->data[x-1];
    for (int i = x; i < p->lenth; i++)
    {
        p->data[i-1] = p->data[i];
    }
    p->lenth--;
    return;
}
int main(){
    struct SList a;
    int b;
    init(&a);               //初始化顺序表
    insert(&a, 1, 33);      //插入元素
    insert(&a, 2, 44);  
    insert(&a, 3, 55);
    insert(&a, 4, 11);
    printList(&a);          //打印顺序表中元素
    deleted(&a, 4 , &b);         //删除元素
    printList(&a);
    printf("被删除元素为：%d",b);
    getchar();
    return 0;
}