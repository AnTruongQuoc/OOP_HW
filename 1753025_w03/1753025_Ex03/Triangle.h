#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Triangle {
public:
	Triangle();
	Triangle(const Triangle& x);
	double getA();
	double getB();
	double getC();
	void setA(double x);
	void setB(double x);
	void setC(double x);
	bool checkTri();
	int classify();
private:
	double a, b, c;
};