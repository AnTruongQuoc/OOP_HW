#include "Fraction.h"
#include <iostream>
#include <cmath>


Fraction::Fraction() {
	nu = 0;
	de = 1;
}

Fraction::Fraction(const Fraction& src) {
	nu = src.nu;
	de = src.de;
}

Fraction::~Fraction() {}

int Fraction::GCD(const Fraction& a) {
	int n = abs(a.nu);
	int m = abs(a.de);
	if (n == 0 || m == 0)
		return n + m;
	while (n != m)
	{
		if (n > m)
			n = n - m;
		else
			m = m - n;
	}
	return n;
}
Fraction Fraction::reduceFrac(Fraction &a) {
	a.nu = a.nu / GCD(a);
	a.de = a.de / GCD(a);
	return a;
}
Fraction Fraction::standardize(Fraction &a) {
	if (a.de < 0)
	{
		a.nu = -a.nu;
		a.de = -a.de;
	}
	return a;
}

Fraction::Fraction(int x) {
	this->nu = x;
	this->de = 1;
}

Fraction::Fraction(int x, int y) {
	if (y == 0)
		return;
	this->nu = x;
	this->de = y;
	reduceFrac(*this);
	standardize(*this);
}

Fraction& Fraction::operator++() {
	*this = *this + 1;
	return *this;
}

Fraction& Fraction::operator--() {
	*this = *this - 1;
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp;
	temp = *this;
	++(*this);
	return temp;
}

Fraction Fraction::operator--(int) {
	Fraction temp;
	temp = *this;
	--(*this);
	return temp;
}

Fraction& Fraction::operator+=(const Fraction& a) {
	this->nu = this->nu*a.de + a.nu*this->de;
	this->de = this->de*a.de;
	reduceFrac(*this);
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& a) {
	this->nu = this->nu*a.de - a.nu*this->de;
	this->de = this->de*a.de;
	reduceFrac(*this);
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& a) {
	this->nu = this->nu*a.nu;
	this->de = this->de*a.de;
	reduceFrac(*this);
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& a) {
	if (a.nu == 0)
	{
		return *this;
	}
	else {
		this->nu = this->nu*a.de;
		this->de = this->de*a.nu;
		reduceFrac(*this);
		return *this;
	}
}

Fraction& Fraction::operator=(const Fraction& a) {
	if (a.de == 0)
	{
		reduceFrac(*this);
		return *this;
	}
	this->nu = a.nu;
	this->de = a.de;
	reduceFrac(*this);
	return *this;
}
Fraction::operator float(){
	return (float)nu / (float)de;
}

