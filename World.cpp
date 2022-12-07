// Name         :   Austin Klein
// Class        :   CSIS-211 
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#include "World.h"
#include "Ant.h"
#include "Doodlebug.h"

#include <random>

World::World() {
    // Initialize the world full of null pointers
    for (int y = 0; y < worldHeight; y++) {
        for (int x = 0; x < worldWidth; x++) {
            world[y][x] = nullptr;
        }
    }

}

void World::draw() {
    // draw out the instance world passed in by pointer
    for (int y = 0; y < worldHeight; y++) {
        for (int x = 0; x < worldWidth; x++) {
            if (world[y][x] == nullptr) {
                cout << " ";
            } else {
                cout << world[y][x]->getChildType();
            }
        }
        cout << endl;
    }
    cout << endl;
}

void World::round() {
    // In each round all the following sections must happen


    // ~~~~~~~~~~~~~~~  Preparation  ~~~~~~~~~~~~~~~~~~
    // Copy the locations of the ants and doodlebugs to have an unchanging list to iterate through
    std::vector<std::vector<int>> copyDoodlebugs    = doodlebugsPopulation;
    std::vector<std::vector<int>> copyAnts          = antPopulation;

    // Create iterators for 2D vectors to go through the list of each type of organisms
    std::vector<std::vector<int>>::const_iterator   doodlebugIterator;
    std::vector<std::vector<int>>::const_iterator   antIterator;


    // ~~~~~~~~~~~~~~~~  Operation  ~~~~~~~~~~~~~~~~~~~~
    // First Doodlebugs search for ants to eat and move to the place where they find one
        // Rounds without feeding is reset to 0
        // Delete this->ant

    // Ints hold rows and columns for each doodlebug in the list so there is less iteration syntax
    int curDoodleRow, curDoodleColumn;
    // Iterate through every doodlebug
    for (doodlebugIterator = doodlebugsPopulation.begin(); doodlebugIterator != doodlebugsPopulation.end() ; doodlebugIterator++) {
        curDoodleRow        = *(doodlebugIterator->begin());
        curDoodleColumn     = *(doodlebugIterator->end() - 1);

        // Using pointer notation means we are dealing with the doodlebug object and calling move() using this world
        world[curDoodleRow][curDoodleColumn]->move(this);
    }



    // If they don't find one, they pick a random move if a space is available and move there
        // ++ Rounds without feeding
    // If no space is available they don't move
        // ++ Rounds without feeding

    // Ants move randomly to an open adjacent space

    // End of round
        // DOODLEBUGS
            // survived rounds == 8
                // New Doodlebug
                // Reset survived rounds
            // Without feeding == 3
                // Delete this->doodlebug
        // ANTS
            // survived rounds == 3
                // add another adjacent ant if space allows
                // reset this->Ant.survivedRounds


}

void World::addOrganismToList(int row, int column, Organism *organism) {

    switch (organism->getChildType()) {
        case 'o': {
            antPopulation.push_back({row, column});
            break;
        }
        default: {
            doodlebugsPopulation.push_back({row, column});
        }
    }
}

void World::removeOrganismFromList(int rowOfOrganism, int columnOfOrganism, Organism *pOrganismToBeDelisted) {
    int counter = 0;
    switch (pOrganismToBeDelisted->getChildType()) {
        case 'o': {
            for (vector<int> coordinate : antPopulation) {
                if (coordinate.at(0) == rowOfOrganism) {
                    if (coordinate.at(1) == columnOfOrganism) {
                        antPopulation.erase(antPopulation.begin() + counter);
                        cout << "Ant eaten or moved at " << endl << "Row    : " << rowOfOrganism << endl << "Column : " << columnOfOrganism << endl;
                        return;
                    }
                }
                counter ++;
            }
        }
        default: {
            for (vector<int> coordinate : doodlebugsPopulation) {
                if (coordinate.at(0) == rowOfOrganism) {
                    if (coordinate.at(1) == columnOfOrganism) {
                        doodlebugsPopulation.erase(doodlebugsPopulation.begin() + counter);
                        cout << "Doodlebug starved or moved at " << endl << "Row    : " << rowOfOrganism << endl << "Column : " << columnOfOrganism << endl;
                        return;
                    }
                }
                counter ++;
            }
        }
    }
}

void World::getRandomEmptyIndexInWorld(int &row, int &column) {
    // Create a vector of ints to hold all possible cells
    vector<int> possibleEmptyLocation[worldHeight * worldWidth];

    // Assign each element its corresponding index number
    for (int location = 0; location < worldHeight * worldWidth; location++) {
        possibleEmptyLocation->push_back(location);
    }

    // Scramble all the numbers
    random_shuffle(possibleEmptyLocation->begin(), possibleEmptyLocation->end());

    // All possible locations are now randomized
    // Go through one at a time and compare the given location to make sure it is nullptr
    for (int element = 0; element < possibleEmptyLocation->size(); element++) {
        row = possibleEmptyLocation->at(element) % worldHeight;
        column = possibleEmptyLocation->at(element) / worldWidth;
        if (this->world[row][column] == nullptr)
            return;
    }
    cout << "Error: No cells found containing nullptr " << endl;
    return;
}

