#include <iostream>
#include "Tree.h"
#include <assert.h>

int main() {
    Tree tree;
    tree.insert(5,tree.root);
    tree.insert(3,tree.root);
    tree.insert(7,tree.root);
    tree.insert(2, tree.root);
    tree.insert(11, tree.root);
    assert(tree.countNodes(tree.root) == 5);
    tree.deletee(3, tree.root);
    assert(tree.countNodes(tree.root) == 4);
    assert(tree.countEdges(tree.root) == 3);
    assert(tree.height(tree.root) == 3);
    std::cout << "Test End!";

    return 0;
}
