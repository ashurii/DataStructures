// FILE: poly.h
// CLASS PROVIDED:
//   class polynomial (in the namespace colorado_edu)
//     A polynomial has one variable x, real number coefficients, and
//     non-negative integer exponents. Such a polynomial can be viewed
//     as having the form:
//       A[n]*x^n + A[n-1]*x^(n-1) + ... A[2]*x^2 + A[1]*x + A[0]
//     where the A[n] are the real number coefficients and x^i represents
//     the variable x raised to the i power. The coefficient A[0] is
//     called the "constant" or "zeroth" term of the polynomial.
//   
// MEMBER CONSTANTS
//   const static size_t MAXIMUM_DEGREE
//     The size of the maximum exponent permitted for a polynomial.
//
// CONSTRUCTOR for the polynomial class
//   polynomial(double c = 0.0, size_type exponent = 0)
//     PRECONDITION: exponent <= MAXIMUM_DEGREE
//     POSTCONDITION: This polynomial has been created with all zero
//     coefficients, except for coefficient c for the specified exponent.
//     When used as a default constructor (using default values for
//     both arguments), the result is a polynomial with all zero
//     coefficients.
//
// MODIFICATION MEMBER FUNCTIONS for the polynomial class
//   void add_to_coef(double amount, size_type exponent)
//     PRECONDITION: exponent <= MAXIMUM_DEGREE.
//     POSTCONDITION: Adds the given amount to the coefficient of the
//     specified exponent.
//
//   void assign_coef(double coefficient, size_type exponent)
//     PRECONDITION: exponent <= MAXIMUM_DEGREE.
//     POSTCONDITION: Sets the coefficient for the specified exponent.
//
//   void clear( )
//     POSTCONDITION: All coefficients of this polynomial are set to zero.
//
// CONSTANT MEMBER FUNCTIONS for the polynomial class
//   polynomial antiderivative( ) const
//     PRECONDITION: degree( ) < MAXIMUM_DEGREE
//     POSTCONDITION: The return value is the antiderivative (indefinite integral)
//     of this polynomial.
//     NOTE: The return polynomial always has a constant term of zero.
//
//   double coefficient(size_type exponent) const
//     POSTCONDITION: Returns coefficient at specified exponent of this
//     polynomial.
//     NOTE: For exponents > MAXIMUM_DEGREE, the return value is always zero.
//
//   double definite_integral(double x0, double x1) const
//     POSTCONDITION: Returns the value of the definite integral computed from
//     x0 to x1.  The answer is computed analytically.
//
//   size_type degree( ) const
//     POSTCONDITION: The function returns the value of the largest exponent
//     with a non-zero coefficient.
//     If all coefficients are zero, then the function returns zero (even
//     though, technically, this polynomial does not have a degree).
//
//   polynomial derivative( ) const
//     POSTCONDITION: The return value is the first derivative of this 
//     polynomial.
//
//   double eval(double x) const
//     POSTCONDITION: The return value is the value of this polynomial with the
//     given value for the variable x.
//
//   void find_root(
//     double& answer,
//     bool& success,
//     size_type& iterations,
//     double starting_guess = 0,
//     size_type maximum_iterations = 100,
//     double epsilon = 1e-8
//     )
//     const
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
//
//   bool is_zero( ) const
//     POSTCONDITION: The return value is true if and only if the polynomial
//     is the zero polynomial.
//
//   size_type next_term(size_type e) const
//     POSTCONDITION: The return value is the next exponent n which is LARGER
//     than e such that coefficient(n) != 0.
//     If there is no such term, then the return value is zero.
//
//   double numeric_definite_integral(double x0, double x1, size_type n) const
//     POSTCONDITION: Returns the value of the definite integral computed from
//     x0 to x1 by using the trapezoid method with n sections of equal width.
//
//   size_type previous_term(size_type e) const
//     POSTCONDITION: The return value is the next exponent n which is SMALLER
//     than e such that coefficient(n) != 0.
//     If there is no such term, then the return value is UINT_MAX
//     from <climits>.
//
// CONSTANT OPERATORS for the polynomial class
//   double operator( ) (double x) const
//     Same as the eval member function.
//
// NON-MEMBER BINARY OPERATORS for the polynomial Class
//   polynomial operator -(const polynomial& p1, const polynomial& p2)
//     POSTCONDITION: return-value is a polynomial with each coefficient
//     equal to the difference of the coefficients of p1 & p2 for any given
//     exponent.
//
//   polynomial operator +(const polynomial& p1, const polynomial& p2)
//     POSTCONDITION: return-value is a polynomial with each coefficient
//     equal to the sum of the coefficients of p1 & p2 for any given
//     exponent.
//
//   polynomial operator *(const polynomial& p1, const polynomial& p2)
//     PRECONDITION: p1.degree( ) + p2.degree( ) <= MAXIMUM_DEGREE.
//     POSTCONDITION: Each term of p1 has been multiplied by each term of p2,
//     and the answer is the sum of all these term-by-term products.
//     For example, if p1 is 2x^2 + 3x + 4 and p2 is 5x^2 - 1x + 7, then the
//     return value is 10x^4 + 13x^3 + 31x^2 + 17x + 28.
//
// NON-MEMBER OUTPUT FUNCTIONS for the polynomial Class
//   ostream& operator << (ostream& out, const polynomial& p)
//     POSTCONDITION: The polynomial has been printed to ostream out, which,
//     in turn, has been returned to the calling function.
//
//   void make_gif(
//     const polynomial& p,
//     const char filename[ ],
//     double low_x,
//     double high_x,
//     double low_y,
//     double high_y
//     )
//     PRECONDITION: filename is a legal filename for a gif file.
//     Also (low_x < high_x) && (low_y < high_y).
//     POSTCONDITION: A gif file has been written to the specified filename
//     with a graphical representation of the polynomial in the specified
//     ranges (low_x...high_x and low_y...high_y).
//
// The value semantics (copy constructor and assignment operator) are valid for
// the polynomial class.

