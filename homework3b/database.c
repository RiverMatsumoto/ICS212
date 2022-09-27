/*****************************************************************
//
//  NAME:       River Matsumoto
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 24, 2022
//
//  FILE:        database.c
//
//  DESCRIPTION:
//
//  REFERENCES:
//
// ****************************************************************/

#include <stdio.h>
#include "record.h"

extern int debug_mode;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   
//
//  Parameters:    
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/

void addRecord (struct record **rec, int accountno, char name[], char address[])
{
    if (debug_mode == 1)
    {
        printf("\nDEBUG: called addRecord. Adding record to database.\n");
        printf("DEBUG: Accountno: %d\n", accountno);
        printf("DEBUG: Name: %s\n", name);
        printf("DEBUG: Address: %s\n", address);
    }
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   
//
//  Parameters:    
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/

void printAllRecords (struct record *rec)
{
    if (debug_mode == 1)
    {
        printf("DEBUG: Called printAllRecords. Printing all records in database.\n");
    }
}

/*****************************************************************
//
//  Function name: findRecord  
//
//  DESCRIPTION:     
//
//  Parameters:    
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/

int findRecord (struct record *rec, int accountno)
{
    if (debug_mode == 1)
    {
        printf("DEBUG: Called findRecord. Finding record: %d\n", accountno);
    }
    return 0;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   
//
//  Parameters:     
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/

int deleteRecord (struct record **rec, int accountno)
{
    if (debug_mode == 1)
    {
        printf("DEBUG: Called deleteRecord. Deleting record: %d\n", accountno);
    }

    return 0;
}
