/******************************************************************************
** Program:     Predator-Prey-Game (CS162 Group Project)
 * Filename:    Validate.hpp
** Author:      Group 39
** Date:        04/01/2019
** Description: Validation routine header file
******************************************************************************/

#ifndef VALIDATE_HPP
#define VALIDATE_HPP

#include <string>

//Include default arguments so no max, or min/max has to be provided
int validateInputInteger(std::string outputString,
                         int min = -2147483647,
                         int max = 2147483647);
float validateInputFloat(std::string outputString,
                         float min = 1.175494e-38,
                         float max = 3.402823e+38);

#endif  //VALIDATE_HPP
