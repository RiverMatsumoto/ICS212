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
//  FILE: Pikachu.h
//
//  DESCRIPTION: The class definition of Pikachu inherits from Pokemon
//
//  REFERENCES: Homework details
//
 * **********************************************/

#include "Pokemon.h"

#ifndef PIKACHU_H
#define PIKACHU_H

class Pikachu : public Pokemon
{
public:
    Pikachu();
    virtual ~Pikachu();
    void printData();
};

#endif // PIKACHU_h
