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
//  FILE: Pikachu.cpp
//
//  DESCRIPTION: The implementation of Pikachu
//
//  REFERENCES: Homework details
//
 * **********************************************/

#include "Pikachu.h"
#include <iostream>

/*************************************************
//
//  Function name: Pikachu
//
//  DESCRIPTION:   The constructor of Pikachu
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
Pikachu::Pikachu()
{
    std::cout << "Pikachu Constructor" << std::endl;
    this->type = "Electric";
    this->weight = 13.2;
}

/*************************************************
//
//  Function name: ~Pikachu
//
//  DESCRIPTION:   The destructor of Pikachu
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
Pikachu::~Pikachu()
{
    std::cout << "Pikachu Destructor" << std::endl;
}

/*************************************************
//
//  Function name: printData
//
//  DESCRIPTION:   Prints the data of the pikachu
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
void Pikachu::printData()
{
    std::cout << "========= Pikachu Data =========" << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Weight (lbs): " << weight << std::endl;
}