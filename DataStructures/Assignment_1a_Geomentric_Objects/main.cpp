// Ashly Altman
// Instructor: Dr Bobbie
// CS3304
// Section 05
// Assignment 1a
 



#include <iostream>
#include <iomanip>     // Provides setw function for setting output width
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <cassert>     // Provides assert function
#include <math.h>
using namespace std;

/*--------------------------------------------
 * Geometric Objects Area Calculator
 * -------------------------------------------*/

double equilateral_triangle_Area(double f)
{
	
    return (pow(3.0,0.5)/4)*(pow(f,0.4));  

}
double square_Area(double f)
{
	
    return pow(f,2.0);  

}
double pentagon_Area(double f)
{
	
    return (.25)*(pow(5*(5+2*pow(5,0.5)),0.5))*(pow(f,0.5));  

}
double hexagon_Area(double f)
{
	
    return ((3*pow(3,0.5))/2)*(pow(f,0.5));  

}
double heptagon_Area(double f)
{
	
    return (7/4)*(pow(f,2.0))*(1/tan(0.45));  

}
double octagon_Area(double f)
{
	
    return 2*(1+pow(2,0.5)*pow(f,2.0));  

}


void setup_cout_fractions(int fraction_digits)
// Precondition: fraction_digits is not negative.
// Postcondition: All double or float numbers printed to cout will now be
// rounded to the specified digits on the right of the decimal.
{
    assert(fraction_digits > 0);
    cout.precision(fraction_digits);
    cout.setf(ios::fixed, ios::floatfield);
    if (fraction_digits == 0)
        cout.unsetf(ios::showpoint);
    else
        cout.setf(ios::showpoint); 
}

int main()
	{
		
	
	//Conversion Table from Feet To Meters
	const char   HEADING1[]  = "Side"; // Heading for table's 1st column
    const char   HEADING2[]  = "Tri"; // Heading for table's 2nd column
	const char   HEADING3[]  = "Sq"; // Heading for table's 3rd column
	const char   HEADING4[]  = "Pent"; // Heading for table's 4th column
	const char   HEADING5[]  = "Hex"; // Heading for table's 5th column
	const char   HEADING6[]  = "Hept"; // Heading for table's 6th column
	const char   HEADING7[]  = "Oct"; // Heading for table's 7th column

	
    const double TABLE_BEGIN =         1.0; // The table's first side length.
    const double TABLE_END   =         6.0; // The table's final side length.
    const double TABLE_STEP  =         1.0; // Increment between measurements
    const int    WIDTH       =            9; // Number chars in output numbers
    const int    DIGITS      =            1; // Number digits right of decimal pt

    double value1;  // A value from the table's first column
    double value2;  // A value from the table's second column
	double value3;  // A value from the table's third column
	double value4;  // A value from the table's fourth column
	double value5;  // A value from the table's 5th column
	double value6;  // A value from the table's 6th column
	double value7;  // A value from the table's 7th column
    
    // Set up the output for fractions and print the table headings.
    setup_cout_fractions(DIGITS);
    cout << "Geometric Areas"<< endl;
    cout << HEADING1 << "\t" << HEADING2 <<"\t" << HEADING3 <<"\t" << HEADING4<<"\t" << HEADING5<<"\t" << HEADING6<<"\t" << HEADING7<<"\t"<<endl;
    
    // Each iteration of the loop prints one line of the table.
    for (value1 = TABLE_BEGIN; value1 <= TABLE_END; value1 += TABLE_STEP) 
    {   
		
        value2 = equilateral_triangle_Area(value1);
		value3 = square_Area(value1);
		value4 = pentagon_Area(value1);
		value5 = hexagon_Area(value1);
		value6 = heptagon_Area(value1);
		value7 = octagon_Area(value1);
		
        cout << value1  << "\t" <<  value2  << "\t" << value3  << "\t" << value4  << "\t" << value5  << "\t" << value6  << "\t" <<  value7  << "\t" <<endl; 
        if(value1 >= 0){
		}
		
		else
			cout << setw(WIDTH) << "value must be greater than 0" << endl;
    }

    return EXIT_SUCCESS;
	}

