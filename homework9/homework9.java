
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
//  FILE: homework9.java
//
//  DESCRIPTION: The java user interface 
//
//  REFERENCES: None.
//
// * **********************************************/

import java.util.Scanner;

public class homework9
{
    static
    {
        System.loadLibrary("homework9");
    }

    /*************************************************
    //
    //  Function name: main
    //
    //  DESCRIPTION:    A program to print a table of numbers that are a multiple of 4
    //
    //  Parameters:     args (String[]): Command line arguments
    //
    //  Return values:  void
    //
    // **********************************************/
    public static void main(String[] args)
    {
        System.out.println("This program will print multiples of 4 up to an inputted number");
        int maxNumToPrint = user_interface();
        print_table(maxNumToPrint);

    }

    private static native int is_multiple4(int num);

    /*************************************************
    //
    //  Function name: user_interface
    //
    //  DESCRIPTION:    The user interface to get a positive integer
    //
    //  Parameters:    none
    //
    //  Return values:  a positive integer
    //
    // **********************************************/
    private static int user_interface()
    {
        Scanner scanner = new Scanner(System.in);
        boolean gotValidInput = false;
        int maxNum = 0;

        while (!gotValidInput)
        {
            System.out.println("Give a positive integer");
            String input = scanner.nextLine();

            Integer parsedNum = Integer.parseInt(input, 10);
            if (parsedNum != null)
            {
                if (parsedNum > 0)
                {
                    maxNum = parsedNum;
                    gotValidInput = true;
                }
                else
                {
                    System.out.println("Invalid Input. Only positive integers are allowed");
                }
            }
        }

        return maxNum;
    }

    /*************************************************
    //
    //  Function name: print_table
    //
    //  DESCRIPTION:    Prints the table of numbers that are multiples of 4
    //
    //  Parameters:    max (int): The maximum number to print up to
    //
    //  Return values:  void
    //
    // **********************************************/
    private static void print_table(int max)
    {
        System.out.printf("%8s %s%n", "Number", "Multiple of 4?");

        for (int i = 0; i <= max; i++)
        {
            if (is_multiple4(i) == 1)
            {
                System.out.printf("%8d %-20s%n", i, "Yes");
            }
            else
            {
                System.out.printf("%8d %-20s%n", i, "No");
            }
        }

    }
}
