#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <string>


using namespace std;

class Triangle : public Shape
{
public:
//class methods
	Triangle(const string&, int, int);

	void setHeight(int);
	int getHeight() const;

	void setBase(int);
	int getBase() const;

	virtual void print() const;
	virtual double get_area() const;

//class data members
private:
	int height;
	int base;
};

#endif
