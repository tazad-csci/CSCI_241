#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;

/**
 *
 * Matrix.h
 *
 * Author:    Tamjid Azad
 * z-ID:      Z-1839612
 * Date:      3/19/19
 *
 * Purpose: Contains the declaration for the Matrix class.
 */

class Matrix
{
   friend ostream& operator<< (ostream& lhs, const Matrix& rhs);
   friend Matrix operator* (const int& lhs, const Matrix& rhs);

   private:

   int matrix[2][2];

   // Data members for the Matrix class go here

   public:

   Matrix();
   Matrix(int array[2][2] );

   int determinant() const;

   Matrix operator+(const Matrix& rhs ) const;
   Matrix operator*(const int& rhs) const;
   Matrix operator*(const Matrix& rhs) const;
   bool operator==(const Matrix& rhs);
   bool operator!=(const Matrix& rhs);

};

#endif
