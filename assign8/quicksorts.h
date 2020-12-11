#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

template <class T> bool lessThan(const T& item1, const T& item2);
template <class T> bool greaterThan(const T& item1, const T& item2);
template <class T> void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));
template <class T> void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));
template <class T> int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));


/****************************************************************

   FUNCTION:   template <class T> bool lessThan(const T& item1, const T& item2);

   ARGUMENTS:  Takes two const item templates

   RETURNS:    Returns true or false

   NOTES:      You may assume that the data type T can be compared using the standard relational operators.
****************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
  return (item1 < item2);  /* return true if item1 is less than item2, else false if not */
}


/****************************************************************

   FUNCTION:   template <class T> bool greaterThan(const T& item1, const T& item2);

   ARGUMENTS:

   RETURNS:    Return true or and false

   NOTES:      You may assume that the data type T can be compared using the standard relational operators.
****************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
  return (item1 > item2);   /* return true if item1 is greater than item2, else false if not */
}


/****************************************************************

   FUNCTION:   template <class T> void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));

   ARGUMENTS:  Takes a reference to a vector object and a pointer to a comparison function to compare two items of the template type.

   RETURNS:    Nothing

   NOTES:      This function should call the recursive quick sort function, passing it the vector, the
               subscript of the first vector element, the subscript of the last vector element, and the
               pointer to the comparison function.
****************************************************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
  quickSort(set, 0, set.size()-1, compare);  /* sort the items in the vector using the quick sort algorithm */
}


/****************************************************************

   FUNCTION:   template <class T> void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

   ARGUMENTS:  Takes a reference to a vector object, two integers representing the start and end points,
               and a pointer to a comparison function to compare two items of the template type.

   RETURNS:    Nothing

   NOTES:      This function performs the recursive calls to implement the quick sort algorithm.
*****************************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
 int pivotPoint;

/* if start is less than end, get the pivot point, sort first sublist and sort the second sublist */
 if (start < end)
   {
     pivotPoint = partition(set, start, end, compare);
     quickSort(set, start, pivotPoint - 1, compare);
     quickSort(set, pivotPoint + 1, end, compare);
   }
}


/****************************************************************

   FUNCTION:   template <class T> int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

   ARGUMENTS:  Takes a reference to a vector object, two integers representing the start and end points,
               and a pointer to a comparison function to compare two items of the template type.

   RETURNS:    Returns an integer

   NOTES:      This function selects a pivot element and then partitions the vector around the pivot.
****************************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
  int pivotIndex, mid;    /* declare integers  */
  T pivotValue;

  mid = (start + end) / 2;   /* find the mid point of the vector */

  swap (set[start], set[mid]);   /* swap elements start and mid of the vector  */

  pivotIndex = start;
  pivotValue = set[start];

/* In the for loop, swap elements pivotIndex and scan of the vector */
 for (int scan = start + 1; scan <= end; scan++)
   {
/* compare the two index values and push the index that is greater */
     if (compare(set[scan], pivotValue))
       {
         ++pivotIndex;                              /* increment subscript */
         swap (set[pivotIndex], set[scan]);
       }
   }

  swap(set[start], set[pivotIndex]);        /* swap elements start and pivotIndex of the vector  */

  return pivotIndex;

}

#endif
