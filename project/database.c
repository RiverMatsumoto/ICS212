/*****************************************************************
//
//  NAME:       River Matsumoto
//
//  HOMEWORK:    project1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 31, 2022 
//
//  FILE:        database.c
//
//  DESCRIPTION: The database function implementations.
//
//  REFERENCES: C textbook.
//
// ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "record.h"

extern int debug_mode;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Adds a record to the database.
//
//  Parameters:    start (struct record **): a pointer to the pointer to the first record in the database
//                  accountno (int): the accountno of the record
//                  name (char[]): the name of the record
//                  address (char[]): the address of the record
//
//  Return values:  none
//
****************************************************************/

void addRecord (struct record **start, int accountno, char name[], char address[])
{
    struct record *new_record = malloc(sizeof(struct record));
    struct record *current;
    struct record *previous;

    if (debug_mode == 1)
    {
        printf("\nDEBUG: called addRecord. Adding record to database.\n");
        printf("DEBUG: Accountno: %d\n", accountno);
        printf("DEBUG: Name: %s\n", name);
        printf("DEBUG: Address: %s\n", address);
    }

    new_record->accountno = accountno;
    strncpy(new_record->name, name, 30);
    strncpy(new_record->address, address, 60);
    new_record->next = NULL;
    
    if (*start == NULL)
    {
        *start = new_record;
    }
    else if (accountno >= (*start)->accountno)
    {
        new_record->next = *start;
        *start = new_record;
    }
    else
    {
        /* iterate to the correct placement of the record */
        current = *start;
        while (accountno < current->accountno && current->next != NULL)
        {
            previous = current;
            current = current->next;
            if (accountno >= current->accountno)
            {
                previous->next = new_record;
                new_record->next = current;
            }
        }
        
        /* Need one last check for when we reach the end of the list */
        if (current->next == NULL)
        {
            if (accountno >= current->accountno)
            {
                previous->next = new_record;
                new_record->next = current;
            }
            else
            {
                current->next = new_record;
            }
        }
    }
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints all the records.
//
//  Parameters:    start (struct record *): a pointer to the first record in the database
//
//  Return values:  none
//
****************************************************************/

void printAllRecords (struct record *start)
{
    struct record *current;

    if (debug_mode == 1)
    {
        printf("DEBUG: Called printAllRecords. Printing all records in database.\n");
    }

    current = start;
    if (start == NULL)
    {
        printf("There are no records in the database\n");
    }
    else
    {
        while (current != NULL)
        {
            printf("Accountno: %d\nName: %s\nAddress: %s\n", current->accountno, current->name, current->address);
            current = current->next;
        }
    }
}

/*****************************************************************
//
//  Function name: findRecord  
//
//  DESCRIPTION:     finds a record in the database and prints it.
//
//  Parameters:    start (struct record *): Points to the first record in the database.
//                  accountno (int): The accountno of the record to find
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/

int findRecord (struct record *start, int accountno)
{
    struct record *current;
    int result;

    if (debug_mode == 1)
    {
        printf("DEBUG: Called findRecord. Finding record: %d\n", accountno);
    }

    current = start;
    while (current != NULL && accountno != current->accountno)
    {
        current = current->next;
    }
    if (current != NULL)
    {
        printf("Record with accountno %d found\n", accountno);
        printf("Accountno: %d\n", current->accountno);
        printf("Name: %s\n", current->name);
        printf("Address: %s\n", current->address);
        result = 0;
    }
    else
    {
        result = -1;
    }
    return result;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Deletes a record in the database.
//
//  Parameters:     start (struct record **): points to the pointer to the first record in the database.
//                  accountno (int): the record(s) accountno to delete
//
//  Return values:  0 : successfully deleted
//                 -1 : record doesn't exist in the database.
//
****************************************************************/

int deleteRecord (struct record **start, int accountno)
{
    struct record *current;
    struct record *previous;
    struct record *to_delete;
    int result;

    if (debug_mode == 1)
    {
        printf("DEBUG: Called deleteRecord. Deleting record: %d\n", accountno);
    }

    if (*start == NULL)
    {
        result = -1;
    }
    else if (accountno == (*start)->accountno)
    {
        current = *start;
        while (current != NULL && accountno == current->accountno)
        {
            to_delete = current;
            current = current->next;
            free(to_delete);
        }
        *start = current;
        result = 0;
    }
    else
    {
        current = *start;
        while (current != NULL && accountno != current->accountno)
        {
            previous = current;
            current = current->next;
        }
        if (current == NULL)
        {
            result = -1;
        }
        else
        {
            while (current != NULL && accountno == current->accountno)
            {
                to_delete = current;
                current = current->next;
                free(to_delete);
            }
            previous->next = current;
            result = 0;
        }
    }

    return result;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes the database to a file
//
//  Parameters:     start (struct record *): pointer to the first record in the database.
//                  filename (char []): filename to write to
//
//  Return values:  0 : successfully wrote to the filename
//                 -1 : unsuccessful write to filename
//
****************************************************************/

int writefile (struct record *start, char filename[])
{
    FILE *file;
    int result;
    struct record *current;

    if (debug_mode == 1)
    {
        printf("Called write, copying the database to disk\n");
        printf("Filename: %s\n", filename);
    }

    if ((file = fopen(filename, "w")) != NULL)
    {
        current = start;
        while (current != NULL)
        {
            fprintf(file, " %d\n%s\n%s~\n", current->accountno, current->name, current->address);
            current = current->next;
        }

        fclose(file);
        result = 0;
    }
    else
    {
        result = -1;
        printf("Couldn't write to the file\n");
    }

    return result;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   reads the file and transfers the data to database.
//
//  Parameters:     start (struct record **): points to a pointer to the first record in the database.
//                  filename (char []): filename to read from
//
//  Return values:  0 : successfully read from the filename
//                 -1 : unsuccessful read from filename
//
****************************************************************/

int readfile (struct record **start, char filename[])
{
    FILE *file;
    int i, result, done_reading = 0;
    int accountno;
    char accountno_text[31];
    char name[31];
    char address[61];
    char buffer[100];
    char address_buffer;

    if (debug_mode == 1)
    {
        printf("Called readfile, parsing the file to add to the database\n");
        printf("Filename: %s\n", filename);
    }
    file = fopen(filename, "r");
    if (file != NULL)
    {
        while (done_reading != 1)
        {
            if (fgetc(file) == EOF)
            {
                done_reading = 1;
            }
            else 
            {
                /* parse accountno, name, and address from the file */
                fgets(accountno_text, 31, file);
                accountno = strtol(accountno_text, NULL, 10);

                fgets(name, 31, file);
                i = 0;
                while (name[i++] != '\n');
                name[i - 1] = '\0';

                for (i = 0; i < 61; i++)
                {
                    address_buffer = fgetc(file);

                    if (address_buffer == '~')
                    {
                        address[i] = '\0';
                        i = 61;
                        /* grab either the space or mark the eof with the fgetc*/
                        fgets(buffer, 100, file);
                    }
                    else
                    {
                        address[i] = address_buffer;
                    }
                }

                addRecord(start, accountno, name, address);
            }
        }

        fclose(file);
        result = 0;
    }
    else
    {
        result = -1;
        printf("Couldn't read from the file\n");
    }

    return result;
}


/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:    cleans up the memory from the database.
//
//  Parameters:     start (struct record **): points to a pointer to the first record in the database.
//
//  Return values:  none
//
****************************************************************/

void cleanup(struct record **start)
{
    struct record *current;
    struct record *to_delete;

    if (debug_mode == 1)
    {
        printf("DEBUG: Called cleanup. Cleaning up memory from the database.\n");
    }

    current = *start;
    if (start == NULL)
    {
        printf("There are no records in the database\n");
    }
    else
    {
        while (current != NULL)
        {
            to_delete = current;
            current = current->next;
            free(to_delete);
        }
        *start = NULL;
    }
}
