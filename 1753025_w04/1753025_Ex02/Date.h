#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date();
	Date(int year);
	Date(int year, int month);
	Date(int year, int motnh, int day);
	Date(const Date& p);
	Date Tomorrow();
	Date Yesterday();
	bool checkTime();
	bool checkFeb();
	int returnLastDayOfMonth();

	Date& operator =(Date p);
	bool operator ==(Date p);
	bool operator !=(Date p);
	bool operator >=(Date p);
	bool operator <=(Date p);
	bool operator >(Date p);
	bool operator <(Date p);
	Date operator +(int day);
	Date operator -(int day);
	Date& operator ++();
	Date operator ++(int x);
	Date& operator --();
	Date operator --(int x);
	Date& operator +=(int x);
	Date& operator -=(int x);

	explicit operator int();
	explicit operator long();

	friend istream& operator >>(istream& in, Date& p);
	friend ostream& operator <<(ostream& out, const Date& p);
};