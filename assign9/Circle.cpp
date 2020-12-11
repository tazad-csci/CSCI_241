#include <iostream>
#include <string>
#include "Circle.h"
#include <math.h>

using namespace std;

/****************************************************************

   FUNCTION:   Circle(const string&, int);

   ARGUMENTS:  takes a string and an integer

   RETURNS:    Nothing

   NOTES:      a constructor that takes a string to initialize the circle's color and
               an int to initiallize the circle's radius. The color string should be
               passed to the Shape constructor.
****************************************************************/
Circle::Circle(const string& col, int rad) : Shape(col)
	{
	setRadius(rad);
	}

/****************************************************************

   FUNCTION:   void setRadius(int);

   ARGUMENTS:  takes an integer

   RETURNS:    Nothing

   NOTES:      Use the set method to change the raduis
****************************************************************/
void Circle::setRadius(int rad)
	{
 	radius = (rad < 0) ? 0 : rad;
	}

/****************************************************************

   FUNCTION:   int getRadius() const;

   ARGUMENTS:  None

   RETURNS:    returns an double

   NOTES:      This method should compute and return the circle's area based on its radius.
****************************************************************/
int Circle::getRadius() const
	{
	return radius;
	}

/****************************************************************

   FUNCTION:   virtual double get_area() const;

   ARGUMENTS:  None

   RETURNS:    returns a double

   NOTES:      This method should compute and return the circle's area based on its radius.
****************************************************************/
double Circle::get_area() const
	{
	return  M_PI*(pow(radius,2));
	}

/****************************************************************

   FUNCTION:   virtual void print() const;

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      The method should call the base class print() method to
               print the color, then print the word "circle" followed by
               the circle's radius and area.
****************************************************************/
void Circle::print() const
	{
	Shape::print();
	cout << " circle, radius " << radius << ", area " << get_area();
	}
