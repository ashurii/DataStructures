//FILE: point.h
//CLASS PROVIDED: point(part of the namespace main_savitch_2A)
//CONSTRUCTOR FOR POINT class:
// point(double initial_x = 0.0, double initial_y = 0.0)
// Postcondition: The point has been set to (initial_x, initial_y)
// MODIFICATION MEMBER FUNCTIONS for the point class:
//	void shift(double x_amount, double y_amount).
//	void rotate90()
//	Poistcondition: The point has been rotated clockwise 90 degrees around the origin
//
// CONSTANT MEMBER FUNCTIONS for the point class:
//	double get_x() const
//	Postcondition: The value returned is the  x coordinate of the point.
//
//	double get_y() const
// Post condition: The value returned is the y coordinate of the point.
//
// VALUE SEMANTICS for the point class:
//		Assignments and the copy constructor may be used with point objects.

#include <iostream>
#ifndef MAIN_SAVITCH_POINT_H
#define MAIN_SAVITCH_POINT_H
namespace main_savitch_2A
{

class point
{
public:
	point(double initial_x = 0.0, double initial_y = 0.0);
	//MODIFCATION MEMBER FUNCTIONS
	void shift(double x_amount, double y_amount);
	void rotate90();
	int rotations_needed(point p);
	void rotate_to_upper_right(point& p);
	double distance(const point& p1, const point& p2);
	friend std::ostream& operator <<(std::ostream& outs, const point& source);
	friend std::istream& operator >>(std::istream& ins, const point& target);
	friend bool operator ==(const point& p1, const point& p2);
	//CONSTANT MEMBER FUNCTIONS
	double get_x() const{ return x;}
	double get_y() const{ return y;}
	
	
private:
		double x;
		double y;

};

}
#endif // POINT_H
