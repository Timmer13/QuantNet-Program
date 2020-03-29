//Circle.cpp
//Class Circle with centre and radius
//10-07-2016 PM
#ifndef CMATH
#define CMATH
#define _USE_MATH_DEFINES
#include <cmath>
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Circle.h"
#endif
namespace Cluster
{
namespace CAD
{
//constructors and destructor (using colon sytax)
Circle::Circle(){}//default constructor
Circle::Circle(Point& p1, Line& l1):centre(p1),radius(l1){}//constructor with parameters
Circle::Circle(const Circle& O):centre(O.centre),radius(O.radius){}//copy constructor
Circle::~Circle(){}//destructor

//Selectors
Point Circle::CentrePoint() const
{
	return centre;
}
Line Circle::Radius() const
{
	return radius;
}

//Modifier
void Circle::CentrePoint(Point& p)
{
	centre=p;//initialize centre
}
void Circle::Radius(Line& l)
{
	radius=l;//initialize radius
}

//Geometric property functions
double Circle::Diameter()
{
	return (radius.Length()*2);//diameter=radius*2
}
double Circle::Circumference()
{
	return (radius.Length()*2*M_PI);//circumference=2*pi*radius
}
double Circle::Area()
{
	return (radius.Length()*radius.Length()*M_PI);//area=pi*radius*radius
}

//Description
std::string Circle::ToString()
{
	std::stringstream source;
	source<<"A circle centered at point("<<centre.X()<<","<<centre.Y()<<") with a radius of "<<radius.Length();
	return source.str();
}

//Operator
Circle& Circle::operator = (const Circle& O)
{
	if (&O!=this)
	{
		centre=O.centre;//assign parameters
		radius=O.radius;//assign parameters
	}
	return *this;
}

//friend function
ostream& operator << (ostream& os, Circle& O)
{
	os<<"A circle centered at point("<<O.centre.x<<","<<O.centre.y<<") with a radius of "<<O.radius.Length()<<".";
	return os;
}
}
}