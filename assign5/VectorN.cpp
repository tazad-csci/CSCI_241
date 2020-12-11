#include "VectorN.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

/****************************************************************

   FUNCTION:   VectorN();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      Should initialize a new VectorN object to an empty vector array with a capacity of 0.
****************************************************************/
VectorN::VectorN()
{

  vCapacity = 0;          /* capacity set to  zero  */
  vArray = nullptr;      /* array set to nullptr  */
}


/****************************************************************

   FUNCTION:   friend ostream& operator<<(ostream& lhs, const VectorN& rhs);

   ARGUMENTS:  Takes a constant vector and and ostream variable

   RETURNS:    ostream&

   NOTES:      Should be overloaded so that a VectorN can be sent to the standard output.
               An empty vector should be printed as ().
****************************************************************/
ostream& operator<< (ostream& lhs, const VectorN& rhs)
{
 unsigned int i;       /* subscript   */

  lhs << "(";

/* In the for loop, print the standard ouput of VectorN until the you reach its full capacity  */
  for(i = 0; i <  rhs.vCapacity;  i++)
   {
     lhs << rhs[i];

     if (i != rhs.vCapacity - 1)
    {
     cout << ",";
    }
}

  lhs << ")";

/* if the vector is empty, print as ()  */
   if (rhs.vCapacity == 0)
   lhs << "()";

 return lhs;
}


/****************************************************************

   FUNCTION:   const double& operator[](size_t) const;

   ARGUMENTS:  Takes the size of the vector

   RETURNS:    Double constant

   NOTES:      The subscript operator should be overloaded to provide accessor methods for the class.
               The provided subscript indicates which value should be accessed from the dynamically-allocated array
****************************************************************/
const double& VectorN::operator[](size_t pos) const
{
  return vArray[pos];     /* return result  */
}

double& VectorN::operator[](size_t pos)
{
  return vArray[pos];     /* return result  */
}


/****************************************************************

   FUNCTION:   double& operator[](size_t);

   ARGUMENTS:  Takes the size of the vector

   RETURNS:    Double

   NOTES:      The subscript operator should be overloaded to provide accessor methods for the class. 
               The provided subscript indicates which value should be accessed from the dynamically-allocated array.
****************************************************************/
VectorN::VectorN(const double values[], size_t n)
{
  vCapacity = n;     /* set vector capacity for new object to zero */

/* if the vector capacity is zero, set the vector array pointer for the new object to nullptr, else
   the number of elements in the new vector array should be equal to the vector capacity  */
  if (vCapacity == 0)
    vArray = nullptr;
  else
    vArray = new double[vCapacity];


/* In the for loop, copy the elements of the array values into the vector array  */
  for (size_t i = 0; i < vCapacity; i++)
    vArray[i]= values[i];
}


/****************************************************************

   FUNCTION:   VectorN(const VectorN& other);

   ARGUMENTS:  Takes a VectorN object other

   RETURNS:    Nothing

   NOTES:      Should initialize a new VectorN object to the same 
               capacity and array contents as the existing VectorN object other.
****************************************************************/
VectorN::VectorN(const VectorN& other)
{
  vCapacity = other.vCapacity; /* Set the vector capacity of the new object to other.*/

/* if vector capacity is 0, set the vector array pointer for the new object to nullptr,else
   the number of elements in the new vector array should be equal to the vector capacity */
  if (vCapacity == 0)
    vArray = nullptr;
  else
    vArray = new double[vCapacity];


/* Copy the elements of the array values into the vector array  */
  for (size_t i =0; i < vCapacity; i++)
    vArray[i] = other.vArray[i];
}


/****************************************************************

   FUNCTION:   ~VectorN();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      The destructor for the VectorN class can simply call the clear() method.
****************************************************************/
VectorN::~VectorN()
{
  delete[] vArray;       /* Delete the dynamic array*/
}


