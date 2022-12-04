// Name         :   Austin Klein
// Class        :   CSIS-211 
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#include "World.h"

#include <random>

World::World() {
    // Initialize the world full of null pointers
    for (int y = 0; y < worldHeight; y++) {
        for (int x = 0; x < worldWidth; x++) {
            world[y][x] = nullptr;
        }
    }

}

void World::Draw() {
    // Draw out the instance world passed in by pointer
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

int World::getRandomEmptyIndex() {
    // Create a vector of ints to hold all possible cells
    vector<int> possibleEmptyLocation[worldHeight * worldWidth];
    int worldRow;
    int worldColumn;

    // Assign each element its corresponding index number
    for (int location = 0; location < worldHeight * worldWidth; location++) {
        possibleEmptyLocation->push_back(location);
    }

    // Scramble all the numbers
    random_shuffle(possibleEmptyLocation->begin(), possibleEmptyLocation->end());

    // All possible locations are now randomized
    // Go through one at a time and compare the given location to make sure it is nullptr
    for (int element = 0; element < possibleEmptyLocation->size(); element++) {
        worldRow = possibleEmptyLocation->at(element) % worldHeight;
        worldColumn = possibleEmptyLocation->at(element) / worldWidth;
        if (this->world[worldRow][worldColumn] == nullptr) {
            cout << "Returned from getRandomEmptyIndex() at " << endl << "Row    : " << worldRow << endl << "Column : " << worldColumn << endl;
            return possibleEmptyLocation->at(element);
        }
    }

    return NULL;
}

void World::instantiateOrganism(int y, int x, Organism* newOrganism) {
    world[y][x] = newOrganism;
}

const int World::getWorldWidth() {
    return worldWidth;
}

const int World::getWorldHeight() {
    return worldHeight;
}

