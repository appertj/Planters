/*****************************************************************************
# Author:           Josiah Appert
# File:             boxtree.h
# Assignment:       Programming Project #4: Planters
# Date:             12/10/2023
# Description:      This file declares the private data members and private 
#                   and public methods of the BoxTree class
#****************************************************************************/
#ifndef BOXTREE_H
#define BOXTREE_H
#include "box.h"
#include "boxlist.h"

class BoxTree {
public:
    BoxTree();
    ~BoxTree();
    void insert(const Box&);
    void remove(int);
    BoxList getRange(const int,const int);
private:
    struct Node {
        Box data;
        Node* leftChildPtr;
        Node* rightChildPtr;
        Node(const Box &aBox): data(aBox), leftChildPtr(NULL), rightChildPtr(NULL) {}
        ~Node() {
            delete leftChildPtr;
            delete rightChildPtr;
        }
    };
    Node* root;
    void destroyTree(Node*&);
    void remove(Node*&, int);
    void deleteNode(Node*&);
    BoxList getRange(const int,const int,Node*);
};

#endif