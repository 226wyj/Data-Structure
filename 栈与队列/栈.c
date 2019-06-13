#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define MAXSIZE 1000
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

/*top为栈顶元素下标，栈空时为-1*/

int Push(SqStack *S, SElemType e) //插入元素e为栈顶元素
{
    if(S->top == MAXSIZE-1)
    {
        return ERROR;           //栈满
    }
    S->top++; //栈顶指针加1
    S->data[S->top]=e;  //将新插入元素赋值给栈顶空间
    return OK;  
}

/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR*/
int Pop(SqStack *s, SElemType e)
{
    if(s->top == -1)
    {
        return ERROR;
    }
    e = s -> data[s->top];
    s -> top--;
    return OK;
}



