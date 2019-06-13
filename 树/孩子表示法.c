//把每个结点的孩子结点排列起来，以单链表作为存储结构
//则n个结点有n个单链表，若为叶子节点则此单链表为空
//然后n个头指针又组成一个线性表，采用顺序结构存进数组中

#define MAX_TREE_SIZE 100
typedef int TElemType;

//孩子结点
typedef struct CTNode 
{
    int child;  //记录指针下标
    struct CTNode* next;
}*ChildPtr;

//表头数组中每个头指针的结构
typedef struct 
{
    TElemType data;
    ChildPtr firstchild;
}CTBox;

typedef struct 
{
    CTBox nodes[MAX_TREE_SIZE];
    int r, n;   //根的位置和结点数
}CTree;