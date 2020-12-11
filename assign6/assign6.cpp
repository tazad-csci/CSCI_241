/***************************************************************************************
 *
 * CSCI 241 Assignment 6
 *
 * Date: 4/11/19
 *
 * Purpose: This program tests the functionality of the Stack class.
 *
 * Input: A driver program is provided for this assignment to test your
 *        implementation.
 *
 * Output: This program will encapsulate a dynamically-allocated array of
 *         elements of a generic data type.
 *
 * Notes: You will need to write a single template class for this assignment,
 *        and implement several methods and functions for that class
 **************************************************************************************/

#include <iostream>
#include "Stack.h"

using std::cout;
using std::endl;

int main()
{
   cout << "Testing default constructor\n\n";
    
   Stack<int> s1;
    
   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");  
   cout << endl;
    
   cout << "Testing push()\n\n";
    
   for (int i = 10; i < 80; i+= 10)
      s1.push(i);
 
   cout << "s1: " << s1 << endl;
  
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   for (int i = 15; i < 85; i+= 10)
      s1.push(i);
    
   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "Testing copy constructor()\n\n";
    
    Stack<int> s2 = s1;
    
   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "Testing top()\n\n";
    
   cout << "Top item of s1: " << s1.top() << endl << endl;
    
   cout << "Testing pop()\n\nTop item of s1: ";
    
   while (!s1.empty())
      {
      cout << s1.top() << ' ';
      s1.pop();
      }
    
   cout << endl << endl;
   cout << "s1: " << s1 << endl;
   cout << "s1 size: " << s1.size() << ", capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "Testing assignment operator\n\n";
    
   Stack<int> s3;
    
   s3 = s2;
    
   cout << "s2 (size " << s2.size() << "): " << s2 << endl;
   cout << "s3 (size " << s3.size() << "): " << s3 << endl << endl;
    
   cout << "Testing clear()\n\n";
    
   s2.clear();
    
   cout << "s2: " << s2 << endl;
   cout << "s2 size: " << s2.size() << ", capacity: " << s2.capacity() << endl;
   cout << "s2 is " << ((s2.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "s3: " << s3 << endl;
   cout << "s3 size: " << s3.size() << ", capacity: " << s3.capacity() << endl;
   cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
    
   cout << "Testing assignment to self and swap\n\n";
    
   s3 = s3;
   s2 = s3;
   s3.clear();
    
   cout << "s2 (size " << s2.size() << "): " << s2 << endl;
   cout << "s3 (size " << s3.size() << "): " << s3 << endl << endl;
    
   cout << "Testing chained assignment\n\n";
    
   Stack<int> s4;
    
   s4 = s3 = s2;
    
   cout << "s2 (size " << s2.size() << "): " << s2 << endl;
   cout << "s3 (size " << s3.size() << "): " << s3 << endl;
   cout << "s4 (size " << s4.size() << "): " << s4 << endl << endl;
    
   Stack<int> s5 = s4;
    
   cout << "s5 (size " << s5.size() << "): " << s5 << endl << endl;


   cout << "Testing other data type\n\n";

   Stack<char> s6;

   for (char c = 'a'; c < 'k'; c++)
      s6.push(c);

   cout << "s6 (size " << s6.size() << "): " << s6 << endl << endl;

   cout << "Testing const correctness\n\n";
    
   const Stack<char>& r6 = s6;
    
   cout << "s6: " << r6 << endl;
   cout << "s6 size: " << r6.size() << ", capacity: " << r6.capacity() << endl;
   cout << "s6 is " << ((r6.empty()) ? "empty\n" : "not empty\n");
   cout << "Top item of s6: " << r6.top() << endl;

   Stack<char> s7 = r6;
    
   cout << "s7: " << s7 << endl;
        
   s7.clear();
        
   cout << "s7: " << s7 << endl;
        
   s7 = r6;
        
   cout << "s7: " << s7 << endl;

   return 0;
}
