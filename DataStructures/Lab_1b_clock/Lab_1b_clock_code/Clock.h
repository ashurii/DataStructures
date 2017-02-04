#ifndef CLOCK_H
#define CLOCK_H
#include <string>
using namespace std;
class Clock
{
public:
	Clock();
	~Clock();
	void set_time(int newHour, int newMinute, string& newAmpm);
	
	int get_Hour() const;
	int get_Minutes() const;
	std::string get_Ampm() const;
	void advance_time(int minute_add);
private:
	int hour;
	int minute;
	std::string ampm;

};

#endif // CLOCK_H
