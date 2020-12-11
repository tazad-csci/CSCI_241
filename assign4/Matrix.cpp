#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>


/****************************************************************

   FUNCTION:   friend ostream& operator<< (ostream& lhs, const Matrix& rhs);

   ARGUMENTS:  Takes two parameters. The first is a reference to an ostream
               object, of the left operand. The second is a reference to a
               constant Matrix object, representing the right operand.

   RETURNS:    A reference to an ostream object.

   NOTES:      Use square brackets around each row of the matrix and around the
               matrix as a whole, and prints the elements of the matrix separated by a comma.
****************************************************************/
ostream& operator<< (ostream& lhs, const Matrix& rhs)
{
  cout << "[";

 /* In this for loop, create square brackets around each row of the matrix and around
    the matrix as a whole.  */
     for(int a = 0; a < 2; a++)
      {
       cout << "[";

 /* print the element of the matrix separated by a comma.       */
        for(int b = 0;  b < 2; b++)
          {
            cout << rhs.matrix[a][b] << "," ;
          }
       cout << "]";
      }

      cout << "]";

 return lhs;
}


/****************************************************************

   FUNCTION:   friend Matrix operator* (const in& lhs, const Matrix& rhs);

   ARGUMENTS:  Takes two parameters, an integer representing the left 
               operand of the scalar multiplication, and a reference to
               a constant Matrix object, from the right operand of the scalar multiplication.

   RETURNS:    A new Matrix object. The result of multiplying the elements of the
               matrix right operand by the integer left operand.

   NOTES:      The product cA of a number c and a matrix A is computed by
               multiplying every entry of A by c.
****************************************************************/

Matrix operator* (const int& lhs, const Matrix& rhs)
{
  Matrix result;            /* new Matrix object  */

/*  Multiply the elements of the right operand of the matrix by the left operand integer   */
   result.matrix[0][0] = rhs.matrix[0][0] * lhs;
   result.matrix[0][1] = rhs.matrix[0][1] * lhs;
   result.matrix[1][0] = rhs.matrix[1][0] * lhs;
   result.matrix[1][1] = rhs.matrix[1][1] * lhs;

  return result;
}

/****************************************************************

   FUNCTION:   Matrix ()

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      Set the elements of the matrix array to the "identity matrix",
               such that all the elements on the main diagonal are equal to 1
               and all other elements are equal to 0.
****************************************************************/
Matrix::Matrix()
{

/* Set the elements of the matrix array to the "identity matrix"     */
     matrix[0][0]=1;
     matrix[1][1]=1;
     matrix[0][1]=0;
     matrix[1][0]=0;
}


/****************************************************************

   FUNCTION:   Matrix (int )

   ARGUMENTS:  Takes a 2-dimensional array of integers with two rows and columns

   RETURNS:    Nothing

   NOTES:      Set the elements of the matrix array to the corresponding 
               elements in the array passed into the constructor.
****************************************************************/
Matrix::Matrix(int array[2][2])
{

/* In this for loop, create a two-dimensional array of integers with two rows and two columns   */
    for(int a=0; a < 2; a++)
     {

   /* In this for loop, set the elements of the matrix array to the corresponding elements
      in the array passed into the construtor    */
       for(int b=0; b < 2; b++)
        {
          matrix[a][b]=array[a][b];
        }
     }
}


/****************************************************************

   FUNCTION:   determinant()

   ARGUMENTS:  None

   RETURNS:    The integer determinant of the Matrix object.

   NOTES:      The determinant subtracts ad by dc of the 2-by-2 matrix
****************************************************************/
int Matrix::determinant() const
{
  int sum;                                 /* accumlator for matrix   */


 /* Multiply and subtract the index of the matrix and store it in sum    */
  sum=matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

 return sum;
}


