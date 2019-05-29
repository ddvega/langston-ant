/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    Doodlebug.cpp
** Author:      Group 39
** Date:        04/25/2019
** Description: This is the header file for the Doodlebug Class.  This Class
 *              is a derived Class of the Critter Class. Doodlebug's breed and
 *              die uniquely, everything else they share in common with base
 *              critters.
******************************************************************************/
#include "Doodlebug.hpp"

/******************************************************************************
** Function:    base constructor
** Description: creates a doodlebug object, setting it's identifying character
 *              (critterChar) to its label 'X'
******************************************************************************/
Doodlebug::Doodlebug()
{
   critterChar = 'X';
}

/******************************************************************************
** Function:    breedAllCritters
** Description: checks the fertility status of all critters on board. Initiates
 *              a birth if conditions are met
******************************************************************************/
void Doodlebug::breed(Critter ***&grid, int i, int j, int rows, int columns)
{

   int randBreed = std::rand() % 4;
   int flag = true;
   bool flagBreed[4] = {false, false, false, false};

   // loop through rows and columns
   // verify if the critter can breed
   if (age % 8 == 0 && age != 0)
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
            grid[i - 1][j] = new Doodlebug;
            flag = false;
         }
            // if west position is available, place newborn critter
         else if ((randBreed == 1) && (j + 1 < columns) && grid[i]
         [j + 1] == nullptr)
         {
            grid[i][j + 1] = new Doodlebug;
            flag = false;
         }
            // if south position is available, place newborn critter
         else if ((randBreed == 2) && (i + 1 < rows) && grid[i + 1]
         [j] == nullptr)
         {
            grid[i + 1][j] = new Doodlebug;
            flag = false;
         }
            // if west position is available, place newborn critter
         else if ((randBreed == 3) && (j - 1 >= 0) && grid[i]
         [j - 1] == nullptr)
         {
            grid[i][j - 1] = new Doodlebug;
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
/*******************************************************************************
** Function:    move override
 * Description: Doodlebug Move/Eat: First checks in order of (N,E,S,W) for an
 *              Ant to eat. The first one it finds, it will eat and move to it's
 *              location, resetting the eat counter. If no ant is found, will
 *              move like the Ant with a random direction number. If a
 *              doodlebug or bounds are in the way, the doodlebug won't move.
*******************************************************************************/
void Doodlebug::move(Critter ***&grid, int r, int c, int rows, int columns)
{
   if (!hasMovedFlag)
      //Critter hasn't moved
   {
      timeLastFeed++;

      if (r - 1 >= 0 && grid[r - 1][c] != nullptr)
      {
         if (grid[r - 1][c]->Critter::getCritterChar() == 'O')
         {
            //Eat the ant
            delete grid[r - 1][c];
            //Move Doodlebug
            hasMovedFlag = true;
            timeLastFeed = 0;
            grid[r - 1][c] = grid[r][c];
            grid[r][c] = nullptr;
         }
      }

      if (c + 1 < columns && grid[r][c + 1] != nullptr && !(hasMovedFlag))
      {
         if (grid[r][c + 1]->getCritterChar() == 'O')
         {
            //Eat the ant
            delete grid[r][c + 1];
            //Move Doodlebug
            hasMovedFlag = true;
            timeLastFeed = 0;
            grid[r][c + 1] = grid[r][c];
            grid[r][c] = nullptr;
         }
      }

      if (r + 1 < rows && grid[r + 1][c] != nullptr && !(hasMovedFlag))
      {
         if (grid[r + 1][c]->getCritterChar() == 'O')
         {
            //Eat the ant
            delete grid[r + 1][c];
            //Move Doodlebug
            hasMovedFlag = true;
            timeLastFeed = 0;
            grid[r + 1][c] = grid[r][c];
            grid[r][c] = nullptr;
         }
      }
      if (c - 1 >= 0 && grid[r][c - 1] != nullptr && !(hasMovedFlag))
      {
         if (grid[r][c - 1]->getCritterChar() == 'O')
         {
            //Eat the ant
            delete grid[r][c - 1];
            //Move Doodlebug
            hasMovedFlag = true;
            timeLastFeed = 0;
            grid[r][c - 1] = grid[r][c];
            grid[r][c] = nullptr;
         }
      }

      if (!hasMovedFlag)
      { //Regular movement
         //First create random direction
         int direction = rand() % 4;

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
}

/******************************************************************************
** Function:    starveCritter
** Description: loops through grid, checks for doodlebugs that haven't eaten
 *              in three steps and kills them off
******************************************************************************/
void Doodlebug::starve(Critter ***&grid, int x, int y, int rows, int columns)
{
   if (grid[x][y] != nullptr)
   {
      if (critterChar == 'X' && timeLastFeed == 3)
      {
         delete grid[x][y]; //deletes the doodlebug
         grid[x][y] = nullptr;
      }
   }
}
/******************************************************************************
** Function:    default destructor
** Description: deallocates memory used in the Class
******************************************************************************/
Doodlebug::~Doodlebug()
{
}
