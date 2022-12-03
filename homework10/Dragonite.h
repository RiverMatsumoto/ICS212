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
//  FILE: Dragonite.h
//
//  DESCRIPTION: The class definition of Dragonite inherits from Pokemon
//
//  REFERENCES: Homework details
//
 * **********************************************/

#include "Pokemon.h"

#ifndef DRAGONITE_H
#define DRAGONITE_H

class Dragonite : public Pokemon
{
public:
    Dragonite();
    virtual ~Dragonite();
    void printData();
};


#endif // DRAGONITE_H