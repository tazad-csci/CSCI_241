#include <iostream>
#include <string>
#include "Triangle.h"

using namespace std;

/****************************************************************

   FUNCTION:   Triangle(const string&, int, int);

   ARGUMENTS:  takes a constant string and two integer values

   RETURNS:    Nohting

   NOTES:      A constructor that takes a string to initialize the triangle's
               color and two ints to initialize the triangle's height and base.
               The color string should be passed to the Shape constructor.
****************************************************************/
Triangle::Triangle(const string& color, int h, int b) :
 Shape(color)
	{
	setHeight(h);
	setBase(b);
	}

/****************************************************************

   FUNCTION:   void setHeight(int);

   ARGUMENTS:  takes an integer

   RETURNS:    Nothing

   NOTES:      Use the set method to get access to the height value.
****************************************************************/
void Triangle::setHeight(int h)
	{
	height = (h < 0) ? 0 : h;
	}


/****************************************************************

   FUNCTION:   int getHeight() const;

   ARGUMENTS:  None

   RETURNS:    returns an integer

   NOTES:      Use the get method to change the data of the height.
****************************************************************/
int Triangle::getHeight() const
        {
        return height;
        }


/****************************************************************

   FUNCTION:   void setBase(int);

   ARGUMENTS:  takes an integer

   RETURNS:    Nothing

   NOTES:      Use the set method to get access to the base value.
****************************************************************/
void Triangle::setBase(int b)
        {
        base = (b < 0) ? 0 : b;
        }


/****************************************************************

   FUNCTION:   int getBase() const;

   ARGUMENTS:  Nothing

   RETURNS:    returns an integer

   NOTES:      Use the get method to change the data of the base.
****************************************************************/
int Triangle::getBase() const
        {
        return base;
        }


/****************************************************************

   FUNCTION:   virtual double get_area() const;

   ARGUMENTS:  None

   RETURNS:    returns a double

   NOTES:      This method should compute and return the triangle's
               area based on its height and width.
****************************************************************/
double Triangle::get_area() const
	{
	return (base*height)/2;
	}


/****************************************************************

   FUNCTION:   virtual void print() const;

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      The method should call the base class print() method to
               print the color, then print the word "triangle" followed
               by the triangle's height, base, and area.
****************************************************************/
void Triangle::print() const
	{
	Shape::print();
	cout << " triangle, height " << height << ", base " << base << ", area " << get_area();
	}
