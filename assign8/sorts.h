#ifndef SORTS_H
#define SORTS_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::left;
using std::setprecision;
using std::setw;

//Function prototypes:

template <class T> void buildList(std::vector<T>& , const char* );
template <class T> void printList(const std::vector<T>& , int , int);


/****************************************************************

   FUNCTION:   template <class T> void buildList(vector<T>& set, const char* fileName);

   ARGUMENTS:  Takes a reference to a vector object and a C-style string 

   RETURNS:    Nothing

   NOTES:      The function should first open the file for input, then read items from the file using the >> operator one 
               at a time until end of file, inserting them into the vector.
****************************************************************/
template <class T>
void buildList(std::vector<T>& set, const char* filename)
{
   T item;                    /* template parameter type  */
   ifstream inFile;         /* declare file */

  inFile.open(filename);
/* check that the file has been successfully opened, if file is unsuccessful print error message */
   if (!inFile)
     {
      cout << "Unable to open input file " << filename << endl;
      exit(1);
     }

   inFile >> item;           /* read item from input file */

/* while in the file, push the item into the vector */
   while (!inFile.eof())
     {
      set.push_back(item);
      inFile >> item;
     }

  inFile.close();
}


/****************************************************************

   FUNCTION:   template <class T> void printList(const vector<T>& set, int itemWidth, int numPerLine);

   ARGUMENTS:  Takes a reference to a constant vector object, an integer specifying the width, and an
               integer specifying the maximum number of items.

   RETURNS:    Nothing

   NOTES:      This function should print a list of items stored in a vector.
****************************************************************/
template <class T>
void printList(const std::vector<T>& set, int itemWidth, int numPerLine)
{
  int i = 0;
/* in the while loop, print out a list of items stored in a vector  */
   while (i < (int) set.size())
      {
      cout << setw(itemWidth) << set[i] << ' ';
      i++;                                           /* increment subscript */
/* if the maximum number equals zero, create a new line   */
     if (i % numPerLine == 0)
         cout << endl;
      }
/* if the maximum number does not equal zero, create a new line */
   if (i % numPerLine != 0)
      cout << endl;
}

#endif
