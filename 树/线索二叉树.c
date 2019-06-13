#define OK 1
#define ERROR 0
typedef int Status;
typedef char TElemType;

//Link == 0表示指向左右孩子指针
//Thread == 1 表示指向前驱或后继的线索
typedef enum {Link, Thread} PointerTag;

//LTag为0时指向该结点的左孩子，为1时指向该结点的前驱
//RTag为0时指向该结点的右孩子，为1时指向该结点的后继
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode, *BiThrTree;

BiThrTree pre;  //全局变量，始终指向刚刚访问过的结点

//中序遍历线索化
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);
        if(!p->lchild)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if(!pre->rchild)
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

//T指向头结点，头结点左链lchild指向根结点，头结点右链rchild指向中序遍历的
//最后一个结点。中序遍历二叉线索链表表示的二叉树T
Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild;  //p指向根结点
    while(p != T)   //空树或遍历结束时 p==T
    {
        while(p->LTag == Link)
        {
            p = p -> lchild;
        }
        printf("%c ", p->data);
        while(p->RTag == Thread && p->rchild != T)  //右指针指向后继结点
        {
            p = p->rchild;
            printf("%c ", p->data);
        }
        p = p->rchild;
    }
    return OK;
}