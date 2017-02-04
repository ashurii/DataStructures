// Created By Ashly Altman
// Data Structures Section 05

#include <iostream>
#include <iomanip>     // Provides setw function for setting output width
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <cassert>     // Provides assert function
#include <math.h>
using namespace std;        // Allows all Standard Library items to be used
class threeDpoint
{
public:
	//CONSTRUCTORS
	threeDpoint();
	threeDpoint(double initX, double initY,double initZ);
	
    // MODIFICATION MEMBER FUNCTIONS
    	// Sets the coordinate values x,y,z for point
	void set_XYZ(double newX, double newY, double newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}
	void shift(char xyz, double move)
	{
		if(xyz == 'x')
			{x += move;}
		else if(xyz == 'y')
			{y += move;}
		else
			{z += move;}
	}
    void rotate_Point(char axis, double angle)
	{
		double x1, y1, z1;
		if(axis == 'x')
		{
			x1 = x;
			y1 = y*cos(angle) - z*sin(angle);
			z1 = y*sin(angle) + z*cos(angle);
		}
		else if(axis == 'y')
		{
			x1 = x*cos(angle) + z*sin(angle);
			y1 = y;
			z1 = (-x)*(sin(angle)) + z*cos(angle);
		}
		else
		{
		x1 = x*cos(angle) - y*sin(angle);
		y1 = x*sin(angle)+y*cos(angle);
		z1 = z;
		}
		x = x1;
		y = y1;
		z = z1;
	}
    // CONSTANT MEMBER FUNCTIONS
    double get_X( ) const;
    double get_Y( ) const;
    double get_Z( ) const;
	

private:
   double x; 		//x plane coordinate
	double y; 		//y plane coordinate
	double z; 		//z plane coordinate
};

class LineSegment
{
	threeDpoint point01;
	threeDpoint point02;
public:
	LineSegment();
	LineSegment(threeDpoint object1, threeDpoint object2);
	void setPoints(threeDpoint point1, threeDpoint point2);
	double get_X1( ) const;
	double get_Y1( ) const;
	double get_Z1( ) const;
	double get_X2( ) const;
	double get_Y2( ) const;
	double get_Z2( ) const;
private:
	double x1;
	double y1;
	double z1; 
	double x2;
	double y2;
	double z2;
	
};
int main( )
{
    threeDpoint point1;
	threeDpoint point2;
	point2.set_XYZ(3,6,7);
	
	LineSegment segment1;
	segment1.setPoints(point1, point2);
	
	cout << "Starting coordinates are:[" << point1.get_X() << ", " << point1.get_Y() << ", " << point1.get_Z()<< "]" <<endl;
	point1.shift('x', 1.0);
	point1.shift('y',1.0);
	point1.shift('z',1.0);
	cout << "shifting the point by 1 for each plane:[" << point1.get_X() << ", " << point1.get_Y() << ", " << point1.get_Z()<< "]" <<endl;
	point1.rotate_Point('z', 20.0);
	cout << "rotating the point by 20 degrees on the z axis:[" << point1.get_X() << ", " << point1.get_Y() << ", " << point1.get_Z()<< "]" <<endl;
	cout << "coordinates for a line segment:\nfirst point[" << segment1.get_X1() << ", " << segment1.get_Y1() << ", " << segment1.get_Z1() 
	<< "]\nsecond point["<< segment1.get_X2() << ", " << segment1.get_Y2() << ", " << segment1.get_Z2() << "]" <<endl;

}
 threeDpoint::threeDpoint()
{
	  x = 0;
      y = 0;
      z = 0;
}
LineSegment::LineSegment()
{
	x1 = 0;
	y1 = 0;
	z1 = 0;
	x2 = 0;
	y2 = 0;
	z2 = 0;
}
//Point Friend Function
void LineSegment::setPoints(threeDpoint point, threeDpoint point2)
{
	x1 = point.get_X();
	y1 = point.get_Y();;
	z1 = point.get_Z();;
	x2 = point2.get_X();
	y2 = point2.get_Y();
	z2 = point2.get_Z();
}
	// Non Member functions for returning x,y,z coordinates
	double threeDpoint::get_X() const
	{
			return x;
	}
	double threeDpoint::get_Y() const
	{
			return y;
	}
	double threeDpoint::get_Z() const
	{
			return z;
	}
	//Non Member functions for returning line segment coordinates
	double LineSegment::get_X1() const
	{
		return x1;
	}
	double LineSegment::get_Y1() const
	{
		return y1;
	}
	double LineSegment::get_Z1() const
	{
		return z1;
	}
	double LineSegment::get_X2() const
	{
		return x2;
	}
	double LineSegment::get_Y2() const
	{
		return y2;
	}
	double LineSegment::get_Z2() const
	{
		return z2;
	}
