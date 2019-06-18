#pragma once
#include <iostream>

using namespace std;

class Fraction {
private:
	int nu; //tu so
	int de; //mau so
public:
	Fraction();
	Fraction(const Fraction& src);
	Fraction(int x); 
	Fraction(int x, int y);
	//Fraction(float x, float y);
	int GCD(const Fraction& a); //find Greatest Common Divisor
	Fraction reduceFrac(Fraction &a);
	Fraction standardize(Fraction &a);
	explicit operator float();

	friend Fraction operator+(const Fraction& a, const Fraction& b);
	friend Fraction operator-(const Fraction& a, const Fraction& b);
	friend Fraction operator*(const Fraction& a, const Fraction& b);
	friend Fraction operator/(const Fraction& a, const Fraction& b);

	Fraction& operator+=(const Fraction& a);
	Fraction& operator-=(const Fraction& a);
	Fraction& operator*=(const Fraction& a);
	Fraction& operator/=(const Fraction& a);
	Fraction& operator=(const Fraction& a);

	

	friend bool operator==(const Fraction& a, const Fraction& b);
	friend bool operator<=(const Fraction& a, const Fraction& b);
	friend bool operator>=(const Fraction& a, const Fraction& b);
	friend bool operator>(const Fraction& a, const Fraction& b);
	friend bool operator<(const Fraction& a, const Fraction& b);
	friend bool operator!=(const Fraction& a, const Fraction& b);

	//extraction op
	friend ostream& operator << (ostream &os, Fraction a);
	//insertion op
	friend istream& operator >> (istream &is, Fraction &a);

	Fraction& operator++();		//postfix
	Fraction operator++(int);	//prefix
	Fraction& operator--();
	Fraction operator--(int);
	

	~Fraction();
};