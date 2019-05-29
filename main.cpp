/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    main.cpp
** Author:      Group 39
** Date:        04/25/2019
** Description: This is the main implementation file for the Predator-Prey-game.
 *              The purpose of this program is to use cellular automata to
 *              create a 2D predator–prey simulation. The preys are ants and
 *              the predators are doodlebugs.
******************************************************************************/
#include <iostream>
#include "Game.hpp"
#include "Menu.hpp"
#include "Validate.hpp"
#include <ctime>

int main()
{
   //seed rand
   srand(time(nullptr));

   //Extra credit warning
   system("clear");
   std::cout << "\nGroup 39 has chosen to allow the user to define the board"
             << "\nsize and the number of ants and doodlebugs in order to"
             << "\nobtain the 10% extra credit.  Please be on the lookout."
             << "\nPress enter to continue..."
             << std::endl;

   getchar();

   int selection = 0;   //Initialize the user selection variable
   int rows = 20;       //Initialize the rows variable with default 20
   int columns = 20;    //Initialize the columns variable with default 20
   int ants = 100;      //Initialize the ants variable with default 20
   int doodlebugs = 5;  //Initialize the doodlebugs variable with default 20
   int steps = 0;       //Initialize the steps variable

   //Setup the menus
   Menu mainMenu = Menu("PREDATOR AND PRAY", "Define parameters",
                        "Use default parameters");
   Menu setupMenu = Menu("SIM PARAMETERS");
   Menu finalMenu = Menu("SIMULATION COMPLETE", "Play more steps", "Quit");
   Menu playMore = Menu("LETS KEEP PLAYING!!");

   //Set user selections
   mainMenu.displayTheMenu();
   selection = validateInputInteger("Enter selection: ", 1, 2);

   if (selection == 1)
   {
      setupMenu.displayTheMenu();
      rows = validateInputInteger("Enter number of rows: ", 1, 100);
      columns = validateInputInteger("Enter number of columns: ", 1, 100);
      ants = validateInputInteger("Enter number of ants: ", 0, rows * columns);
      doodlebugs = validateInputInteger("Enter number of doodlebugs: ", 0,
                                        (rows * columns - ants));
      steps = validateInputInteger("Enter number of steps to simulate: ",
                                   1, 100000);
   }
   if (selection == 2)
   {
      steps = validateInputInteger("Enter number of steps to simulate: ",
                                   1, 100000);
      selection = 1;
   }

   //Initialize board and start game
   Game g1 = Game(rows, columns, ants, doodlebugs);
   std::cout << "Initial grid layout" << std::endl;
   g1.printGrid();
   while (selection == 1)
   {
      for (int n = 0; n < steps; n++)
      {
         std::cout << "Simulating step " << n + 1 << " of " << steps
                   << std::endl;
         g1.incrementAllAges();
         g1.runStep();
         g1.printGrid();
         g1.resetMoveFlag();
      }

      std::cout << "Simulation complete, press enter to continue..."
                << std::endl;
      getchar();
      finalMenu.displayTheMenu();
      selection = validateInputInteger("Enter selection: ", 1, 2);
      if (selection == 1)
      {
         playMore.displayTheMenu();
         steps = validateInputInteger("Number of steps to continue "
                                      "simulating: ", 1, 100000);
      }
   }
   return 0;
}
