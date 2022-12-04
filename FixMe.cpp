/*
 *
 * TODO :
 *          #MoveLogic
 *          #OrganismMove
 *      Organism location interaction conflict resolution ( one organism / space / round )
 *
 *
 * TODO :
 *          #MoveLogic
 *          #OrganismMove
 *      Organisms are bound by the edge of the world therefore if on the edge, that side becomes an invalid move
 *
 *
 * TODO :
 *          #MoveLogic
 *          #OrganismMove
 *      Organism must move during every time step
 *
 *
 * TODO :
 *          #MoveLogic
 *          #OrganismMove
 *      Randomly move to a free space (any direction as fits the confines of the move rules)
 *
 *
 * TODO :
 *          #MoveLogic
 *          #DoodlebugMove
 *          #DoodlebugEat
 *      Before completing the normal move pattern, prioritize searching for an ant in every direction and moving there / eating the ant if it is found (Delete the ant) -> otherwise proceed with a random move
 *      Doodlebugs only eat ants - not other doodlebugs
 *
 *
 *  TODO :
 *          #BreedLogic
 *          #OrganismBreed
 *      After the organism move function executes, if the organism is still alive and has tripped the breed flag (see next to-do for rounds required per child class), breed it by adding another of the same child type of organism. Do this by randomly checking for an empty space around the organism and fill it with a new instance of the same child organism type. If no space is available, the breed opportunity is forfeit and the 'roundsSurvived' counter returns to 0, but the ant does not die.
 *
 * TODO :
 *          #BreedLogic
 *          #ChildOrganisms
 *          #OrganismConstructor
 *      In the breed function, check the type of child and use a switch statement to determine if the organism should attempt to breed based on the 'roundsSurvived' counter comparison with the case in the switch statement determined by the type of child organism. For Ex -> at the end of the 3rd round that an ant survives, the 'roundsSurvived' counter iterates to 3. The program will switch on 'Organism->getChildType();' it would receive a char of 'o' for ant which would lead it to a case that compares the 'roundsSurvived' to 'Organism->getBreedRequirement();' we will say that returns 3 for this example. Since the two inputs are == , this will trigger a breed() function.
 *
 * TODO :
 *          #StarveLogic
 *          #DoodlebugStarve()
 *      exit if starve requirement is < 0 (Organisms that do not starve have constructors set the 'starveRequirement' to -1.
 *      check if the organism->getStarveRequirement() == organism->roundsSurvived, if so, delete that instance of this->organism
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */