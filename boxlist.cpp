/*****************************************************************************
# Author:           Josiah Appert
# File:             boxlist.cpp
# Assignment:       Programming Project #4: Planters
# Date:             12/10/2023
# Description:      This file contains functions used to perform operations on
#                   objects of the BoxList class including a default constructor, 
#                   destructor, and functions to build, manipulate, and 
#                   display data.
# Input:            const Box& boxIn, const BoxList& listIn, Node*& head1, 
#                   Node* head2, Node*& head
# Output:           bool head == NULL, Box* aBox, bool hasNext
# Sources:          Data Abstraction & Problem Solving chs 1-20, Project 4 
#                   Specs
#****************************************************************************/
#include "boxlist.h"
#include <iostream>
#include <cstring>
using namespace std;

// Name:	  BoxList()
// Desc:	  Default constructor for BoxList class
// input:   none
// output:	none
// return:	none
BoxList::BoxList() {
    head = NULL;
    mCurrent = NULL;
    tail = NULL;
}

// Name:	  ~BoxList()
// Desc:	  Destructor for BoxList class
// input:   none
// output:  none
// return:	none
BoxList::~BoxList() {
    Node* curr = head;
    while(head) {
        curr = head->next;
        delete head;
        head = curr;
    }
    delete curr;
    head = NULL;
}

// Name:	  insertAtTail()
// Desc:	  Adds a Box to the end of the list
// input:   const Box& boxIn
// output:  none
// return:	none
void BoxList::insertAtTail(const Box& boxIn) {
    Node* newNode = new Node{boxIn, nullptr, nullptr};
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Name:	  append()
// Desc:	  Adds a BoxList to the end of the list
// input:   const BoxList& listIn
// output:  none
// return:	none
void BoxList::append(const BoxList& listIn) {
    if (!listIn.isEmpty()) {
        Node* current = listIn.head;
        while (current) {
            insertAtTail(current->data);
            current = current->next;
        }
    }
}

// Name:	  isEmpty()
// Desc:	  Checks if the list is empty
// input:   none
// output:  none
// return:  bool head == NULL
bool BoxList::isEmpty() const {
    return head == NULL;
}

// Name:	  startIterating()
// Desc:	  Sets the iterator to the beginning of the list
// input:   none
// output:  none
// return:  none
void BoxList::startIterating() {
    mCurrent = head;
} 

// Name:	  getNextBox()
// Desc:	  Returns the next Box in the list
// input:   none
// output:  none
// return:  Box* aBox
const Box& BoxList::getNextBox() {
    Box* aBox = NULL;
    if(mCurrent == NULL) {
        aBox = NULL;
    }
    else {
        aBox = &(mCurrent->data);
        mCurrent = mCurrent->next;
    }
    return *aBox;
}

// Name:	  hasNextBox()
// Desc:	  Checks if there is another Box in the list
// input:   none
// output:  none
// return:  bool hasNext
bool BoxList::hasNextBox() {
    bool hasNext = false;
    if(mCurrent) {
        hasNext = true;
    }
    return hasNext;
}

// Name:	  merge()
// Desc:	  Merges two BoxLists into one
// input:   Node*& head1, Node* head2
// output:  none
// return:  none
void BoxList::merge(Node*& head1, Node* head2) {
    Node* temp = new Node;
    Node* tail = temp;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data.getNum() < head2->data.getNum()) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != nullptr) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    head1 = temp->next;
    delete temp;
}

// Name:	  mergeSort()
// Desc:	  Sorts the BoxList using merge sort
// input:   Node*& head
// output:  none
// return:  none
void BoxList::mergeSort(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* middle = slow;
    Node* nextToMiddle = middle->next;
    middle->next = nullptr;

    mergeSort(head);
    mergeSort(nextToMiddle);

    Node* dummy = new Node;
    Node* tail = dummy;

    while (head != nullptr && nextToMiddle != nullptr) {
        if (head->data.getNum() < nextToMiddle->data.getNum()) {
            tail->next = head;
            head = head->next;
        } else {
            tail->next = nextToMiddle;
            nextToMiddle = nextToMiddle->next;
        }
        tail = tail->next;
    }

    if (head != nullptr) {
        tail->next = head;
    } else {
        tail->next = nextToMiddle;
    }

    head = dummy->next;
    delete dummy;
}

// Name:	  sort()
// Desc:	  Calls private mergeSort method
// input:   none
// output:  none
// return:  none
void BoxList::sort() {
    mergeSort(head);
}