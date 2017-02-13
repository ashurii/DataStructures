#include <stdio.h>
#include <iostream>
#include "poly.h"

using namespace std;
using namespace colorado_edu;

int main(int argc, char **argv)
{
	polynomial poly2(2,2);
	
	cout << poly2.numeric_definite_integral(0,2,2) << endl;

}
