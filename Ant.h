// Name         :   Austin Klein
// Class        :   CSIS-211 
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#pragma once
#include <iostream>
#include <string>
#include "Organism.h"

using namespace std;

class Ant : public Organism {
private:

public:
    Ant();
    void move()     /*override*/;
    void breed()    /*override*/;
};