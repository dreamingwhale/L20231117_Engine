#pragma once
#include "Actor.h"
class AWall :
    public AActor
{
public:
    AWall();
                              // default argument
    AWall(int NewX, int NewY, char NewShape = '*', int NewSortOrder = 100, SDL_Color NewColor = SDL_Color{ 255,102,255,0 });
    int GetX();
    int GetY();
    bool GetIsWall(int InputX, int InputY);
    virtual ~AWall();

};