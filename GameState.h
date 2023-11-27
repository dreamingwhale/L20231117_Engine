#pragma once
#include "Actor.h"
class AGameState :
    public AActor
{
public:
    AGameState();
    ~AGameState();
    virtual void Render() override;

    bool IsGameOver;
    bool IsNextLevel;
};

