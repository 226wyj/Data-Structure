/*
 *普里姆算法的思想是：设图G的顶点集合为U, 首先任选U中的一个顶点为起始顶点a, 将该顶点加入集合V，
 *再从集合U-V中找到另一顶点b,使得b到V中的任一点的权值最小，然后将b加入V中。以此类推，直到U中所有顶点
 *被选中。
*/

#define MAXVEX 100
#define IFINITY 65535
void MiniSpanTree_Prim(MGraph G)
{
    int min, i, j, k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];
    lowcost[0] = 0; //lowcost[j]表示从所选顶点开始到以j为终点的边的最小权值
    adjvex[0] = 0;  //adjvex[j]表示第j条边的起始点
    for(i = 1; i < G.numVertexes; i++)  //初始化，由于取的是v0点为第一个点，则用邻接矩阵的第1行进行初始化
    {
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }
    //初始化结束，正式开始算法部分
    for(i = 1; i < G.numVertexes; i++)
    {
        min = IFINITY;
        j = 1;  //j用来迭代
        k = 0;  //k用来存储最小权值的顶点下表
        while(j < G.numVertexes)
        {
            if(lowcost[j]!=0 && lowcost[j]<min) //该节点未被访问过且权值小于当前最小值, 更新
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d, %d)", adjvex[k], k);
        lowcost[k] = 0; //k为当前所访问的节点
        for(j = 1; j < G.numVertexes; j++)  //重新进行初始化
        {
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}