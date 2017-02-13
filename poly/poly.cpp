
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
			coef[i] = 0;			
		}
		coef[exponent] = c;
		current_degree = exponent;
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
	double polynomial:: coefficient(unsigned int exponent) const
	{
		if(exponent <= MAXIMUM_DEGREE)
			return coef[exponent];
		else
			return 0;
		}
	double polynomial::eval(double x) const
	//     POSTCONDITION: The return value is the value of this polynomial with the
	//     given value for the variable x.	double eval(double x) const
	{
		double eval_result;
		unsigned int i;
		for(i = 0; i < current_degree; ++i)
		{
			eval_result+= pow(x, i);
		}
		return eval_result;
	}
	unsigned int polynomial:: next_term(unsigned int e) const
	//     POSTCONDITION: The return value is the next exponent n which is LARGER
	//     than e such that coefficient(n) != 0.
	//     If there is no such term, then the return value is zero.
	{
		if(coef[e+1] > 0)
			return coef[e+1];
		else
			return 0;
	}
	double polynomial::numeric_definite_integral(double x0, double x1, unsigned int n)
	//     POSTCONDITION: Returns the value of the definite integral computed from
	//     x0 to x1 by using the trapezoid method with n sections of equal width.
	{
		// Definite Integral: delta(x) = (x1 - x0)/n
		// (where x0 and x1 are the upper and lower bounds) 
		// (delta(x))/2 * [f(x0) + 2f(x0)... 2f(x1) + f(x1)]
		
		double delta_x;	
		double poly_eval;
		double d_intgrl;
		double i;
		
		delta_x = (x1 - x0)/n;
		poly_eval = eval(x0);
		
		for(i = x0; i < x1; ++i)
			poly_eval+= 2*eval(i);
		
		poly_eval +=eval(x1);
		
		d_intgrl = (delta_x/2)*poly_eval;
		
		return d_intgrl;
	}
	polynomial polynomial::antiderivative( ) const
	{
			//Anti-derivative: Take the exponent of the variale+1, divide coefficient by the exponent
			//for antiderivative of(x^r) = (x/r)^(r+1)
			polynomial a_poly;
			
			double z;	//z is a temporary variable for containin the value of the current coefficient
			
			unsigned int i;
			
			for(i = this->current_degree; i > 0; --i)
		{
			z = coef[i];	// z assigned to current coefficient
			z/=(double)(i);			// z divided by the exponent (index) of the current coefficient
			a_poly.assign_coef(z, current_degree+1);
			
		}
		return a_poly;
	}
	
	 ostream& operator<< (ostream& out, const polynomial& p)
//     POSTCONDITION: The polynomial has been printed to ostream out, which,
//     in turn, has been returned to the calling function.
	{

			unsigned int i;
			unsigned int count;
			
			for(i = p.degree(); i > 0; i)
			{
				if(p.coefficient(i) > 0)
				out << p.coefficient(i) <<"x^"<< i;	// prints x ^ index of coef[]
				
			}
			
			return out;
	}
	
	unsigned int polynomial::previous_term(unsigned int e) const
	//     POSTCONDITION: The return value is the next exponent n which is SMALLER
	//     than e such that coefficient(n) != 0.
	//     If there is no such term, then the return value is UINT_MAX
	//     from <climits>.
	{
		if(coef[e-1] > 0)
			return coef[e-1];
		else
			return UINT_MAX;
	}
//	void polynomial::find_root(
	//	double& answer,
	//	bool& success,
	//	unsigned int& iterations,
	//	double starting_guess = 0,
	//	unsigned int maximum_iterations = 100,
	//	double epsilon = 1e-8
	//	)const
//     PRECONDITION: epsilon > 0.
//     POSTCONDITION: This function uses Newton's method to search for a root of
//     the polynomial (i.e., a value of x for which the polynomial is zero).
//     The method requires some starting guess for the value of the root. This
//     guess is improved over a series of iterations (with the maximum allowed
//     iterations defined by the parameter maximum_iterations). There are three
//     possible outcomes:
//     1. SUCCESS:
//        The method hits a near-root (a value of x for which the absolute value
//        of the polynomial is no more than epsilon). In this case, the function
//        sets answer to equal this near-root, success is set to true, and
//        iterations is set to the number of iterations required.
//     2. FLAT FAILURE:
//        Newton's method fails because the guess hits a very flat area of the
//        polynomial (a point where first derivative is no more than epsilon).
//        In this case, the function sets answer equal to the guess that caused
//        flat failure, success is set to false, and iterations is the number
//        of iterations carried out (which will be less than maximum_iterations).
//     3. MAXIMUM ITERATIONS REACHED:
//        The maximum number of iterations is reached without success or flat
//        failure. In this case, the function sets answer to the last guess tried,
//        success is set to false, and iterations is set to maximum_iterations.
	//	{}
}

