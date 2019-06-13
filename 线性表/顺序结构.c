#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;
int GetElem(SqList L,int i,ElemType e) //用e返回顺序表中i下标对应的元素
{
    if(L.length==0 || i<1 || i>L.length)
        return ERROR;
    else
    {
        e=L.data[i-1];
        return OK;
    }
}
int ListInsert(SqList* L,int i,ElemType e) //在L的第i个位置处插入元素e
{
    int k;
    if(L->length==MAXSIZE) //顺序表满
        return ERROR;
    else if(i<1 || i>L->length+1)  //i的范围非法
        return ERROR;
    else if(i<=L-length) //若插入位置不在表尾则元素依次后移
    {
        for(k=L->length-1;k>=i-1;k--)
            L->data[k+1]=L->data[k];
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}
int ListDelete(SqList* L,int i,ElemType e)
{
    int k;
    if(L->length==0) //空表
        return ERROR;
    else if(i<1 || i>L-length-1)  //i的范围非法
        return ERROR;
    else if(i<L->length-1) //若删除位置不在表尾则元素依次前移
    {
        for(k=i-1;k<=L->length-1;k++)
            L->data[k]=L->data[k+1];
    }
    L->length--;
    return OK;
}
void ShowList(SqList* L)
{
    printf("顺序表的长度为:%d\n",&(L->length));
    printf("表中的元素依次为：\n");
    for(int i=0;i<L->length;i++)
    {
        printf("%d  ",&(L->data[i]));
    }
    printf("\n");
}
int main()
{
    SqList L;
    for(int i=0;i<10;i++)
        L.data[i]=i;
    L.length=10;
    SqList* p=&L;
    int j;
    int k;
    j=GetElem(p,1,k);
    switch(j)
    {
        case 1 : printf("取得元素成功!\n");break;
        case 0 : printf("取得元素失败!\n");break;
    }
    printf("取得的元素为%d\n",&k);
    ShowList(p);
    j=ListInsert(p,0,3);
    switch(j)
    {
        case 1 : printf("插入成功!\n");break;
        case 2 : printf("插入失败!\n");break;
    }
    printf("在顺序表开头插入元素3\n");
    ShowList(p);
    j=ListDelete(p,0,k);
    switch(j)
    {
        case 1: printf("删除成功!\n");break;
        case 2: printf("删除失败!\n");break;
    }
    printf("删除表头元素\n");
    ShowList(p);
    printf("被删除的元素为%d\n",&k);
    return 0;
}