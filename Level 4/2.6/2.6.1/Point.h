//point.hpp
#ifndef SSTREAM
#define SSTREAM
#include <sstream>
#endif
#ifndef CLUSTER_H
#define CLUSTER_H
#include "Cluster.h"
#endif
#ifndef CLASS_POINT
#define CLASS_POINT
using namespace std;
using namespace Cluster;
class CAD::Point
{
private:
	double x;
	double y;
public:
	//Friends
	friend class CAD::Line;
	friend ostream& Cluster::operator << (ostream& os, const Cluster::CAD::Point& p);
	friend ostream& Cluster::operator << (ostream& os, const Cluster::CAD::Line& l);
	
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

#endif
 