#define MAXVEX 9
typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];
// Floyd算法，求网图G中各顶点v到其余顶点w最短路径P[v][w]及带权长度D[v][w]
void ShortestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable *D)
{
    // v为起点，w为终点，k为中转顶点
    int v, w, k;
    // 初始化
    for(v = 0; v < G.numVertexes; v++)
    {
        for(w = 0; w < G.numVertexes; w++)
        {
            (*D)[v][w] = G.matrix[v][w];
            (*P)[v][w] = w;
        }
    }
    // 算法
    for(k = 0; k < G.numVertexes; ++k)
    {
        for(v = 0; v < G.numVertexes; ++v)
        {
            for(w = 0; w < G.numVertexes; ++w)
            {
                if((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
                {
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    (*P)[v][w] = (*P)[v][k];
                }
            }
        }
    }
}