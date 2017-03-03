#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include "poly.h"

using namespace std;
using namespace colorado_edu;

void poly_run( )
{
	double user_input_double = 0;
	unsigned int user_input_int = 0;
	cout << "Enter the coefficient:" << endl;
	cin >> user_input_double;
	cout << "Enter the exponent:" << endl;
	cin >> user_input_int;
	polynomial poly1;
	
	
	
	 poly1.assign_coef(user_input_double,user_input_int);
	
	cout << "polynomial 1:\t" << poly1 << endl;
	cout << endl;
	if(poly1.is_zero())
		cout << "poly1 is the zero polynomial" << endl;
	else
		cout << "poly1 is not the zero polynomial" << endl;
	

	
	cout << poly1 << endl;
	cout << endl;
	polynomial poly2;
	poly2.assign_coef(2, 3);
	
	cout << "Poly 2:\t" <<poly2 << endl;
	
	
	polynomial poly3;
	poly3 = poly1;
	cout << "poly 3 " << poly3 << endl;
	
	cout << endl;
	cout << "Poly1 + Poly2 :\t" << poly1 + poly2<< endl;
	cout << endl;
	cout << "Poly1 - Poly2:\t" << poly1 -poly2 << endl;
	cout << endl;
	cout << "poly1 * poly2 :\t" << poly1 * poly2<< endl;
	cout << endl;
	cout << "Derivative of Poly1:\t"<< poly1.derivative() << endl;
	cout << endl;
	cout << "Antiderivative of Poly1:\t" << poly1.antiderivative() << endl;
	cout << endl;
	cout << "Definite Integral of Poly1 from 0 to 2:\t" << poly1.definite_integral(0,2) << endl;
	cout << endl;
	cout << "Numeric Definite Integral of Poly1,\n from 0 to 2 with 4 rectangles:\t" << poly1.numeric_definite_integral(0,2,4) << endl;
	cout << endl;
	cout << "poly3.next_term(2)" << poly3.next_term(2) << endl;
	cout << endl;
	cout << "poly3.previous_term(6)" << poly3.previous_term(6) << endl;
	cout << endl;
}

int main(int argc, char **argv)
{
	
	char command = 'n';
	do{
		cout << "Press 'r' to test a polynomial, 'q' to quit:" << endl;
		cin >> command;
		
		
		if(command != 'Q' && command !='q')
			poly_run( );
			
	}while(command != 'Q' && command !='q');
	
	return(EXIT_SUCCESS);
	
	
}
