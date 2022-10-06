
/*****************************************************************
//
//  NAME:        River Matsumoto
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 7, 2022
//
//  FILE:        driver.c 
//
//  DESCRIPTION: The driver code to test the iofunctions.c functions.
//              This code will be used to attempt to prove that the
//              functions indeed work.
//
****************************************************************/

#include <string.h>
#include <stdio.h>
#include "pokemon.h"
#include "iofunctions.h"

/*****************************************************************
//
//  Function name: main 
//
//  DESCRIPTION:   Tests the iofunctions.c functions to prove 
//                  that they work.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : reached the end of the program successfully
//
****************************************************************/

int main(int argc, char *argv[])
{
    struct pokemon pokemonbank[5];
    struct pokemon bigpokemonbank[7];
    int numpokemons;
    int i, result;
    char filename[30] = "myPokemon";

    /* Set up the test data */
    strcpy(pokemonbank[0].name, "Charizard");
    strcpy(pokemonbank[1].name, "Blastoise");
    strcpy(pokemonbank[2].name, "Mewtwo");
    strcpy(pokemonbank[3].name, "Cubone");
    strcpy(pokemonbank[4].name, "Gengar");
    pokemonbank[0].level = 46;
    pokemonbank[1].level = 63;
    pokemonbank[2].level = 73;
    pokemonbank[3].level = 19;
    pokemonbank[4].level = 37;
    numpokemons = 5;

    printf("NOTE ON TESTS: This driver code will not use any hand-made files to read and write from. It will create it on its own\n\n");
    printf("=======TEST 1 ON writefile FUNCTION=========\n");
    printf("Testing whether the writefile functions successfully creates a file and writes the pokemon data to that file.\n");
    printf("\nSetting up test 1 data\n");
    printf("Pokemon array data (5 pokemons): \n");
    for (i = 0; i < numpokemons; i++)
    {
        printf("Pokemon %d:  name = %-15s  level = %d\n", i, (pokemonbank + i)->name, (pokemonbank + i)->level);
    }
    printf("\n");

    printf("Called writefile function and is attempting to write to \"%s\"\n", filename);
    result = writefile(pokemonbank, numpokemons, filename);
    printf("writefile returned %d\n", result);
    if (result == 0)
    {
        printf("Successfully wrote to the file \"%s\"\n\n", filename);
    }
    else
    {
        printf("Error occured when writing to the file \"%s\"\n\n", filename);
    }

    printf("\n==========TEST 2 ON readfile FUNCTION==========\n");
    printf("Testing whether the readfile function parses the file and stores the data in the pokemon array\n");
    printf("\nSetting up test 2 data\n");
    for (i = 0; i < numpokemons; i++)
    {
        strncpy((pokemonbank + i)->name, "", 30);
        (pokemonbank + i)->level = 0;
    }
    numpokemons = 5;
    printf("Pokemon array data before reading from the file: \n");
    for (i = 0; i < numpokemons; i++)
    {
        printf("Pokemon %d:  name = %-15s  level = %d\n", i, (pokemonbank + i)->name, (pokemonbank + i)->level);
    }

    printf("\nCalling the readfile function\n");
    result = readfile(pokemonbank, &numpokemons, filename);
    printf("readfile returned %d\n", result);
    if (result == 0)
    {
        printf("Successfully opened file in readfile function\n");
        printf("\nPokemon array data after attempting to read from the file: \n");
        for (i = 0; i < numpokemons; i++)
        {
            printf("Pokemon %d:  name = %-15s  level = %d\n", i, (pokemonbank + i)->name, (pokemonbank + i)->level);
        }
    }
    else
    {
        printf("Error occured when writing to file with given data\n");
    }

    printf("Checking for correct number of pokemon read from the file.\n");
    if (numpokemons == 5)
    {
        printf("Successfully read the correct number of pokemon from the file. Expected 5 pokemon\n\n");
    }
    else
    {
        printf("Number of pokemons read from the file are incorrect. Expected 5 pokemon\n\n");
    }

    printf("===========TEST 3 ON writefile WITH 7 POKEMONS===========\n");
    printf("Testing whether the writefile function will overwrite the previous file with another set of pokemons\n");
    /* different pokemon added, then test readfile where there are only 5 array slots */
    printf("Setting up test 3 data\n");
    /* Set up the test data */
    strcpy(bigpokemonbank[0].name, "Charmander");
    strcpy(bigpokemonbank[1].name, "Seal");
    strcpy(bigpokemonbank[2].name, "Lugia");
    strcpy(bigpokemonbank[3].name, "Driftloon");
    strcpy(bigpokemonbank[4].name, "Geodude");
    strcpy(bigpokemonbank[5].name, "Pikachu");
    strcpy(bigpokemonbank[6].name, "Staraptor");
    bigpokemonbank[0].level = 13;
    bigpokemonbank[1].level = 27;
    bigpokemonbank[2].level = 65;
    bigpokemonbank[3].level = 19;
    bigpokemonbank[4].level = 28;
    bigpokemonbank[5].level = 38;
    bigpokemonbank[6].level = 47;
    numpokemons = 7;

    printf("Pokemon array data (7 pokemons): \n");
    for (i = 0; i < numpokemons; i++)
    {
        printf("Pokemon %d:  name = %-15s  level = %d\n", i, (bigpokemonbank + i)->name, (bigpokemonbank + i)->level);
    }
    printf("\n");


    printf("Called writefile function with above data\n");
    result = writefile(bigpokemonbank, numpokemons, filename);
    if (result == 0)
    {
        printf("Successfully wrote to file with given data\n\n");
    }
    else
    {
        printf("Error occured when writing to file with given data\n\n");
    }

    printf("\n===========TEST 4 ON readfile===========\n");
    printf("Testing that the readfile will not store more than the array can hold (max 5 pokemons) even though the file has 7 pokemon\n");
    /* different pokemon added, then test readfile where there are only 5 array slots */
    printf("Setting up test 4 data\n");
    /* Set up the test data */
    strcpy(pokemonbank[0].name, "");
    strcpy(pokemonbank[1].name, "");
    strcpy(pokemonbank[2].name, "");
    strcpy(pokemonbank[3].name, "");
    strcpy(pokemonbank[4].name, "");
    pokemonbank[0].level = 0;
    pokemonbank[1].level = 0;
    pokemonbank[2].level = 0;
    pokemonbank[3].level = 0;
    pokemonbank[4].level = 0;
    numpokemons = 5;

    printf("Pokemon array data before reading the file (array size = 5): \n");
    for (i = 0; i < numpokemons; i++)
    {
        printf("Pokemon %d:  name = %-15s  level = %d\n", i, (pokemonbank + i)->name, (pokemonbank + i)->level);
    }
    printf("\n");


    printf("Called writefile function with above data\n");
    result = readfile(pokemonbank, &numpokemons, filename);
    printf("writefile returned %d\n", result);
    if (result == 0)
    {
        printf("Successfully wrote to file with given data\n\n");
    }
    else
    {
        printf("Error occured when writing to file with given data\n\n");
    }

    printf("\nPokemon array data after reading the file (array size = 5): \n");
    for (i = 0; i < numpokemons; i++)
    {
        printf("Pokemon %d:  name = %-15s  level = %d\n", i, (pokemonbank + i)->name, (pokemonbank + i)->level);
    }
    printf("\n");

    return 0; 
}
