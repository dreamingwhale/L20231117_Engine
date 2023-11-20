#pragma once
#include "Actor.h"
#include "Wall.h" 
class APlayer : public AActor
{

public:
    APlayer();
    APlayer(int NewX, int NewY, char NewShape = 'P', int NewSortOrder = 400);
    virtual ~APlayer();

    bool IsCollide(int NewX, int NewY);
    virtual void Tick(int KeyCode) override;
};

