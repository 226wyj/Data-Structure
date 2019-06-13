#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node;
typedef struct Node* LinkList;
void CreateListHead(LinkList *L,int n)  //头插法建立链表
{
    LinkList p;
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;
        p->next=(*L)->next;
        (*L)->next=p;
    }
}
void CreateListTail(LinkList *L,int n)  //尾插法建立链表
{
    LinkList p,r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r=*L;
    for(i=0;i<n;i++)
    {
        p=(Node*)malloc(sizeof(Node));
        p->data=rand()%100+1;
        r->next=p;
        r=p;
    }
    p->next=NULL;
}
//L为头节点
int GetElem(LinkList L,int i,ElemType e) //取得链表中第i号元素，用e返回
{
    int j=1;
    LinkList p;
    p=L->next;
    while(p && j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p || j>i)
        return ERROR;
    e = p->data;
    return OK;
}
int LinkInsert(LinkList* L,int i,ElemType e) //在链表中第i号元素之前插入一个新的元素e
{
    int j;
    LinkList p,s;
    p=*L;
    j=1;
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)
        return ERROR;
    s=(LinkList)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}
int LinkDelete(LInkList* L,int i,ElemType e) //删除链表中第i号元素，用e返回
{
    int j;
    LinkList p = *L;
    LinkList q;
    j=1;
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)
        return ERROR;
    q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return OK;
}
int ClearList(LinkList* L) //单链表整表删除
{
    LinkList p,q;
    p=(*L)->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
    return OK;
}