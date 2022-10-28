/*****************************************************************
//
//  NAME:        River Matsumoto
//
//  HOMEWORK:    project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 31, 2022
//
//  FILE:        user_interface.c
//
//  DESCRIPTION: The user interface for the database.
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "record.h"
#include "database.h"

int debug_mode;

void getaddress (char [], int);
int compare_option (char [], char []);
int get_positive_int ();

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:    Gets the option for the database from user 
//                  and calls to the database functions.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program. 
//
//  Return values:  0 : program ended successfully 
//
****************************************************************/

int main(int argc, char* argv[])
{
    struct record *start = NULL;
    char name[30];
    char address[60];
    int accountno;
    char add_option[] = "add";
    char printall_option[] = "printall";
    char find_option[] = "find";
    char delete_option[] = "delete";
    char quit_option[] = "quit";
    char input[200] = "";
    char database_file_path[30] = "save_file";
    int i, is_quitting, file_read, file_wrote;

    printf("This program will access the database to add items, remove items, and read items.\n");

    is_quitting = 0;
    debug_mode = 0;
    if (argc == 2)
    {
        if (strcmp(argv[1], "debug") == 0)
        {
            printf("Entered debug mode.\n");
            debug_mode = 1;
        }
        else
        {
            printf("Only a single \"debug\" option is allowed. The program will exit.\n");
            is_quitting = 1;
        }
    }
    else if (argc > 2)
    {
        printf("Only a single \"debug\" option is allowed. The program will exit.\n");
        is_quitting = 1;
    }

    if (is_quitting != 1)
    {
        file_read = readfile(&start, database_file_path);
        
        if (file_read == 0)
        {
            printf("Database file loaded and stored in database\n\n");
        }
        else
        {
            printf("There was no file to read from for the database\n\n");
        }
    }

    while (is_quitting != 1)
    {
        printf("\nType an option below and press enter:\n");
        printf("add: Add a new record.\n");
        printf("printall: print all records.\n");
        printf("find: find a specific record.\n");
        printf("delete: remove a specific item.\n");
        printf("quit: exit from the program.\n");
        
        fgets(input, 200, stdin);
        i = 0;
        while (input[i] != '\n')
        {
            i++;
        }
        input[i] = '\0';

        if (compare_option(input, add_option) == 1)
        {
            /* Get accountno, name, and address. Then add the record to database */
            accountno = get_positive_int();

            printf("Give a name:\n");
            fgets(name, 30, stdin);
            i = 0;
            while (name[i++] != '\n');
            name[i - 1] = '\0';

            printf("Give an address and enter a tilde (~) when finished.\n");
            getaddress(address, 60);

            printf("\nAdding to database\n");
            addRecord(&start, accountno, name, address);
        }
        if (compare_option(input, printall_option) == 1)
        {
            /* call the printall database function and pass the record start in there*/
            printf("\nPrinting all records\n\n");
            printAllRecords(start);
        }
        if (compare_option(input, find_option) == 1)
        {
            /* Get a positive integer and call findRecord with that number */
            accountno = get_positive_int();
            printf("\nFinding record: %d\n\n", accountno);
            findRecord(start, accountno);
        }
        if (compare_option(input, delete_option) == 1)
        {
            /* Get a positive integer and call deleteRecord with that number */
            accountno = get_positive_int();
            printf("\nDeleting record: %d\n\n", accountno);
            deleteRecord(&start, accountno);
        }
        if (compare_option(input, quit_option) == 1)
        {
            is_quitting = 1;

            file_wrote = writefile(start, database_file_path);
            cleanup(&start);

            if (file_wrote == 0)
            {
                printf("\nSuccessfully saved database to file\n");
            }
            else
            {
                printf("\nError saving the database to a file\n");
            }
            printf("Program will now exit\n");
        }
    }

    return 0;
}

/*****************************************************************
//
//  Function name:  getaddress 
//
//  DESCRIPTION:    gets an address from the stdin. Will read
//          from the stdin buffer until a backslash '\\' is encountered.
//
//  Parameters:     str (char []) : The string to store the address in
//                  size (int): The maximum size of the string
//
//  Return values:  none 
//
****************************************************************/

void getaddress (char str[], int size)
{
    int i;
    char char_to_del;

    i = 0;
    while (i < size - 1 && (str[i] = getchar()) != '~')
    {
        i++;
    }
    str[i] = '\0';

    /* Clear the buffer */
    while ((char_to_del = getchar()) != EOF && char_to_del != '\n');
}

/*****************************************************************
//
//  Function name:  get_positive_int
//
//  DESCRIPTION:    Will keep prompting the user in the until
//              given a positive integer.
//
//  Parameters:     none
//
//  Return values:  A positive integer that the user inputted.
//
****************************************************************/

int get_positive_int ()
{
    int num_input, result, char_to_del;
    
    num_input = 0;
    while (num_input <= 0)
    {
        printf("Enter a positive integer:");
        result = scanf("%d", &num_input);
        
        if (result < 1 || num_input < 1)
        {
            printf("Invalid input. Only POSITIVE INTEGERS are allowed.\n");
            while ((char_to_del = getchar()) != EOF && char_to_del != '\n');
        }
    }

    /* clear the buffer */
    while ((char_to_del = getchar()) != EOF && char_to_del != '\n');
    return num_input;
}

/*****************************************************************
//
//  Function name:  compare_option 
//
//  DESCRIPTION:    Compares an input string to the option string. An
//              input string is equal to the option if it's length is
//              less than or equal to the option string, and if every character
//              in input is equal to the option string's corresponding index.
//
//  Parameters:     input (char []) : The string to store the address in
//                  option (char []): The maximum size of the string
//
//  Return values:  1 : if the input is equal to the option
//                  0 : if the input is not equal to the option
//
****************************************************************/

int compare_option (char input[], char option[])
{
    int min_str_len, i, result = 1;
    
    if (strlen(input) <= strlen(option))
    {
        min_str_len = strlen(input);
        for (i = 0; i < min_str_len; i++)
        {
            if (input[i] != option[i])
            {
                result = 0;
            }
        }
    }
    else
    {
        result = 0;
    }
    
    return result;
}
