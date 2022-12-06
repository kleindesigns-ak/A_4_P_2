// Name         :   Austin Klein
// Class        :   CSIS-211
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#pragma once
#include <cstdlib>
#include <ctime>
#include "World.h"

class World;

class Organism {
protected:
    char ascii_identifier = '#';
    int roundsSurvived = 0;
    int breedingRequirement;
    int starveRequirement;
    int curY, curX;

public:
    virtual void move(World *worldInstance);
    virtual void breed() = 0;
    void setCurY(int y);
    void setCurX(int x);
    char getChildType();
    int getBreedingRequirement();
    static int getStarveRequirement();
};