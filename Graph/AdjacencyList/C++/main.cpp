#include <iostream>

#include "AdjacencyList.h"

using namespace std;

int main() {
    AdjacencyList demo = AdjacencyList();

    // 输入顶点
    int vertex;
    char choice;
    do {
        cout << "Please input vertex:" << endl;
        cin >> vertex;
        demo.addVertex(vertex);
        cout << "Continue? (y/n)" << endl;
        cin >> choice;
    } while (choice != 'n');

    // 输入边
    int source, target;
    do {
        cout << "Please input the source vertex and target vertex of the edge:" << endl;
        cin >> source >> target;
        demo.addArc(source, target);
        cout << "Continue? (y/n)" << endl;
        cin >> choice;
    } while (choice != 'n');

    // 展示结果
    cout << endl;
    demo.showGraph();

    // 获取所有顶点
    cout << "Vertexes:" << endl;
    for (auto v : demo.getVertexes()) {
        cout << v << ' ';
    }
    cout << endl;

    // 获取所有边
    cout << "Edges:" << endl;
    for (auto e : demo.getEdges()) {
        cout << "(" << e.first << "," << e.second << ")\t";
    }
    cout << endl;

    return 0;
}