/*****************************************************************************
# Author:           Josiah Appert
# File:             box.h
# Assignment:       Programming Project #4: Planters
# Date:             12/10/2023
# Description:      This file declares the private data members and public
#                   methods of the Box class
#****************************************************************************/
#ifndef BOX_H
#define BOX_H
#include <cstring>
#include <iostream>

using namespace std;

class Box {
public:
    //default constructor
    Box();
    //paramaterized constructor
    Box(int, const char*);
    //copy constructor
    Box(const Box &aBox);
    //destructor
    ~Box();
    //assignment operator
    const Box& operator=(const Box& aBox);
    //getters
    const int getNum() const;
    const char* getPlantName();
private:
    int boxNum;
    char* plantName;
};

#endif