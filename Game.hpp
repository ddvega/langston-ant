/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    Game.hpp
** Author:      Group 39
** Date:        04/25/2019
** Description: This is the header file for the Game class.  This class,
 *              using the critter base class and it's derived classes,
 *              Ant and Doodlebug, creates a 2d array of pointers(grid) for
 *              the critters to interact with each other.
******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <ctime>
#include <iostream>

class Game
{
private:
   Critter ***grid;
   int rows;
   int columns;

public:
   Game(int, int, int, int);  //Constructor
   void printGrid();          //Function to print the current grid
   void incrementAllAges();
   void resetMoveFlag();
   void runStep();
   ~Game();
};

#endif  //GAME_HPP 
