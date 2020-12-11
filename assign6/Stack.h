#ifndef STACK_H
#define STACK_H

/**
 *
 * Stack.h
 *
 * Author:    Tamjid Azad
 * z-ID:      Z-1839612
 * Date:      4/11/19
 *
 * Purpose: contains the declaration/defintions for the Stack class.
 *
 */

#include <iostream>
#include <ostream>
#include <stdexcept>

// Forward declaration of the Stack template class
template <class T>
class Stack;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

template <class T>
class Stack
   {
    private:
    //Stack<T>* top;
    int stkTop;
    T* stkArray;
    size_t stkSize, stkCapacity;

    public:
   // friend declaration for the template function - note the
   // special syntax
    friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);

    Stack<T>();
    ~Stack<T>();
    Stack(const Stack<T>&);
    Stack<T>& operator=(const Stack<T>&);

    void clear();
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    T& top() const;
    void push(const T&);
    void pop();
    void reserve(size_t);

   };

/****************************************************************

   FUNCTION:   Stack<T>();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      The constructor should set the stack size and stack capacity to 0 and the
               stack array pointer to nullptr
****************************************************************/
template <class T>
Stack<T>::Stack()
{
 /* default constructor */
  stkSize = 0;
  stkCapacity = 0;
  stkArray = nullptr;
}


/****************************************************************

   FUNCTION:   friend std::ostream operator<< <>(std::ostream&, const Stack<T>&);

   ARGUMENTS:  Takes a reference to an ostream object and a Stack object

   RETURNS:    returns a reference to the ostream object.

   NOTES:      The output operator should be overloaded so that a Stack can be printed on
               the standard output. This will need to be a standalone friend function rather than a method.
****************************************************************/
template <class T>
std::ostream& operator<<(std::ostream& lhs, const Stack<T>& rhs)
{
  unsigned int i;
  //stkArray = new int[stkCapacity];

/* In the for loop, print the items stored in the stack starting at subscript
   0 and ending with last valid element */
  for(i = 0; i < rhs.stkSize; i++)
  {
    lhs << rhs.stkArray[i];

    if ( i != rhs.stkSize - 1)
     {
      lhs <<" ";
     }
  }

  return lhs;
}


/****************************************************************

   FUNCTION:   void push(const T&);

   ARGUMENTS:  takes a reference to a constant item of the template parameter type

   RETURNS:    Nothing

   NOTES:      This method calls the reserve() method to increase the capacity
               and  make room for the value to insert. Next copy the value to
               be inserted into the stack array
****************************************************************/
template <class T>
void Stack<T>::push(const T& info)
{

/* if the stack capacity is zero, pass a new capacity  of 1 to reserve(), else
   pass a capacity of twice the current stack to reserve() */
  if (stkSize == stkCapacity)
    {
      if (stkCapacity == 0)
	     reserve(1);
      else
         reserve(stkCapacity * 2);
    }

/* copy the value to be inserted into the stack array */
   stkArray[stkSize++] = info;

}


/****************************************************************

   FUNCTION:   void reserve(size_t);

   ARGUMENTS:  takes a single integer argument

   RETURNS:    Nothing

   NOTES:      The temporary array pointer to allocate an array of items of the template parameter type.
               Then set the stack array pointer equal to the temporary array pointer.

****************************************************************/
template <class T>
void Stack<T>::reserve(size_t newCapacity)
{

/* if the new capacity is less than the stack size or equal to the current stack capacity,
   simply return */
   if (newCapacity < stkSize || newCapacity == stkCapacity )
	   return;

	stkCapacity = newCapacity;               /* set the stack Capacity equal to the new capacity */

	T* tempArray = new T[newCapacity];       /* declare a temporary array pointer */


/* if the stack capacity is 0, set the temporary array pointer to nullptr, else use the temporary
   array pointer to allocate an array of items */
	if (stkCapacity == 0)
	  tempArray = nullptr;


/* In the for loop, copy the contents of the stack array into the temporary array */
    for (unsigned int i = 0; i < stkSize; i++)
	   {
	      tempArray[i] = stkArray[i];
	   }

        stkCapacity = newCapacity;

	delete[] stkArray;           /* delete stack array  */

	stkArray = tempArray;       /* set stack array pointer equal to temporary array pointer  */

}


