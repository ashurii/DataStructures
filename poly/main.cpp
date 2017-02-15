#include <stdio.h>
#include <iostream>
#include "poly.h"

using namespace std;
using namespace colorado_edu;

int main(int argc, char **argv)
{
	polynomial poly1(2,3);
	polynomial poly2(2,2);
	
	polynomial poly3;
	
	poly3 = poly1.antiderivative();
	
	cout <<  poly1.antiderivative() << endl;
	
	
	

	
}
