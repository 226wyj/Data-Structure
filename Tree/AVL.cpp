#include <iostream>
using namespace std;

// 结点定义
struct Node {
    int data;
    Node* lchild;
    Node* rchild;

    Node() {
        data = INT_MAX;
        lchild = nullptr;
        rchild = nullptr;
    }
};