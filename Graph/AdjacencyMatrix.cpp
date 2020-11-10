#include <iostream>
#include <vector>
using namespace std;

// 邻接矩阵
class AdjacencyMatrix {
private:
    vector<int> vertexes;
    vector<pair<int, int>> edges;
public:

    // 插入顶点
    void addVertex(int vertex) {
        vertexes.push_back(vertex); 
    }

    // 插入边
    void addArc(int source, int target) {
        edges.push_back(make_pair(source, target));
    }

    // 构造邻接矩阵
    pair<int**, int> createMatrix() {
        int length = vertexes.size();
        int matrix[length][length];
        for (auto i : edges) {
            int index1 = find(vertexes.begin(), vertexes.end(), i.first);
            int index2 = find(vertexes.begin(), vertexes.end(), i.second);
            matrix[index1][index2] = 1;
        }
        auto result = make_pair(matrix, length);
        return result;      
    }

    //  展示结果
    void showGraph() {
        int** matrix = createMatrix().first;
        int length = createMatrix().second;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                cout << matrix[i][j];
            }
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