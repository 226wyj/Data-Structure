#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define MAXSIZE 1000
typedef int SElemType;

typedef struct
{
    SElemType data[MAXSIZE];
    int top1; //栈1顶指针
    int top2; //栈2顶指针
}SqDoubleStack;

//插入值为e的元素, stackNumber为判断是栈1还是栈2的序号参数
int Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if(S->top1 == S->top2)    //栈满
    {
        return ERROR;
    }
    if(stackNumber == 1)
    {
        S->top1++;
        data[S->top1] = e;
    }
    else if (stackNumber == 2)
    {
        S->top2--;
        data[s->top2] = e;
    }
    return OK;
}

//若栈不空，则删除S的栈顶元素，用e返回其值，否则返回ERROR
int Pop(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if(stackNumber == 1)
    {
        if(S->top1 == -1)
        {
            return ERROR;
        }
        else
        {
            e = data[S->top1];
            S->top1--;
        }
    }
    else if(stackNumber == 2)
    {
        if(S->top2 == MAXSIZE)
        {
            return ERROR;
        }
        else 
        {
            e = data[S->top2];
            S->top2++;
        }
    }
    return OK;
}

