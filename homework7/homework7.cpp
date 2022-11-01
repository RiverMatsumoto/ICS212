/*****************************************************************
//
//  NAME:        River Matsumoto
//
//  HOMEWORK:    7
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:       November 5, 2022
//
//  FILE:        homework7.cpp
//
//  DESCRIPTION: Homework 7.
//          prints a list of numbers up to a certain number
//          given by the user and whether it is a multiple of 4.
//
//  REFERENCES: cpp textbook
//
****************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int user_interface();
void print_table(int);
int is_multiple4(int);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:    Takes a maximum number from the user and
//          makes a list of numbers and whether they are 
//          a multiple of 4.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 :  Successfully exited program.
//
****************************************************************/

int main(int argc, char* argv[])
{
    int max_num;
    cout << "This program will print numbers from 0 to a given number and tell whether it is a multiple of 4" << endl << endl;
    max_num = user_interface();
    print_table(max_num);
    return 0;
}

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:    Reads input by the user and will only accept
//      positive integers. Will keep prompting the user until
//      a positive integer is inputted by user.
//
//  Parameters:     none
//
//  Return values:  int : an integer that the user inputted.
//
****************************************************************/

int user_interface()
{
    int input = 0;
    bool gotValidInput;

    while (!gotValidInput)
    {
        cout << "Give a maximum number to print up. Enter positive integers only." << endl;
        cin >> input;
        
        if (input > 0)
        {
            gotValidInput = true;
        }
        else
        {
            cout << "Invalid input. Enter positive integers only" << endl;
            // clear the error flag and clear up to the newline
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    return input;
}

/*****************************************************************
//
//  Function name:  print_table
//
//  DESCRIPTION:    Prints numbers up to a given number and says
//                  whether each number is a multiple of 4.
//
//  Parameters:     max_num (int) : how many numbers to print up to.
//
//  Return values:  none.
//
****************************************************************/

void print_table(int max_num)
{
    cout << "  Number  Multiple of 4?" << endl;
    for (int i = 0; i <= max_num; i++)
    {
        cout << setw(8) << i << " ";

        if (is_multiple4(i))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

/**************************************************************
//
//  Function name:  is_multiple4
//
//  DESCRIPTION:    Takes an integer and determines if it's a
//                  multiple of 4
//
//  Parameters:     num (int) : the integer being tested for
//                              multiples of 4.
//
//  Return values:  0 : given integer is not a multiple of 4.
//                  1 : given integer is a multiple of 4.
//
****************************************************************/

int is_multiple4(int num)
{
    int multiple4;

    if (num % 4 == 0)
    {
        multiple4 = 1;
    }
    else
    {
        multiple4 = 0;
    }

    return multiple4;
}
