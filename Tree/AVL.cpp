#include <iostream>
#include <cmath>
using namespace std;

// 结点定义
struct Node {
    int key;        // 关键字（键值，用来排序的）
    int height;     // 高度
    Node* lchild;   // 左孩子
    Node* rchild;   // 右孩子

    Node() {
        key = INT_MAX;
        height = 0;
        lchild = nullptr;
        rchild = nullptr;
    }
};

class AVLTree {
private:
    Node* root;
    int size;

    // 获取某一结点的高度，当结点为空时默认其高度为-1
    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        else {
            return node->height;
        }
    }

    // 获取节点的平衡因子
    int getBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        else {
            return (getHeight(node->lchild) - getHeight(node->rchild));
        }
    }

    // 判断树是否平衡
    bool isBalanced(Node* node) {
        if (node == nullptr) {
            return true;
        }
        else {
            int balanceFactory = abs(getBalanceFactor(node));
            if (balanceFactory > 1) {
                return false;
            }
            else {
                return (isBalanced(node->lchild) && isBalanced(node->rchild));
            }
        }
    }

    // LL情况，右旋
    Node* rightRotate(Node* y) {
        Node* x = y->lchild;    // 将x调整为根结点
        Node* temp = x->rchild;
        x->rchild = y;  
        y->lchild = temp;
        
        // 更新height
        y->height = max(getHeight(y->lchild), getHeight(y->rchild)) + 1;
        x->height = max(getHeight(x->lchild), getHeight(x->rchild)) + 1;

        return x;
    }

    // RR情况，左旋
    Node* leftRotate(Node* y) {
        Node* x = y->rchild;
        Node* temp = x->lchild;
        x->lchild = y;
        y->rchild = temp;

        // 更新height
        y->height = max(getHeight(y->lchild), getHeight(y->rchild)) + 1;
        x->height = max(getHeight(x->lchild), getHeight(x->rchild)) + 1;

        return x;
    }

    // LR情况, 先对y的左孩子左旋变成LL情况，再对y右旋
    Node* LR(Node* y) {
        y->lchild = leftRotate(y->lchild);
        return rightRotate(y);
    }

    // RL情况，先对y的右孩子右旋变成RR情况，再对y左旋
    Node* RL(Node* y) {
        y->rchild = rightRotate(y->rchild);
        return leftRotate(y);
    }

public:
    AVLTree() {
        root = nullptr;
        size = 0;
    }

    // 获取树中结点的数量
    int getSize() {
        return size;
    }

    // 判断树是否为空
    bool isEmpty() {
        return (size == 0);
    }

    // 判断是否为平衡二叉树
    bool isBalanced() {
        return isBalanced(root);
    }

    // 插入结点，返回插入新节点之后AVL的树根
    Node* insertNode(Node* node, int key) {
        Node* newNode = new(Node);
        newNode->key = key;
        if (node == nullptr) {
            node = newNode;
            return node;
        }
        else {
            if (key < node->key) {
                root->lchild = insertNode(node->lchild, key);
            }
            else if (key > node->key) {
                node->rchild = insertNode(node->rchild, key);
            }
            // 更新height
            node.height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
            
            // 计算平衡因子
            int balanceFactor = getBalanceFactor(node);
            // LL 右旋
            if (balanceFactor > 1 && getBalanceFactor(node->lchild) > 0) 
                return rightRotate(node);
            // RR 左旋
            if (balanceFactor < -1 && getBalanceFactor(node->rchild) < 0)
                return leftRotate(node);
            // LR
            if (balanceFactor > 1 && getBalanceFactor(node->lchild) < 0)
                return LR(node);
            // RL
            if (balanceFactor < -1 && getBalanceFactor(node->rchild) > 0)
                return RL(node);
        }
        return node;
    }

    // 删除结点
    

};
