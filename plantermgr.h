/*****************************************************************************
# Author:           Josiah Appert
# File:             plantermgr.h
# Assignment:       Programming Project #4: Planters
# Date:             12/10/2023
# Description:      This file declares the private data member and 
#                   public methods of the PlanterMgr class
#****************************************************************************/
#ifndef PLANTERMGR_H
#define PLANTERMGR_H
#include "boxtree.h"

class PlanterMgr {
public:
    void plant(int, char*);
    void harvest(char*, int, int);
    void prune(int);
private:
    BoxTree btData;
};

#endif