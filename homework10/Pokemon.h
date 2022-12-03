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
//  FILE: Pokemon.h
//
//  DESCRIPTION: The header file of Pokemon
//
//  REFERENCES: Homework details
//
 * **********************************************/

#include <string>

#ifndef POKEMON_H
#define POKEMON_H

class Pokemon
{
public:
   Pokemon();
   virtual ~Pokemon();
   virtual void printData();

protected:
    std::string type; // e.g, electric, poison, etc
    float weight;
};


#endif
