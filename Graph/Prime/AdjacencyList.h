#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include <vector>

// 链表结点
struct ListNode {
    int vertex;
    ListNode* next;
    ListNode();
};

// 数组结点
struct ArrayNode 
{
    int vertex;
    ListNode* head;
    ArrayNode();
};

// 邻接表
class AdjacencyList {
private:
    std::vector<int> vertexes;                  // 顶点集
    std::vector<std::pair<int, int>> edges;     // 边集
    std::vector<ArrayNode*> array;              // 邻接表数组

public:
    // 构造函数
    AdjacencyList() {};

    // 析构函数
    ~AdjacencyList();

    // 获取所有结点
    std::vector<int> getVertexes();

    // 获取所有边
    std::vector<std::pair<int, int>> getEdges();

    // 获取邻接表
    std::vector<ArrayNode*> getArray();

    // 插入顶点
    void addVertex(int v);

    // 插入边(u, v)
    void addEdge(int u, int v);

    // 输入邻接表的内容
    void showGraph();
};

#endif