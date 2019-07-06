/*
 *基本思想：按权值的递增次序选择合适的边来构造MST。
 *初始化：Vt = V; E = 空
 *循环： 按G的边的权值递增顺序一次从E-Et中选择一条边，如果这条边加入T后不构成回路
 *       则将其加入Et, 否则舍弃，直到Et中含有n-1条边
 */

#define MAXEDGE 100 //最大边数
#define MAXVEX 10   //最大顶点数
#define INFINITY 65535  //无穷大

//边的结构
typedef struct _EdgeData
{
    int begin; //边的起点
    int end;   //边的终点
    int weight; //边的权重
}Edge;

Edge edges[MAXEDGE];    //边集数组

//查找连线顶点的尾部下标
int Find(int* parent, int f)
{
    while(parent[f] > 0)
        f = parent[f];
    return f;
}

//将邻接矩阵转换为边结构数组形式,该数组按照权值的大小从小到大排序
void TransformEdge(MGraph G)
{
    for(int i = 0; i < G.numVertexes; i++)
    {
        for(int j = i + 1; j < G.numVertexes; j++)
        {
            if(G.arc[i][j] != INFINITY)
            {
                edges[i].begin = i;
                edges[i].end = j;
                edges[i].weight = G.arc[i][j];
            }
        }
    }
    for(int i = 0; i < MAXEDGE; i++)
    {
        for(int j = i + 1; j < MAXEDGE; j++)
        {
            if(edges[i] > edges[j])
            {
                Edge e = edges[i];
                edges[i] = edges[j];
                edges[j] = e;
            }
        }
    }
}

void MiniSpanTree_Kruscal(MGraph G)
{
    TransformEdge(G);   //将邻接矩阵转换成有序边集数组
    int m, n, i;
    int parent[MAXVEX]; //该数组用于判断边与边是否形成环
    for(i = 0; i < G.numVertexes; i++)  //初始化为全0
        parent[i] = 0;
    for(i = 0; i < G.numEdges; i++)
    {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);
        if(n != m)
        {
            parent[n] = m;
            printf("(%d, %d) %d", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

int Find(int *parent, int f)
{
    while (parent[f] > 0)
    {
        f = parent[f];
    }
    return f;
}
