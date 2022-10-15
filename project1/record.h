/*************************************************
//  NAME: River Matsumoto
//
//  HOMEWORK: project1
//
//  CLASS: ICS212
//
//  INSTRUCTOR: Ravi Narayan
//
//  DATE: October 31, 2022
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
