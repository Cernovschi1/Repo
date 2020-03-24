#include <iostream>
#include "Tree.h"
#include <queue>
#include "Node.h"

Tree::Tree() {
    root = nullptr;
}
void Tree::insert(int v, Node* tree) {
    if (root == nullptr) {
        //Daca arborele este gol ,nodul ce trebuie inserat va deveni radacina
        root = new Node(v);
    }
    else {
        Node *nodcurent = root;
        //pornim parcurgerea de la radacina 
        while (nodcurent) {
            if (nodcurent->elem >= v) {
                //daca indeplineste conditia parcurgem arborele in stanga
                if (nodcurent->l == nullptr) {
                    //am gasit pozitia unde trebuie inserata valoarea
                    nodcurent->l = new Node(v);
                    break;
                }
                nodcurent = nodcurent->l;
            }
            else if (nodcurent->elem <= v) {
                //daca indeplineste conditia parcurgem arborele in dreapta
                if (nodcurent->r == nullptr) {
                    //am gasit pozitia unde trebuie inserata valoarea
                    nodcurent->r = new Node(v);
                    break;
                }
                nodcurent = nodcurent->r;
            }
        }
    }
}
void Tree::deletee(int v, Node* tree) {
    Node *tmp, *tmp1, *tmp2,*aux;
    tmp1 = root;
    
    //Se porneste cautarea elem de sters din radacina
    while (tmp1->elem != v)
    {
        if (tmp1->elem > v)
            tmp1 = tmp1->l;
        else
            tmp1 = tmp1->r;
    }

    tmp = tmp1;
    if(tmp1->l==nullptr and tmp1->r==nullptr)
    {
        delete tmp1;
        tmp1 = nullptr;
        
        
    }//in caz de nod terminal 
    else {
        if (tmp->r == nullptr)
        {
            //mutare elem din nodul din stanga,in nodul curent

            tmp1->elem = tmp1->l->elem;
            //refacere legaturi
            tmp1->l = tmp1->l->l;
            delete tmp1->l;

        }
        else
            //nu avem fiu in stanga
            if (tmp1->l == nullptr)
            { //mutare elem din nodul din l,in nodul curent
                tmp1->elem = tmp1->r->elem;
                tmp1->r = tmp1->r->r;
                delete tmp1->r;
            }
            else {
                //mergem la fiul din dreapta
                tmp = tmp1->r;
                tmp2 = tmp1;
                //cautam cel mai din stanga copil
                while (tmp->l != nullptr)
                {
                    tmp2 = tmp;
                    tmp = tmp->l;

                }
                tmp1->elem = tmp->elem;
                tmp2->l = nullptr;
                delete tmp;


            }
    }

}
std::string Tree::inorder(Node* n) {
    if (n == nullptr)
        return "";
    return inorder(n->l) + std::to_string(n->elem) + " " + inorder(n->r);
}
std::string Tree::preorder(Node* n) {
    if (n == nullptr)
        return "";
    return std::to_string(n->elem) + " " + preorder(n->l) + preorder(n->r);
}
std::string Tree::postorder(Node* n) {

    if (n == nullptr)
        return "";
    return postorder(n->l) + postorder(n->r) + std::to_string(n->elem) + " ";
}
int Tree::countNodes(Node* n) {
    if (n == nullptr)
        return 0;
    else
        return 1 + countNodes(n->l) + countNodes(n->r);
}

int Tree::countEdges(Node* n) {
    return countNodes(n) - 1;
}

int Tree::height(Node* n) {
    int l = 0;
    int r = 0;

    if (n == nullptr)
    {
        return 0;
    }
    {
        l = height(n->l);
        r = height(n->r);
        if (l > r || l == r)
        {
            return (l + 1);
        }
        else
        {
            return (r + 1);
        }
    }
}
