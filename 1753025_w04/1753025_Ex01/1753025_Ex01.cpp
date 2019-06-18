#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction operator+(const Fraction& a, const Fraction& b) {
	
	Fraction temp;
	temp.nu = a.nu*b.de + a.de*b.nu;
	temp.de = a.de*b.de;
	return temp;
}

Fraction operator-(const Fraction& a, const Fraction& b) {
	Fraction temp;
	temp.nu = a.nu*b.de - a.de*b.nu;
	temp.de = a.de*b.de;
	return temp;
}

Fraction operator*(const Fraction& a, const Fraction& b) {
	Fraction temp;
	temp.nu = a.nu*b.nu;
	temp.de = a.de*b.de;
	return temp;
}

Fraction operator/(const Fraction& a, const Fraction& b) {
	Fraction temp;
	if (b.nu == 0)
	{
		cout << "Can't divde between " << a.nu << "/" << a.de << " and " << b.nu << "/" << b.de << endl;
		
	}
	temp.nu = a.nu*b.de;
	temp.de = a.de*b.nu;
	return temp;
}



bool operator==(const Fraction& a, const Fraction& b)
{
	return (a.nu*b.de == a.de*b.nu);
}

bool operator!=(const Fraction& a, const Fraction& b)
{
	return !(a == b);
}

bool operator>(const Fraction& a, const Fraction& b)
{
	return (a.nu*b.de > a.de*b.nu);
}

bool operator>=(const Fraction& a, const Fraction& b)
{
	return (a > b || a == b);
}

bool operator<(const Fraction& a, const Fraction& b)
{
	return (a.nu*b.de < a.de*b.nu);
}
bool operator<=(const Fraction& a, const Fraction& b)
{
	return (a < b || a == b);
}

ostream& operator << (ostream &os, Fraction a)
{
	if (a.de == 1)
		os << a.nu << endl;
	else
		os << a.nu << "/" << a.de << "\n";
	return os;
}

istream& operator >> (istream &in, Fraction &a)
{
	in >> a.nu;
	do {
		in >> a.de;
	} while (a.de == 0);
	return in;
}


void main() {
	Fraction f1, f2;					// 0/1
	Fraction f3(1, -7);				// -1/7
	Fraction f4(f3);				// Copy constructor
	Fraction f5 = f2;					// Copy constructor
	Fraction f6, f7, f8;					// Default constructor
	f6 = f3;							// Operator =

	f7 = f1 + f5;
	//cout << f7;
	f8 = f2 - f4;
	//cout << f8;
	f3 = f1 * f7;
	//cout << f3;
	f5 = f6 / f2;
	//cout << f5;

	if (f2 == f3)
		cout << "f2==f3" << endl;
	if (f3 != f1)
		cout << "f3!=f1" << endl;
	if (f2 >= f5)
		cout << "f2>=f5" << endl;
	if (f2 > f5)
		cout << "f2>f5" << endl;
	if (f5 <= f3)
		cout << "f5<=f3" << endl;
	if (f5 < f3)
		cout << "f5<f3" << endl;

	f1 = f2 + 3;
	f3 = -7 + f1;
	f5 = 7 * f3;
	f6 = f4 - 6;

	cout << f3;
	cout << f6;

	f1 += f5;
	f6 -= f7;
	f8 *= f1;
	f8 /= f2;

	cout << f8++;
	cout << ++f7;

	cout << f8--;
	cout << --f7;

	float f = (float)f3;
	//cout << f;
	
	system("pause");
}