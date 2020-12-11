#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <string>

using namespace std;

class Circle : public Shape
{
public:
//class methods
	Circle(const string&, int);

	void setRadius(int);
	int getRadius() const;

	virtual void print() const;
	virtual double get_area() const;

//class data memebers
private:
	int radius;
};

#endif
