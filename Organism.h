// Name         :   Austin Klein
// Class        :   CSIS-211
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#pragma once
#include <cstdlib>
#include <ctime>

class Organism {
protected:
    char ascii_identifier;
    int roundsSurvived = 0;
    int breedingRequirement;
    int starveRequirement;

public:
    //virtual void breed
    char getChildType();
    int getBreedingRequirement();
    int getStarveRequirement();
};