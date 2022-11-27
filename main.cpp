// Name         :   Austin Klein
// Class        :   CSIS-211
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.
#include <iostream>
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
using namespace std;


int main() {
    // Initialize the world with 5 doodlebugs and 100 ants in random locations


    cout << endl << "Welcome to the Doodlebug Simulator " << endl << endl << "Have you ever wanted to see how doodlebugs attack ants in the " << endl << "wild? Well sit back and get ready to watch a time-lapsed " << endl << "simulation of the ant vs doodlebug life cycle. " << endl << endl;

    char gameLoopSentinel;
    do {
        // Flush the buffer from the last loop
        cin.ignore();



        // Sentinel Loop Control for advancing to the next time step
        cout << "Press 'Enter' to advance another time step. " << endl;
        cin.get(gameLoopSentinel);
    } while ( gameLoopSentinel == '\n' );

    return 0;
}
