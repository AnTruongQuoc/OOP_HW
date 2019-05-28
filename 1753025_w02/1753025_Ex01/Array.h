#pragma once
#include "Fraction.h"
#include <iostream>

using namespace std;

class Array
{
public:
	Array();
	void input(const char *nameFile);
	void output();
	Fraction findMax();
	Fraction findMin();
	Fraction calcSum();
	void swapElement(Fraction &b, Fraction &y);
	void sortAscending();
	~Array();

private:
	Fraction *array;
	int length;
};

