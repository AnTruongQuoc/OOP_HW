#pragma once
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(const Date& src);
	void setTime();
	void display();
	void inputTime();
	bool checkTime();
	bool checkFeb();
	Date theNextDay();
	Date theDayBefore();
	int returnLastDayOfMonth();
	
};

