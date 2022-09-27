/*************************************************
//  NAME: River Matsumoto
//
//  HOMEWORK: homework3b
//
//  CLASS: ICS212
//
//  INSTRUCTOR: Ravi Narayan
//
//  DATE: September 24, 2022
//
//  FILE: record.h
//
//  DESCRIPTION: The header file for a record
//
//  REFERENCES: None.
//
 * **********************************************/

struct record
{
    int             accountno;
    char            name[30];
    char            address[60];
    struct record*  next;
};
