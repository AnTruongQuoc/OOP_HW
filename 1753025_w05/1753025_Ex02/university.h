#pragma once
#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
	Teacher();
	Teacher (const Teacher& src);
	Teacher (int basicSalary, int daysOff);
	Teacher (int basicSalary);
	Teacher (float cs, int basicSalary, int daysOff);
	//Teacher& operator=(const Teacher& src);
	friend ostream& operator << (ostream &os, Teacher src);
	friend istream& operator >> (istream &is, Teacher &src);
	double Salary();
private:
	string ID;
	string FullName;
	float cs; //coefficients salary
	int basicSalary;
	int daysOff;
};

class HomeroomTeacher : public Teacher {
public:
	HomeroomTeacher();
	HomeroomTeacher(const HomeroomTeacher &src);
	HomeroomTeacher(int a);
	HomeroomTeacher(int a, int b);
	double Salary();
private:
	int allowance;
};