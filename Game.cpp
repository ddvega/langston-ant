/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    Game.cpp
** Author:      Group 39
** Date:        04/25/2019
** Description: This is the cpp file for the Game class.  This class,
 *              using the critter base class and it's derived classes,
 *              Ant and Doodlebug, creates a 2d array of pointers(grid) for
 *              the critters to interact with each other.
******************************************************************************/

#include <iostream>
#include "Game.hpp"
#include "Critter.hpp"

/******************************************************************************
** Function:    Base constructor
** Description: Creates object with 2d array of critter pointers and randomly
 *              populates that grid with the number of ants and doodlebugs
 *              selected by the user or set in the default options.
******************************************************************************/
Game::Game(int rows, int columns, int ants, int doodlebugs)
{
   //set and fill 2D grid with Critter pointers
   grid = new Critter **[rows];
   for (int i = 0; i < rows; i++)
   {
      grid[i] = new Critter *[columns];
   }

   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < columns; j++)
      {
         grid[i][j] = nullptr;
      }
   }

   //Randomly populate grid with Ants
   int n = 0, rnX = 0, rnY = 0;
   while (n < ants)
   {
      rnX = rand() % (rows);
      rnY = rand() % (columns);
      if (grid[rnX][rnY] == nullptr)
      {
         grid[rnX][rnY] = new Ant;
         n++;
      }
   }

   //Randomly populate grid with Doodlebugs
   int z = 0, ranX = 0, ranY = 0;
   while (z < doodlebugs)
   {
      ranX = rand() % (rows);
      ranY = rand() % (columns);
      if (grid[ranX][ranY] == nullptr)
      {
         grid[ranX][ranY] = new Doodlebug;
         z++;
      }
   }

   this->rows = rows;
   this->columns = columns;
}

/******************************************************************************
** Function:    printGrid
** Description: loops through 2d array of critter pointers and prints their
 *              corresponding characters (critterChar)
******************************************************************************/
void Game::printGrid()
{
   for (int i = 0; i < columns + 2; i++)
   {
      std::cout << "-";
   }
   std::cout << std::endl;

   for (int i = 0; i < rows; i++)
   {
      std::cout << "|";
      for (int j = 0; j < columns; j++)
      {
         if (grid[i][j] != nullptr)
         {
            std::cout << grid[i][j]->Critter::getCritterChar();
         }
         else
         {
            std::cout << ' ';
         }
      }
      std::cout << "|" << std::endl;
   }

   for (int i = 0; i < columns + 2; i++)
   {
      std::cout << "-";
   }
   std::cout << std::endl;
}
/******************************************************************************
** Function:    incrementAllAges()
** Description: increases age of all critters on the board by one day
******************************************************************************/
void Game::incrementAllAges()
{
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < columns; j++)
      {
         if (grid[i][j] != nullptr)
         {
            grid[i][j]->incrementAge();
         }
      }
   }

}

/******************************************************************************
** Function:    resetMoveFlag()
** Description: Resets the critters move flag
******************************************************************************/
void Game::resetMoveFlag()
{
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < columns; j++)
      {
         if (grid[i][j] != nullptr)
         {
            grid[i][j]->resetMovedStepFlag();
         }
      }
   }
}

/******************************************************************************
** Function:    runStep()
** Description: Runs the full step routine
******************************************************************************/
void Game::runStep()
{
   //move doodlebug
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < columns; j++)
      {
         if (grid[i][j] != nullptr)
         {
            if (grid[i][j]->getCritterChar() == 'X')
            {
               grid[i][j]->move(grid, i, j, rows, columns);
            }
         }
      }
   }

   //move ant
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < columns; j++)
      {
         if (grid[i][j] != nullptr)
         {
            if (grid[i][j]->getCritterChar() == 'O')
            {
               grid[i][j]->move(grid, i, j, rows, columns);
            }
         }
      }
   }

   //breed
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < columns; j++)
      {
         if (grid[i][j] != nullptr)
         {
            grid[i][j]->breed(grid, i, j, rows, columns);
         }
      }
   }

   //starve doodlebugs
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < columns; j++)
      {
         if (grid[i][j] != nullptr)
         {
            if (grid[i][j]->Critter::getCritterChar() == 'X')
            {
               grid[i][j]->starve(grid, i, j, rows, columns);
            }
         }
      }
   }
}

/******************************************************************************
** Function:    Destructor
** Description: Deallocates memory for grid
******************************************************************************/
Game::~Game()
{
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < columns; j++)
      {
         delete grid[i][j];
      }
   }

   for (int i = 0; i < rows; i++)
   {
      delete[] grid[i];
   }

   delete[] grid;

}
