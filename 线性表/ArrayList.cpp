/*��Ϊ˳����ʼ����ʼ��Ϊ�գ�lenth��ʼ��Ϊ1���������������Ԫ��ʱ��lenth��֮��1������
data[0]��Ӧ��lenth��1����Ҳ����������ļ���ϰ�ߡ������һ���ǿյ�˳���ʱ����data[0]��Ӧ
��lenth����Ҳ������Ϊ0���ڱ�д����ʱ��Ҫע����һ�㣬����������������*/
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
        printf("����\n"); 
        return;
    }
    if(k<1 || k>p->lenth+1){
        printf("����λ�ô���\n");
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
        printf("��Ҫɾ���ĵ�%d��Ԫ�ز�����",x);
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
    init(&a);               //��ʼ��˳���
    insert(&a, 1, 33);      //����Ԫ��
    insert(&a, 2, 44);  
    insert(&a, 3, 55);
    insert(&a, 4, 11);
    printList(&a);          //��ӡ˳�����Ԫ��
    deleted(&a, 4 , &b);         //ɾ��Ԫ��
    printList(&a);
    printf("��ɾ��Ԫ��Ϊ��%d",b);
    getchar();
    return 0;
}