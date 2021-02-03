//
// Created by wyj on 2021/2/3.
//

#include "AdjacencyList.h"
#include <algorithm>
#include <iostream>
using std::make_pair;
using std::cout;
using std::endl;

AdjacencyList::~AdjacencyList() {
    for (auto i : AdjacencyList::array) {
        if (i->head) {
            ListNode* current = i->head;
            while (current) {
                ListNode* tmp = current;
                current = current->next;
                delete tmp;
            }
        }
    }
}

void AdjacencyList::addVertex(int v) {
    // 遍历顶点数组，若发现顶点重复插入则报错
    vector<int>::iterator it;
    it = find(AdjacencyList::vertexes.begin(), AdjacencyList::vertexes.end(), v);
    if (it != AdjacencyList::vertexes.end()) {
        cout << "The vertex has already been inserted" << endl;
        return;
    }

    auto newNode = new (ArrayNode);
    newNode->vertex = v;
    array.push_back(newNode);
    AdjacencyList::vertexes.emplace_back(v);
}


void AdjacencyList::addArc(int u, int v) {
    // 遍历边数组，若发现边重复插入则报错
    vector<pair<int, int>>::iterator it;
    it = find(AdjacencyList::edges.begin(), AdjacencyList::edges.end(), make_pair(u, v));
    if (it != AdjacencyList::edges.end()) {
        cout << "The vertex has already been inserted" << endl;
        return;
    }

    // 遍历顶点数组，找到u对应的起始顶点
    for (auto i : AdjacencyList::array) {
        if (i->vertex == u) {
            // 将v插入到以u为头结点的链表中
            auto newNode = new(ListNode);
            newNode->vertex = v;

            if (!i->head) {
                i->head = newNode;
            }
            else {
                newNode->next = i->head;
                i->head = newNode;
            }
        }
    }
    AdjacencyList::edges.emplace_back(u, v);
}

vector<int> AdjacencyList::getVertexes() {
    return vertexes;
}

vector<pair<int, int>> AdjacencyList::getEdges() {
    return edges;
}

vector<ArrayNode *> AdjacencyList::getArray() {
    return array;
}

void AdjacencyList::showGraph() {
    for (auto i : AdjacencyList::array) {
        cout << i->vertex;
        if (i->head) {
            cout << "\t=>\t";
            auto current = i->head;
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

ArrayNode AdjacencyList::getLinkedList(int v) {
    for (auto i : array) {
        if (i->vertex == v) {
            return *i;
        }
    }
}