#include "Clock.h"
using namespace std;
Clock::Clock()
{
	hour = 12;
	minute = 0;
	ampm = "am";
}

Clock::~Clock()
{
}
void Clock::set_time(int newHour, int newMinute, string& newAmpm)
{
	hour = newHour;
	minute = newMinute;
	ampm = newAmpm;
}
int Clock::get_Hour() const{return hour;}
int Clock::get_Minutes() const{return minute;}
string Clock::get_Ampm() const{return ampm;}
void Clock::advance_time(int minute_add)
{
	if((minute+ minute_add) >= 60)
	{
		hour+=1;
		minute = (minute + minute_add) - 60;
	}
	if(hour > 12)
	{
		hour = (hour-12);
		if(ampm == "am")
			ampm = "pm";
		else
			ampm = "am";
	}
}
