/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    Ant.cpp
** Author:      Group 39
** Date:        04/25/2019
** Description: This is the cpp file for the Ant class.  This is a derived
 *              class of the Critter class.  Ants breed uniquely, everything
 *              else they share in common with base Critters.
******************************************************************************/
#include "Ant.hpp"

/******************************************************************************
** Function:    Base constructor
** Description: creates a Ant object, setting it's identifying character
 *              (critterChar) to its label 'O'
******************************************************************************/
Ant::Ant()
{
   critterChar = 'O';
}

/*******************************************************************************
** Function:    moveAnt
 * Description: Ant Move: Calls a random number for direction.(0,1,2,3) ->
 *              (N,E,S,W). Then checks that location for an ant/doodlebug. If
 *              one exists or if the movement is out of bounds, the Ant stays
 *              in place. Override from the virtual function in Critter class.
*******************************************************************************/
void Ant::move(Critter ***&grid, int r, int c, int rows, int columns)
{
   //First create random direction
   int direction = rand() % 4;

   if (!hasMovedFlag) //Critter hasn't moved
   {
      //Depending on direction, try to move ant one step
      if (direction == 0)
      {
         //Check bounds
         if (r - 1 >= 0 && grid[r - 1][c] == nullptr)
         {
            hasMovedFlag = true;
            grid[r - 1][c] = grid[r][c];
            grid[r][c] = nullptr;
         } //Stays in place if out of bounds or not an open space
      }
      else if (direction == 1)
      {
         //Check bounds
         if (c + 1 < columns && grid[r][c + 1] == nullptr)
         {
            hasMovedFlag = true;
            grid[r][c + 1] = grid[r][c];
            grid[r][c] = nullptr;
         } //Stays in place if out of bounds or not an open space
      }
      else if (direction == 2)
      {
         //Check bounds
         if (r + 1 < rows && grid[r + 1][c] == nullptr)
         {
            hasMovedFlag = true;
            grid[r + 1][c] = grid[r][c];
            grid[r][c] = nullptr;
         } //Stays in place if out of bounds or not an open space
      }
      else if (direction == 3)
      {
         //Check bounds
         if (c - 1 >= 0 && grid[r][c - 1] == nullptr)
         {
            hasMovedFlag = true;
            grid[r][c - 1] = grid[r][c];
            grid[r][c] = nullptr;
         } //Stays in place if out of bounds or no open space
      }
   }
}

/******************************************************************************
** Function:    breedAllCritters
** Description: checks the fertility status of all critters on board. Initiates
 *              a birth if conditions are met
******************************************************************************/
void Ant::breed(Critter ***&grid, int i, int j, int rows, int columns)
{
   int randBreed = std::rand() % 4;
   int flag = true;
   bool flagBreed[4] = {false, false, false, false};

   // loop through rows and columns

   // verify if the critter can breed
   if (age % 3 == 0 && age != 0)
   {
      // reset flags
      flag = true;
      for (int x = 0; x < 4; x++)
      {
         flagBreed[x] = false;
      }

      // will continue to loop until it randomly finds a space to
      // place newborn critter
      while (flag)
      {
         // if north position is available, place newborn critter
         if ((randBreed == 0) && (i - 1 >= 0) && grid[i - 1]
         [j] == nullptr)
         {
            grid[i - 1][j] = new Ant;
            flag = false;
         }
            // if west position is available, place newborn critter
         else if ((randBreed == 1) && (j + 1 < columns) && grid[i]
         [j + 1] == nullptr)
         {
            grid[i][j + 1] = new Ant;
            flag = false;
         }
            // if south position is available, place newborn critter
         else if ((randBreed == 2) && (i + 1 < rows) && grid[i + 1]
         [j] == nullptr)
         {
            grid[i + 1][j] = new Ant;
            flag = false;
         }
            // if west position is available, place newborn critter
         else if ((randBreed == 3) && (j - 1 >= 0) && grid[i]
         [j - 1] == nullptr)
         {
            grid[i][j - 1] = new Ant;
            flag = false;
         }
            // if cardinal position was occupied, flag
         else
         {
            flagBreed[randBreed] = true;
         }
         // if all cardinal position are occupied, then newborn
         // critter cannot be placed and dies.
         if (flagBreed[0] && flagBreed[1] &&
            flagBreed[2] && flagBreed[3])
         {
            flag = false;
         }
         randBreed = std::rand() % 4;
      }
   }
}

/******************************************************************************
** Function:    starveCritter
** Description: Used in doodlebug only
******************************************************************************/
void Ant::starve(Critter ***&grid, int x, int y, int rows, int columns)
{
}
/******************************************************************************
** Function:    default destructor
** Description: deallocates memory used in the Class
******************************************************************************/
Ant::~Ant()
{
}
