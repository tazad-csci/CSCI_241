#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
#include <ostream>

template <class T>
struct Node
   {

   Node<T>* next;         /* pointer to a node */

   T data;             /* template parameter type */

   //constructor method
   Node(const T&);

   };

// Method definitions for the Node class

// Forward declaration of the Queue template class
template <class T>
class Queue;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue
   {
   private:

   Node<T>* qFront;
   Node<T>* qBack;
   size_t qSize;

   public:
   // friend declaration for the template function - note the
   // special syntax
   friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

   Queue<T>();
   ~Queue<T>();
   Queue<T>(const Queue<T>&);
   Queue<T>& operator=(const Queue<T>&);

   void clear();
   size_t size() const;
   bool empty() const;
   void push(const T&);
   void copyList(const Queue<T>&);
   void pop();
   const T& front() const;
   const T& back() const;

   };

/****************************************************************

   FUNCTION:   Node(const T&);

   ARGUMENTS:  Takes an argument of the template parameter type

   RETURNS:    Nothing

   NOTES:      The constructor should copy the argument into the queue node
               and set the node's pointer to nullptr.

****************************************************************/
template <class T>
Node<T>::Node(const T& other)
{
 /* constructor should copy the argument into the queue node  */
    data = other;
    next = nullptr;
}

/****************************************************************

   FUNCTION:   Queue()<T>;

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      a short paragraph stating what the function does
****************************************************************/
template <class T>
Queue<T>::Queue()
{
/* constructor should set both pointer data members to nullptr and the queue size to 0  */
    qFront = nullptr;
    qBack = nullptr;
    qSize = 0;
}


/****************************************************************

   FUNCTION:   friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

   ARGUMENTS:  Takes an ostream& lhs and Queue rhs

   RETURNS:    Returns output of the Queue

   NOTES:      The output operator should be overloaded so that an entire Queue can be sent to the
               standard output. This function will need to be a friend rather than a method

****************************************************************/
template <class T>
std::ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs)
{
  Node<T>* ptr;   /* pointer to Node */

/* In the for loop, print queue element starting at subscript 0 */
  for(ptr = rhs.qFront; ptr != nullptr; ptr = ptr->next)
    {
     lhs << ptr->data << " ";
    }

  return lhs;
}


/****************************************************************

   FUNCTION:   void size();

   ARGUMENTS:  None

   RETURNS:    Returns a size_t

   NOTES:      It should return the current size of the queue; the number
               of data items currently stored in the queue
******************************************************************/
template <class T>
size_t Queue<T>::size() const
{
  return qSize;   /*  return current size */
}


/****************************************************************

   FUNCTION:   bool empty();

   ARGUMENTS:  None

   RETURNS:    Returns ture or false

   NOTES:      Returns true if there are no data items currently stored in
               the queue; otherwise returns false
****************************************************************/
template <class T>
bool Queue<T>::empty() const
{
  bool status = false;    /* bool value */

/* if there are no data items currently stored in the queue, return true, else returns false  */
  if (qSize == 0)
    {
      status = true;
    }

  return status;
}


/****************************************************************

   FUNCTION:   void push(const T&);

   ARGUMENTS:  Takes a reference to a constant item of the template

   RETURNS:    Nothing

   NOTES:      The method should insert the item at the back of the queue
               and increment the queue size.

****************************************************************/
template <class T>
void Queue<T>::push(const T& other)
{
  Node<T>* newNode  = new Node<T>(other);

/* if the size is zero, push data to the beginning and connects the pointer to the next node, else
   push from the back  */
  if ( qSize == 0)
   qFront = newNode;
  else
   qBack->next = newNode;

  qBack = newNode;
  ++qSize;         /* increment size */
}

/****************************************************************

   FUNCTION:   Queue(const Queue<T>&);

   ARGUMENTS:  Takes a const Queue

   RETURNS:    Nothing

   NOTES:      If you choose to make a copy of the linked list by using the push()
               method, make sure you set both the front and back pointers for the new
               queue to nullptr and the queue size to 0
****************************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
 /* set the data memebrs to null and zero  */
    qFront =  qBack = nullptr;
    qSize = 0;

    copyList(other);        /* call the copylist method */
}


/****************************************************************

   FUNCTION:   void copyList();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      Method that can be called by both the copy constructor and overloaded assignment operator.

****************************************************************/
template <class T>
void Queue<T>::copyList(const Queue<T>& other)
{
   Node<T>* ptr;     /* pointer to Node */

/* In the for loop, copy constructor extension that copies the data */
   for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
     {
       push(ptr->data);
     }
}


/****************************************************************

   FUNCTION:   void clear();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      It should properly set the queue back to the empty state

*****************************************************************/
template <class T>
void Queue<T>::clear()
{
/* clears the queue  */
   qFront = nullptr;
   qBack = nullptr;
   qSize = 0;
}

/****************************************************************

   FUNCTION:   void pop();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      This should remove the item at the front of the queue and decrement the queue size

****************************************************************/
template <class T>
void Queue<T>::pop()
{
/* if empty throw an error, else it returns the front of the queue */
 if (empty())
   {
    throw std::underflow_error("Queue underflow on pop()");
   }

  /* Remove first node in list */
   Node<T>* delNode = qFront;
   qFront = qFront->next;

/* If the front queue is now empty, make sure the back pointer is nullptr */
  if (qFront == nullptr)
     qBack = nullptr;

  delete delNode;
  --qSize;         /* decrement size */

}


/****************************************************************

   FUNCTION:   Queue<T> opearator=(const Queue<T>&);

   ARGUMENTS:  Takes a const Queue

   RETURNS:    Nothing

   NOTES:      The copy assignment operator should be properly overloaded
******************************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
/* if the arguement and reference aren't the same, clear and copy the Queue's linked list  */
   if (this != &other)
      {
      /* Make the left Queue object empty */
      clear();

      /* Copy the other Queue's linked list */
      copyList(other);
      }

   return *this;
}

/****************************************************************

   FUNCTION:   const T& front() const;

   ARGUMENTS:  None

   RETURNS:    Returns a reference to a constant item

   NOTES:      This method should return the data stored in the front node of the queue

****************************************************************/
template <class T>
const T& Queue<T>::front() const
{
/* if the Queue is empty, throw an error ,else it should return the data stored in the
   front node of the queue */
 if (empty())
  {
   throw std::underflow_error("Queue underflow on front()");
  }

   return qFront->data;
}


/****************************************************************

   FUNCTION:   const T& back() const;

   ARGUMENTS:  None

   RETURNS:    Returns a reference to a constant item

   NOTES:      This method should return the data stored in the back node of the queue

****************************************************************/
template <class T>
const T& Queue<T>::back() const
{
/* if the Queue is empty throw an error, else it should return the data stored in the
   front node of the queue  */
  if (empty())
  {
   throw std::underflow_error("Queue underflow on back()");
  }

    return qBack->data;
}


/****************************************************************

   FUNCTION:   ~Queue();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      The destructor can simply call the clear() method
****************************************************************/
template <class T>
Queue<T>::~Queue()
{
  clear();    /* call the clear method */
}

#endif
