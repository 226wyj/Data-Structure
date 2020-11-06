#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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
    vector<ArrayNode*> array;

public:

    // 析构函数
    ~AdjacencyList() {
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
    void addVertex(int v) {
        // 遍历顶点数组，若发现顶点重复插入，则报错
        for (auto i : array) {
            if (i->vertex == v) {
                throw "The vertex has already been inserted.";
            }
        }
        ArrayNode* newNode = new (ArrayNode);
        newNode->vertex = v;
        array.push_back(newNode);
    }

    // 插入边(u, v)
    void addArc(int u, int v) {
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
    }

    // 获取所有结点
    vector<int> getAllVertex() {
        vector<int> vertexes;
        for (auto i : array) {
            vertexes.push_back(i->vertex);
        }
        return vertexes;
    }

    // 获取所有边
    vector<pair<int, int>> getAllEdge() {
        vector<pair<int, int>> edges;
        for (auto i : array) {
            ListNode* current = i->head;
            int source, target;
            while (current) {
                source = i->vertex;
                target = current->vertex;
                edges.push_back(make_pair(source, target));
                current = current->next;
            }
        }
        return edges;
    }

    // 输出邻接表的内容
    void showGraph() {
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
};

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
    demo.showGraph();

    // 获取所有顶点
    cout << "Vertexes:" << endl;
    for (auto v : demo.getAllVertex()) {
        cout << v << ' ';
    }
    cout << endl;

    // 获取所有边
    cout << "Edges:" << endl;
    for (auto e : demo.getAllEdge()) {
        cout << "(" << e.first << "," << e.second << ")\t";
    }
    cout << endl;

    return 0;
}