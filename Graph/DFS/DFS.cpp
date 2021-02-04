//
// Created by wyj on 2021/2/3.
//

#include "DFS.h"
#include <stack>
#include <iostream>
#include <algorithm>
using std::stack;
using std::cout;
using std::cin;
using std::endl;

void DFS::initVertex(vector<int> vertex) {
    for (auto v : vertex) {
        DFS::visited[v] = "unseen";
    }
}

void DFS::traverse(AdjacencyList graph) {
    // 借助栈完成DFS
    stack<int> dfsStack;

    // 将所有结点都初始化为unseen
    vector<int> allVertex = graph.getVertexes();
    initVertex(allVertex);

    // 从start指示的顶点开始遍历
    cout << "Please input the start vertex of BFS:" << endl;
    int start;
    cin >> start;

    auto it = find(allVertex.begin(), allVertex.end(), start);
//    cout << "*********" << endl << *it << "***********" << endl;
    if (it == graph.getVertexes().end()) {
        cout << "The starter of BFS doesn't exist in the graph.";
        exit(0);
    }

    dfsStack.push(start);
    visited[start] = "seen";
    while (!dfsStack.empty()) {
        // 队头元素出队列并打印，开始访问其所有邻接点
        int u = dfsStack.top();
        cout << u << '\t';
        dfsStack.pop();

        // 通过邻接表获取u的所有邻接点，依次访问
        ArrayNode adjLink = graph.getLinkedList(u);
        ListNode* curr = adjLink.head;
        while (curr != nullptr) {
            int vertex = curr->vertex;
            if (visited[vertex] == "unseen") {
                dfsStack.push(vertex);
                visited[vertex] = "seen";
            }
            curr = curr->next;
        }
    }
}