#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 1000
typedef int SElemType;
typedef int Status;

//结点定义
typedef struct StackNode
{
    SElemType data;
    struct StackNode* next;
}StackNode, *LinkStackPtr;

//链栈定义
typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

//插入e为栈顶元素
Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr p = (LinkStackPtr) malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
    return OK;                          
}

//删除栈顶元素,用e返回其值
Status Pop(LinkStack *S, SElemType e)
{
    LinkStackPtr p;
    if(S->count == 0)
    {
        return ERROR;
    }
    else
    {
        p = S->top;
        e = p->data;
        S->top = p->next;
        free(p);
        S->count --;
        return OK;
    }
}
    