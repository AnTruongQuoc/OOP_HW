#include "Time.h"
#include <iostream>
using namespace std;

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}
Time::Time(const Time& src) {
	hour = src.hour;
	minute = src.minute;
	second = src.second;
}
void Time::input()
{
	char sign;
	do
	{
		cout << "Enter time hh:mm:ss : ";
		cin >> hour >> sign >> minute >> sign >> second;
	} while (hour < 0 || hour > 23 || minute < 0 || minute >= 60 || second < 0 || second >= 60);
}
void Time::output()
{
	cout << "Time: " << hour << ":" << minute << ":" << second << endl;
}
Time Time::future()
{
	Time future;
	if (this->second == 59)
	{
		future.second = 0;
		if (this->minute == 59)
		{
			future.minute = 0;
			if (this->hour == 23)
			{
				future.hour = 0;
			}
			else
			{
				future.hour = this->hour + 1;
			}
		}
		else
		{
			future.minute = this->minute + 1;
			future.hour = this->hour;
		}
	}
	else
	{
		future.second = this->second + 1;
		future.minute = this->minute;
		future.hour = this->hour;
	}
	return future;
}