const int World::getWorldWidth() {
    return worldWidth;
}

const int World::getWorldHeight() {
    return worldHeight;
}

void World::instantiateOrganismRandomDirection(int row, int column, Organism *newOrganism) {

    int targetRow       = -1;
    int targetColumn    = -1;

    randSearchAdjacentLocations(row, column, targetRow, targetColumn, ' ');
    if (targetRow != -1) {
        world[targetRow][targetColumn] = newOrganism;
    }

}

void World::randSearchAdjacentLocations(int row, int column, int &targetRow, int &targetColumn,
                                        char organismIdentifier) {
    vector<char> direction = {'N', 'E', 'S', 'W'};
    int test;
    bool searchingForNullptr = false;
    if (organismIdentifier == ' ') {
        searchingForNullptr = true;
    }
    // Run loop 4 times to test north, east, south, and west
    for (int i = 0; i < 4; i++) {

        // Test each direction in a random order based on the number of options left to test from the last loop
        test = ::rand() % direction.size();

        // Switch on the position result of the random modulus from the previous line
        // If a direction has been erased from the
        switch (direction.at(test)) {
            // Check north
            case 'N': {
                // Bounds checking on the world
                if (row - 1 > 0){
                    // If search term is located to the north break out of the switch and change the passed by reference values
                    if (world[row - 1][column] != nullptr){
                        if (world[row - 1][column]->getChildType() == organismIdentifier ||
                            (world[row - 1][column]->getChildType() == '#' && searchingForNullptr)) {
                            targetRow = row - 1;
                            targetColumn = column;
                            return;
                        }
                    } else if (searchingForNullptr) {
                        targetRow = row - 1;
                        targetColumn = column;
                        return;
                    }

                }
                break;
            }
            // Check south
            case 'S': {
                // Bounds checking on the world
                if (world[row + 1][column] != nullptr){
                    if (row + 1 <= worldHeight) {
                        if (world[row + 1][column]->getChildType() == organismIdentifier ||
                            (world[row + 1][column]->getChildType() == '#' && searchingForNullptr)) {
                            targetRow = row + 1;
                            targetColumn = column;
                            return;
                        }
                    }
                } else if (searchingForNullptr) {
                    targetRow = row - 1;
                    targetColumn = column;
                    return;
                }
                break;
            }
                // Check east
            case 'E': {
                // Bounds checking on the world
                if (column + 1 <= worldWidth){
                    if (world[row][column + 1] != nullptr){
                        if (world[row][column + 1]->getChildType() == organismIdentifier ||
                            (world[row][column + 1]->getChildType() == '#' && searchingForNullptr)) {
                            targetRow = row;
                            targetColumn = column + 1;
                            return;
                        }
                    }
                } else if (searchingForNullptr) {
                    targetRow = row - 1;
                    targetColumn = column;
                    return;
                }
                break;
            }
                // Check west
            case 'W': {
                // Bounds checking on the world
                if (column - 1 > 0){
                    if (world[row][column - 1] != nullptr){
                        if (world[row][column - 1]->getChildType() == organismIdentifier ||
                            (world[row][column - 1]->getChildType() == '#' && searchingForNullptr)) {
                            targetRow = row;
                            targetColumn = column - 1;
                            return;
                        }
                    }
                } else if (searchingForNullptr) {
                    targetRow = row - 1;
                    targetColumn = column;
                    return;
                }
                break;
            }
            default:
                // The switch logic is keyed from the direction vector the only way to make it here is if the location has no available moves. This means no breeding will occur.
                return;
        }
        direction.erase(direction.begin() + test);

    }
}
void World::addOrganismToLocation(int y, int x, Organism* organism) {
    // Add to organism * world
    world[y][x] = organism;

    // Set organisms x and y, so it knows where it is at
    world[y][x]->setCurY(y);
    world[y][x]->setCurX(x);

    // Update the iteration list 2D vector organism parameter passed in to determine which list to add the occurrence to
    addOrganismToList(y, x, organism);
}

void World::removeOrganismFromLocation(int organismRow, int organismColumn, Organism* pOrganismToBeRemoved) {
    // Remove from the world of Organism *
    world[organismRow][organismColumn] = nullptr;

    // Don't have to update integral organismColumn and organismRow to each pOrganismToBeRemoved as it will either be overwritten through addOrganismToLocation() or will be deleted when starving or being eaten

    // Remove from coordinate vector saved in the World class
    removeOrganismFromList(organismRow, organismColumn, pOrganismToBeRemoved);
}

Organism *World::getCellOrganismPointer(int row, int column) {
    return world[row][column];
}

void World::killOrganism(int rowOfOrganism, int columnOfOrganism, Organism *pOrganismToBeKilled) {
    Organism *temp = pOrganismToBeKilled;
    removeOrganismFromLocation(rowOfOrganism, columnOfOrganism, pOrganismToBeKilled);
    delete pOrganismToBeKilled;
}
