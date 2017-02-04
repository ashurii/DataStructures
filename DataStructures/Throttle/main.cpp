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

int main(int argc, char **argv)
{
	throttle a;
	
	//throttle new_throttle;
	cout << "Please type a number from 0 to 6:";
	return 0;
}
void throttle::shut_off( )
{
	position = 0;
}
throttle::throttle()
{
}

throttle::~throttle()
{
}