// Name         :   Austin Klein
// Class        :   CSIS-211
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "World.h"
#include "Organism.h"
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

    // Runs once per ant to be added
    for (int i = 0; i < startingAnts; i++) {
        Organism* temp = new Ant; // FIXME : Start here next time -> Pass back the location in the world to place ants, don't just pass back the nullptr from the location as that does not give any information as to the location in the world.
        DoodleZoo.getRandomEmptyLocation();
        delete temp;
    }


    cout << endl << "Welcome to the Doodlebug Simulator " << endl << endl << "Have you ever wanted to see how doodlebugs attack ants in the " << endl << "wild? Well sit back and get ready to watch a time-lapsed " << endl << "simulation of the ant vs doodlebug life cycle. " << endl << endl;


    char gameLoopSentinel;
    do {
        DoodleZoo.Draw();

        // Sentinel Loop Control for advancing to the next time step
        cout << "Press 'Enter' to advance another time step. " << endl;
        cin.get(gameLoopSentinel);
    } while ( gameLoopSentinel == '\n' );

    return 0;
}
