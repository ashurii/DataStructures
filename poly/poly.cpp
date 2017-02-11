
#include <math.h>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <algorithm>
#include "poly.h"
using namespace std;
namespace colorado_edu
{

	polynomial::polynomial(double c, unsigned int exponent)
	{
		assert(exponent <= MAXIMUM_DEGREE);
	
		unsigned int i;
		for(i =0; i < MAXIMUM_DEGREE; ++i)
		{	
			coef[i] = c;			
		}
	}
	void polynomial::add_to_coef(double amount, unsigned int exponent)
	//     PRECONDITION: exponent <= MAXIMUM_DEGREE.
	//     POSTCONDITION: Adds the given amount to the coefficient of the
	//     specified exponent.
	{
			assert(exponent <= MAXIMUM_DEGREE);
			coef[exponent] += amount;
	}
	void polynomial::assign_coef(double coefficient, unsigned int exponent)
	//     PRECONDITION: exponent <= MAXIMUM_DEGREE.
	//     POSTCONDITION: Sets the coefficient for the specified exponent.
	{
			assert(exponent <= MAXIMUM_DEGREE);
			coef[exponent] = coefficient;
	}
	void polynomial::clear( )
	//     POSTCONDITION: All coefficients of this polynomial are set to zero.
	{
			unsigned int i;
			for(i = 0; i < degree( ); ++i)
				coef[i] = 0;
	}
	
	//polynomial derivative( ) 
//     POSTCONDITION: The return value is the first derivative of this 
//     polynomial.
//	{

		
			
//	}
	polynomial antiderivative( )
//     PRECONDITION: degree( ) < MAXIMUM_DEGREE
//     POSTCONDITION: The return value is the antiderivative (indefinite integral)
//     of this polynomial.
//     NOTE: The return polynomial always has a constant term of zero.
	{
			//assert(degree() < MAXIMUM_DEGREE);
			
			
	}
	
}

