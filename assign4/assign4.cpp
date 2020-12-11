/***********************************************************************
 *
 * CSCI 241 Assignment 4
 *
 * Date: 3/19/19
 *
 * Function: This program tests the functionality of the Complex class.
 *
 * Input: A main program to test your class has been provided.
 *
 * Output: The program should take the input and create matrices based
 *         on the operation that is required.
 *
 * Notes: A matrix (plural matrices) is a rectangular array of numbers, symbols,
          or expressions, arranged in rows and columns. 
 **********************************************************************/

#include <iostream>
#include "Matrix.h"

using std::cout;
using std::endl;

int main()
{
   int array1[2][2] = {{5, 7}, {3, 2}};
   int array2[2][2] = {{2, 3}, {1, 4}};

   // Test identity matrix constructor

   cout << "1. Testing identity matrix constructor\n\n";

   const Matrix m1;
   cout << "m1 = " << m1 << endl << endl;

   // Test array initialization constructor

   cout << "2. Testing array initialization constructor\n\n";

   Matrix m2(array1);
   cout << "m2 = " << m2 << endl;

   const Matrix m3(array2);
   cout << "m3 = " << m3 << endl << endl;

   // Test determinant

   cout << "3. Testing determinant\n\n";

   cout << "det" << m2 << " = " << m2.determinant() << endl;
   cout << "det" << m3 << " = " << m3.determinant() << endl << endl;

   // Test matrix addition

   cout << "4. Testing matrix addition\n\n";

   cout << m2 << " + " << m3 << " = " << m2 + m3 << endl;
   cout << m3 << " + " << m2 << " = " << m3 + m2 << endl << endl;

   // Test scalar multiplication

   cout << "5. Testing scalar multiplication\n\n";

   cout << m2 << " * 2 = " << m2 * 2 << endl;
   cout << "4 * " << m2 << " = " << 4 * m2 << endl << endl;

   // Test matrix multiplication

   cout << "6. Testing matrix multiplication\n\n";

   cout << m2 << " * " << m3 << " = " << m2 * m3 << endl;
   cout << m3 << " * " << m2 << " = " << m3 * m2 << endl;
   cout << m3 << " * " << m1 << " = " << m3 * m1 << endl;
   cout << m1 << " * " << m3 << " = " << m1 * m3 << endl << endl;

   cout << "det(m2 * m3) and det(m2) * det(m3) are ";
   cout << (((m2 * m3).determinant() == m2.determinant() * m3.determinant()) ? 
     "equal\n\n" : "not equal\n\n");

   // Test relational operators

   cout << "7. Testing relational operators\n\n";

   const Matrix m4(array1);

   cout << m2 << " and " << m4;
   cout << ((m2 == m4) ? " are equal\n" : " are not equal\n");

   cout << m2 << " and " << m3;
   cout << ((m2 != m3) ? " are not equal\n" : " are equal\n");

   return 0;
}
