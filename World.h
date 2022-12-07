// Name         :   Austin Klein
// Class        :   CSIS-211 
// Assignment   :   Assignment 4 : Doodlebug Simulation
// Date         :   11/26/2022.

// The World class creates a world that is worldWidth x worldHeight
// To change the value of the width and height or the world, change the private constant values before compilation
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Organism;

class World {
private:
    const static int worldWidth = 20;
    const static int worldHeight = 20;
    Organism*  world[worldHeight][worldWidth] = {};
    // 2D vectors arranged by child type for procedural purposes since doodlebugs go first each round
    std::vector<std::vector<int>> doodlebugsPopulation = {};
    std::vector<std::vector<int>> antPopulation = {};
public:
    World();
    static const int getWorldWidth();
    static const int getWorldHeight();
    void draw();
    void round();
    // During a move, organism must first be added to the new location before removing from the old, otherwise the reference to the organism object will be deleted
    void addOrganismToLocation(int y, int x, Organism* organism);
    void removeOrganismFromLocation(int organismRow, int organismColumn, Organism* pOrganismToBeRemoved);
    Organism* getCellOrganismPointer(int row, int column);
    void addOrganismToList(int row, int column, Organism* organism);
    void removeOrganismFromList(int rowOfOrganism, int columnOfOrganism, Organism* pOrganismToBeDelisted);
    void killOrganism(int rowOfOrganism, int columnOfOrganism, Organism* pOrganismToBeKilled);
    void getRandomEmptyIndexInWorld(int &row, int &column);
    void randSearchAdjacentLocations(int row, int column, int &targetRow, int &targetColumn, char organismIdentifier);
    void instantiateOrganismRandomDirection(int row, int column, Organism * newOrganism);
};