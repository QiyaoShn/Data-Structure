#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node* Llist;
void init(Llist *phead){
    *phead=NULL;            //ע������ط�ӦΪ*phead��ʾͷָ�룬phead��ͷָ��ĵ�ַ
}
int getLength(Llist phead){
    int length = 0;                 
    while (phead)              //�˴������ֻ��head��ֵ�����������ú����󲢲��ı�headֵ
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
    if(k<1){         //�����1��ʼ�ƽڵ���������λ��Ϊcount������Ҫ�ҵ�count-1��λ��
        printf("����λ�ô���\n");
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
            Llist ph = createList(x);        //����ڵ�
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
    init(&head);                //�˴���Ҫ�޸�ͷָ���ֵ������ΪNULL�����Դ���ָ�루���ã�
    insert(&head,1,11);
    insert(&head,1,22);
    insert(&head,2,33);
    insert(&head,4,22);
    insert(&head,6,33);
    int l = getLength(head);    //�˴�����Ҫ�޸�ͷָ���ֵ�����Դ���ֵ���ɣ�����
    printf("������Ϊ%d\n",l);
    printf("�������Ԫ��Ϊ��");
    printList(head);
    getchar();
}