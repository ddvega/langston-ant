/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    menu.cpp
** Author:      Group 39
** Date:        04/14/2019
** Description: Menu function for up to 10 options
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Menu.hpp"

/******************************************************************************
** Function: Menu constructor for title only
** Description: Only display a title
******************************************************************************/
Menu::Menu(std::string t)
{
   title = t;
   if (strlen < t.length())
   {
      strlen = t.length();
   }
   centerTitle();
}

/******************************************************************************
** Function: Menu constructor for title + 1 option
** Description: Title + 1 option selected...which technically isn't an option
******************************************************************************/
Menu::Menu(std::string t, std::string o1)
{
   title = t;
   option1 = o1;
   if (strlen < o1.length())
   {
      strlen = o1.length();
   }
   centerTitle();
}

/******************************************************************************
** Function: Menu constructor for title + 2 options
** Description: Title + 2 options selected
******************************************************************************/
Menu::Menu(std::string t, std::string o1, std::string o2)
{
   title = t;
   option1 = o1;
   option2 = o2;
   if (strlen < o1.length())
   {
      strlen = o1.length();
   }
   if (strlen < o2.length())
   {
      strlen = o2.length();
   }
   centerTitle();
}

/******************************************************************************
** Function: Menu constructor for title + 3 options
** Description: Title + 3 options selected
******************************************************************************/
Menu::Menu(std::string t, std::string o1, std::string o2, std::string o3)
{
   title = t;
   option1 = o1;
   option2 = o2;
   option3 = o3;
   if (strlen < o1.length())
   {
      strlen = o1.length();
   }
   if (strlen < o2.length())
   {
      strlen = o2.length();
   }
   if (strlen < o3.length())
   {
      strlen = o3.length();
   }
   centerTitle();
}

/******************************************************************************
** Function: Menu constructor for title + 4 options
** Description: Title + 4 options selected
******************************************************************************/
Menu::Menu(std::string t,
           std::string o1,
           std::string o2,
           std::string o3,
           std::string o4)
{
   title = t;
   option1 = o1;
   option2 = o2;
   option3 = o3;
   option4 = o4;
   if (strlen < o1.length())
   {
      strlen = o1.length();
   }
   if (strlen < o2.length())
   {
      strlen = o2.length();
   }
   if (strlen < o3.length())
   {
      strlen = o3.length();
   }
   if (strlen < o4.length())
   {
      strlen = o4.length();
   }
   centerTitle();
}

/******************************************************************************
** Function: Menu constructor for title + 5 options
** Description: Title + 5 options selected
******************************************************************************/
Menu::Menu(std::string t,
           std::string o1,
           std::string o2,
           std::string o3,
           std::string o4,
           std::string o5)
{
   title = t;
   option1 = o1;
   option2 = o2;
   option3 = o3;
   option4 = o4;
   option5 = o5;
   if (strlen < o1.length())
   {
      strlen = o1.length();
   }
   if (strlen < o2.length())
   {
      strlen = o2.length();
   }
   if (strlen < o3.length())
   {
      strlen = o3.length();
   }
   if (strlen < o4.length())
   {
      strlen = o4.length();
   }
   if (strlen < o5.length())
   {
      strlen = o5.length();
   }
   centerTitle();
}

/******************************************************************************
** Function: Menu constructor for title + 6 options
** Description: Title + 6 options selected
******************************************************************************/
Menu::Menu(std::string t,
           std::string o1,
           std::string o2,
           std::string o3,
           std::string o4,
           std::string o5,
           std::string o6)
{
   title = t;
   option1 = o1;
   option2 = o2;
   option3 = o3;
   option4 = o4;
   option5 = o5;
   option6 = o6;
   centerTitle();
   if (strlen < o1.length())
   {
      strlen = o1.length();
   }
   if (strlen < o2.length())
   {
      strlen = o2.length();
   }
   if (strlen < o3.length())
   {
      strlen = o3.length();
   }
   if (strlen < o4.length())
   {
      strlen = o4.length();
   }
   if (strlen < o5.length())
   {
      strlen = o5.length();
   }
   if (strlen < o6.length())
   {
      strlen = o6.length();
   }
}

