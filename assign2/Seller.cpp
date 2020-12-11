
#include "Seller.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using std::cout;
using std::string;
using namespace std;

// Seller constructors
Seller::Seller()
 {
   name[31] = '\0';
   salesTotal = 0.0;
 }

Seller::Seller(const char* newName, double newSalesTotal)
 {
  strcpy(name , newName);
  salesTotal = newSalesTotal;
 }

const char* Seller::getName() const
 {
   return name;
 }

double Seller::getSalesTotal() const
 {
   return salesTotal;
 }

void Seller::setSalesTotal(double newSalesTotal)
 {
   salesTotal = newSalesTotal;
 }

void Seller::print() const
 {
   cout << fixed << setprecision(2);

   cout << left <<  setw(30) << name;

   cout << right << setw(9) << salesTotal;

   cout << endl;
 }
