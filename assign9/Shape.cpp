#include <iostream>
#include "Shape.h"

using namespace std;

/****************************************************************

   FUNCTION:   Shape(const string&);

   ARGUMENTS:  takes a constant string

   RETURNS:    Nothing

   NOTES:      A constructor that initialize the shape's color. This
               constructor will only be invoked by a derived-class constructor.
****************************************************************/
Shape::Shape(const string& col) : color(col)
	{
	//empty body
	}

/****************************************************************

   FUNCTION:   virtual ~Shape();

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      The method body for this destructor can be empty, since it
               does not need to delete any dynamic storage.
****************************************************************/
Shape::~Shape()
	{
	}

/****************************************************************

   FUNCTION:   string getColor() const;

   ARGUMENTS:  None

   RETURNS:    returns a string

   NOTES:      Use the get method to retreve the color.
****************************************************************/
string Shape::getColor() const
	{
	return color;
	}

/****************************************************************

   FUNCTION:   void setColor(const string&);

   ARGUMENTS:  takes a constant string

   RETURNS:    Nothing

   NOTES:      Use the set method to change the data for the color.
****************************************************************/
void Shape::setColor(const string& col)
	{
	color = col;
	}

/****************************************************************

   FUNCTION:   virtual void print() const;

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      A virtual method called print() that should print the color.
****************************************************************/
void Shape::print() const
	{
	cout << color;
	}
