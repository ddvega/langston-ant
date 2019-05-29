/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    Ant.hpp
** Author:      Group 39
** Date:        04/25/2019
** Description: This is the header file for the Ant class.  This is a derived
 *              class of the Critter class.  Ants breed uniquely, everything
 *              else they share in common with base Critters.
******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"
#include <ctime>
#include <cstdlib>

class Ant : public Critter
{
public:
   Ant();
   void breed(Critter ***&grid, int i, int j, int rows, int columns) override;
   void move(Critter ***&grid, int i, int j, int rows, int columns) override;
   void starve(Critter ***&grid, int, int, int, int) override;
   ~Ant() override;
};

#endif  //ANT_HPP 
