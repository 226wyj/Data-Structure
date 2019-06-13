#define MAXVEX 100	//最大顶点数量
typedef char VertexType;    //顶点类型
typedef int EdgeType;   //边上的权值类型

///有向邻接表
typedef struct EdgeNode //边表结点
{
    int adjvex; //邻接点域，存储该顶点对应的下标
    EdgeType weight;    //存储权值
    struct EdgeNode* next;  //链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode   //顶点表结点
{
    VertexType data;    //顶点域
    EdgeNode* firstedge;    //边表头指针
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;	//图中当前顶点数和边数
}GraphAdList;

///无向邻接表的创建
void CreateAlGraph(GraphAdList *G)
{
	int i, j, k;
	EdgeNode* e;
	printf("输入顶点数和边数: ");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	for (i = 0; i < G->numVertexes; i++)	//读入顶点信息，建立顶点表
	{
		scanf(&G->adjList[i].data);		//输入顶点信息
		G->adjList[i].firstedge = NULL;	//将边表置空
	}
	for (k = 0; k < G->numEdges; k++)	//建立边表
	{
		print("输入边(vi, vj)上的顶点序号: \n");
		scanf("%d,%d", &i, &j);
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;	//邻接序号为j
		e->next = G->adjList[i].firstedge;	//无向图，相互指
		G->adjList[i].firstedge = e;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = i;	//邻接序号为i
		e->next = G->adjList[j].firstedge;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}