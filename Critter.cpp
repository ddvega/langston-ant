/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    Critter.cpp
** Author:      Group 39
** Date:        04/25/2019
** Description: This is the cpp file for the Critter class.  This is a base
 *              class responsible establishing the core functionality of Ants
 *              and doodlebugs.
******************************************************************************/
#include "Critter.hpp"

/******************************************************************************
** Function:    base constructor
** Description: creates a critter object and sets protected variables to null
******************************************************************************/
Critter::Critter()
{
   timeLastFeed = 0;
   critterChar = ' ';
   age = 0;
}

/******************************************************************************
** Function:    getCritterChar()
** Description: Returns the critter display character
******************************************************************************/
char Critter::getCritterChar()
{
   return critterChar;
}

/******************************************************************************
** Function:    incrementAge
** Description: adds a day to the age of a critter
******************************************************************************/
void Critter::incrementAge()
{
   age++;
}

/******************************************************************************
** Function:    resetMovedStepFlag
** Description: resets critter movement to false
******************************************************************************/
void Critter::resetMovedStepFlag()
{
   hasMovedFlag = false;
}
/******************************************************************************
** Function:    Default destructor
** Description: Deallocates memory used within the class
******************************************************************************/
Critter::~Critter()
{
}