/****************************************************************

   FUNCTION:   Matrix operator+(const Matrix& rhs) const;

   ARGUMENTS:  Takes an integer from the right operand of the scalar multiplication.

   RETURNS:    A new Matrix object. Result of the matrix addition of the left/right operands.

   NOTES:      This method does not alter any data members of the Matrix
               object that called the method, so it should be declared const.
****************************************************************/
Matrix Matrix::operator+ (const Matrix &rhs) const
{
  Matrix x;          /* new Matrix object   */


/*  In the for loop, create the right operand of the matrix  */
 for (int i=0; i <= 2; i++)
   {

  /* In this for loop, add the left and right operand of the matrix and store it in result   */
     for (int j=0; j <= 2; j++)
       {
	 x.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
       }
   }

 return x;
}


/****************************************************************

   FUNCTION:   Matrix Opeartor*(const int& rhs) const;

   ARGUMENTS:  Takes an integer representing the right operand of the scalar multiplication.

   RETURNS:    A new Matrix object. Result of the matrix left operand
               multiplied by the ineger right operand.

   NOTES:      This method does not alter any data members of the Matrix
               object that called the method, so it should be declared const.
****************************************************************/
Matrix Matrix::operator* (const int& rhs) const
{
  Matrix x;        /* new Matrix object  */


 /* muultiply the left operand of the expression by the integer of the right operand  */
  x.matrix[0][0] = this->matrix[0][0] * rhs;
  x.matrix[0][1] = this->matrix[0][1] * rhs;
  x.matrix[1][0] = this->matrix[1][0] * rhs;
  x.matrix[1][1] = this->matrix[1][1] * rhs;

 return x;
}


/****************************************************************

   FUNCTION:   Matrix Operator*(const Matrix& rhs) const;

   ARGUMENTS:  Takes a reference to a constant Matrix object, representing
               the right operand of the expression.

   RETURNS:    A new Matrix object. Result of multiplying the matrix left
               operand by the matrix right operand.

   NOTES:      This method does not alter any data members of the Matrix object
               that called the method, so it should be declared const.
****************************************************************/
Matrix Matrix::operator* (const Matrix& rhs) const
{
  Matrix x;      /* new Matrix object    */


/*  In the for loop, create the right and left operand of the expression    */
  for(int i=0; i < 2; i++)
   {
     for(int j=0; j < 2; j++)
      {
         x.matrix[i][j] = 0;

/*  In this for loop, take the right and left operand of the expression and mulitply/add them together   */
       for( int k=0; k < 2; k++)
        {
          x.matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
        }
      }
   }
 return x;
}


/****************************************************************

   FUNCTION:   bool operator!=(const Matrix& rhs);

   ARGUMENTS:  Takes a reference to a constant Matrix object,representing
               the right operand of the relational expression.

   RETURNS:    A boolean value.

   NOTES:      This method does not alter any data members, so it should be declared const.
****************************************************************/
bool Matrix::operator==(const Matrix& rhs)
{
  bool status = true;                  /*value of status     */


/* In the for loop, create the right operand and left operand of the expression   */
    for(int a=0, b=0; a < 2 && b < 2; a++, b++)
     {

  /*  if all elements of the left operand are equal to the elements of the right operand,
      status equals false */
       if(this->matrix[a][b] != rhs.matrix[a][b])
         status = false;
     }

   return status;
}


/****************************************************************

   FUNCTION:   bool operator!=(const Matrix& rhs);

   ARGUMENTS:  Takes a reference to a constant Matrix object, representing
               the right operand of the relational expression.

   RETURNS:    A boolean value.

   NOTES:      This method does not alter any data members, so it should be declared const.
****************************************************************/
bool Matrix::operator!=(const Matrix& rhs)
{
  bool status = false;         /* value of status   */


/* In the for loop, create the  right operand and left operand of the expression   */
    for(int a=0, b=0; a < 2 && b < 2; a++, b++)
     {

  /*  if the left operand equals the right operand, status equals true  */
       if(this->matrix[a][b]!=rhs.matrix[a][b])
         status = true;
     }

  return status;
}
