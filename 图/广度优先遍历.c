#include <queue>
#include <iostream>

//邻接矩阵的广度优先遍历
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for (i = 0; i < G.numVertexes; i++)
	{
		visited[i] = FALSE;
	}
	InitQueue(&Q);
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", G.vexs[i]);
			EnQueue(&Q, i);	//该节点入队列
			while(!QueueEmpty(Q))	//队列不空
			{
				DeQueue(&Q, &i);	//队头出队列
				for(j = 0; j < G.numVertexes; j++)
				{
					if(G.arc[i][j] == 1 && !visited[j])	//有任何与队头邻接的节点，则访问之并入队列
					{
						visited[j] = TRUE;
						printf("%c ", G.vexs[j]);
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}

//邻接表的广度优先遍历
void BFSTraverse(GraphAdjList GL)
{
	int i, j;
	EdgeNode *p;
	queue<int> Q;
	for(i = 0; i < GL.numVertexes; i++)
	{
		visited[i] = FALSE;
	}
	Q = queue<int> ();
	for(i = 0; i < GL.numVertexes; i++)
	{
		if(!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", GL.adjList[i].data);
			Q.push(i);
			while(!Q.empty())
			{
				j = Q.pop();
				p = GL.adjList[i].firstedge;	//找到当前顶点边表的头指针
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex] = TRUE;
						printf("%c ", GL.adjList[p->adjvex].data);
						Q.push(p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}
}