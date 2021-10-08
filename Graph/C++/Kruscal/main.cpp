#include <iostream>
#include "AdjacencyList.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
    AdjacencyList testGraph = AdjacencyList();
    // 输入顶点
    int vertex;
    char choice;
    do {
        cout << "Please input vertex:" << endl;
        cin >> vertex;
        testGraph.addVertex(vertex);
        cout << "Continue? (y/n)" << endl;
        cin >> choice;
    } while (choice != 'n');

    // 输入边以及对应的权重
    int source, target, cost;
    do {
        cout << "Please input the source vertex, target vertex,"
                " and the cost of the edge:" << endl;
        cin >> source >> target >> cost;
        testGraph.addArc(source, target, cost);
        cout << "Continue? (y/n)" << endl;
        cin >> choice;
    } while (choice != 'n');

    // 展示结果
    testGraph.showGraph();

    // 展示所有顶点
    cout << "Vertexes:" << endl;
    for (auto v : testGraph.getVertexes()) {
        cout << v << ' ';
    }
    cout << endl;

    // 展示所有边以及对应的权重
    cout << "Edges and corresponding costs:" << endl;
    for (auto e : testGraph.getCosts()) {
        cout << "(" << e.first.first << "," <<
            e.first.second << "):\t" << e.second << endl;
    }
    cout << endl;

    return 0;
}
