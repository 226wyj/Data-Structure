//
// Created by wyj on 2021/2/3.
//

#ifndef BFS_BFS_H
#define BFS_BFS_H

#include "AdjacencyList.h"
#include <map>
#include <string>
using std::map;
using std::string;

class BFS {
private:
    // 存储所有结点的访问状态
    map<int, string> visited;

    // 初始化所有的结点状态为unseen
    void initVertex(vector<int> vertex);

public:
    // BFS
    void traverse(AdjacencyList graph);
};

#endif //BFS_BFS_H
