#include <stdio.h>
#include "point.h"
#include <iostream>
#include <cstdlib>

using namespace std;
using main_savitch_2A::point;

int main(int argc, char **argv)
{
	point p(6, -4);
	point p2(4, 6);
	cout<< "x coordinate:" << p.get_x() <<endl;
	cout<< "y coordinate:" << p.get_y() << endl;
	p.rotate_to_upper_right(p);
	cout<< "x coordinate:" << p.get_x() <<endl;
	cout<< "y coordinate:" << p.get_y() << endl;
	if(p == p2)
		cout<< "equal";
	return EXIT_SUCCESS;
};
