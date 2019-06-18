#include "Date.h"
Date::Date()
{
	m_day = 2;
	m_month = 11;
	m_year = 2012;
}
Date::Date(int year)
{
	m_day = 1;
	m_month = 1;
	m_year = year;
}
Date::Date(int year, int month)
{
	m_day = 1;
	m_month = month;
	m_year = year;
}
Date::Date(int year, int month, int day)
{
	m_day = day;
	m_month = month;
	m_year = year;
}
Date::Date(const Date& p)
{
	m_day = p.m_day;
	m_month = p.m_month;
	m_year = p.m_year;
}

Date Date::Tomorrow()
{
	Date tomorrow;
	if (m_day == returnLastDayOfMonth())
	{
		tomorrow.m_day = 1;
		if (m_month == 12)
		{
			tomorrow.m_month = 1;
			tomorrow.m_year = m_year + 1;
		}
		else
		{
			tomorrow.m_month = m_month + 1;
			tomorrow.m_year = m_year;
		}
	}
	else
	{
		tomorrow.m_day = m_day + 1;
		tomorrow.m_month = m_month;
		tomorrow.m_year = m_year;
	}
	return tomorrow;
}
Date Date::Yesterday()
{
	Date yesterday;
	if (m_day == 1)
	{
		if (m_month == 1)
		{
			yesterday.m_month = 12;
			yesterday.m_day = 31;
			yesterday.m_year = m_year - 1;
		}
		else
		{
			yesterday.m_month = m_month - 1;
			yesterday.m_day = yesterday.returnLastDayOfMonth();
			yesterday.m_year = m_year;
		}
	}
	else
	{
		yesterday.m_day = m_day - 1;
		yesterday.m_month = m_month;
		yesterday.m_year = m_year;
	}
	return yesterday;
}
int Date::returnLastDayOfMonth()
{
	switch (m_month)
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
bool Date::checkTime()
{
	if (m_month == 2)
	{
		return checkFeb();
	}
	else
	{
		if ((m_month <= 0 || m_month > 12) || (m_day <= 0 || m_day > returnLastDayOfMonth()) || (m_year <= 0))
			return 0;
		else
			return 1;
	}

}
bool Date::checkFeb()
{
	if (m_day <= 0)
		return 0;
	else
	{
		if ((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0))
		{
			if (m_day > 29)
				return 0;
			else
				return 1;
		}
		else
		{
			if (m_day > 28)
				return 0;
			else
				return 1;
		}

	}
}

Date& Date::operator =(Date p)
{
	m_day = p.m_day;
	m_month = p.m_month;
	m_year = p.m_year;
	return *this;
}
bool Date::operator ==(Date p)
{
	if (m_day == p.m_day && m_month == p.m_month && m_year == p.m_year)
		return 1;
	else
		return 0;
}
bool Date::operator !=(Date p)
{
	if (m_day == p.m_day && m_month == p.m_month && m_year == p.m_year)
		return 0;
	else
		return 1;
}
bool Date::operator >=(Date p)
{
	if (m_day >= p.m_day && m_month >= p.m_month && m_year >= p.m_year)
		return 1;
	else
		return 0;
}
bool Date::operator <=(Date p)
{
	if (m_day <= p.m_day && m_month <= p.m_month && m_year <= p.m_year)
		return 1;
	else
		return 0;
}
bool Date::operator >(Date p)
{
	if (m_day > p.m_day && m_month > p.m_month && m_year > p.m_year)
		return 1;
	else
		return 0;
}
bool Date::operator <(Date p)
{
	if (m_day < p.m_day && m_month < p.m_month && m_year < p.m_year)
		return 1;
	else
		return 0;
}

Date Date::operator +(int day)
{
	Date temp;
	temp = *this;
	temp.m_day += day;
	if (temp.checkTime() == 0)
	{
		if (temp.m_month == 12)
		{
			temp.m_day = m_day - this->returnLastDayOfMonth() + day;
			temp.m_month = 1;
			temp.m_year += 1;
		}
		else
		{
			temp.m_day = m_day - this->returnLastDayOfMonth() + day;
			temp.m_month += 1;
		}
	}
	return temp;
}
Date Date::operator -(int day)
{
	Date temp;
	temp = *this;
	temp.m_day -= day;
	if (temp.checkTime() == 0)
	{
		if (temp.m_month == 1)
		{
			temp.m_month = 12;
			temp.m_year -= 1;
			temp.m_day = m_day - day + temp.returnLastDayOfMonth();
		}
		else
		{
			temp.m_month -= 1;
			temp.m_day = m_day - day + temp.returnLastDayOfMonth();
		}
	}
	return temp;
}

Date& Date::operator +=(int x)
{
	*this = *this + x;
	return *this;
}
Date& Date::operator -=(int x)
{
	*this = *this - x;
	return *this;
}

Date& Date::operator ++()
{
	m_day++;
	if (checkTime() == 0)
	{
		if (m_month == 12)
		{
			m_day = 1;
			m_month = 1;
			m_year++;
		}
		else
		{
			m_day = 1;
			m_month++;
		}
	}
	return *this;
}
Date Date::operator ++(int x)
{
	Date temp = *this;
	m_day++;
	if (checkTime() == 0)
	{
		if (m_month == 12)
		{
			m_day = 1;
			m_month = 1;
			m_year++;
		}
		else
		{
			m_day = 1;
			m_month++;
		}
	}
	return temp;
}
Date& Date::operator --()
{
	m_day--;
	if (checkTime() == 0)
	{
		if (m_month == 1)
		{
			m_day = 31;
			m_month = 12;
			m_year--;
		}
		else
		{
			m_month--;
			m_day = returnLastDayOfMonth();
		}
	}
	return *this;
}
Date Date::operator --(int x)
{
	Date temp = *this;
	m_day--;
	if (checkTime() == 0)
	{
		if (m_month == 1)
		{
			m_day = 31;
			m_month = 12;
			m_year--;
		}
		else
		{
			m_month--;
			m_day = returnLastDayOfMonth();
		}
	}
	return temp;
}

Date::operator int()
{
	int totalDay = 0;
	Date temp = *this;
	while (--temp.m_month != 0)
	{
		totalDay += temp.returnLastDayOfMonth();
	}
	totalDay += temp.m_day;
	return totalDay - 1;
}
Date::operator long()
{
	int totalDay = 0;
	Date temp = *this;
	while (--temp.m_year != 0)
	{
		if ((temp.m_year % 4 == 0 && temp.m_year % 100 != 0) || (temp.m_year % 400 == 0))
		{
			totalDay += 366;
		}
		else
		{
			totalDay += 365;
		}
	}
	totalDay += (int)*this;
	return totalDay;
}

istream& operator >>(istream& in, Date& p)
{
	char divideSign;
	do
	{
		cout << "Enter dd/mm/yyyy: ";
		in >> p.m_day >> divideSign >> p.m_month >> divideSign >> p.m_year;
	} while (p.checkTime() == 0);
	return in;
}
ostream& operator <<(ostream& out, const Date& p)
{
	out << p.m_day << "/" << p.m_month << "/" << p.m_year << endl;
	return out;
}