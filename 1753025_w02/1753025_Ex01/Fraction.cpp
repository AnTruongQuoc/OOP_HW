#include "Fraction.h"
#include <iostream>

using namespace std;


Fraction::Fraction()
{
	num = 0;
	denom = 1;
}

void Fraction::input()
{
	char divSign; // "/"
	do
	{
		cout << "Input a fraction a/b: ";
		cin >> num >> divSign >> denom;
	} while (denom == 0);
}

int& Fraction::getNum()
{
	return num;
}

int& Fraction::getDenom()
{
	return denom;
}

void Fraction::display()
{
	cout << num << "/" << denom << " ";
}

bool Fraction::compare(Fraction p)
{
	double x = (this->num * 1.0) / this->denom;
	double y = (p.num * 1.0) / p.denom;
	return x > y;
}

Fraction Fraction::add(Fraction p)
{
	Fraction sum;
	sum.num = this->num * p.denom + p.num * this->denom;
	sum.denom = this->denom * p.denom;
	return sum;
}

