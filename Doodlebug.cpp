// Name         :   Austin Klein
// Class        :   CSIS-211 
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#include "Doodlebug.h"

Doodlebug::Doodlebug() {
    ascii_identifier = 'X';
    breedingRequirement = 8;
    starveRequirement = 3;
}

void Doodlebug::move(World* worldInstance) {
    // Pass into search by ref to effectively receive multiple returns from the function
    int adjacentAntRow      = -1;
    int adjacentAntColumn   = -1;

    // Search for an ant. If found, eat and move there
    worldInstance->randSearchAdjacentLocations(curY, curX, adjacentAntRow, adjacentAntColumn, 'o');
    if (adjacentAntColumn != -1) {
        // Eat the ant
        worldInstance->killOrganism(adjacentAntRow, adjacentAntColumn, worldInstance->getCellOrganismPointer(adjacentAntRow, adjacentAntColumn));
        // Move to it's location
        Organism * temp = this;
        worldInstance->addOrganismToLocation(adjacentAntRow, adjacentAntColumn, this);
        worldInstance->removeOrganismFromLocation(adjacentAntRow, adjacentAntColumn, temp);

    } // If not found, proceed with a normal random move if an open space is available
    else {
        worldInstance->randSearchAdjacentLocations(curY, curX, adjacentAntRow, adjacentAntColumn, ' ');
        if (adjacentAntColumn != -1) {
            Organism * temp = this;
            int tempY = curY;
            int tempX = curX;
            worldInstance->addOrganismToLocation(adjacentAntRow, adjacentAntColumn, this);
            worldInstance->removeOrganismFromLocation(tempY, tempX, temp);
        }
    }
}

void Doodlebug::breed() {

}

void Doodlebug::eat() {

    //World::removeOrganismFromList();
}

void Doodlebug::starve() {

}
