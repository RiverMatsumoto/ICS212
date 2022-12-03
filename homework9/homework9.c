/*************************************************
//  NAME: River Matsumoto
//
//  HOMEWORK: homework9
//
//  CLASS: ICS212
//
//  INSTRUCTOR: Ravi Narayan
//
//  DATE: Decemter 3, 2022
//
//  FILE: homework9.c
//
//  DESCRIPTION: The c library
//
//  REFERENCES: None.
//
// * **********************************************/

#include "homework9.h"
#include <stdio.h>

/*************************************************
//
//  Function name: Java_homework9_is_1multiple4
//
//  DESCRIPTION:   Checks whether the given number is a multiple of 4
//
//  Parameters:    env (JNIEnv*): The java environment
//                  homework9 (jclass): The class that uses this method
//                  num (jint): A java integer
//
//  Return values:  1 (int): The given number is a multiple of 4
//                  0 (int): The given numebr is not a multiple of 4
//
// **********************************************/
JNIEXPORT jint JNICALL 
Java_homework9_is_1multiple4 (JNIEnv *env, jclass homework9, jint num)
{
    int result;
    if ((num % 4) == 0)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    
    return result;
}
