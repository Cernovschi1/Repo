#pragma once
#include "Tree.h"
class Node {
    friend class Tree;
private:
    int elem;
    Node *l, *r;
public:
    Node(int e);//constructor


};