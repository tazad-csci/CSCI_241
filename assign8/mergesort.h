#ifndef MERGESORT_H
#define MERGESORT_H


#include <iostream>
#include <vector>

template <class T> void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&));
template <class T> void mergeSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));
template <class T> void merge(vector<T>& set, int start, int mid, int end, bool (*compare)(const T&, const T&));

/****************************************************************

   FUNCTION:   template <class T> void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&));

   ARGUMENTS:  Takes a reference to a vector object and a pointer to a comparison function used to compare
               two items of the template type

   RETURNS:    Nothing

   NOTES:      This function should call the recursive merge sort function, passing it the vector, the
               subscript of the first vector element, the subscript of the last vector element, and the
               pointer to the comparison function.
****************************************************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
  mergeSort(set, 0, set.size()-1, compare);  /* sort the items using the merge sort algorithm  */
}


/****************************************************************

   FUNCTION:   template <class T> void mergeSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

   ARGUMENTS:  Takes a reference to a vector object, two integers representing the start and end points,
               and a pointer to a comparison function to compare two items of the template type.

   RETURNS:    Nothing

   NOTES:      This recursive function divides a vector into two subvectors, sorts them, and then
               merges the two sorted subvectors.
****************************************************************/
template <class T>
void mergeSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
int mid;   /* declare integer */

/* if the loop hasn't reached the end, divide a vector into two subvectors, sort them, and
   then merge the two sorted subvectors  */
   if (start < end)
      {
      mid = (start + end) / 2;

      /* Divide and conquer */
      mergeSort(set, start, mid, compare);
      mergeSort(set, mid+1, end, compare);

      /* Combine */
      merge(set, start, mid, end, compare);
      }
   }


/****************************************************************

   FUNCTION:   template <class T> void merge(vector<T>& set, int start, int mid, int end, bool (*compare)(const T&, const T&));

   ARGUMENTS:  Takes a reference to a vector object, two integers representing the start and end points,
               and a pointer to a comparison function to compare two items of the template type.

   RETURNS:    Nothing

   NOTES:      This function merges two sorted subvectors..
****************************************************************/
template <class T>
void merge(vector<T>& set, int start, int mid, int end, bool (*compare)(const T&, const T&))
{
 /* Create temporary vector to hold merged subvectors */
   vector<T> temp(end - start + 1);


   int i = start;            /* subscript for start of left sorted subvector */
   int j = mid + 1;          /* subscript for start of right sorted subvector */
   int k = 0;                /* subscript for start of merged vector */


   /* while not at the end of either subvector */
   while (i <= mid && j <= end)
      {
  /* in the if statement, compare the two elements and return the greater value */
      if (compare(set[i], set[j]))
         {
          temp[k] = set[i];
          i++;
          k++;
         }
      else
         {
          temp[k] = set[j];
          j++;
          k++;
         }
      }

   /* copy over any remaining elements of left subvector */
   while (i <= mid)
      {
       temp[k] = set[i];
       i++;
       k++;
      }

   /* copy over any remaining elements of right subvector */
   while (j <= end)
      {
       temp[k] = set[j];
       j++;
       k++;
      }

   /* in the for loop, copy merged elements back into original vector */
   for (i = 0, j = start; j <= end; i++, j++)
      set[j] = temp[i];

}

#endif
