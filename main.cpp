// Name         :   Austin Klein
// Class        :   CSIS-211
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "World.h"
#include "Ant.h"
#include "Doodlebug.h"

using namespace std;


int main() {
    srand(time(NULL));
    int startingAnts = 100;
    int startingDoodlebugs = 5;

    // The simulation is underway!! (Creation of a world instance to be used for the rest of the game.)
    World DoodleZoo;

    // Initialize the world with 'startingDoodlebugs' number of doodlebugs and 'startingAnts' number of ants in random locations

    // Runs once per doodlebug to be added
    Organism* temp;

    int worldRow;
    int worldColumn;

    for (int doodlebug = 0; doodlebug < startingDoodlebugs; doodlebug++) {
        temp = new Doodlebug;
        DoodleZoo.getRandomEmptyIndexInWorld(worldRow, worldColumn);
        DoodleZoo.addOrganismToLocation(worldRow, worldColumn, temp);
    }
    // Runs once per ant to be added
    for (int i = 0; i < startingAnts; i++) {
        temp = new Ant;
        DoodleZoo.getRandomEmptyIndexInWorld(worldRow, worldColumn);
        DoodleZoo.addOrganismToLocation(worldRow, worldColumn, temp);
    }

    cout << endl << "Welcome to the Doodlebug Simulator " << endl << endl << "Have you ever wanted to see how doodlebugs attack ants in the " << endl << "wild? Well sit back and get ready to watch a time-lapsed " << endl << "simulation of the ant vs doodlebug life cycle. " << endl << endl;


    char gameLoopSentinel;

    do {
        DoodleZoo.draw();
        // Sentinel Loop Control for advancing to the next time step
        cout << "Press 'Enter' to advance another time step. " << endl;
        cin.get(gameLoopSentinel);
        DoodleZoo.round();
    } while ( gameLoopSentinel == '\n' );

    return 0;
}
