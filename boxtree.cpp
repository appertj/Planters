/*****************************************************************************
# Author:           Josiah Appert
# File:             boxtree.cpp
# Assignment:       Programming Project #4: Planters
# Date:             12/10/2023
# Description:      This file contains functions used to perform operations on
#                   objects of the BoxTree class including a default constructor, 
#                   destructor, and functions to build, manipulate, and 
#                   display data.
# Input:            Node*& root, const Box& aBox, int boxIn, Node*& target,
# Output:           BoxList getRange(start, stop, root), BoxList boxList
# Sources:          Data Abstraction & Problem Solving chs 1-20, Project 4 
#                   Specs
#****************************************************************************/
#include "boxtree.h"

// Name:	  BoxTree()
// Desc:	  Default constructor for BoxTree class
// input:   none
// output:	none
// return:	none
BoxTree::BoxTree(): root(NULL) {}

// Name:	  ~BoxTree()
// Desc:	  Destructor for BoxTree class
// input:   none
// output:  none
// return:	none
BoxTree::~BoxTree() {
    destroyTree(root);
}

// Name:	  destroyTree()
// Desc:	  Recursive helper function for destructor
// input:   Node*& root
// output:  none
// return:	none
void BoxTree::destroyTree(Node*& root) {
    if(root) {
        destroyTree(root->leftChildPtr);
        destroyTree(root->rightChildPtr);
        delete root;
        root = NULL;
    }
}

// Name:	  insert()
// Desc:	  Inserts a Box object into the tree
// input:   const Box& aBox
// output:  none
// return:	none
void BoxTree::insert(const Box& aBox) {
    Node* curr = root;
    Node* prev = nullptr;

    while (curr) {
        prev = curr;

        if (aBox.getNum() < curr->data.getNum()) {
            curr = curr->leftChildPtr;
        } else {
            curr = curr->rightChildPtr;
        }
    }

    Node* newNode = new Node(aBox);

    if (!prev) {
        root = newNode;
    } else if (aBox.getNum() < prev->data.getNum()) {
        prev->leftChildPtr = newNode;
    } else {
        prev->rightChildPtr = newNode;
    }
}

// Name:	  remove()
// Desc:	  Removes a Box object from the tree
// input:   int boxIn
// output:  none
// return:	none
void BoxTree::remove(int boxIn) {
    remove(root, boxIn);
}

// Name:	  remove()
// Desc:	  Recursive helper function for remove()
// input:   Node*& root, int boxIn
// output:  none
// return:	none
void BoxTree::remove(Node*& root, int boxIn) {
    if(root) {
        if(boxIn == root->data.getNum()) {
            deleteNode(root);
        }
        else if(boxIn < root->data.getNum()) {
            remove(root->leftChildPtr, boxIn);
        }  
        else {
            remove(root->rightChildPtr, boxIn);
        }
    }
}

// Name:	  deleteNode()
// Desc:	  Deletes a node from the tree
// input:   Node*& target
// output:  none
// return:	none
void BoxTree::deleteNode(Node*& target) {
    Node* temp;
  
    if(!target->leftChildPtr && !target->rightChildPtr) {
        delete target;
        target = NULL;
    }
    else if(!target->leftChildPtr) {
        temp = target;
        target = target->rightChildPtr;
        temp->rightChildPtr = NULL;
        delete temp;
    }
    else if(!target->rightChildPtr) {
        temp = target;
        target = target->leftChildPtr;
        temp->leftChildPtr = NULL;
        delete temp;
    }
    else {
        Node* prev = NULL;
        Node* curr = target->rightChildPtr;
        while(curr->leftChildPtr) {
            prev = curr;
            curr = curr->leftChildPtr;
        }
    
        target->data = curr->data;
    
        if(!prev) {
            target->rightChildPtr = curr->rightChildPtr;
        }
        else {
            prev->leftChildPtr = curr->rightChildPtr;
        }
    
        curr->rightChildPtr = NULL;
        delete curr;
    }
}

// Name:	  getRange()
// Desc:	  Returns a list of Box objects within a given range
// input:   const int start, const int stop
// output:  none
// return:	BoxList getRange(start, stop, root)
BoxList BoxTree::getRange(const int start, const int stop) {
    return getRange(start, stop, root);
}

// Name:	  getRange()
// Desc:	  Recursive helper function for getRange()
// input:   const int start, const int stop, Node* root
// output:  none
// return:	BoxList boxList
BoxList BoxTree::getRange(const int start, const int stop, Node* root) {
    BoxList boxList;

    if (root) {
        if (root->data.getNum() >= start && root->data.getNum() <= stop) {
            boxList.insertAtTail(root->data);
        }

        if (root->data.getNum() > start) {
            boxList.append(getRange(start, stop, root->leftChildPtr));
        }

        if (root->data.getNum() < stop) {
            boxList.append(getRange(start, stop, root->rightChildPtr));
        }
    }

    return boxList;
}