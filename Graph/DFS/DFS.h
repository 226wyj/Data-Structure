//
// Created by wyj on 2021/2/3.
//

#ifndef DFS_DFS_H
#define DFS_DFS_H

#include "AdjacencyList.h"
#include <map>
#include <string>
using std::map;
using std::string;

class DFS {
private:
    // 存储所有结点的访问状态
    map<int, string> visited;

    // 初始化所有的结点状态为unseen
    void initVertex(vector<int> vertex);

public:
    // DFS
    void traverse(AdjacencyList graph);
};

#endif //DFS_DFS_H
