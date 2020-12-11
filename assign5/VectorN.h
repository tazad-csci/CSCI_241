#ifndef VECTORN_H
#define VECTORN_H
#include <iostream>
#include <stdexcept>

/**
 *
 * VectorN.h
 *
 * Author:    Tamjid Azad
 * z-ID:      Z-1839612
 * Date:      3/28/19
 *
 * Purpose: Contains the declaration for the VectorN class.
 */

using namespace std;

class VectorN
   {
   private:

   double* vArray;
   size_t vCapacity;

   // Data members for the VectorN class go here

   public:

   VectorN();
   VectorN(const double values[], size_t n);
   VectorN(const VectorN& other);
   VectorN operator=(const VectorN& other);
  ~VectorN();

   friend ostream& operator<<(ostream& lhs, const VectorN& rhs);
   friend VectorN operator*(const double& num, const VectorN& v1);

   void clear();
   size_t size() const;

   VectorN operator+(VectorN) const;
   VectorN operator-(VectorN) const;
   double operator*(const VectorN&) const;
   VectorN operator*(const double&) const;
   const double& operator[](size_t) const;
   double& operator[](size_t);
   bool operator==(const VectorN&) const;

   double at(unsigned int sub) const;
   double& at(unsigned int sub);

   // Method prototypes for the VectorN class

   };

#endif
