#include <stdio.h>
#include <iostream>
#include "poly.h"

using namespace std;
using namespace colorado_edu;

int main(int argc, char **argv)
{
	polynomial poly1(6,4);
	
	poly1.assign_coef(5,3);
	
	polynomial poly2(2,2);
	
	polynomial poly3;
	
	cout << poly1.derivative();
	
	
	
	

	
}
