#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0 
typedef int QElemType;
typedef int Status;

//结点定义
typedef struct QNode
{
    QElemType data;
    struct QNode* next;
}QNode, *QueuePtr;

typedef struct LinkQueue
{
    QueuePtr front; //队头指针
    QueuePtr rear;  //队尾指针
}LinkQueue;

//插入元素e为队尾元素
Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)   //分配失败
    {
        return ERROR;
    }
    else
    {
        p->data = e;
        p->next = NULL;
        Q->rear->next = p;
        Q->rear = p;
    }
    return OK;
}

//删除队头操作
Status DeQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr p;
    if(Q->front == Q->rear)  //队空
    {
        return ERROR;
    }
    else
    {
        p = Q->front->next;
        e = p->data;
        Q->front->next = p->next;
        if(Q->rear == p)      //如果p是最后一个元素，则让Q->rear = Q->front， 代表栈已经空了
        {
            Q->rear = Q->front;
        }
        free(p);
    }
    return OK;
}