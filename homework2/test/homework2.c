/*****************************************************************
//
//  NAME:        River Matsumoto
//
//  HOMEWORK:    2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 9, 2022
//
//  FILE:        homework2.c
//
//  DESCRIPTION: Homework 2.
//          prints a list of numbers up to a certain number
//          given by the user and whether it is a multiple of 4.
//
//  REFERENCES: C Textbook Section 7.4
//      Lab0126 in laulima resources io_prac.c and io_prac2.c
//
****************************************************************/

#include <stdio.h>

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
    printf("This program will print numbers from 0 to a given number and tell whether it is a multiple of 4\n\n");
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
    int max_num, result;
    char invalid_input[100];
    
    max_num = 0;
    while (max_num < 1)
    {
        printf("Enter the maximum number to show\n");
        result = scanf("%d", &max_num);
        
        if (result < 1 || max_num < 1)
        {
            printf("Invalid input. Only POSITIVE INTEGERS are allowed.\n");
            fgets(invalid_input, 100, stdin);
        }
    }

    return max_num;
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
    int i;

    printf("  Number  Multiple of 4?\n");
    for (i = 0; i <= max_num; i++)
    {
        printf("%8d  ", i);

        if (is_multiple4(i))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
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
