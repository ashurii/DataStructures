#include "point.h"
#include <cmath>
#include <iostream>

namespace main_savitch_2A
{
	point::point(double initial_x, double initial_y)
	{
		x = initial_x;
		y = initial_y;
	}
	void point::shift(double x_amount, double y_amount)
	{
			x += x_amount;
			y += y_amount;
	}
	void point::rotate90()
	{
	double new_x;
	double new_y;
	
	new_x = y;	//For a 90 degree clockwise rotation, the new x is the original y
	new_y = -x;	//and the new y is -1 times the original x.
	x = new_x;
	y = new_y;
	}
	int point::rotations_needed(point p)
	//Postcondition: The value returned is the number of 90 degree clockwise rotations needed to move p into upper right quadrant
	{
		int answer;
		answer = 0;
		while((p.get_x() < 0) || (p.get_y() < 0))
		{
			p.rotate90();
			++answer;
		}
	return answer;
	}
	void point::rotate_to_upper_right(point& p)
	//Postcondition: The point p has been rotated in 90-degree
	//increments until p has been moved into the upper-right
	//quadrant(where x >=0 and y >=0)
	{
		while((p.get_x() < 0) || (p.get_y() < 0))
		{
			p.rotate90();
			}
	}
	double distance(const point& p1, const point& p2)
	//Postcondition: The value returned is the distance between p1 and p2
	// Library facilities used: cmath
	{
	double a, b, c_squared;
	
	//Calculate differences in x and y coordinates
	a = p1.get_x() - p2.get_x(); // Difference in x coordinates
	b = p1.get_y() - p2.get_y(); //	Difference in y coordinates
	//Use Pythagorean Theorem to calculate suqare of the distance between two points.
	c_squared = a*a + b*b;
	return sqrt(c_squared);
	}
	bool operator ==(const point& p1, const point& p2)
	{
		return
			(p1.get_x() == p2.get_x())
			&&
			(p1.get_y() == p2.get_y());
	}
	std::ostream& operator <<(std::ostream& outs, const point& source)
	{
			outs << source.get_x()<<" "<<source.get_y();
			return outs;
	}
	std::istream& operator >>(std::istream& ins, const point& target)
	{
		ins >> target.x >> target.y;
		return ins;
	}
	

}

