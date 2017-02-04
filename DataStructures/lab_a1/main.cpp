
// Ashly Altman
// Instructor: Dr Bobbie
// CS3304
// Section 05
// Lab 1a
 
#include "main.h"
#include <iostream>
#include <iomanip>     // Provides setw function for setting output width
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <cassert>     // Provides assert function
using namespace std;

/*--------------------------------------------
 * Problem 8: Feet to Meters Converstion Table
 * -------------------------------------------*/

double feet_to_meters(double f)
{
	
    return f/3.28;  

}

/*--------------------------------------------
 * Problem 11: Feet to Meters Converstion Table
 * -------------------------------------------*/
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
		
		//Souther Version of Hello World 
	cout <<"Buenos dias, mundo!" << endl;
	
	//Conversion Table from Feet To Meters
	const char   HEADING1[]  = "   Feet"; // Heading for table's 1st column
    const char   HEADING2[]  = "Meters"; // Heading for table's 2nd column
    const char   LABEL1      =          'F'; // Label for numbers in 1st column
    const char   LABEL2      =          'M'; // Label for numbers in 2nd column
    const double TABLE_BEGIN =         -1.0; // The table's first Measurement in Feet.
    const double TABLE_END   =         50.0; // The table's final Measurement in Feet.
    const double TABLE_STEP  =         10.0; // Increment between measurements
    const int    WIDTH       =            9; // Number chars in output numbers
    const int    DIGITS      =            1; // Number digits right of decimal pt

    double value1;  // A value from the table's first column
    double value2;  // A value from the table's second column
    
    // Set up the output for fractions and print the table headings.
    setup_cout_fractions(DIGITS);
    cout << "CONVERSIONS from " << TABLE_BEGIN << " to " << TABLE_END << endl;
    cout << HEADING1 << "  " << HEADING2 << endl;
    
    // Each iteration of the loop prints one line of the table.
    for (value1 = TABLE_BEGIN; value1 <= TABLE_END; value1 += TABLE_STEP) 
    {   
		
        value2 = feet_to_meters(value1);
        cout << setw(WIDTH) << value1 << LABEL1 << "  "; 
        if(value2 >= 0){
		cout << setw(WIDTH) << value2 << LABEL2 << endl; }
		else
			cout << setw(WIDTH) << "value must be greater than 0" << endl;
    }

    return EXIT_SUCCESS;
	}
