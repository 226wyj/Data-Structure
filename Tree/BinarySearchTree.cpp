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

// 获取树中的最大值结点
Node* getMax(Node* root) {
    if (root == nullptr) {
        cout << "Empty Tree!" << endl;
        exit(0);
    }
    else {
        Node* parent = nullptr;
        while (root) {
            parent = root;
            root = root->rchild;
        }
        return parent;
    }
}

// 获取树中的最小值结点
Node* getMin(Node* root) {
    if (root == nullptr) {
        cout << "Empty Tree!" << endl;
        exit(0);
    }
    else {
        Node* parent = nullptr;
        while (root) {
            parent = root;
            root = root->lchild;
        }
        return parent;
    }
}

// 删除某一个结点
Node* deleteNode(Node* root, int data) {
    if (root == nullptr) {
        cout << "Empty Tree!" << endl;
        exit(0);
    }
    // 当前结点的值小于待删除的结点值，则进入左子树查找
    else if (data < root->data) {
        root->lchild = deleteNode(root->lchild, data);
    }
    // 当前结点的值大于待删除的结点值，则进入右子树查找
    else if (data > root->data) {
        root->rchild = deleteNode(root->rchild, data);
    }
    // 找到要删除的结点
    else {
        // 该结点既有左子树又有右子树
        if (root->lchild && root->rchild) {
            // 找到右子树中的最小值填充删除结点，也可以找左子树的最大值
            Node* temp = getMin(root->rchild);
            root->data = temp->data;
            // 在右子树中删除最小元素
            root->rchild = deleteNode(root->rchild, temp->data);
        }
        // 该结点有1个或0个子结点
        else {
            Node* temp = root;
            // 只有右孩子或无子结点
            if (!root->lchild) {
                root = root->rchild;
            }
            // 只有左孩子或无子结点
            else if (!root->rchild) {
                root = root->lchild;
            }
            delete temp;
        }
    }
    return root;
}

int main() {
    // 测试数据
    int a[11] = { 50, 30, 10, 0, 20, 40, 70, 90, 100, 60, 80 };

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

    // 最大值
    cout << "Max number:" << endl;
    cout << getMax(root)->data << endl << endl;

    // 最小值
    cout << "Min number:" << endl;
    cout << getMin(root)->data << endl << endl;
    
    // 删除70，则根据我们的规则，前序遍历的结果应该为
    // 50 30 10 0 20 40 80 60 90 100
    cout << "Delete 70: " << endl;
    root = deleteNode(root, 70);
    preOrderTraverse(root);
    cout << endl << endl;

    return 0;
}