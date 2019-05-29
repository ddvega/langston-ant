/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    Validate.cpp
** Author:      Group 39
** Date:        04/01/2019
** Description: Validation routine for integers, but will be expanded later
**              to validate other data types.
******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <climits>
#include <cmath>
#include "Validate.hpp"

int validateInputInteger(std::string outputString, int min, int max)
{
   std::string testIntString;
   int testInt;
   bool valid = false;
   bool isNum = true;
   bool isInt = true;

   std::cout << outputString;

   while (!valid)
   {
      isNum = true;
      isInt = true;
      std::cin >> testIntString;

      //Loop through each character of the string to test for non-digits
      //Using just stoi allowed some input to get through (floats or numbers
      // followed by letters)
      for (unsigned int i = 0; i < testIntString.length(); i++)
      {
         if (!std::isdigit(testIntString[i]))
         {
            if (i == 0 && testIntString[0]
               == '-') //Check if first character is minus sign
            {
               isNum = true; //Allow negative numbers to pass this check
            }
            else
            {
               isNum =
                  false; //Set the flag because there is a non-digit in the
               // string
            }
         }
      }

      //Try to convert numerical string to int, set isInt flag so range
      // validation isn't run
      //This will catch numerical data outside the normal integer range
      try  //https://www.techiedelight.com/convert-string-to-int-cpp/
      {
         testInt = std::stoi(testIntString);
      }
      catch (...)
      {
         isInt = false;
      }

      //If we passed the last 2 tests, now we can do bounds checking
      if (isNum && isInt)
      {
         if (testInt >= min && testInt <= max) //Is data within the bounds
         {
            valid = true; //Data is good, escape while loop
            std::cin.clear();
            std::cin.ignore(256, '\n');
         }
         else //Data is not in bounds, inform user of error and the bounds and
            // reprompt
         {
            valid = false;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Out of bounds, please enter an integer between ";
            std::cout << min << " and " << max << ": ";
         }
      }
      else //Data is either not a number or an integer, inform user and reprompt
      {
         std::cin.clear();
         std::cin.ignore(256, '\n');
         std::cout << "That is not an integer, please enter an integer: ";
      }
   }
   return testInt;  //Return only integers to the code that called this function
}

float validateInputFloat(std::string outputString, float min, float max)
{
   std::string testFloatString;
   float testFloat;
   bool valid = false;
   char *end = NULL;

   std::cout << outputString;

   while (!valid)
   {
      std::cin >> testFloatString;

      //Code from:
      //https://stackoverflow.com/questions/15339548/c-validating-float
      testFloat = strtod(testFloatString.c_str(), &end);
      if (end == testFloatString.c_str()
         || end - testFloatString.c_str()
            != static_cast<int>(testFloatString.length()))
      {
         std::cout << "Not a valid floating point value, please try again: ";
      }
      else if (testFloat == +HUGE_VAL || testFloat == -HUGE_VAL)
      {
         std::cout
            << "Value outside limits for floating point, please try again: ";
      }
      else if (testFloat > max || testFloat < min)
      {
         std::cout << "Outside valid range of ";
         std::cout << std::fixed << std::setw(3) << std::setprecision(1) << min
                   << "-" << max;
         std::cout << ", please try again: ";
      }
      else
      {
         valid = true;
      }
   }
   return testFloat;
}
