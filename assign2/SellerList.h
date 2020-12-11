#ifndef SELLERLIST_H
#define SELLERLIST_H
#include "Seller.h"
#include <string>
using namespace std;
/************************************************************************
 *
 * SellerList.h
 * Date:      2/21/19
 *
 * Purpose:  Contains the declaration for the SellerList  class.
 ************************************************************************/

class SellerList
   {
   private:

   Seller sellers[30];
   int numSellers;
   // Data members for the SellerList class go here
   
   public:

   // Method prototypes for the SellerList class

   SellerList();
   SellerList(const string& fileName);


   int searchForSeller(const char* searchName) const;
   void sortSellers();
   void processSalesData(const string& fileName);
   void print()const;

  };

#endif
