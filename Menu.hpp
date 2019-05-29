/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    menu.hpp
** Author:      Group 39
** Date:        04/14/2019
** Description: Menu function for up to 10 options
******************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>

class Menu
{
private:
   std::string title = "";
   std::string option1 = "";
   std::string option2 = "";
   std::string option3 = "";
   std::string option4 = "";
   std::string option5 = "";
   std::string option6 = "";
   std::string option7 = "";
   std::string option8 = "";
   std::string option9 = "";
   std::string option10 = "";
   unsigned int strlen = 25;
   void centerTitle();

public:
   Menu(std::string);
   Menu(std::string, std::string);
   Menu(std::string, std::string, std::string);
   Menu(std::string, std::string, std::string, std::string);
   Menu(std::string, std::string, std::string, std::string, std::string);
   Menu(std::string, std::string, std::string, std::string, std::string,
        std::string);
   Menu(std::string, std::string, std::string, std::string, std::string,
        std::string, std::string);
   Menu(std::string, std::string, std::string, std::string, std::string,
        std::string, std::string, std::string);
   Menu(std::string, std::string, std::string, std::string, std::string,
        std::string, std::string, std::string, std::string);
   Menu(std::string, std::string, std::string, std::string, std::string,
        std::string, std::string, std::string, std::string, std::string);
   Menu(std::string,
        std::string,
        std::string,
        std::string,
        std::string,
        std::string,
        std::string,
        std::string,
        std::string,
        std::string,
        std::string);
   void displayTheMenu();
   void displayTheMenuNoClear();
};

#endif  //MENU_HPP
