/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    Critter.hpp
** Author:      Group 39
** Date:        04/25/2019
** Description: This is the header file for the Critter class.  This is a base
 *              class responsible establishing the core functionality of Ants
 *              and doodlebugs.
******************************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <ctime>
#include <cstdlib>
#include <iostream>

class Critter
{
protected:
   int timeLastFeed;
   char critterChar;
   int age;
   bool hasMovedFlag = false;

public:
   //constructor
   Critter();

   //destructor
   virtual ~Critter();

   //Getters
   char getCritterChar();

   //setters
   void incrementAge();
   void resetMovedStepFlag();

   //Functions
   virtual void move(Critter ***&grid, int, int, int, int) = 0;
   virtual void breed(Critter ***&grid, int, int, int, int) = 0;
   virtual void starve(Critter ***&grid, int, int, int, int) = 0;

};

#endif  //CRITTER_HPP 
