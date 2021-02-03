//
// Created by wyj on 2021/2/3.
//

#include "BFS.h"
#include <queue>
#include <iostream>
#include <algorithm>
using std::queue;
using std::cout;
using std::cin;
using std::endl;

void BFS::initVertex(vector<int> vertex) {
    for (auto v : vertex) {
        BFS::visited[v] = "unseen";
    }
}

void BFS::traverse(AdjacencyList graph) {
    // 借助队列完成BFS
    queue<int> bfsQueue;

    // 将所有结点都初始化为unseen
    vector<int> allVertex = graph.getVertexes();
    initVertex(allVertex);

    // 从start指示的顶点开始遍历
    cout << "Please input the start vertex of BFS:" << endl;
    int start;
    cin >> start;

//    auto it = find(graph.getVertexes().begin(), graph.getVertexes().end(), start);
//    if (it == graph.getVertexes().end()) {
//        cout << "The starter of BFS doesn't exist in the graph.";
//        exit(0);
//    }

    bfsQueue.push(start);
    visited[start] = "seen";
    while (!bfsQueue.empty()) {
        // 队头元素出队列并打印，开始访问其所有邻接点
        int u = bfsQueue.front();
        cout << u << '\t';
        bfsQueue.pop();

        ArrayNode adjLink = graph.getLinkedList(u);
        ListNode* curr = adjLink.head;
        while (curr != nullptr) {
            int vertex = curr->vertex;
            if (visited[vertex] == "unseen") {
                bfsQueue.push(vertex);
                visited[vertex] = "seen";
            }
            curr = curr->next;
        }
    }

//    for (int i = 0; i < graph.getArray().size(); i++) {
//
//        int currentVertex = graph.getArray()[i]->vertex;
//        if (visited[currentVertex] == "seen")
//            continue;
//
//        visited[currentVertex] = "seen";
//        bfsQueue.push(currentVertex);
//        // 队列不空
//        while (!bfsQueue.empty()) {
//            // 队头元素u出队列，开始访问其所有邻接点
//            int u = bfsQueue.front();
//            ArrayNode adjVertexes = graph.getLinkedList(u);
//            bfsQueue.pop();
//
//            auto curr = adjVertexes.head;
//            while (curr) {
//                if (visited[curr->vertex] == "unseen") {
//                    cout << curr->vertex << "\t";
//                    bfsQueue.push(curr->vertex);
//                    visited[curr->vertex] = "seen";
//                }
//                curr = curr->next;
//            }
//        }
//    }
}


