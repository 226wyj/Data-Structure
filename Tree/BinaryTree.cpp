#include <iostream>
using namespace std;

// 树结点
struct Node {
    int data;
    Node* lchild, *rchild;
};

// 二叉树
class BinaryTree {
private:
    Node* root;
public:
    BinaryTree() {
        root = nullptr;
    }

    BinaryTree(int data) {
        root->data = data;
        root->lchild = nullptr;
        root->rchild = nullptr;
    }

    // 前序遍历
    void preOrderTraverse(Node* node) {
        if (root == nullptr) {
            cout << "Empty Tree!" << endl;
            return;   
        }
        else {
            cout << root->data << " ";
            preOrderTraverse(root->lchild);
            preOrderTraverse(root->rchild);
        }
    }

    // 中序遍历
    void inOrderTraverse(Node* node) {
        if (root == nullptr) {
            cout << "Empty Tree!" << endl;
            return;
        }
        else {
            inOrderTraverse(root->lchild);
            cout << root->data << " ";
            inOrderTraverse(root->rchild);
        }
    }

    // 后序遍历
    void postOrderTraverse(Node* node) {
        if (root == nullptr) {
            cout << "Empty Tree!" << endl;
            return;
        }
        else {
            postOrderTraverse(root->lchild);
            postOrderTraverse(root->rchild);
            cout << root->data << " ";
        }
    }

    // 建立树

    //清空树
    void clear() {
        this->root = nullptr;
    }
}