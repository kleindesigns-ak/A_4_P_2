// Name         :   Austin Klein
// Class        :   CSIS-211 
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.

// The World class creates a world that is worldWidth x worldHeight
// To change the value of the width and height or the world, change the private constant values before compilation
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"

using namespace std;

class World {
private:
    const static int worldWidth = 20;
    const static int worldHeight = 20;
    Organism*  world[worldHeight][worldWidth];
public:
    World();
    static const int getWorldWidth();
    static const int getWorldHeight();
    void Draw();
    int getRandomEmptyIndex();
    void instantiateOrganism(int y, int x, Organism* newOrganism);
};