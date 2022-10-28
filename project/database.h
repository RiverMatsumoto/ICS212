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
int writefile(struct record*, char[]);
int readfile(struct record**, char[]);
void cleanup(struct record**);