/****************************************************************

   FUNCTION:   ~Stack<T>();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      The class should have a destructor that deletes the dynamic memory for the stack array.
               The destructor does not call the clear() method.
****************************************************************/
template <class T>
Stack<T>::~Stack()
{
   delete[] stkArray;    /* delete stack array  */
}


/****************************************************************

   FUNCTION:   Stack<T>(const Stack<T>&);

   ARGUMENTS:  takes a const Stack object

   RETURNS:    Nothing

   NOTES:      Your code should account for the possibility that you might be copying an empty Stack object.
****************************************************************/
template <class T>
Stack<T>::Stack(const Stack<T>& other)
{

    stkCapacity = other.stkCapacity;
    stkSize = other.stkSize;


/* if the stack capacity is 0, set the stack array pointer for the new object to nullptr, else use the
   stack array pointer for the new object to allocate  */
    if (stkCapacity == 0)
        stkArray = nullptr;
    else
        stkArray = new T[stkCapacity];


/* In the for loop, copy the contents of the stack array of other into the stack array of the object */
    for(unsigned int i = 0; i < stkSize; i++)
     {
      stkArray[i] = other.stkArray[i];
     }

}


/****************************************************************

   FUNCTION:   Stack<T>()& operator=(const Stack<T>&);

   ARGUMENTS:  takes a const Stack object

   RETURNS:    Nothing

   NOTES:      The assignment operator should be properly overloaded to allow one Stack object to be assigned
               to another. Your code should also account for the possibility that you might be copying and
               empty Stack object.
****************************************************************/
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
	{
	  delete[] stkArray;           //delete stack array

/* set the stack capacity/size for the new object to the capacity/size of other */
          stkCapacity = other.stkCapacity;
	  stkSize = other.stkSize;


/* if the stack capacity is 0, set the stack array pointer for the object to nullptr, else use the
   stack array pointer to allocate an array of double */
	  if (stkCapacity == 0)
	     stkArray = nullptr;
	  else
	     stkArray = new T[stkCapacity];


/* In the for loop, copy the contents of the stack array of other into the stack array of the object  */
          for(unsigned int i = 0; i < stkSize; i++)
             stkArray[i] = other.stkArray[i];
	}

     return *this;
}


/****************************************************************

   FUNCTION:   T& top() const;

   ARGUMENTS:  None

   RETURNS:    return the top element of the stack array

   NOTES:      You may assume this method will not be called if the stack is empty. 
               The top  element of the stack array also is the subscript stack size - 1.
****************************************************************/
template <class T>
T& Stack<T>::top() const
{
   return stkArray[stkSize - 1];      /* returns the top element of the stack array  */
}


/****************************************************************

   FUNCTION:   void pop();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      This method should decrement the stack size by 1, which effectively removes the
               top (last) value from the stack array.
****************************************************************/
template <class T>
void Stack<T>::pop()
{
   stkSize--;       /* decrement the stack size by 1  */
}


/****************************************************************

   FUNCTION:   void clear();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      It should properly set the queue back to the empty state
****************************************************************/
template <class T>
void Stack<T>::clear()
{
   stkSize = 0;       /* set the stack size to 0  */
}


/****************************************************************

   FUNCTION:   size_t size() const;

   ARGUMENTS:  None

   RETURNS:    returns the stack size

   NOTES:      This method should return the stack size.
****************************************************************/
template <class T>
size_t Stack<T>::size() const
{
   return stkSize;      /* return the stack size */
}


/****************************************************************

   FUNCTION:   size_t capacity() const;

   ARGUMENTS:  None

   RETURNS:    return the stack capacity.

   NOTES:      This method should return the stack capacity.

****************************************************************/
template <class T>
size_t Stack<T>::capacity() const
{
   return stkCapacity;    /* return the stack capacity */
}


/****************************************************************

   FUNCTION:   bool empty() const;

   ARGUMENTS:  None

   RETURNS:    return true or false

   NOTES:      If the stack size is equal to 0, return true; otherwise it should return false.
****************************************************************/
template <class T>
bool Stack<T>::empty() const
{
  bool status = false;   /* bool value */

/* if the stack size is equal to 0, else it should return false */
   if (stkSize == 0)
     {
       status = true;
     }

   return status;
}


#endif
