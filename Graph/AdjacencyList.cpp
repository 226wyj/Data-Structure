#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 数组结点
struct ArrayNode {
    int vertex;
    ListNode* next;
    
    ArrayNode() {
        vertex = INT_MAX;
        next = nullptr;
    }
};

// 链表结点
struct ListNode {
    int vertex;
    ListNode* next;

    ListNode() {
        vertex = INT_MAX;
        next = nullptr;
    }
};

// 邻接表
class AdjacencyList {
private:
    vector<ArrayNode*> array;

public:

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
                if (!i->next) {
                    i->next = newNode;
                }
                // 以u为头结点的链表非空，考虑到复杂度问题，采用头插法
                // 这样可以省去每一次的遍历链表的操作
                else {
                    newNode->next = i->next;
                    i->next = newNode;
                }
            }
        }
    }

    // 输出邻接表的内容
    void showGraph() {
        for (auto i : array) {
            cout << i->vertex;
            if (i->next) {
                cout << "\t=>\t";
                ListNode* current = i->next;
                while (current) {
                    cout << current->vertex << " => ";
                }
                cout << endl;
            }
        }
    }
};


int main() {
    AdjacencyList demo = AdjacencyList();

    // 输入顶点，当值为10086时候结束
    int vertex;
    while ((cin >> vertex) != 10086) {
        demo.addVertex(vertex);
    }

    // 输入边
    int source, target;
    
    
    return 0;
}