//静态链表中数组第一个元素和最后一个元素特殊处理。第一个元素的cur存放第一个空闲位置的下标，最后一个元素的cur存放
//第一个插入元素的下标，两个元素的data都不存数据。如果下一数据为空，则cur=0
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct
{
    ElemType data;
    int cur;
}Component,StaticLinkList[MAXSIZE];

int InitList(StaticLinkList space) //初始化
{
    int i;
    for(i=0;i<MAXSIZE-1;i++)
        space[i].cur=i+1;
    space[MAXSIZE-1].cur=0;
    return OK;
}
int ListLength(StaticLinkList L)  //返回L中数据元素个数
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}
/**************************************************插入操作*********************************************************/
int Malloc_SLL(StaticLinkList space) //取得一个空闲的位置下标
{
    int i=space[0].cur;
    if(i)
        space[0].cur=space[i].cur;
    return i;
}
int ListInsert(StaticLinkList L,int i,ElemType e)  //数组中的元素没有移动，改变的是cur，即“指针”
{                                                  //在第i个元素前插入元素e
    int j,k,l;
    k=MAXSIZE-1;
    if(i<1 || i>ListLength(L)+1)
        return ERROR;
    j=Malloc_SLL(L);
    if(j)
    {
        L[j].data=e;
        for(l=1;l<=i-1;l++)
           k=L[k].cur;
        L[j].cur=L[k].cur;
        L[k].cur=j;
        return OK;
    }
    return ERROR;
}
/*******************************************************************************************************************/

/***********************************************删除操作********************************************************/
void Free_SSL(StaticLinkList L)
{
    space[k].cur = space[0].cur;  //把第一个元素cur值赋给要删除的分量cur
    space[0].cur = k;    //把要删除的分量下标赋值给第一个空闲的位置
}

int ListDelete(StaticLinkList L, int i)
{
    int j, k;
    if (i < 1 || i > ListLength(L))
    {
        return ERROR;
    }
    k = MAX_SIZE-1;
    for(j=1;j<=i-1;j++)
    {
        k=L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL (L, j);
    return OK;
}
/*********************************************************************************************************/

int ListLength ( StaticLinkList L )
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}