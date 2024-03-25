/*****************************************************************************
# Author:           Josiah Appert
# File:             box.cpp
# Assignment:       Programming Project #4: Planters
# Date:             12/10/2023
# Description:      This file contains functions used to perform operations on
#                   objects of the Box class including a default constructor, 
#                   additional constructor, copy constructor, destructor, 
#                   overloaded assignment operator, and appropriate getters
# Input:            int boxNumIn, const char* plantNameIn, const Box &aBox
# Output:           *this, this->boxNum, this->plantName
# Sources:          Data Abstraction & Problem Solving chs 1-20, Project 4 
#                   Specs
#****************************************************************************/
#include "box.h"

// Name:	  Box()
// Desc:	  Default constructor for Box class
// input:   none
// output:	none
// return:	none
Box::Box(): boxNum(0), plantName(NULL) {}

// Name:	  Box()
// Desc:	  Constructor for Box class
// input:   int boxNumIn, const char* plantNameIn
// output:  none
// return:	none
Box::Box(int boxNumIn, const char* plantNameIn): boxNum(boxNumIn), plantName(NULL) {
    if(plantNameIn != nullptr) {
        this->plantName = new char[strlen(plantNameIn)+1];
        strcpy(this->plantName, plantNameIn);
    }
}

// Name:	  Box()
// Desc:	  Copy constructor for Box class
// input:   const Box &aBox
// output:  none
// return:	none
Box::Box(const Box &aBox) : boxNum(aBox.boxNum), plantName(nullptr) {
    if (aBox.plantName != nullptr) {
        if (this->plantName != nullptr) {
            delete[] this->plantName;
        }

        this->plantName = new char[strlen(aBox.plantName) + 1];
        strcpy(this->plantName, aBox.plantName);
    }
}

// Name:	  ~Box()
// Desc:	  Destructor for Box class
// input:   none
// output:  none
// return:	none
Box::~Box() {
    if(plantName) {
        delete [] plantName;
    }
}

// Name:	  operator=
// Desc:	  Overloaded assignment operator for Box class
// input:   const Box& aBox
// output:  none
// return:	*this
const Box& Box::operator=(const Box& aBox) {
    if(this != &aBox) {
        delete[] this->plantName;
        this->boxNum = aBox.boxNum;
        this->plantName = new char[strlen(aBox.plantName)+1];
        strcpy(this->plantName, aBox.plantName);
    }
    return *this;
}

// Name:	  getNum()
// Desc:	  Accessor for boxNum
// input:   none
// output:  none
// return:	this->boxNum
const int Box::getNum() const {
    return this->boxNum;
}

// Name:	  getPlantName()
// Desc:	  Accessor for plantName
// input:   none
// output:  none
// return:	this->plantName
const char* Box::getPlantName() {
    return this->plantName;
}