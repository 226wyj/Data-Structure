#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 邻接矩阵
class AdjacencyMatrix {
private:
    vector<int> vertexes;
    vector<pair<int, int>> edges;
public:
    
    int vertexNum;  // 顶点数量

    // 插入顶点
    void addVertex(int vertex) {
        // 插入新的顶点之前首先要检查是否重复插入
        for (auto v : vertexes) {
            if (v == vertex)
                throw "The vertex has already been inserted.";
        }
        vertexes.push_back(vertex); 
        // 插入顶点之后更新顶点数量
        vertexNum = vertexes.size();
    }

    // 插入边
    void addArc(int source, int target) {
        // 插入新的边之前首先要检查是否重复插入
        pair<int, int> newEdge = make_pair(source, target);
        for (auto e : edges) {
            if (e == newEdge)
                throw "The vertex has already been inserted.";
        }
        edges.push_back(newEdge);
    }

    // 获取所有顶点
    vector<int> getVertexes() {
        return vertexes;
    }

    // 获取所有边
    vector<pair<int, int>> getEdges() {
        return edges;
    }

    // 构造邻接矩阵
    int **createMatrix() {
        // 初始化矩阵
        int **matrix = new int*[vertexNum]();
        // 根据边的关系填充矩阵
        for (int i = 0; i < vertexNum; i++) {
            matrix[i] = new int[vertexNum]();
        }
        for (auto e : edges) {
            vector<int>::iterator iter1 = find(vertexes.begin(), vertexes.end(), e.first);
            vector<int>::iterator iter2 = find(vertexes.begin(), vertexes.end(), e.second);
            int index1 = distance(vertexes.begin(), iter1);
            int index2 = distance(vertexes.begin(), iter2);
            matrix[index1][index2] = 1;
        }
        return matrix;
    }

    //  展示结果
    void showGraph() {
        auto matrix = createMatrix();
        for (int i = 0; i < vertexNum; i++) {
            for (int j = 0; j < vertexNum; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    AdjacencyMatrix demo = AdjacencyMatrix();

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
    demo.showGraph();

    return 0;
}