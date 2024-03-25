/*****************************************************************************
# Author:           Josiah Appert
# File:             plantermgr.cpp
# Assignment:       Programming Project #4: Planters
# Date:             12/10/2023
# Description:      This file contains functions used to perform operations on
#                   objects of the PlanterMgr class including a plant, 
#                   harvest, and prune method
# Input:            int numIn, char* nameIn, int startIn, int stopIn
# Output:           int numIn, char* nameIn, int startIn, int stopIn
# Sources:          Data Abstraction & Problem Solving chs 1-20, Project 4 
#                   Specs
#****************************************************************************/
#include "plantermgr.h"

// Name:	  plant()
// Desc:	  Adds a plant to the tree
// input:   int numIn, char* nameIn
// output:	int numIn, char* nameIn
// return:	none
void PlanterMgr::plant(int numIn, char* nameIn) {
    Box aBox(numIn, nameIn);
    btData.insert(aBox);
    cout << "Planting " << nameIn << " in box " << numIn << endl;
}

// Name:	  harvest()
// Desc:	  Removes a range of plants from the tree
// input:   char* nameIn, int startIn, int stopIn
// output:	char* nameIn, int startIn, int stopIn
// return:	none
void PlanterMgr::harvest(char* nameIn, int startIn, int stopIn) {
    BoxList thisList = btData.getRange(startIn, stopIn);

    cout << "Harvesting " << nameIn << " plants from boxes " << startIn << " to " << stopIn << ". " << endl;
    cout << "The following boxes will be harvested:";

    thisList.startIterating();

    BoxList harvestedBoxes;

    while (thisList.hasNextBox()) {
        Box thisBox = thisList.getNextBox();

        if (thisBox.getPlantName() != nullptr && strcmp(thisBox.getPlantName(), nameIn) == 0) {
            harvestedBoxes.insertAtTail(thisBox);
        }
    }

    harvestedBoxes.sort();

    harvestedBoxes.startIterating();

    while (harvestedBoxes.hasNextBox()) {
        Box harvestedBox = harvestedBoxes.getNextBox();
        cout << " " << harvestedBox.getNum();
    }

    cout << " " << endl;
}

// Name:	  prune()
// Desc:	  Removes a plant from the tree
// input:   int numIn
// output:	int numIn
// return:	none
void PlanterMgr::prune(int numIn) {
    btData.remove(numIn);
    cout << "Pruning box number " << numIn << "." << endl;
}