/****************************************************************

   FUNCTION:   VectorN operator=(const VectorN& other);

   ARGUMENTS:  Takes a VectorN object

   RETURNS:    *this

   NOTES:      should assign one VectorN object (the object other) toanother the
               object that called the method, which is pointed to by this.
****************************************************************/
VectorN VectorN::operator=(const VectorN& other)
{
/* if the address stored in the pointer this is the same as the address of the object other,
  then skip to the final step.*/
  if(this != &other)
   {
     delete[] vArray;   /* delete the vector array for the object pointed to by this */

     vCapacity = other.vCapacity;  /* set the vector capacity of this to the vector capacity of other */

/* if the vector capacity is 0, set the vector array pointer for the object pointed to by this to nullptr. Otherwise, else 
  the number of elements in the new vector array should be equal to the vector capacity   */
     if (vCapacity == 0)
       vArray = nullptr;
     else
       vArray = new double[vCapacity];


/* In the for loop, copy the contents of the vector array of other into the vector array
   of the object pointed to by this     */
    for (size_t i = 0; i < vCapacity; i++)
       vArray[i] = other.vArray[i];
   }

  return *this;
}


/****************************************************************

   FUNCTION:   void Clear();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      Should properly set the instance back to a vector of zero elements.
****************************************************************/
void VectorN::clear()
{
  delete[] vArray;  /* delete the vector array */

  vArray = nullptr;   /* set the vector array pointer to nullptr */

  vCapacity = 0;   /* set the vector capacity to 0  */
}


/****************************************************************

   FUNCTION:   size_t size() const;

   ARGUMENTS:  None

   RETURNS:    Size of vector

   NOTES:      Returns the size of the vector, which is equal to the vector capacity.
****************************************************************/
size_t VectorN::size() const
{
  return vCapacity;     /* return capacity */
}


/****************************************************************

   FUNCTION:   VectorN operator+(VectorN) const;

   ARGUMENTS:  Takes a VectorN

   RETURNS:    VectorN

   NOTES:      The result are computed by adding the components of the operands.If there
               capacities are different, then only the first n components of each vector
               should be used in the product.
****************************************************************/
VectorN VectorN::operator+(VectorN v2) const
{
 VectorN answer;     /* new VectorN object */
 unsigned int i;     /* subscript */
 size_t limit;      /* lowest capacity of VectorN */


/* if the two operands are of different capacities, then only the first n components of each
   vector should be used in the product where n is the capacity of the smaller of the two vectors */
  if(vCapacity == v2.vCapacity)
   {
     limit = v2.vCapacity;
   }
  else if (vCapacity < v2.vCapacity)
   {
     limit = vCapacity;
   }
  else if (vCapacity > v2.vCapacity)
   {
     limit = v2.vCapacity;
   }


  answer.vCapacity = limit;             /* set the limit to the new object's capacity  */
  answer.vArray = new double[limit];


/* In the for loop, add the two VectorN components of the operands unitl you reach the limit   */
  for(i=0; i < limit; i++)
   {
     answer.vArray[i] = vArray[i] + v2.vArray[i];
   }

  return answer;
}


/****************************************************************

   FUNCTION:   VectorN operator-(VectorN) const;

   ARGUMENTS:  Takes a VectorN

   RETURNS:    VectorN

   NOTES:      The result is the component-wise difference of the operands.
               As with addition, the result should have the capacity of the smaller operand.
****************************************************************/
VectorN VectorN::operator-(VectorN v2) const
{
 VectorN answer;       /* new VectorN object */
 unsigned int i;       /* subscript */
 size_t limit;         /* lowest capacity of vectorN*/


/* if the two operands are of different capacities, then only the first n components of each vector
   should be used in the product where n is the capacity of the smaller of the two vectors   */
  if (vCapacity == v2.vCapacity)
   {
     limit = v2.vCapacity;
   }
  else if (vCapacity < v2.vCapacity)
   {
     limit = vCapacity;
   }
  else if (vCapacity > v2.vCapacity)
   {
     limit = v2.vCapacity;
   }

  answer.vCapacity = limit;          /* set limit to the  new object's capacity  */
  answer.vArray = new double[limit];

/* In the for loop, subtract the two VectorN operands until you reach the limit  */
  for(i = 0; i < limit; i++)
   {
    answer.vArray[i] = vArray[i] - v2.vArray[i];
   }

  return answer;
}


