
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
	const polynomial::size_type polynomial::DEFAULT_DEGREE;
	polynomial::polynomial( )
	{
		maximum_degree = DEFAULT_DEGREE;
		
		coef = new value_type[maximum_degree];
		for(unsigned int i = maximum_degree-1; i > 0; --i)
			coef[i] = 0;
		coef[0] = 0;
		current_degree = 0;
	}
	polynomial::polynomial(double a0)
	{
		maximum_degree = DEFAULT_DEGREE;
		coef = new value_type[maximum_degree];
		coef[0] = a0;
		for(unsigned int i = maximum_degree-1; i > 0; --i)
			coef[i] = 0;
		current_degree = 0;
	}
	polynomial::~polynomial( )
	{
		delete [ ] coef;
	}
	void polynomial::add_to_coef(double amount, unsigned int exponent)
	//     PRECONDITION: exponent <= MAXIMUM_DEGREE.
	//     POSTCONDITION: Adds the given amount to the coefficient of the
	//     specified exponent.
	{
			if(exponent > maximum_degree)
				reserve(exponent);
			coef[exponent] += amount;
			
			current_degree = exponent;
			
	}
	void polynomial::reserve(size_t new_capacity)
	{
		value_type *larger_array;
		
		if(new_capacity == maximum_degree)
			return;
			
		if(new_capacity < maximum_degree)
			new_capacity = maximum_degree;
			
		larger_array = new value_type[new_capacity];
		copy(coef, coef + degree(), larger_array);
		delete [ ] coef;
		coef = larger_array;
		current_degree = new_capacity;
	}
	void polynomial::assign_coef(double coefficient, unsigned int exponent)
	//     PRECONDITION: exponent <= MAXIMUM_DEGREE.
	//     POSTCONDITION: Sets the coefficient for the specified exponent.
	{
			if(exponent > maximum_degree)
				reserve(exponent);
			coef[exponent] = coefficient;
			
			if(current_degree < exponent)
				current_degree = exponent;
			
	}
	void polynomial::clear( )
	//     POSTCONDITION: All coefficients of this polynomial are set to zero.
	{
			unsigned int i;
			for(i = 0; i < degree( ); ++i)
				coef[i] = 0;
			current_degree = 0;
	}
	double polynomial:: coefficient(unsigned int exponent) const
	{
		if(exponent <= degree( ))
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
			
		polynomial a_poly((coef[degree( )])/(degree( )+1));
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
		polynomial d_poly((coef[degree( )])*(degree( )-1));			
		
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
	void polynomial::operator +=(const polynomial& addend)
	{
		if(degree( ) + addend.degree( ) > maximum_degree)
			reserve(degree( ) + addend.degree( ));
			
		copy(addend.coef, addend.coef + addend.degree( ), coef + degree( ));
		current_degree += addend.degree( );
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
			
			
			polynomial poly_sum;
			
			
			for(i = new_degree; i > 0; --i)
			{
				
				new_coefficient = p1.coefficient(i) + p2.coefficient(i);
				
				if(new_coefficient != 0)
					poly_sum.assign_coef(new_coefficient, i);
				cout << "+operator out:\t" << poly_sum << endl;
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
			polynomial poly_diff;
			
			for(i = new_degree; i > 0; --i)
			{
				
				new_coefficient = p1.coefficient(i) - p2.coefficient(i);
				if(new_coefficient != 0)
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
			polynomial poly_multi;
			
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
	polynomial& polynomial::operator =(const polynomial& source)
	{
		value_type *new_data;
		
		// Check for possible self assignment
		if(this == &source)
			return *this;
		
		if(maximum_degree != source.maximum_degree)
		{
			new_data = new value_type[source.maximum_degree];
			delete [ ] coef;
			coef = new_data;
			maximum_degree = source.maximum_degree;
		}
		current_degree = source.current_degree;
		copy(source.coef, source.coef + (current_degree + 1), coef);
		return *this;
	}
	polynomial& polynomial::operator =(double a0)
	{
		coef[0] = a0;
		for(unsigned int i = this->degree( ); i > 1; --i)
			coef[i] = 0;
		return *this;
	}
}

