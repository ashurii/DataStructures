// Created By Ashly Altman
// Data Structures Section 05

#include <iostream>         // Provides cout and cin
#include <cstdlib>          // Provides EXIT_SUCCESS
using namespace std;        // Allows all Standard Library items to be used
class throttle
{
public:
	//CONSTRUCTORS
	throttle();
	throttle(int totalPositions, int initialPosition);
    // MODIFICATION MEMBER FUNCTIONS
    void shut_off( );
    void shift(int amount);
    // CONSTANT MEMBER FUNCTIONS
    double flow( ) const;
    bool is_on( ) const;
	bool greaterThanHalf( ) const;
private:
    int position;
	int totalPositions;
	int initialPosition;
};

int main( )
{
    throttle sample;
	
	int halfThrottle = 3;
    // Halfway throttle value.
    cout << "I have a throttle with 6 positions." << endl;
	cout << "Shifting the throttle halfway up..."<< endl;
    
    sample.shut_off( );
    sample.shift(halfThrottle);
	sample.greaterThanHalf();
    // Shift the throttle down to zero, printing the flow along the way.
	
	
	
    while (sample.is_on( ))
    {
        cout << "The flow is now " << sample.flow( ) << endl;
        sample.shift(-1);
    }
    cout << "The flow is now off" << endl;
    return EXIT_SUCCESS;
}
throttle::throttle()
{
		totalPositions = 6;
		initialPosition = 0;
}
void throttle::shut_off( )
// Precondition: None.
// Postcondition: The throttle has been turned off.
{
    position = 0;
}
bool throttle::greaterThanHalf( ) const
{
		return (flow() > 0.5);
}
double throttle::flow( ) const
// Precondition: shut_off has been called at least once to initialize the
// throttle.
// Postcondition: The value returned is the current flow as a proportion of
// the maximum flow.
{
    return position / 6.0;
}

void throttle::shift(int amount)
// Precondition: shut_off has been called at least once to initialize the
// throttle.
// Postcondition: The throttle's position has been moved by amount (but not
// below 0 or above 6).
{
    position += amount;

    // Adjust the throttle if it went too high or too low
    if (position < 0)
        position = 0;
    else if (position > 6)
        position = 6;
}

bool throttle::is_on( ) const
// Precondition: shut_off has been called at least once to initialize the
// throttle.
// Postcondition: If the throttle's flow is above 0 then the function
// returns true; otherwise it returns false.
{
    return (flow( ) > 0);
}