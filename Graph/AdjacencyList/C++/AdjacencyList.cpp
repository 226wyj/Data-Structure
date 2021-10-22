#include <iostream>
#include <vector>
#include <climits>

#include "AdjacencyList.h"
using namespace std;


// 析构函数
AdjacencyList::~AdjacencyList() {
    for (auto i : array) {
        if (i->head) {
            ListNode* current = i->head;
            while (current) {
                ListNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
}

// 插入顶点
void AdjacencyList::addVertex(int v) {
    // 遍历顶点数组，若发现顶点重复插入，则报错
    for (auto i : array) {
        if (i->vertex == v) {
            throw "The vertex has already been inserted.";
        }
    }
    ArrayNode* newNode = new (ArrayNode);
    newNode->vertex = v;
    array.push_back(newNode);
    vertexes.push_back(v);
}

// 插入边(u, v)
void AdjacencyList::addArc(int u, int v) {
    // 遍历顶点数组，找到对应的起始顶点
    for (auto i : array) {
        if (i->vertex == u) {
            // 将v插入到以u为头结点的链表中
            ListNode* newNode = new (ListNode);
            newNode->vertex = v;

            // 若以u为头结点的链表为空，则直接插入
            if (!i->head) {
                i->head = newNode;
            }
            // 以u为头结点的链表非空，考虑到复杂度问题，采用头插法
            // 这样可以省去每一次的遍历链表的操作
            else {
                newNode->next = i->head;
                i->head = newNode;
            }
        }
    }
    edges.push_back(make_pair(u, v));
}

// 获取所有结点
vector<int> AdjacencyList::getVertexes() {
    return vertexes;
}

// 获取所有边
vector<pair<int, int>> AdjacencyList::getEdges() {
    return edges;
}

// 输出邻接表的内容
void AdjacencyList::showGraph() {
    for (auto i : array) {
        cout << i->vertex;
        if (i->head) {
            cout << "\t=>\t";
            ListNode* current = i->head;
            while (current) {
                cout << current->vertex;
                if (current->next)
                    cout << " -> ";
                current = current->next;
            }
        }
        cout << endl;
    }
}