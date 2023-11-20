#pragma once
#include "Actor.h"
class AWall :
    public AActor
{
public:
    AWall();
                              // default argument
    AWall(int NewX, int NewY, char NewShape = '*', int NewSortOrder = 100);
    int GetX();
    int GetY();
    bool GetIsWall(int InputX, int InputY);
    virtual ~AWall();

};