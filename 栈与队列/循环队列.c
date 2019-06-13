#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 1000
typedef int QElemType;
typedef int Status;

//循环队列，队列空的时候认为front = rear， 队列满的时候认为(rear + 1) % QueueSize == front
typedef struct 
{
    QElemType data[MIXSIZE];
    int front;   //头指针
    int rear;    //尾指针
}SqQueue;

//初始化
Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

//求长度, 通用公式为(rear - front + QueueSize) % QueueSize
int QueueLength(SqQueue *Q)
{
    return Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

//入队列
Status EnQueue(SqQueue *Q, QElemType e)
{
    if((Q->rear + 1) % MAXSIZE == Q->front)  //队列满
    {
        return ERROR;
    }
    else
    {
        Q->data[Q->rear] = e;
        Q->rear = (Q->rear + 1) % MAXSIZE;   //若rear到最后则循环移到开头
    }
    return OK;
}

//出队列
Status DeQueue(SqQueue *Q, QElemType e)
{
    if(Q->rear == Q->front)   //队列空
    {
        return ERROR;
    }
    else
    {
        e = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
    }
    return OK;
}

