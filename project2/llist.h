/*************************************************
//  NAME: River Matsumoto
//
//  HOMEWORK: project2
//
//  CLASS: ICS212
//
//  INSTRUCTOR: Ravi Narayan
//
//  DATE: November 26, 2022
//
//  FILE: llist.h
//
//  DESCRIPTION: The header file for llist
//
//  REFERENCES: None.
//
 * **********************************************/

#ifndef LLIST_H
#define LLIST_H

#include <string>
#include <fstream>
#include "record.h"

class llist {
public:
    llist();
    llist(char[]);
    llist(const llist&);
    ~llist();
    void addRecord(int, char [],char []);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
    llist& operator=(const llist&);
    friend std::ostream& operator<<(std::ostream&, const llist&);

private:
    record *    start;
    char        filename[20];
    int         readfile();
    int         writefile();
    void        cleanup();
};

#endif