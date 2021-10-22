#include <iostream>
#include "AdjacencyList.h"
#include "BFS.h"
using namespace std;

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

    // 输入边
    int source, target;
    do {
        cout << "Please input the source vertex and target vertex of the edge:" << endl;
        cin >> source >> target;
        testGraph.addArc(source, target);
        cout << "Continue? (y/n)" << endl;
        cin >> choice;
    } while (choice != 'n');

    // 展示结果
    testGraph.showGraph();

    // 获取所有顶点
    cout << "Vertexes:" << endl;
    for (auto v : testGraph.getVertexes()) {
        cout << v << ' ';
    }
    cout << endl;

    // 获取所有边
    cout << "Edges:" << endl;
    for (auto e : testGraph.getEdges()) {
        cout << "(" << e.first << "," << e.second << ")\t";
    }
    cout << endl;

    // BFS测试
    BFS bfs = BFS();
    bfs.traverse(testGraph);

    return 0;
}