/****************************************************************

   FUNCTION:   double operator*(const VectorN&) const;

   ARGUMENTS:  Takes two VectorNs

   RETURNS:    Single double value

   NOTES:      The scalar product is computed by multiplying the corresponding components 
               of the two vectors and adding the results.
****************************************************************/
double VectorN::operator*(const VectorN& v1) const
{
 double product = 0;       /* accumlator for total product */
 size_t limit;          /* lowest capacity of vectorN  */
 unsigned int i;        /* subscript */


/* if the two operands are of different capacities, then only the first n components of
   each vector should be used in the product where n is the capacity of the smaller of the two vectors */
 if ( vCapacity == v1.vCapacity )
  {
    limit = v1.vCapacity;
  }
  else if ( vCapacity < v1.vCapacity)
  {
    limit = vCapacity;
  }
  else if ( vCapacity > v1.vCapacity)
  {
    limit = vCapacity;
  }


/* In the for loop, first multiply the two VectorN operands and contiune to add them toeghter  */
  for(i = 0; i < limit; i++)
   {
     product = product + (vArray[i] * v1.vArray[i]);
   }

 return product;
}


/****************************************************************

   FUNCTION:   VectorN operator*(const double&) const;

   ARGUMENTS:  Takes double constant

   RETURNS:    VectorN

   NOTES:      handle multiplication of the vector by the constant in that order
****************************************************************/
VectorN VectorN::operator*(const double& lhs) const
{
 VectorN multiple;    /* new VectorN object */
 unsigned int i;      /* subscript */


 multiple.vCapacity = vCapacity;          /* set vCapacity to the new object's capacity  */
 multiple.vArray = new double[vCapacity];

/* In the for loop, multiplication of the vector by the constant in that order      */
  for (i = 0; i < vCapacity; i++)
   {
     multiple.vArray[i] = vArray[i] * lhs;
   }

 return multiple;
}


/****************************************************************

   FUNCTION:   friend VectorN operator*(const double& num, const VectorN& v1);

   ARGUMENTS:  Takes a double constant and VectorN constant

   RETURNS:    VectorN

   NOTES:      Handle multiplication of the constant by the vector in that order.
****************************************************************/
VectorN operator*(const double& num, const VectorN& v1)
{
 VectorN multiple2;    /* new VectorN object */
 unsigned int i;       /* subscript  */


 multiple2.vCapacity = v1.vCapacity;        /* set the capacity the new object's capacity  */
 multiple2.vArray = new double[v1.vCapacity];

/* In the for loop, multiplication of the constant by the vector in that order  */
  for (i = 0; i <= v1.vCapacity; i++)
   {
     multiple2.vArray[i] = num * v1.vArray[i];
   }

   return multiple2;
}


/****************************************************************

   FUNCTION:   bool operator==(const VectorN&) const;

   ARGUMENTS:  Takes a VectorN

   RETURNS:    A bool value

   NOTES:      The two vectors are considered equal only if they are componentwise equal.
               If the operands have different capacities, then the vectors are automatically not equal.
****************************************************************/
bool VectorN::operator==(const VectorN& v1) const
{
 bool status = false;  /* bool value */

/*  the operands have different capacities, then the status if false and not equal
    regardless of the component values   */
 if ( v1.vCapacity != vCapacity)
     status = false;
 else
  {
/* In the for loop, compare two VectorNs to see if they are equal    */
    for(unsigned int i = 0; i < vCapacity; i++)
   {
/* if they one of the pairs  of vectorNs aren't equal status becomes false  */
     if (v1.vArray[i] != vArray[i])
         status = false;
     else
         status = true;
    }
  }
  return status;
}


/****************************************************************

   FUNCTION:   double at(int sub) const;

   ARGUMENTS:  Takes an integer

   RETURNS:    Double

   NOTES:      Should be overloaded to provide accessor for this const (read only) methods for this class. 
****************************************************************/
double VectorN::at(unsigned int sub) const
{
/* if sub is less than 0 or greater than or equal to the capacity of the vector array  */
  if (sub < 0 || sub >= vCapacity)
    {
      throw out_of_range("subscript out of range");
    }
  else
    return vArray[sub];
}


/****************************************************************

   FUNCTION:   double& at(int sub);

   ARGUMENTS:  Takes an integer

   RETURNS:    Double

   NOTES:      Should be overloaded to provide accessor for this non-const(read-write only) methods for this class.
****************************************************************/
double& VectorN::at(unsigned int sub)
{
/* if sub is less than 0 or greater than or equal to the capacity of the vector array, otherwise, it should return element sub of the vector array.   */
  if (sub < 0 || sub >= vCapacity)
    {
     throw out_of_range("subscript out of range");
    }
  else
    return vArray[sub];
}
