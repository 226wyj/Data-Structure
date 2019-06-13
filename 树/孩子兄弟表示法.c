typedef int TElemType;

/* 树的孩子兄弟表示法 */
//firstchild存储该结点的第一个孩子，rightsib存储该结点右兄弟结点
typedef struct CSNode
{
    TElemType data;
    struct CSNode *firstchild, *rightsib;
}CSNode, *CSTree;