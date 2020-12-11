#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>

using namespace std;

class Rectangle : public Shape
{
public:
//class methods
	Rectangle(const string&, int, int);

	void setWidth(int);
	int getWidth() const;

	void setHeight(int);
	int getHeight() const;

	virtual void print() const;
	virtual double get_area() const;

//class data members
private:
	int height;
	int width;
};

#endif
