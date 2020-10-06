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

// 二叉树
class BinaryTree {
private:

    // -----------
    // Attributes
    // -----------
    
    Node* root; 
    int size;   

    // 前序遍历
    void preOrderTraverse(Node* node) {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrderTraverse(root->lchild);
            preOrderTraverse(root->rchild);
        }
    }

    // 中序遍历
    void inOrderTraverse(Node* node) {
        if (root != nullptr) {
            inOrderTraverse(root->lchild);
            cout << root->data << " ";
            inOrderTraverse(root->rchild);
        }
    }

    // 后序遍历
    void postOrderTraverse(Node* node) {
        if (root != nullptr) {
            postOrderTraverse(root->lchild);
            postOrderTraverse(root->rchild);
            cout << root->data << " ";
        }
    }

    // 插入结点
    Node* insertData(Node* node, int data) {
        // 根节点为空，则说明树不存在，先建立根节点
        if (root == nullptr) {
            root->data = data;
            setSize(getSize() + 1);
        }
        else {
            Node* newNode = new (Node);
            newNode->data = data;
            if (data < root->data) {
                root->lchild = insertData(root->lchild, data);
            }
            else if (data > root->data) {
                root->rchild = insertData(root->rchild, data);
            }
            setSize(getSize() + 1);
        }    
        return root;
    }

public:
    BinaryTree() {
        root = nullptr;
        size = 0;
    }

    ~BinaryTree() {}

    Node* getRoot() {
        return root;
    }

    int getSize() {
        return size;
    }

    void setSize(int size) {
        this->size = size;
    }

    // 前序遍历API
    void preOrder() {
        this->preOrderTraverse(this->getRoot());
    }

    // 中序遍历API
    void inOrder() {
        this->inOrderTraverse(this->getRoot());
    }

    // 后序遍历API
    void postOrder() {
        this->postOrderTraverse(this->getRoot());
    }

    // 插入结点API
    void insert(int data) {
        this->insertData(this->getRoot(), data);
    }

};

int main() {
    BinaryTree myTree = BinaryTree();
    int a[11] = {50, 30, 10, 0, 20, 40, 70, 90, 100, 60, 80};
    for (int i = 0; i < 11; i++) {
        myTree.insert(a[i]);
    } 
    cout << "前序遍历" << endl;
    myTree.preOrder();
    return 0;
}