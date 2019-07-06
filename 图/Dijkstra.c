#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX];        // 用于存储最短路径下标
typedef int ShortPathTable[MAXVEX]; // 用于存储到各点最短路径的权值和

void ShartestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{
    int v, w, k, min;
    int final[MAXVEX];              // final[w] = 1代表已经求得v0到vw的最短路径
    // 初始化
    for(v = 0; v < G.numVertexes; v++)  
    {
        final[v] = 0;
        (*D)[v] = G.arc[v0][v];     // 将与v0点有连线的顶点加上权值
        (*P)[v] = 0;                // 初始化路径数组P为0
    }
    (*D)[v0] = 0;                   // v0至v0路径为0
    final[v0] = 1;                  // v0至v0不需要求路径
    // 每次求得v0到某个顶点v的最短路径
    for(v = 1; v < G.numVertexes; v++)
    {
        min = INFINITY;
        for(w = 0; w < G.numVertexes; w++)
        {
            if(!final[w] && (*D)[w] < min)
            {
                k = w;
                min = (*D)[w];
            }
        }
        final[k] = 1; // 将目前找到的最近的顶点置1
        // 修正当前最短路径及距离
        for(w = 0; w < G.numVertexes; w++)
        {
            if(!final[w] && (min + G.arc[k][w] < (*D)[w]))
            {
                // 说明找到了更短的路径，修改D[w]和P[w]
                (*D)[w] = min + G.arc[k][w];
                (*P)[w] = k;
            }
        }
    }

}