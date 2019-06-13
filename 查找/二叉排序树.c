//二叉树的二叉链表结点结构定义
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//递归查找二叉排序树T中是否存在key
//指针f指向T的双亲，当T为根结点时候f为NULL
//若查找成功则指针p指向该数据元素结点并返回True
//否则指针p指向查找路径上访问的最后一个结点并返回False
bool SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if(!T)  //树不存在，查找失败
    {
        *p = f; //NULL
        return false;
    }
    else if(key == T->data)
    {
        *p = T;
        return true;
    }
    else if(key < T->data)  //key值小于当前根结点的值，则递归搜索左子树
        return SearchBST(T->lchild, key, T, p);
    else    //key值大于当前根结点的值，递归搜索右子树
        return SearchBST(T->rchild, key, T, p);
}

//当二叉排序树T中不存在关键字等于key的数据元素时
//插入key并返回true, 否则返回false
bool InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if(!SearchBST(*T, key, NULL, &p))   //没有找到该结点
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        //查找失败会返回待插入结点的父亲结点，但是要判断该父亲结点是否为空
        if(!p)  //父亲结点为空，说明原来的树T为空树
        {
            *T = s;
        } 
        //父亲结点不为空，根据待插入值与父亲结点值的大小关系进行插入
        else if(key < p->data)
        {
            p->lchild = s;
        }
        else
            p->rchild = s;
    }
    else    //树中已有关键字相同的点，不再插入
        return false;
}
