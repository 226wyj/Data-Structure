typedef char TElemType;

/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode
{
    TElemType data; //结点数据
    struct BiTNode* lchild, *rchild;    //左右孩子指针
}BiTNode, *BiTree;

//前序遍历
void PreOrderTraverse(BiTree T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        printf("%c ", T->data); //显示结点数据
        PreOrderTraverse(T->lchild);    //遍历左子树
        PreOrderTraverse(T->rchild);    //遍历右子树
    }
}

//中序遍历
void InOrderTraverse(BiTree T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        InOrderTraverse(T->lchild);
        printf("%c ", T->data);
        InOrderTraverse(T->rchild);
    }
}

//后序遍历
void PostOrderTraverse(BiTree T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c ", T->data);
    }
}

//建立二叉树
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf("%c", &ch);
    if(ch == '#')
    {
        *T = NULL;
    }    
    else
    {
        *T == (BiTree)malloc(sizeof(BiTNode));
        if(! *T)
        {
            exit(1);
        }
        else
        {
            (*T) ->data = ch;   //生成根结点
            CreateBiTree(& (*T)->lchild);   //构造左子树
            CreateBiTree(& (*T)->rchild);   //构造右子树
        }
    }
}