#include <stdio.h>
#include <iostream>
#include "poly.h"

using namespace std;
using namespace colorado_edu;

int main(int argc, char **argv)
{
	polynomial poly1(6,4);
	
	poly1.assign_coef(5,2);
	
	cout << poly1 << endl;
	
	polynomial poly2(2,3);
	
	cout << poly2 << endl;
	
	polynomial poly3;
	
	//poly3 =poly1 + poly2;
	
	//cout << poly3 << endl;
	
	//poly3 = poly1 * poly2;
	
	cout << poly1 * poly2 << endl;
	cout << poly2 * poly1 << endl;
	
	
}