/******************************************************************************
** Function: Menu constructor for title + 7 options
** Description: Title + 7 options selected
******************************************************************************/
Menu::Menu(std::string t,
           std::string o1,
           std::string o2,
           std::string o3,
           std::string o4,
           std::string o5,
           std::string o6,
           std::string o7)
{
   title = t;
   option1 = o1;
   option2 = o2;
   option3 = o3;
   option4 = o4;
   option5 = o5;
   option6 = o6;
   option7 = o7;
   if (strlen < o1.length())
   {
      strlen = o1.length();
   }
   if (strlen < o2.length())
   {
      strlen = o2.length();
   }
   if (strlen < o3.length())
   {
      strlen = o3.length();
   }
   if (strlen < o4.length())
   {
      strlen = o4.length();
   }
   if (strlen < o5.length())
   {
      strlen = o5.length();
   }
   if (strlen < o6.length())
   {
      strlen = o6.length();
   }
   if (strlen < o7.length())
   {
      strlen = o7.length();
   }
   centerTitle();
}

/******************************************************************************
** Function: Menu constructor for title + 8 options
** Description: Title + 8 options selected
******************************************************************************/
Menu::Menu(std::string t,
           std::string o1,
           std::string o2,
           std::string o3,
           std::string o4,
           std::string o5,
           std::string o6,
           std::string o7,
           std::string o8)
{
   title = t;
   option1 = o1;
   option2 = o2;
   option3 = o3;
   option4 = o4;
   option5 = o5;
   option6 = o6;
   option7 = o7;
   option8 = o8;
   if (strlen < o1.length())
   {
      strlen = o1.length();
   }
   if (strlen < o2.length())
   {
      strlen = o2.length();
   }
   if (strlen < o3.length())
   {
      strlen = o3.length();
   }
   if (strlen < o4.length())
   {
      strlen = o4.length();
   }
   if (strlen < o5.length())
   {
      strlen = o5.length();
   }
   if (strlen < o6.length())
   {
      strlen = o6.length();
   }
   if (strlen < o7.length())
   {
      strlen = o7.length();
   }
   if (strlen < o8.length())
   {
      strlen = o8.length();
   }
   centerTitle();
}

/******************************************************************************
** Function: Menu constructor for title + 9 options
** Description: Title + 9 options selected
******************************************************************************/
Menu::Menu(std::string t,
           std::string o1,
           std::string o2,
           std::string o3,
           std::string o4,
           std::string o5,
           std::string o6,
           std::string o7,
           std::string o8,
           std::string o9)
{
   title = t;
   option1 = o1;
   option2 = o2;
   option3 = o3;
   option4 = o4;
   option5 = o5;
   option6 = o6;
   option7 = o7;
   option8 = o8;
   option9 = o9;
   if (strlen < o1.length())
   {
      strlen = o1.length();
   }
   if (strlen < o2.length())
   {
      strlen = o2.length();
   }
   if (strlen < o3.length())
   {
      strlen = o3.length();
   }
   if (strlen < o4.length())
   {
      strlen = o4.length();
   }
   if (strlen < o5.length())
   {
      strlen = o5.length();
   }
   if (strlen < o6.length())
   {
      strlen = o6.length();
   }
   if (strlen < o7.length())
   {
      strlen = o7.length();
   }
   if (strlen < o8.length())
   {
      strlen = o8.length();
   }
   if (strlen < o9.length())
   {
      strlen = o9.length();
   }
   centerTitle();
}

/******************************************************************************
** Function: Menu constructor for title + 10 options
** Description: Title + 10 options selected
******************************************************************************/
Menu::Menu(std::string t,
           std::string o1,
           std::string o2,
           std::string o3,
           std::string o4,
           std::string o5,
           std::string o6,
           std::string o7,
           std::string o8,
           std::string o9,
           std::string o10)
{
   title = t;
   option1 = o1;
   option2 = o2;
   option3 = o3;
   option4 = o4;
   option5 = o5;
   option6 = o6;
   option7 = o7;
   option8 = o8;
   option9 = o9;
   option10 = o10;
   if (strlen < o1.length())
   {
      strlen = o1.length();
   }
   if (strlen < o2.length())
   {
      strlen = o2.length();
   }
   if (strlen < o3.length())
   {
      strlen = o3.length();
   }
   if (strlen < o4.length())
   {
      strlen = o4.length();
   }
   if (strlen < o5.length())
   {
      strlen = o5.length();
   }
   if (strlen < o6.length())
   {
      strlen = o6.length();
   }
   if (strlen < o7.length())
   {
      strlen = o7.length();
   }
   if (strlen < o8.length())
   {
      strlen = o8.length();
   }
   if (strlen < o9.length())
   {
      strlen = o9.length();
   }
   if (strlen < o10.length() + 1)
   {
      strlen = o10.length() + 1;
   }
   centerTitle();
}

