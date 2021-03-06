//Written by Ashly Sarah Altman

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
			// needs to check if the pos at expo is more than current degree
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
	bool polynomial::is_zero( ) const
	{
		bool result = true;
		for(unsigned int i = degree( ); i > 0; --i)
			if(coefficient(i) != 0)
				result = false;
		
		return result;
			
	}
	
	double polynomial::eval(double x) const
	//     POSTCONDITION: The return value is the value of this polynomial with the
	//     given value for the variable x.	double eval(double x) const
	{
		double eval_result = 0;
		unsigned int i;
		double temp;
		for(i = 0; i <= current_degree; ++i)
		{
			if(coefficient(i) != 0)	
			{			
				temp = coefficient(i) * pow(x, i);
				eval_result += temp;	
			}
								
		}
		return eval_result;
	}
	unsigned int polynomial:: next_term(unsigned int e) const
	//     POSTCONDITION: The return value is the next exponent n which is LARGER
	//     than e such that coefficient(n) != 0.
	//     If there is no such term, then the return value is zero.
	{
		unsigned int answer = 0;
		for(unsigned int i = degree( ); i >0; --i){
			if(coef[i] != 0 && i > e)
				
				answer = i;
			else
				answer = 0;
				}
			return answer;
	}
	double polynomial::numeric_definite_integral(double x0, double x1, unsigned int n)
	//     POSTCONDITION: Returns the value of the definite integral computed from
	//     x0 to x1 by using the trapezoid method with n sections of equal width.
	{
		// Definite Integral: delta(x) = (a - b)/n
		// (where x0 and x1 are the upper and lower bounds) 
		// (delta(x))/2 * [f(x0) + 2f(x0)... 2f(xn-1) + f(xn)]
		
		double delta_x;	
		double poly_eval;
		double d_intgrl;
		double i;
		
		delta_x = ((x1 - x0)/(double)n);
		poly_eval = eval(x0);
		
		
		for(i = x0 + delta_x; i < x1; i+=delta_x)
			poly_eval+= 2*eval(i);
		
		poly_eval += eval(x1);
		
		d_intgrl = (delta_x/2.0)*poly_eval;
		
		return d_intgrl;
	}
	double polynomial::definite_integral(double x0, double x1) const 
	//     POSTCONDITION: Returns the value of the definite integral computed from
	//     x0 to x1.  The answer is computed analytically.
	{
		// definite integral: antiderivative of polynomial at x1 - antiderivative at x0
		polynomial eval_poly;
		eval_poly = antiderivative( );
		
		double result = 0;
		result = eval_poly.eval(x1) - eval_poly.eval(x0);
		return result;
	}
	polynomial polynomial::antiderivative( ) const
	{
			//Anti-derivative: Take the exponent of the variale+1, divide coefficient by the exponent
			//for antiderivative of(x^r) = (x/r)^(r+1)
			
		polynomial a_poly((coef[degree( )])/(degree( )+1), degree( )+1);
		double z;	//z is a temporary variable for containin the value of the current coefficient
		
		unsigned int i;
		
		
		for(i = this->degree( ); i > 0; --i)
		{
			z = this->coef[i];	// z assigned to current coefficient
			z/=(double)(i);			// z divided by the exponent (index) of the current coefficient
			
			if(coef[i] != 0)
				a_poly.assign_coef(z, i+1);
			
		}
		
		return a_poly;
	}
	polynomial polynomial:: derivative( ) const
	{
			//The derivative: Take the exponent of the variable-1, multiply the coefficient by the exponent
		//for , dy/dx(x^r) = rx^(r-1) 
		polynomial d_poly((coef[degree( )])*(degree( )-1), degree( )-1);			
		
		double z;		// z is a temporary variable for containing the value of the current coefficient
		
		unsigned int i;
		for(i = this->degree( ); i > 1; --i)
		{
			z = coef[i];	// z assigned to current coefficient
			z*=(double)(i);			// z multiplied by the exponent (index) of the current coefficient
			d_poly.assign_coef(z, i-1);
			
		}
		
		return d_poly;	
	}	
	 ostream& operator<< (ostream& out, const polynomial& p)
