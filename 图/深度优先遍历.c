#define MAX 100 //最大顶点数
bool visited[MAX];

//邻接矩阵的深度优先递归算法
void DFS(MGraph G, int i)   //G为目标邻接矩阵，i为当前顶点
{
    int j;
    visited[i] = TRUE;
    printf("%c ", G.vexs[i]);   //默认操作为输出该顶点的值,可以根据需要改变
    for(j = 0; j < G.numVertexes; j++)
    {
        if(G.arc[i][j] == 1 && !visited[j]) //i, j连通且j未被访问
        {
            DFS(G, j);
        }
    }
}

//邻接矩阵的深度遍历操作
void DFSTraverse(MGraph G)
{
    int i;
    for(i = 0; i < G.numVertexes; i++)
    {
        visited[i] = FALSE; //初始化所有节点都是未访问状态
    }
    for(i = 0; i < G.numVertexes; i++)
    {
        if(!visited[i])
            DFS(G, i);
    }
}

//邻接表的深度优先递归算法
void DFS(GraphAdjList GL, int i)
{
    EdgeNode* p;
    visited[i] = TRUE;
    printf("%c ", GL->adjList[i].data);
    p = GL->adjList[i].fitstedge;
    while(p)
    {
        if(!visited[p->adjvex])
            DFS(GL, p->adjvex); //对未访问的邻接顶点递归调用
        p = p->next;    
    }
}

//邻接表的深度遍历操作
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for(i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE;
    for(i = 0; i < GL->numVertexes; i++)
        if(!visited[i])
            DFS(GL, i);
}