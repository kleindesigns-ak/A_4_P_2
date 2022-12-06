// Name         :   Austin Klein
// Class        :   CSIS-211 
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#pragma once
#include <iostream>
#include <string>
#include "Organism.h"

using namespace std;

class Doodlebug : public Organism {
private:
public:
    Doodlebug();
    void move(World *worldInstance) override;
    void breed() /*override*/;
    void eat();
    void starve();
};