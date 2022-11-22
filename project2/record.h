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
//  FILE: record.h
//
//  DESCRIPTION: The header file for a record
//
//  REFERENCES: None.
//
 * **********************************************/

#ifndef RECORD_H
#define RECORD_H

struct record
{
    int             accountno;
    char            name[30];
    char            address[60];
    struct record*  next;
};

#endif