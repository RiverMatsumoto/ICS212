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
//  FILE: main.cpp
//
//  DESCRIPTION: Creates and stores pointers to some pokemon and prints it data from the pokedex
//
//  REFERENCES: Homework details
//
 * **********************************************/

#include "Pokemon.h"
#include "Pikachu.h"
#include "Dragonite.h"
#include "Charizard.h"
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
using namespace std;

void checkPokedex(Pokemon* pokemon);

/*************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Creates and stores pokemon in containers and prints its data from the pokedex
//
//  Parameters:    argc (int): the number of arguments
//                  argv (char*[]): The null terminated argument strings
//
//  Return values:  0: successfully exited
//                  -1: an error occurred in the program
//
// **********************************************/
int main(int argc, char* argv[])
{
    Pokemon* pikachu = new Pikachu();
    Pokemon* dragonite = new Dragonite();
    Pokemon* charizard = new Charizard();

    cout << "Adding nicknames to list and mapping each nickname to a pokemon" << endl;
    vector<string> nicknames;
    nicknames.push_back("Electro Rat");
    nicknames.push_back("Cute Dragon");
    nicknames.push_back("Fire Dragon");
    map<string, Pokemon*> mappings;
    mappings.insert(pair<string, Pokemon*>(nicknames[0], pikachu));
    mappings.insert(pair<string, Pokemon*>(nicknames[1], dragonite));
    mappings.insert(pair<string, Pokemon*>(nicknames[2], charizard));

    cout << endl << "Looping through nicknames and checking the pokedex" << endl;
    for (vector<string>::iterator iter = nicknames.begin(); iter != nicknames.end(); iter++)
    {
        cout << "Checking the pokedex for " << *iter << endl;
        checkPokedex(mappings[*iter]);
    }

    cout << endl << "Clearing heap memory" << endl;
    delete pikachu;
    delete dragonite;
    delete charizard;
    return 0;
}

/*************************************************
//
//  Function name: checkPokedex
//
//  DESCRIPTION:   Prints the data of the pokemon
//
//  Parameters:    pokemon (Pokemon*): The pokemon to print the data for.
//
//  Return values:  none
//
// **********************************************/
void checkPokedex(Pokemon* pokemon)
{
    pokemon->printData();
}
