#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
#define OK 1
#define ERROR 0
typedef char SElemType;

//串的结构定义
typedef struct 
{
    int len;    //串的实际长度
    SElemType s[MAXSIZE]; 
}Str, *StrPtr;

//生成一个值等于字符串常量chars的串T
int StrAssign(StrPtr T, char* a)
{
    int i = 0;
    while(a[i])
    {
        i++;
    }
    T->len = i;
    for(int v = 0; v < T->len; v++)
    {
        T->s[v] = a[v];
    }
    T->s[v] = '\0';      //以‘\0’作为串的结束标志
    return OK;
}

//串S存在，由串S复制得串T
int StrCopy(StrPtr T, StrPtr S)
{
    if(S->len == 0)      //串长度为0，S为空串
        return ERROR;
    else
    {
        T->len = S->len;
        for(int i = 0; i < S->len; i++)
        {
            T->s[i] = S->s[i];
        }
    }
    return OK;
}

//串S存在，将串清空
int ClearString(StrPtr S)
{
    if(S->len == 0)    //空串  
        return ERROR;
    else
    {
        memset(S->s, '\0', sizeof(S->s));
        S->len = 0;
    }
    return OK;
}

//若串S为空，返回true, 否则返回false
bool StringEmpty(StrPtr S)
{
    if(S->len == 0)
        return true;
    else
        return false;
}

//返回串S的元素个数，即串的长度
int StrLength(StrPtr S)
{
    return S->len;
}

//若S > T, 返回1，若S < T, 返回值-1, 若S = T, 返回0
int StrCompare(StrPtr S, StrPtr T)
{
    if(S->len == T->len)
    {
        for(int i = 0; i < S->len; i++)
        {
            if(S->s[i] > T->s[i])
                return 1;
            else if(S->s[i] < T->s[i])
                return -1;
            else
                continue;
        }
        return 0;
    }
    else
    {
        if(S->len < T->len)
            return -1;
        else if(S->len > T->len)
            return 1;
    }
}

//用T返回由S1和S2连接而成的新串
int Concat(Str T, StrPtr S1, StrPtr S2)
{
    T.len = S1->len + S2->len;
    int i;
    while(i < S1->len)
    {
        T.s[i] = S1->s[i];
        i++;
    }
    while(i < S2->len)
    {
        T.s[i] = S2->s[i];
        i++;
    }
    return OK;
}

//若串S存在，1<=pos<=StrLength(S), 且0<=length<=StrLength(S)-pos+1
//用Sub返回串S的第pos个字符起长度为length的子串
int SubString(StrPtr Sub, StrPtr S, int pos, int length)
{
    if(S->len == 0)     //S为空  
        return ERROR;
    if(pos < 1 || pos > StrLength(S))   //位置不合格
        return ERROR;
    if(len < 0 || length > StrLength(s) - pos + 1)     //长度越界
        return ERROR;
    Sub->len = length;
    for(int i = 0; i < length; i++)
    {
        Sub->s[i] = S->s[i + pos - 1];
    }
    return OK;
}

//串S和T存在，T非空，1<=pos<=StrLength(S)
//若主串S中存在和串T值相同的串，则返回它在主串S
//中第pos个字符后第一次出现的位置，否则返回0
int Index(StrPtr S, StrPtr T, int pos)
{
    if(S->len == 0 || T->len == 0)
        return ERROR;
    if(pos < 1 || pos > StrLength(S))
        return ERROR;
    int n, m, i;
    StrPtr sub;
    if(pos > 0)
    {
        n = StrLength(S);
        m = StrLength(T);
        i = pos;
        while(i <= n-m+1)
        {
            SubString(sub, S, i ,m);
            if(StrCompare(sub, T) != 0)
                ++i;
            else
                return i;
        }
    }
    return 0;
}

//串S和T存在，T是非空串，用V替换主串S中出现的所有
//与T相等的不重叠的子串
int Replace(StrPtr S, StrPtr T, StrPtr V)
{
    if(S->len == 0 || T->len == 0 || V->len == 0)
        return ERROR;
    int l, m, n;
    StrPtr H;
    l = StrLength(S);
    m = StrLength(T);
    n = StrLength(V);
    for(int i = 0; i < l; i++)
    {
        SubString(H, i, m);
        if(StrCompare(H, T) == 0)
        {
            
        }
    }
}