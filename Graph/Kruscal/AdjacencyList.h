//
// Created by wyj on 2021/2/3.
//

#ifndef BFS_ADJACENCYLIST_H
#define BFS_ADJACENCYLIST_H

#include <vector>
#include <climits>
#include <map>
using std::vector;
using std::pair;
using std::map;

// 链表结点
struct ListNode {
    int vertex;
    ListNode* next;

    ListNode() {
        vertex = INT_MAX;
        next = nullptr;
    }
};

// 数组结点
struct ArrayNode {
    int vertex;
    ListNode* head;

    ArrayNode() {
        vertex = INT_MAX;
        head = nullptr;
    }
};

// 邻接表
class AdjacencyList {
private:
     vector<ArrayNode*> array;              // 邻接表数组
     vector<int> vertexes;                  // 顶点集
     vector<pair<int, int>> edges;          // 边集
     map<pair<int, int>, int> costs;        // 每条边对应的权重

public:
    // 析构函数
    ~AdjacencyList();

    // 插入顶点
    void addVertex(int v);

    // 插入边(u, v)，无权重
    void addArc(int u, int v);

    // 插入边(u, v)，有权重
    void addArc(int u, int v, int cost);

    // 获取所有顶点
    vector<int> getVertexes();

    // 获取所有边
    vector<pair<int, int>> getEdges();

    // 获取邻接表数组
    vector<ArrayNode*> getArray();

    // 获取权重表
    map<pair<int, int>, int> getCosts();

    // 输出邻接表内容
    void showGraph();

    // 通过顶点值获取其所在的链表
    ArrayNode getLinkedList(int v);
};

#endif //BFS_ADJACENCYLIST_H
