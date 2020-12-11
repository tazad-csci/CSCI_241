#ifndef SELLER_H
#define SELLER_H

/************************************************************
 *
 * Seller.h
 *
 * Date:      2/21/19
 * 
 * Contains the declaration for the Seller class.
 **********************************************************/

class Seller
   {
   private:

   char name[31];
   double salesTotal;

   // Data members for the Seller class go here
   
   public:

   // Method prototypes for the Seller class

   Seller();
   Seller(const char*, double);

   const char* getName() const;
   double getSalesTotal() const;
   void setSalesTotal(double);
   void print() const;
   };

#endif
