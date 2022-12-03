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
//  FILE: Charizard.cpp
//
//  DESCRIPTION: The implementation of Charizard
//
//  REFERENCES: Homework details
//
 * **********************************************/

#include "Charizard.h"
#include <iostream>

/*************************************************
//
//  Function name: Charizard
//
//  DESCRIPTION:   The constructor of Charizard
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
Charizard::Charizard()
{
    std::cout << "Charizard Constructor" << std::endl;
    this->type = "Fire Flying";
    this->weight = 200;
}

/*************************************************
//
//  Function name: ~Charizard
//
//  DESCRIPTION:   The destructor of Charizard
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
Charizard::~Charizard()
{
    std::cout << "Charizard Destructor" << std::endl;
}

/*************************************************
//
//  Function name: printData
//
//  DESCRIPTION:   Prints the data of the Charizard
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
void Charizard::printData()
{
    std::cout << "========= Charizard Data =========" << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Weight (lbs): " << weight << std::endl;
}