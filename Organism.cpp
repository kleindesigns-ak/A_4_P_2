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

void Organism::setCurY(int y) {
    this->curY = y;
}

void Organism::setCurX(int x) {
    this->curX = x;
}

void Organism::move(World * worldInstance) {
    // Pass into search by ref to effectively receive multiple returns from the function
    int availableMoveRow    = -1;
    int availableMoveColumn = -1;

    // Temps to make shuffling possible
    Organism* temp ;
    int tempRow     = curY;
    int tempColumn  = curX;

    worldInstance->randSearchAdjacentLocations(curY, curX, availableMoveRow, availableMoveColumn, ' ');
    if (availableMoveRow != -1) {
        worldInstance->addOrganismToLocation(availableMoveRow, availableMoveColumn, worldInstance->getCellOrganismPointer(curY, curX));
        worldInstance->removeOrganismFromLocation(tempRow, tempColumn, worldInstance->getCellOrganismPointer(curY, curX));
    }
}

int Organism::getStarveRequirement() {
    return 0;
}
