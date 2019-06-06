#include "Date.h"
#include <iostream>
#include <ctime>
using namespace std;

Date::Date()
{
	year = 0;
	month = 0;
	day = 0;
}
Date::Date(const Date& src) {
	year = src.year;
	month = src.month;
	day = src.day;
}
void Date::setTime()
{
	time_t now = time(0);
	tm *present = localtime(&now);
	year = 1900 + present->tm_year;
	month = 1 + present->tm_mon;
	day = present->tm_mday;
}
void Date::display()
{
	cout << day << "/" << month << "/" << year << endl;
}
void Date::inputTime()
{
	char sign;
	cout << "Input date dd/mm/yyyy: ";
	cin >> day >> sign >> month >> sign >> year;
}

bool Date::checkTime()
{
	if (month == 2)
	{
		return checkFeb();
	}
	else
	{
		if ((month <= 0 || month > 12) || (day <= 0 || day > returnLastDayOfMonth()) || (year <= 0))
			return 0;
		else
			return 1;
	}

}
bool Date::checkFeb()
{
	if (day <= 0)
		return 0;
	else
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day > 29)
				return 0;
			else
				return 1;
		}
		else
		{
			if (day > 28)
				return 0;
			else
				return 1;
		}

	}
}
Date Date::theNextDay()
{
	Date tomorrow;
	if (day == returnLastDayOfMonth())
	{
		tomorrow.day = 1;
		if (month == 12)
		{
			tomorrow.month = 1;
			tomorrow.year = year + 1;
		}
		else
		{
			tomorrow.month = month + 1;
			tomorrow.year = year;
		}
	}
	else
	{
		tomorrow.day = day + 1;
		tomorrow.month = month;
		tomorrow.year = year;
	}
	return tomorrow;
}
Date Date::theDayBefore()
{
	Date yesterday;
	if (day == 1)
	{
		if (month == 1)
		{
			yesterday.month = 12;
			yesterday.day = 31;
			yesterday.year = year - 1;
		}
		else
		{
			yesterday.month = month - 1;
			yesterday.day = yesterday.returnLastDayOfMonth();
			yesterday.year = year;
		}
	}
	else
	{
		yesterday.day = day - 1;
		yesterday.month = month;
		yesterday.year = year;
	}
	return yesterday;
}
int Date::returnLastDayOfMonth()
{
	switch (month)
	{
	case 1:return 31;
	case 2:return 28;
	case 3:return 31;
	case 4:return 30;
	case 5:return 31;
	case 6:return 30;
	case 7:return 31;
	case 8:return 31;
	case 9:return 30;
	case 10:return 31;
	case 11:return 30;
	case 12:return 31;
	default: return 0;
	}
}