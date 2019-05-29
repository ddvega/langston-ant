/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    Doodlebug.hpp
** Author:      Group 39
** Date:        04/25/2019
** Description: This is the header file for the Doodlebug Class.  This Class
 *              is a derived Class of the Critter Class. Doodlebug's breed and
 *              die uniquely, everything else they share in common with base
 *              critters.
******************************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"
#include <ctime>
#include <cstdlib>

class Doodlebug : public Critter
{
private:
public:
   Doodlebug();
   void breed(Critter ***&grid, int i, int j, int rows, int columns) override;
   void move(Critter ***&, int, int, int, int) override;
   void starve(Critter ***&, int, int, int, int) override;
   ~Doodlebug() override;
};

#endif // DOODLEBUG_HPP
