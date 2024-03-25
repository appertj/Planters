/*****************************************************************************
# Author:           Josiah Appert
# File:             boxlist.h
# Assignment:       Programming Project #4: Planters
# Date:             12/10/2023
# Description:      This file declares the private data members and public
#                   methods of the BoxList class
#****************************************************************************/
#ifndef BOXLIST_H
#define BOXLIST_H
#include "box.h"

class BoxList {
private:
    //defines private node structure
    struct Node {
        Box data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* mCurrent;
    Node* tail;
    void merge(Node*&, Node*);
    void mergeSort(Node*&);
public:
    //constructor
    BoxList();
    //destructor
    ~BoxList();
    void insertAtTail(const Box&);
    void append(const BoxList&);
    bool isEmpty() const;
    void startIterating();	  
    const Box& getNextBox();
    bool hasNextBox();
    void sort();
};

#endif