//假设以一组连续的空间存储树的结点，同时在每个结点中，附设一个指示器
//指示其双亲结点在数组中的位置

#define MAX_TREE_SIZE 100
typedef int TElemType;

//结点结构,约定根结点的parent = -1
typedef struct PTNode
{
    TElemType data;
    int parent;
}PTNode;

//树结构
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];    //以一组连续的空间存储结点
    int r, n;   //根的位置和结点数
}PTree;