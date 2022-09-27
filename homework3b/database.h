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
//  FILE: database.h
//
//  DESCRIPTION: The header file for the database
//
//  REFERENCES: None.
//
 * **********************************************/

void addRecord(struct record **, int, char[], char[]);
void printAllRecords(struct record *);
int findRecord(struct record *, int);
int deleteRecord(struct record **, int);
