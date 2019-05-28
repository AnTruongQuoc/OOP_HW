#pragma once
#include "Point.h"
#include <iostream>
using namespace std;

class Array
{
public:
	Array();
	void input(const char *nameFile);
	void output();
	Point FLD(Point p);
	~Array();
private:
	Point *array;
	int length;
};