#ifndef POLY_H
#define POLY_H
#include <cstdlib>
#include <iostream>  // Provides ostream
namespace colorado_edu
{
    
    class polynomial
    {
    public:
	typedef double value_type;
	typedef std::size_t size_type;
	// CONSTANTS
	static const size_type DEFAULT_DEGREE = 29;
	
        // CONSTRUCTOR
	polynomial( );
	polynomial(double a0);
	polynomial(const polynomial& source);
	~polynomial( );
	// MODIFICATION MEMBER FUNCTIONS
	void add_to_coef(double amount, unsigned int exponent);
	void assign_coef(value_type coefficient, unsigned int exponent);
	void clear( );
	void reserve(size_t number);
	
	// CONSTANT MEMBER FUNCTIONS
     polynomial antiderivative( ) const;
	 
	value_type coefficient(unsigned int exponent) const;
	value_type definite_integral(value_type x0, value_type x1) const;
	size_type degree( ) const { return current_degree; }
	polynomial derivative( ) const;
	
	value_type eval(value_type x) const;
	bool is_zero( ) const;
	unsigned int next_term(unsigned int e) const;
	value_type numeric_definite_integral(value_type x0, value_type x1, unsigned int n);
	unsigned int previous_term(unsigned int e) const;
	
	void operator +=(const polynomial& addend);
	polynomial& operator =(const polynomial& source);
	polynomial& operator =(double a0);
	// CONSTANT OPERATORS
	value_type operator( ) (value_type x) const { return eval(x); }
    private:
	value_type *coef;
	size_type current_degree;
	size_type maximum_degree;
    };
    
    // NON-MEMBER BINARY OPERATORS
	
	
    polynomial operator +(const polynomial& p1, const polynomial& p2);
    polynomial operator -(const polynomial& p1, const polynomial& p2);
    polynomial operator *(const polynomial& p1, const polynomial& p2);
    
    // NON-MEMBER OUTPUT FUNCTIONS
    std::ostream& operator << (std::ostream& out, const polynomial& p);
   

}
#endif
