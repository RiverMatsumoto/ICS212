/*****************************************************************
//
//  NAME:        Ravi Narayan
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 24, 2022
//
//  FILE:        template.c
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
    int i, is_option, min_str_len, is_quitting, is_valid_input, scanf_result;

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
            printf("Only \"debug\" option is allowed.\n");
        }
    }
    else if (argc > 2)
    {
        printf("Only \"debug\" option is allowed.\n");
    }

    printf("This program will access the database to add items, remove items, and read items.\n");
    is_quitting = 0;
    while (is_quitting != 1)
    {
        printf("\nOptions:\n");
        printf("add: Add a new record.\n");
        printf("printall: print all records.\n");
        printf("find: find a specific record.\n");
        printf("delete: remove a specific item.\n");
        printf("quit: exit from the program.\n");
        
        printf("Input: %s\n", input);
        fgets(input, 200, stdin);

        i = 0;
        while (input[i] != '\n')
        {
            i++;
        }
        input[i] = '\0';

        i = 0;
        if (strlen(input) <= strlen(add_option))
        {
            is_option = 1;
            min_str_len = strlen(input);
            for (i = 0; i < min_str_len; i++)
            {
                if (input[i] != add_option[i])
                {
                    is_option = 0;
                }
            }

            if (is_option == 1)
            {
                is_valid_input = 0;
                while (is_valid_input != 1)
                {
                    accountno = 0;
                    printf("\nGive an account number (positive integer):\n");
                    scanf_result = scanf("%d", &accountno);
                    
                    if (scanf_result == 1 && accountno > 0)
                    {
                            is_valid_input = 1;
                    }
                    if (scanf_result < 1 || accountno <= 0)
                    {
                        printf("Give positive integers only\n");
                        fgets(input, 100, stdin);
                    }
                }
                fgets(input, 200, stdin);

                printf("Give a name:\n");
                fgets(name, 30, stdin);
                i = 0;
                while (name[i++] != '\n');
                name[i - 1] = '\0';

                printf("Give an address and enter a backslash ('\\') when finished.\n");
                getaddress(address, 60);

                addRecord(&start, accountno, name, address);
            }
        }
        if (strlen(input) <= strlen(printall_option))
        {
            is_option = 1;
            min_str_len = strlen(input);
            for (i = 0; i < min_str_len; i++)
            {
                if (input[i] != printall_option[i])
                {
                    is_option = 0;
                }
            }
            
            /* call the printall database function and pass the record start in there*/
            printAllRecords(start);
        }
        if (strlen(input) <= strlen(find_option))
        {
            is_option = 1;
            min_str_len = strlen(input);
            for (i = 0; i < min_str_len; i++)
            {
                if (input[i] != find_option[i])
                {
                    is_option = 0;
                }
            }


            /* Get a positive integer and call findRecord with that number */
        }
        if (strlen(input) <= strlen(delete_option))
        {
            is_option = 1;
            min_str_len = strlen(input);
            for (i = 0; i < min_str_len; i++)
            {
                if (input[i] != delete_option[i])
                {
                    is_option = 0;
                }
            }

            /* Get a positive integer and call deleteRecord with that number */
        }
        if (strlen(input) <= strlen(quit_option))
        {
            is_option = 1;
            min_str_len = strlen(input);
            for (i = 0; i < min_str_len; i++)
            {
                if (input[i] != quit_option[i])
                {
                    is_option = 0;
                }
            }

            if (is_option == 1)
            {
                is_quitting = 1;
            }
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
    int i = 0;
    char str_to_delete[100];
    while (i < size - 1 && (str[i] = getchar()) != '\\')
    {
        i++;
    }
    str[i] = '\0';
    fgets(str_to_delete, 100, stdin); /* clean up everything after the backslash character */
}
