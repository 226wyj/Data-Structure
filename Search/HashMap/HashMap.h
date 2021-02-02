//
// Created by wyj on 2020/11/25.
//

#ifndef HASHMAP_HASHMAP_H
#define HASHMAP_HASHMAP_H

#include "LinkedList.h"

class HashMap {
private:
    int mapSize;
    LinkedList *array;

public:
    HashMap();
    HashMap(int size);

    int getMapSize();
    LinkedList * getArray();
};

#endif //HASHMAP_HASHMAP_H
