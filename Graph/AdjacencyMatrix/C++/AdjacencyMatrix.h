#include <vector>

using std::vector;
using std::pair;

// 邻接矩阵
class AdjacencyMatrix {
private:
    vector<int> vertexes;
    vector<pair<int, int>> edges;
public:
    
    int vertexNum;  // 顶点数量

    // 插入顶点
    void addVertex(int vertex);

    // 插入边
    void addArc(int source, int target);

    // 获取所有顶点
    vector<int> getVertexes();

    // 获取所有边
    vector<pair<int, int>> getEdges();

    // 构造邻接矩阵
    int **createMatrix();

    //  展示结果
    void showGraph();
};
