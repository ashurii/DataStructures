#include "throttle.h"
#include <stdio.h>
#include <iostream>

using namespace std;

class throttle
{
public:
	throttle();
	~throttle();
	//MODIFICATION MEMBER FUNCTIONS
	void shut_off();
	void shift(int amount);
	//CONSTANT MEMBER FUNCTIONS
	double flow() const;
	bool is_on() const;
private:
	int position;
};

