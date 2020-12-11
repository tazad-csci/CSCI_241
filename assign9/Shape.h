#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

class Shape
{
public:
//class methods
	Shape(const string&);
	virtual ~Shape();

	void setColor(const string&);
	string getColor() const;

	virtual void print() const;
	virtual double get_area() const = 0;

//class data members
private:
	string color;	
};

#endif
