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
//  FILE: Charizard.h
//
//  DESCRIPTION: The class definition of Charizard inherits from Pokemon
//
//  REFERENCES: Homework details
//
 * **********************************************/

#include "Pokemon.h"

#ifndef CHARIZARD_H
#define CHARIZARD_H

class Charizard : public Pokemon
{
public:
    Charizard();
    virtual ~Charizard();
    void printData();
};

#endif // CHARIZARD_H