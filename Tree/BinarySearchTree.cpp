#include <iostream>
#include <climits>
using namespace std;

// 结点
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

 // 前序遍历
void preOrderTraverse(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrderTraverse(root->lchild);
        preOrderTraverse(root->rchild);
    }
}

// 中序遍历
void inOrderTraverse(Node* root) {
    if (root != nullptr) {
        inOrderTraverse(root->lchild);
        cout << root->data << " ";
        inOrderTraverse(root->rchild);
    }
}

// 后序遍历
void postOrderTraverse(Node* root) {
    if (root != nullptr) {
        postOrderTraverse(root->lchild);
        postOrderTraverse(root->rchild);
        cout << root->data << " ";
    }
}

// 插入结点
Node* insertData(Node* root, int data) {
    if (root == nullptr) {
        Node* newNode = new (Node);
        newNode->data = data;
        root = newNode;
    }
    else {
        if (root->data > data) {
            root->lchild = insertData(root->lchild, data);
        }
        else if (root->data < data) {
            root->rchild = insertData(root->rchild, data);
        }
    }
    return root;
}


int main() {
    // 测试数据
    int a[11] = {50, 30, 10, 0, 20, 40, 70, 90, 100, 60, 80};

    // 根节点
    Node* root = nullptr;

    for (int i = 0; i < 11; i++)
        root = insertData(root, a[i]);
    
    // 前序遍历
    cout << "Pre Order Traverse: " << endl;
    preOrderTraverse(root);
    cout << endl << endl;

    // 中序遍历
    cout << "In Order Traverse: " << endl;
    inOrderTraverse(root);
    cout << endl << endl;

    // 后序遍历
    cout << "Post Order Traverse: " << endl;
    postOrderTraverse(root);
    cout << endl << endl;

    return 0;
}