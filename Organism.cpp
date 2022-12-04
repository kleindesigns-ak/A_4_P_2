// Name         :   Austin Klein
// Class        :   CSIS-211
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#include "Organism.h"

char Organism::getChildType() {
    return ascii_identifier;
}

int Organism::getBreedingRequirement() {
    return breedingRequirement;
}
