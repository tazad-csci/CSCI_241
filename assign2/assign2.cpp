/****************************************************************
   PROGRAM:   CSCI 241 Assignment 2

   DUE DATE:  2/21/19

   FUNCTION:  This part of the assignment introduces the insertion sort
              and binary search algorithms.

   INPUT:     Calls the SellerList.h file which contains class and
              prototypes of the functions.

   OUTPUT:    The program prints out a list of sellers names and
              the sales Transactions they did.

   NOTES:     any relevant information that would be of
              additional help to someone looking at the program
****************************************************************/
#include <iostream>
#include "SellerList.h"
#include<string>
using std::cout;
using std::endl;
using std::string;

int main()
{

    // Test alternate constructor
    SellerList seller1("sellerData");

    // Test print() method and whether constructors
    // properly initialized objects
    cout << "Printing seller2\n\n";
    seller1.print();
    cout << endl << endl;

    seller1.processSalesData("sales.txt");

    seller1.print();

    return 0;
}
