// Name         :   Austin Klein
// Class        :   CSIS-211 
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#include "World.h"

World::World() {
    // Initialize the world full of null pointers
    for (int y = 0; y < worldHeight; y++) {
        for (int x = 0; x < worldWidth; x++) {
            world[y][x] = nullptr;
        }
    }

}

void World::Draw(World *worldPtr) {
    // Draw out the instance world passed in by pointer
    for (int y = 0; y < worldHeight; y++) {
        for (int x = 0; x < worldWidth; x++) {
            if (world[y][x] = nullptr) {
                cout << " ";
            } else if (world[y][x]) {
                cout << "o";
            } else {
                cout << "X";
            }
        }
        cout << endl;
    }
    cout << endl;
}