/******************************************************************************
** Function: centerTitle();
** Description: Center the Menu title
******************************************************************************/
void
Menu::centerTitle()
{
   while (title.length() < strlen + 4)
   {
      title.insert(title.begin(), ' ');
      if (title.length() < strlen + 4)
      {
         title.insert(title.length(), " ");
      }
   }
}

/******************************************************************************
** Function: displayTheMenu()
** Description: To display the menu
******************************************************************************/
void
Menu::displayTheMenu()
{
   system("clear");
   std::cout << std::string(strlen + 6, '-') << std::endl;
   std::cout << "|" << title << "|" << std::endl;

   if (option1 != "")
   {
      std::cout << std::string(strlen + 6, '-') << std::endl;
      std::cout << "|1 - " << std::left << std::setw(strlen) << option1 << "|"
                << std::endl;
   }
   if (option2 != "")
   {
      std::cout << "|2 - " << std::left << std::setw(strlen) << option2 << "|"
                << std::endl;
   }
   if (option3 != "")
   {
      std::cout << "|3 - " << std::left << std::setw(strlen) << option3 << "|"
                << std::endl;
   }
   if (option4 != "")
   {
      std::cout << "|4 - " << std::left << std::setw(strlen) << option4 << "|"
                << std::endl;
   }
   if (option5 != "")
   {
      std::cout << "|5 - " << std::left << std::setw(strlen) << option5 << "|"
                << std::endl;
   }
   if (option6 != "")
   {
      std::cout << "|6 - " << std::left << std::setw(strlen) << option6 << "|"
                << std::endl;
   }
   if (option7 != "")
   {
      std::cout << "|7 - " << std::left << std::setw(strlen) << option7 << "|"
                << std::endl;
   }
   if (option8 != "")
   {
      std::cout << "|8 - " << std::left << std::setw(strlen) << option8 << "|"
                << std::endl;
   }
   if (option9 != "")
   {
      std::cout << "|9 - " << std::left << std::setw(strlen) << option9 << "|"
                << std::endl;
   }
   if (option10 != "")
   {
      std::cout << "|10 - " << std::left << std::setw(strlen - 1) << option10
                << "|" << std::endl;
   }
   std::cout << std::string(strlen + 6, '-') << std::endl;

}

/******************************************************************************
** Function: displayTheMenuNoClear()
** Description: To display the menu but not clear the screen
******************************************************************************/
void
Menu::displayTheMenuNoClear()
{
   std::cout << std::string(strlen + 6, '-') << std::endl;
   std::cout << "|" << title << "|" << std::endl;

   if (option1 != "")
   {
      std::cout << std::string(strlen + 6, '-') << std::endl;
      std::cout << "|1 - " << std::left << std::setw(strlen) << option1 << "|"
                << std::endl;
   }
   if (option2 != "")
   {
      std::cout << "|2 - " << std::left << std::setw(strlen) << option2 << "|"
                << std::endl;
   }
   if (option3 != "")
   {
      std::cout << "|3 - " << std::left << std::setw(strlen) << option3 << "|"
                << std::endl;
   }
   if (option4 != "")
   {
      std::cout << "|4 - " << std::left << std::setw(strlen) << option4 << "|"
                << std::endl;
   }
   if (option5 != "")
   {
      std::cout << "|5 - " << std::left << std::setw(strlen) << option5 << "|"
                << std::endl;
   }
   if (option6 != "")
   {
      std::cout << "|6 - " << std::left << std::setw(strlen) << option6 << "|"
                << std::endl;
   }
   if (option7 != "")
   {
      std::cout << "|7 - " << std::left << std::setw(strlen) << option7 << "|"
                << std::endl;
   }
   if (option8 != "")
   {
      std::cout << "|8 - " << std::left << std::setw(strlen) << option8 << "|"
                << std::endl;
   }
   if (option9 != "")
   {
      std::cout << "|9 - " << std::left << std::setw(strlen) << option9 << "|"
                << std::endl;
   }
   if (option10 != "")
   {
      std::cout << "|10 - " << std::left << std::setw(strlen - 1) << option10
                << "|" << std::endl;
   }
   std::cout << std::string(strlen + 6, '-') << std::endl;

}
