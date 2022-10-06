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
//  DATE:       October 7, 2022
//
//  FILE:       iofunctions.c
//
//  DESCRIPTION: io functions that will write a pokemon array's
//              data to a file and also read and parse that data
//              from the file and store it in another pokemon array.
//
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

/*****************************************************************
//
//  Function name: writefile 
//
//  DESCRIPTION:    Will take an array of pokemons and write to a file.
//
//  Parameters:     pokearray (struct pokemon[]) : the pokemon array that 
//                          will be used to write to the file.
//                  num (int) : the size of the pokemon array.
//                  filename (char[]) : the filename to write to.
//
//  Return values:  0 : successfully opened file and wrote.
//                  -1 : failed to write to file
//
****************************************************************/

int writefile(struct pokemon pokearray[], int num, char filename[])
{
    FILE *file;
    int i, num_char_wrote, result = 0;

    if ((file = fopen(filename, "w")) == NULL)
    {
        result = -1;
    }

    for (i = 0; i < num; i++)
    {
        num_char_wrote = fprintf(file, "%d\n%s\n", (pokearray + i)->level, (pokearray + i)->name);
        if (num_char_wrote < 0)
        {
            result = -1;
        }
    }

    if (fclose(file) == EOF)
    {
        result = -1;
    }
    return result;
}

/*****************************************************************
//
//  Function name:  readfile
//
//  DESCRIPTION:    Will read from a file then parse and store the data
//                  in the given pokemon array. Will store the number of
//                  successfully read pokemon into the num variable
//
//  Parameters:     pokearray (struct pokemon[]) : the pokemon array that
//                              will be used to write to the file.
//                  num (int*) : the maximum number of pokemons to read.
//                              This function will store the number of
//                              successfully read pokemon into num
//                  filename (char[]) : the filename to write to.
//
//  Return values:  0 : successfully opened file and wrote.
//                  -1 : failed to open file. 
//
****************************************************************/

int readfile(struct pokemon pokearray[], int* num, char filename[])
{
    FILE *file;
    int i, j, result = 0, num_pokemon_read = 0, max_pokemon = *num;
    char level[31];
    char name[31];

    /* use feof for checking end of file */
    if ((file = fopen(filename, "r")) == NULL)
    {
        result = -1;
    }

    if (result == 0)
    {
        for (i = 0; i < max_pokemon; i++)
        {
            if (fgets(level, 31, file) != NULL && fgets(name, 31, file) != NULL)
            {
                (pokearray + i)->level = strtol(level, NULL, 10);

                j = 0;
                while (name[j++] != '\n');
                name[j - 1] = '\0';
                strncpy((pokearray + i)->name, name, 30);

                num_pokemon_read++;
            }
            else
            {
                i = max_pokemon;
            }
        }
    }
    *num = num_pokemon_read;

    if (fclose(file) == EOF)
    {
        result = -1;
    }
    return result;
}
