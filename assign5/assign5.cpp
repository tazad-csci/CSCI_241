/*********************************************************************************************************
 *
 * CSCI 241 Assignment 5
 *
 * Date: 3/28/19
 *
 * Function: This program tests the functionality of the VectorN class.
 *
 * Input: A main program to test your class has been provided.
 *
 * Output: This program creates and implements a class to manipulate n-dimensional vectors
 *
 * Notes: You will need to write a single class for this assignment, the VectorN class. You
 * will need to implement several methods and functions assoicated with this class.
 *
 ********************************************************************************************************/

#include <iostream>
#include <stdexcept>
#include "VectorN.h"

using std::cout;
using std::endl;
using std::out_of_range;

int main()
{
   int test = 1;

   cout << "\nTest " << test++ << ": Default constructor and printing\n" << endl;

   const VectorN v1;

   cout << "v1: " << v1 << endl;

   cout << "\nTest " << test++ << ": Array constructor and printing\n" << endl;

   double ar2[] = {1.0, 2.0, 3.0};

   const VectorN v2(ar2, 3);

   cout << "v2: " << v2 << endl;
  
   cout << "\nTest " << test++ << ": Clear and size\n" << endl;
   VectorN v3(ar2, 3);
  
   cout << "The size of v3: " << v3 << " is " << v3.size() << endl;

   v3.clear();

   cout << "After clearing, the size of v3: " << v3 << " is ";
   cout << v3.size() << endl;

   cout << "\nTest " << test++ << ": Subscripting\n" << endl;

   double ar3[] = {-1.0, -3.0, -5.0, 7.0};
   const VectorN v4(ar3, 4);

   cout << "v4: " << v4 << endl;
   cout << "v4[0]: " << v4[0] << "  v4[1]: " << v4[1] << endl;
   cout << "v4[2]: " << v4[2] << "  v4[3]: " << v4[3] << endl;
  
   VectorN v5(ar3, 4);
   v5[0] = 17;  v5[1] = 3;  v5[2] = 0;  v5[3] = -9;
   cout << "v5: " << v5 << endl;
  
   cout << "\nTest " << test++ << ": Copy constructor\n" << endl;
  
   const VectorN v6(ar2, 3);
   const VectorN v7 = v6;

   cout << "v6: " << v6 << " size: " << v6.size() << endl;
   cout << "v7: " << v7 << " size: " << v7.size() << endl;

   VectorN v8(ar3, 4);
   VectorN v9 = v8;

   cout << "v8: " << v8 << " size: " << v8.size() << endl;
   cout << "v9: " << v9 << " size: " << v9.size() << endl;

   v8[1] = 300.0;
   cout << "Changing..." << endl;
   cout << "v8: " << v8 << " size: " << v8.size() << endl;
   cout << "v9: " << v9 << " size: " << v9.size() << endl;

   cout << "\nTest " << test++ << ": Assignment operator\n" << endl;
   VectorN v10(ar3, 4);
   VectorN v11;

   cout << "v10: " << v10 << endl;
   cout << "v11: " << v11 << endl;

   v11 = v10;

   v10[0] = 0.0;

   cout << "v10: " << v10 << endl;
   cout << "v11: " << v11 << endl;

   cout << endl;

   // Chained assignment
   VectorN v12, v13;

   cout << "v11: " << v11 << endl;
   cout << "v12: " << v12 << endl;
   cout << "v13: " << v13 << endl;

   v13 = v12 = v11;

   cout << "v11: " << v11 << endl;
   cout << "v12: " << v12 << endl;
   cout << "v13: " << v13 << endl;

   cout << endl;

   // Assignment to self

   v13 = v13;

   VectorN v14(ar2, 3);

   cout << "v13: " << v13 << endl;
  
   cout << "\nTest " << test++ << ": Addition and subtraction\n" << endl;

   double ar4[] = {-2.0, 3.0, -1.0};
   double ar5[] = {0, 1, 2, -3};

   const VectorN v15(ar2, 3), v16(ar4, 3);
   const VectorN v17(ar5, 4);

   cout << "v13: " << v13 << endl;
   cout << "v15: " << v15 << endl;
   cout << "v16: " << v16 << endl;
   cout << "v17: " << v17 << endl;

   cout << endl;
   cout << "v15 + v16 is " << v15 + v16 << endl;
   cout << "v13 + v17 is " << v13 + v17 << endl;
   cout << "v15 + v13 is " << v15 + v13 << endl;
   cout << "v17 + v16 is " << v17 + v16 << endl;

   cout << endl;
   cout << "v15 - v16 is " << v15 - v16 << endl;
   cout << "v13 - v17 is " << v13 - v17 << endl;
   cout << "v15 - v13 is " << v15 - v13 << endl;
   cout << "v17 - v16 is " << v17 - v16 << endl;

   cout << "\nTest " << test++ << ": Vector multiplication\n" << endl;

   cout << "The scalar product of " << v15 << " and " << v16 << " is ";
   cout << v15 * v16 << endl;

   cout << "The scalar product of " << v13 << " and " << v17 << " is ";
   cout << v13 * v17 << endl;

   cout << "The scalar product of " << v13 << " and " << v15 << " is ";
   cout << v13 * v15 << endl;

   cout << "The scalar product of " << v16 << " and " << v17 << " is ";
   cout << v16 * v17 << endl;

   cout << "\nTest " << test++ << ": Scalar multiplication\n" << endl;

   double k = 2.345;

   cout << v17 << " * " << k << " = " << v17 * k << endl;
   cout << k << " * " << v17 << " = " << k * v17 << endl;

   cout << "\nTest " << test++ << ": Equality\n" << endl;

   double ar6[] = {1, 2, 2};
   double ar7[] = {1, 2, -2};
   double ar8[] = {1, 2, 2, 0};
   double ar9[] = {1, 2, -2, 0};

   const VectorN v18(ar6, 3), v19(ar7, 3);
   const VectorN v20(ar8, 4), v21(ar9, 4);

   cout << v18 << " and " << v18 << " are ";

   if (v18 == v18)
      cout << "equal" << endl;
   else
      cout << "not equal" << endl;
  
   cout << v18 << " and " << v19 << " are ";

   if (v18 == v19)
      cout << "equal" << endl;
   else
      cout << "not equal" << endl;
  
   cout << v18 << " and " << v20 << " are ";

   if (v18 == v20)
      cout << "equal" << endl;
   else
      cout << "not equal" << endl;
  
   cout << v21 << " and " << v19 << " are ";

   if (v21 == v19)
      cout << "equal" << endl;
   else
      cout << "not equal" << endl;

    /*
    * Extra Credit: Uncomment the following lines if you choose to do the extra credit portion of this assignment.
    *
*/
   cout << "\nTest " << test++ << ": Read-write form of at() method\n" << endl;

   VectorN v22(ar9, 4);
   const VectorN v23(ar9, 4);
   
   try
      {
      v22.at(0) = 9.1;
      v22.at(1) = 3.97;
      v22.at(-1) = -7.43;
      }
   catch (out_of_range orex)
      {
      cout << "Caught "<< orex.what() << endl;
      }

   cout << "v22: " << v22 << endl;

   cout << "\nTest " << test++ << ": Read-only form of at() method\n" << endl;
      
   try
      {
      cout << "v23: (";
      for (unsigned i = 0; i <= v23.size(); i++)
         cout << v23.at(i) << ", ";
      cout << ")\n\n";
      }
   catch (out_of_range orex)
      {
      cout << endl << "Caught "<< orex.what() << endl;
      }


   return 0;
}
