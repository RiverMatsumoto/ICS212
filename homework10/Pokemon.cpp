/*************************************************
//  NAME: River Matsumoto
//
//  HOMEWORK: homework10
//
//  CLASS: ICS212
//
//  INSTRUCTOR: Ravi Narayan
//
//  DATE: December 10, 2022
//
//  FILE: Pokemon.cpp
//
//  DESCRIPTION: The implementation of Pokemon
//
//  REFERENCES: Homework details
//
 * **********************************************/

#include "Pokemon.h"
#include <iostream>

/*************************************************
//
//  Function name: Pokemon
//
//  DESCRIPTION:   The constructor of the Pokemon
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
Pokemon::Pokemon()
{
    std::cout << "Pokemon Constructor" << std::endl;
}

/*************************************************
//
//  Function name: ~Pokemon
//
//  DESCRIPTION:   The destructor of the Pokemon
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
Pokemon::~Pokemon()
{
    std::cout << "Pokemon Destructor" << std::endl;
}

void Pokemon::printData() {}
