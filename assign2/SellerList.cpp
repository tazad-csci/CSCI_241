#include "SellerList.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using std::cout;
using std::string;
using std::ifstream;
using namespace std;

/****************************************************************

   FUNCTION:   SellerList();

   ARGUMENTS:  None

   RETURNS:    Constuctors do not have a return data type

   NOTES:      This constuctor is called to create an empty database
               so this mehod should set the number of seller data member
               to zero
****************************************************************/
SellerList::SellerList() //default contructor
  {

  }


/****************************************************************

   FUNCTION:   SellerList(const string& fileName);

   ARGUMENTS:  A C++ string that will not be changed the method that has
               the name of the input file of seller data

   RETURNS:    Constructors do not have a return type

   NOTES:      This constructor should declare and open a input file stream,
               read the database file into your SellerList object
***************************************************************/
SellerList::SellerList(const string& fileName) //initializes the data members of the SellerList
  {
    ifstream inFile;

    /* Open the input file and test for failure*/
    inFile.open(fileName);
    if (!inFile)
     {
      cerr << "Error - unable to open input file " << fileName << endl;
      exit(1);
     }

     /* Read the database file into your SellerList object*/ 
     inFile.read((char*) this, sizeof(SellerList));

     /* Close the file stream*/
     inFile.close();

     /* Call to the sortSeller()*/
     sortSellers();
  }


/****************************************************************

   FUNCTION:   SortSeller();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      This method sorts the array of Seller objects in
               ascending order by name
****************************************************************/
void SellerList::sortSellers()
  {
    int i, j;                                  /* subscripts */
    Seller bucket,temp;                        /* elements of the Seller class */


 /* While in the for loop, this will sort the array of Seller objects that were read in from 
    the input file    */
    for (i = 1; i < numSellers; i++)
      {
        bucket = sellers[i];                   /* Swaps the name into bucket*/



/* While in the For loop, swap elements of the array of Seller object whenever, sellers is greater
   than the bucket array using strcmp() to compare. Use getName() to access the data member within
   each Seller object*/
       for (j = i; (j > 0) && (strcmp(sellers[j-1].getName(), bucket.getName()) > 0); j--)
       {
        temp = bucket;                       /* temporary storage of the lowest name*/
        sellers[j] = sellers[j-1];           /* put sellers name into */
        sellers[j-1] = temp;
       }
     }
  }


/****************************************************************

   FUNCTION:   searchForSeller(const char* searchName) const;

   ARGUMENTS:  A C string that will not be changed by this medthod
               that conatins a name to search for

   RETURNS:    If successful, it returns  the index of the array
               element that has the account number that was searched,
               else -1 if the search fails

   NOTES:      This method does not modify the object for which it is
               called and is therefore declared to be const.
****************************************************************/
int SellerList::searchForSeller(const char* searchName) const 
  {
   int low = 0;                                     /* subscript of the lowest in the array */
   int high = numSellers - 1;                       /* number of valid Seller objects in the array */
   int mid;                                         /* subscript */


  /* In the While loop, find out which subscript the searchname is located in by comparing it to the
     Seller object */
   while (low <= high)
      {
      mid = (low + high) / 2;                          /* find the middle subscript */


  /* if the searchname is found to be the same as the sellers[mid], return the subscript named mid */
      if (strcmp(searchName,sellers[mid].getName())== 0)
           return mid;


  /* if the searchname is less than the sellers[mid], subtract the mid by one, else searchname is 
     greater, so add one to mid */
      if (strcmp(searchName,sellers[mid].getName())< 0)
         high = mid - 1;

      else
         low = mid + 1;

      }

   return -1;                            //send -1 if search is a fail
}


/****************************************************************

   FUNCTION:   processSalesData(const string& fileName);

   ARGUMENTS:  A C++ string that won't change and that contains the
               name of a file of sales data

   RETURNS:    Nothing

   NOTES:      This method will read and search for a seller name, for each sales record. If
               found, the sales amount to the sales total for the seller. If the name isn't
               an error message should be shown. series of sales records, each containing a
               last name,a first name, and a sales amount.

****************************************************************/
void SellerList::processSalesData(const string& fileName)
  {
   ifstream inFile;                        /* declare inFile  */
   char lastName[21];                      /* the lastname  */
   char firstName[11];                     /* firstname  */
   double salesAmount;                     /* amount sold  */
   char name[31];                          /* stores the name  */
 

   cout << "Sales Transactions" << endl << endl;

   /*  Open the input file and test for failure  */
   inFile.open(fileName);
   if (!inFile)
      {
      cerr << "Error - unable to open input file " << fileName << endl;
      exit(1);
      }

   inFile >> lastName;
   while (!inFile.eof( ))
      {
       inFile >> firstName;                 /* take firstnaem */
       inFile >> salesAmount;              /* take salesAmount */


       strcpy(name, lastName);               /* copy string into the array name */
       strcat(name, ", ");
       strcat(name, firstName);              /* Appends copty of string to name */


 /* call the serachForSeller using one name from array and store it's subscript in an int name index */
       int index  = searchForSeller(name);


 /* if the subscript in index which was returned from searchForSeller is -1, print error */
       if (index == -1)
        cout  << "Error - " << name << " does not exist" <<  endl;

       else
        {
         cout << name << " sold " <<  salesAmount << endl;           /* print out name and salesamount */
         sellers[index].getSalesTotal();
        }

       inFile >> lastName;                      /* take the next lastname from the inFile */
      }

   inFile.close();

  }


/****************************************************************

   FUNCTION:   print() const;

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      This method prints the header line and loops through
               the array of Seller objects
****************************************************************/
void SellerList::print() const
  {
    cout << endl <<  "Seller Listing" << endl << endl;

    cout<< "Name" << setw(33)  << "Sales" << endl << endl; 

    int i;

    for(i=0; i < numSellers; i++) 
    {
      sellers[i].print();
    }
  }

