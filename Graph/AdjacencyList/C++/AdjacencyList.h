#include <climits>
#include <vector>

using std::vector;
using std::pair;

// 链表结点
struct ListNode {
    int vertex;
    ListNode* next;

    ListNode() {
        vertex = INT_MAX;
        next = nullptr;
    }
};

// 数组结点
struct ArrayNode {
    int vertex;
    ListNode* head;
    
    ArrayNode() {
        vertex = INT_MAX;
        head = nullptr;
    }
};

// 邻接表
class AdjacencyList {
private:
    vector<ArrayNode*> array;       // 邻接表数组
    vector<int> vertexes;           // 顶点集
    vector<pair<int, int>> edges;   // 边集
public:

    // 析构函数
    ~AdjacencyList();

    // 插入顶点
    void addVertex(int v);

    // 插入边(u, v)
    void addArc(int u, int v);

    // 获取所有结点
    vector<int> getVertexes();

    // 获取所有边
    vector<pair<int, int>> getEdges();

    // 输出邻接表的内容
    void showGraph();
};
