#include <iostream>
#include <vector>
#include <algorithm>

#include "AdjacencyMatrix.h"

using std::make_pair;
using std::cout;
using std::endl;


// 插入顶点
void AdjacencyMatrix::addVertex(int vertex) {
    // 插入新的顶点之前首先要检查是否重复插入
    for (auto v : vertexes) {
        if (v == vertex)
            throw "The vertex has already been inserted.";
    }
    vertexes.push_back(vertex); 
    // 插入顶点之后更新顶点数量
    vertexNum = vertexes.size();
}

// 插入边
void AdjacencyMatrix::addArc(int source, int target) {
    // 插入新的边之前首先要检查是否重复插入
    pair<int, int> newEdge = make_pair(source, target);
    for (auto e : edges) {
        if (e == newEdge)
            throw "The vertex has already been inserted.";
    }
    edges.push_back(newEdge);
}

// 获取所有顶点
vector<int> AdjacencyMatrix::getVertexes() {
    return vertexes;
}

// 获取所有边
vector<pair<int, int>> AdjacencyMatrix::getEdges() {
    return edges;
}

// 构造邻接矩阵
int** AdjacencyMatrix::createMatrix() {
    // 初始化矩阵
    int **matrix = new int*[vertexNum]();
    // 根据边的关系填充矩阵
    for (int i = 0; i < vertexNum; i++) {
        matrix[i] = new int[vertexNum]();
    }
    for (auto e : edges) {
        vector<int>::iterator iter1 = find(vertexes.begin(), vertexes.end(), e.first);
        vector<int>::iterator iter2 = find(vertexes.begin(), vertexes.end(), e.second);
        int index1 = distance(vertexes.begin(), iter1);
        int index2 = distance(vertexes.begin(), iter2);
        matrix[index1][index2] = 1;
    }
    return matrix;
}

//  展示结果
void AdjacencyMatrix::showGraph() {
    auto matrix = createMatrix();
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}