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
//  FILE: user_interface.cpp
//
//  DESCRIPTION: The user interface for the database.
//
//  REFERENCES: None.
//
 * **********************************************/

#include "llist.h"
#include <iostream>
#include <string>
#include <cstring>

int getPositiveInt();
void getaddress(char[], int);
bool compareOption(std::string&, const std::string&);

/*************************************************
//
//  Function name: main
//
//  DESCRIPTION:   The entry point of the database. The user interface
//
//  Parameters:    argc (int): the number of arguments
//                  argv (char*[]): The null terminated argument strings
//
//  Return values:  0: successfully exited
//                  -1: an error occurred in the program
//
// **********************************************/
int main(int argc, char *argv[])
{
    const int MAX_NAME_LEN = 30;
    const int MAX_ADDRESS_LEN = 60;
    int accountno;
    std::string name;
    std::string address;
    std::string input;
    char filename[] = "database.txt";
    llist database(filename);

#ifdef DEBUGMODE
    std::cout << "===>DEBUG Running DEBUG release" << std::endl;
#endif
    std::cout << "This program will let you add, delete, and find records in the database." << std::endl << std::endl;

    bool isQuitting = false;
    while (!isQuitting)
    {
        std::cout << std::endl << "Type and option below and press enter: " << std::endl;
        std::cout << "add: add a new record" << std::endl;
        std::cout << "printall: print all records in database." << std::endl;
        std::cout << "find: find a record" << std::endl;
        std::cout << "delete: remove a record" << std::endl;
        std::cout << "quit: exit from the program" << std::endl;

        std::cout << "What option do you choose?" << std::endl;
        std::getline(std::cin, input);
        std::cin.clear();

        if (compareOption(input, "add"))
        {
            // get accountno
            accountno = getPositiveInt();

            // get name
            std::cout << "Give your name: " << std::endl;
            std::getline(std::cin, name);
            char name_temp[30];
            strncpy(name_temp, name.c_str(), MAX_NAME_LEN);

            // get address
            char address_temp[60];
            getaddress(address_temp, MAX_ADDRESS_LEN);

            std::cout << "============Adding record to the database============" << std::endl;
            database.addRecord(accountno, name_temp, address_temp);
        }
        else if (compareOption(input, "printall"))
        {
            std::cout << std::endl;
            std::cout << "===========Printing all records==========" << std::endl;
            std::cout << database;
        }
        else if (compareOption(input, "find"))
        {
            std::cout << std::endl;
            std::cout << "=========Finding Record=========" << std::endl;
            accountno = getPositiveInt();
            database.findRecord(accountno);

        }
        else if (compareOption(input, "delete"))
        {
            std::cout << std::endl;
            std::cout << "==========Deleting a record==========" << std::endl;
            accountno = getPositiveInt();
            database.deleteRecord(accountno);
        }
        else if (compareOption(input, "quit"))
        {
            std::cout << std::endl;
            std::cout << "=======Exiting program=======" << std::endl;
            isQuitting = true;
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

void getaddress(char str[], int size)
{
    std::cout << "Give your address and enter a tilde (~) to mark the end:" << std::endl;
    std::cin.getline(str, size, '~');
    std::cin.ignore(100, '\n');
}

/*****************************************************************
//
//  Function name:  get_positive_int
//
//  DESCRIPTION:    Will keep prompting the user in the until
//              given a positive integer.
//
//  Parameters:     none
//
//  Return values:  A positive integer that the user inputted.
//
****************************************************************/

int getPositiveInt()
{
    int input = 0;
    bool gotValidInput = false;

    while (!gotValidInput)
    {
        std::cout << "Give a positive number: " << std::endl;
        std::cin >> input;

        if (input > 0)
        {
            gotValidInput = true;
        }
        else
        {
            std::cout << "Invalid input. Enter positive integers only" << std::endl;
        }
        // clear the error flag and clear up to the newline
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    return input;
}

/*****************************************************************
//
//  Function name:  compare_option
//
//  DESCRIPTION:    Compares an input string to the option string. An
//              input string is equal to the option if it's length is
//              less than or equal to the option string, and if every character
//              in input is equal to the option string's corresponding index.
//
//  Parameters:     input (std::string) : The input to compare
//                  option (const std::string): The options string to compare to
//
//  Return values:  true (bool): if the input is equal to the option
//                  false (bool): if the input is not equal to the option
//
****************************************************************/

bool compareOption(std::string& input, const std::string& option)
{
    bool result = true;
    if (input.length() <= option.length())
    {
        for (int i = 0; i < (int)input.length(); i++)
        {
            if (input[i] != option[i])
            {
                result = false;
            }
        }
    }
    else
    {
        result = false;
    }

    return result;
}
