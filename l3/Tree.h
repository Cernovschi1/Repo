#pragma once
#include "Node.h"
#include <string>
class Tree {
    friend class Node;
private:
    //Node* root;

public:
    Node* root;
    Tree();
    void insert(int v, Node* tree);
    void deletee(int v, Node* tree);
    std::string inorder(Node* n);
    std::string preorder(Node* n);
    std::string postorder(Node* n);
    int countNodes(Node* n);
    int countEdges(Node* n);
    int height(Node* n);
};
