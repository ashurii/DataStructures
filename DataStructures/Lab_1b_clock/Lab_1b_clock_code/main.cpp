#include <stdio.h>
#include <iostream>
#include <iomanip>     // Provides setw function for setting output width
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <cassert>     // Provides assert function
#include <math.h>
#include <string>
#include "Clock.h"
using namespace std;        // Allows all Standard Library items to be used
int main()
{

	Clock time;
	
	cout << "Initial time is" << time.get_Hour() << ":";
	if(time.get_Minutes() < 10)
	{
		cout<<"0" << time.get_Minutes()<<endl;
		}
	else
	{
		cout<< time.get_Minutes()<<endl;
		}
}