//     POSTCONDITION: The polynomial has been printed to ostream out, which,
//     in turn, has been returned to the calling function.
	{

			unsigned int i;
			
			
			for(i = p.degree(); i > 0; --i)
			{
				if(p.coefficient(i) != 0)
					out << p.coefficient(i) <<"x^ " << i;	// prints x ^ index of coef[]
				if((i - 1) != 0 && p.coefficient(i-1) != 0)
					out << " + ";
			}
			
			return out;
	}
	
	unsigned int polynomial::previous_term(unsigned int e) const
	//     POSTCONDITION: The return value is the next exponent n which is SMALLER
	//     than e such that coefficient(n) != 0.
	//     If there is no such term, then the return value is UINT_MAX
	//     from <climits>.
	{
		unsigned int answer;
		for(unsigned int i = degree( ); i >0; --i)
		{
			if(coef[i] != 0 && i < e)
				answer = i;
			else
				answer = UINT_MAX;
		}
	
		return answer;
	}
	void polynomial::find_root(
		double& answer,
		bool& success,
		unsigned int& iterations,
		double starting_guess,
		unsigned int maximum_iterations,
		double epsilon
		) const
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
		{
				assert(epsilon > 0);
				
		}
	
	polynomial operator +(const polynomial& p1, const polynomial& p2)
	{
		//     POSTCONDITION: return-value is a polynomial with each coefficient
		//     equal to the sum of the coefficients of p1 & p2 for any given
		//     exponent.
		
		   unsigned int i;
		   unsigned int new_degree;
		   double new_coefficient;
		   
		   
		   if(p1.degree() >= p2.degree())
				new_degree = p1.degree();
			else
				new_degree = p2.degree();
			
			new_coefficient = p1.coefficient(new_degree) + p2.coefficient(new_degree);
			polynomial poly_sum(new_coefficient , new_degree);
			
			for(i = new_degree-1; i > 0; --i)
			{
				
				new_coefficient = p1.coefficient(i) + p2.coefficient(i);
				poly_sum.assign_coef(new_coefficient, i);
				
			}
			
		   return poly_sum;
		}
	   polynomial operator -(const polynomial& p1, const polynomial& p2)
	{
		//     POSTCONDITION: return-value is a polynomial with each coefficient
		//     equal to the difference of the coefficients of p1 & p2 for any given
		//     exponent.
			unsigned int i;
		   unsigned int new_degree;
		   double new_coefficient;
		   
		   
		   if(p1.degree() >= p2.degree())
				new_degree = p1.degree();
			else
				new_degree = p2.degree();
			
			new_coefficient = p1.coefficient(new_degree) - p2.coefficient(new_degree);
			polynomial poly_diff(new_coefficient , new_degree);
			
			for(i = new_degree-1; i > 0; --i)
			{
				
				new_coefficient = p1.coefficient(i) - p2.coefficient(i);
				poly_diff.assign_coef(new_coefficient, i);
				
			}
			
		   return poly_diff;
		}
	polynomial operator *(const polynomial& p1, const polynomial& p2)
//     PRECONDITION: p1.degree( ) + p2.degree( ) <= MAXIMUM_DEGREE.
//     POSTCONDITION: Each term of p1 has been multiplied by each term of p2,
//     and the answer is the sum of all these term-by-term products.
//     For example, if p1 is 2x^2 + 3x + 4 and p2 is 5x^2 - 1x + 7, then the
//     return value is 10x^4 + 13x^3 + 31x^2 + 17x + 28.
	{
			unsigned int i,j;
			unsigned int new_degree = 0;
			double new_coefficient = 0;
		   
			new_degree = p1.degree( ) + p2.degree( );
			
			new_coefficient = p1.coefficient(p1.degree( )) * p2.coefficient(p2.degree( ));
			polynomial poly_multi(0, new_degree);
			
			for(i = p1.degree( ); i >  0; --i)
			{
				if (p1.coefficient(i) != 0)
				{
					for(j = p2.degree( ); j > 0; --j)
					{
						
						if (p2.coefficient(j) != 0){
						new_coefficient = p1.coefficient(i) * p2.coefficient(j);
						new_degree = i + j;
						poly_multi.add_to_coef(new_coefficient, new_degree);
						}

					}
				}
			}
		   return poly_multi;
	}
}

