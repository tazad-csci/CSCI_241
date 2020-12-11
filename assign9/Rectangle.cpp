#include <iostream>
#include <string>
#include "Rectangle.h"
#include <math.h>

using namespace std;

/****************************************************************

   FUNCTION:   Rectangle(const string&, int, int);

   ARGUMENTS:  takes a constant string and two integer values

   RETURNS:    Nothing

   NOTES:      A constructor that takes a string to initialize the circle's
               color and two ints to initialize the rectangle's height and width.
               The color string should be passed to the Shape constructor.
****************************************************************/
Rectangle::Rectangle(const string& color, int w, int h) : Shape(color)
	{
	setWidth(w);
	setHeight(h);
	}

/****************************************************************

   FUNCTION:   int getWidth() const;

   ARGUMENTS:  None

   RETURNS:    returns an integer

   NOTES:      Use the get method to change the data of the width.
****************************************************************/
int Rectangle::getWidth() const
	{
	return width;
	}


/****************************************************************

   FUNCTION:   void setWidth(int);

   ARGUMENTS:  takes an integer

   RETURNS:    Nothing

   NOTES:      Use the set method to gain access to the width.
****************************************************************/
void Rectangle::setWidth(int w)
	{
	width = (w < 0) ? 0 : w;
	}


/****************************************************************

   FUNCTION:   int getHeight() const;

   ARGUMENTS:  None

   RETURNS:    returns an integer

   NOTES:      Use the get method to change the data of the height.
****************************************************************/
int Rectangle::getHeight() const
        {
        return height;
        }


/****************************************************************

   FUNCTION:   void setHeight(int);

   ARGUMENTS:  takes an integer

   RETURNS:    Nothing

   NOTES:      Use the set method to gain access to the height.
****************************************************************/
void Rectangle::setHeight(int h)
        {
        height = (h < 0) ? 0 : h;
        }


/****************************************************************

   FUNCTION:   virtual double get_area() const;

   ARGUMENTS:  None

   RETURNS:    returns a double

   NOTES:      This method should compute and return the rectangle's
               area based on its height and width.
****************************************************************/
double Rectangle::get_area() const
	{
	return width*height;
	}


/****************************************************************

   FUNCTION:   virtual void print() const;

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      The method should call the base class print() method to
               print the color, then print the word "rectangle" followed
               by the rectangle's height, width, and area.
****************************************************************/
void Rectangle::print() const
	{
	Shape::print();
	cout << " rectangle, height " << height << ", width " << width << ", area " << get_area();
	}
