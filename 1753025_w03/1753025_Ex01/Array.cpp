#include "Array.h"
#include <iostream>
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;


Array::Array()
{
	array = NULL;
	length = 0;
}

Array::Array(const Array& src) {
	if (this == &src)
		return;
	delete[]array;
	length = src.length;
	array = new Fraction[length];
	for (int i = 0; i < length; i++) {
		array[i] = src.array[i];
	}
}

void Array::input(const char *nameFile)
{
	FILE *in = fopen(nameFile, "r");

	if (in == NULL)
	{
		cout << "Error." << endl;
		return;
	}

	fscanf_s(in, "%d", &length);
	if (length == 0)
	{
		cout << "Error." << endl;
		fclose(in);
		return;
	}

	array = new Fraction[length];

	for (int i = 0; i < length; i++)
	{
		fscanf_s(in, "%d/%d", &array[i].getNum(), &array[i].getDenom());
	}

	fclose(in);
}

void Array::output()
{
	for (int i = 0; i < length; i++)
	{
		array[i].display();
	}
	cout << endl;
}

void Array::swapElement(Fraction &b, Fraction &y)
{
	Fraction temp = b;
	b = y;
	y = temp;
}

void Array::sortAscending()
{
	for (int i = 0; i < length; i++)
	{
		int index = i;

		for (int j = i + 1; j < length; j++)
		{
			if (array[index].compare(array[i]))
				index = j;
		}

		if (index != i)
			swapElement(array[i], array[index]);
	}
}

Fraction Array::findMax()
{
	Fraction max = array[0];
	for (int i = 0; i < length; i++)
	{
		if (max.compare(array[i]) != 1)
		{
			max = array[i];
		}
	}
	return max;
}

Fraction Array::findMin()
{
	Fraction min = array[0];
	for (int i = 0; i < length; i++)
	{
		if (min.compare(array[i]) == 1)
		{
			min = array[i];
		}
	}
	return min;
}

Fraction Array::calcSum()
{
	Fraction sum;
	for (int i = 0; i < length; i++)
	{
		sum = sum.add(array[i]);
	}
	return sum;
}

Array::~Array()
{
	delete[]array;
}
