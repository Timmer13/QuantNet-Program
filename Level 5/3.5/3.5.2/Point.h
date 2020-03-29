//point.hpp
#ifndef SSTREAM
#define SSTREAM
#include <sstream>
#endif
#ifndef SHAPE_H
#define SHAPE_H
#include "Shape.h"
#endif
#ifndef CLASS_POINT
#define CLASS_POINT
using namespace std;
namespace Cluster
{
namespace CAD
{
class Point: public Shape
{
private:
	double x;
	double y;
public:
	//Friends
	friend class Line;
	friend class Circle;
	friend ostream& operator << (ostream& os, const Point& p);
	friend ostream& operator << (ostream& os, const Line& l);
	friend ostream& operator << (ostream& os, Circle& O);

	//Constructor and Destructor
	Point();
	Point(double x,double y);
	explicit Point(double coordinate);//new constructor
	Point(const Point& P);
	~Point();

	//Selectors
	double X() const;//Access x value
	double Y() const;//Access y value

	//Modifiers
	void X(double newxval);//Set x value
	void Y(double newyval);//Set y value
	
	//Description
	std::string ToString() const;

	//Distance  function
	double Distance() const;
	double Distance(Point &p);//Call by referece

	//Operators
	Point operator - () const; // Negate the coordinates
	Point operator * (double factor) const; // Scale the coordinates
	Point operator + (const Point& p) const; // Add coordinates
	bool operator == (const Point& p) const; // Equally compare operator
	Point& operator = (const Point& source); // Assignment operator
	Point& operator *= (double factor); // Scale the coordinates & assign
};
}
}
#endif
 