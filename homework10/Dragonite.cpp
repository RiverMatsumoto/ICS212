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
//  FILE: Dragonite.cpp
//
//  DESCRIPTION: The implementation of Dragonite
//
//  REFERENCES: Homework details
//
 * **********************************************/

#include "Dragonite.h"
#include <iostream>

/*************************************************
//
//  Function name: Dragonite
//
//  DESCRIPTION:   The constructor of Dragonite
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
Dragonite::Dragonite()
{
    std::cout << "Dragonite Constructor" << std::endl;
    this->type = "Dragon Flying";
    this->weight = 463;
}

/*************************************************
//
//  Function name: ~Dragonite
//
//  DESCRIPTION:   The destructor of Dragonite
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
Dragonite::~Dragonite()
{
    std::cout << "Dragonite Destructor" << std::endl;
}

/*************************************************
//
//  Function name: printData
//
//  DESCRIPTION:   Prints the data of the Dragonite
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/
void Dragonite::printData()
{
    std::cout << "========= Dragonite Data =========" << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Weight (lbs): " << weight << std::endl;
}
