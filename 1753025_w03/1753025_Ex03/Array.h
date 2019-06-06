#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Triangle.h"


using namespace std;

class Array
{
public:
	Array();
	Array(const Array& src); 
	void input();
	void output();
	~Array();
private:
	int size;
	Triangle *data;
};