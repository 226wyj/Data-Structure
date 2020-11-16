#include "AdjacencyList.h"
#include <climits>
#include <iostream>
using std::vector;
using std::pair;
using std::cout;
using std::endl;
using std::make_pair;

// 链表结点构造函数
ListNode::ListNode() {
    vertex = INT_MAX;
    next = nullptr;
}

// 数组结点构造函数
ArrayNode::ArrayNode() {
    vertex = INT_MAX;
    head = nullptr;
}

/* 邻接表 */

// 获取邻接表数组
vector<ArrayNode*> AdjacencyList::getArray() {
    return this->array;
}

// 获取结点集
vector<int> AdjacencyList::getVertexes() {
    return this->vertexes;
}

// 获取边集
vector<pair<int, int>> AdjacencyList::getEdges() {
    return this->edges;
}

// 析构函数
AdjacencyList::~AdjacencyList() {
    for (auto i : this->getArray()) {
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

// 插入结点
void AdjacencyList::addVertex(int v) {
    // 遍历顶点数组，若发现顶点重复插入，则报错
    for (auto i : this->getArray()) {
        if (i->vertex == v) {
            throw "The vertex has already been inserted.";
        }
    }
    ArrayNode* newNode = new (ArrayNode);
    newNode->vertex = v;
    this->getArray().push_back(newNode);
    this->getVertexes().push_back(v);
}

// 插入边(u, v)
void AdjacencyList::addEdge(int u, int v) {
    // 遍历顶点数组，找到对应的起始顶点
    for (auto i : this->getArray()) {
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
    this->getEdges().push_back(make_pair(u, v));
}

// 输出邻接表内容
void AdjacencyList::showGraph() {
    for (auto i : this->getArray()) {
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