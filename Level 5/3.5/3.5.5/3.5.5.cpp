#ifndef LINE_H
#define LINE_H
#include "Line.h"
#endif
using namespace std;
using namespace Cluster::CAD;

//this is a test programme for template method pattern
void main()
{
	//create the objects
	Point p1(1,1);Point p2;
	Line l1(p2,p1);

	//call Print() function
	p1.Print();
	l1.Print();
	
	//The information is right even though class Point and class Line don't have a Print() function
}