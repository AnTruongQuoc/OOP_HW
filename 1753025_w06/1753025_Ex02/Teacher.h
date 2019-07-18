#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

void menu();

class Teacher {
public:
	Teacher();
	virtual ~Teacher();
	Teacher(const Teacher& src);
	Teacher(int basicSalary, int daysOff);
	Teacher(int basicSalary);
	Teacher(float cs, int basicSalary, int daysOff);
	//Teacher& operator=(const Teacher& src);
	friend ostream& operator << (ostream &os, Teacher src);
	friend istream& operator >> (istream &is, Teacher &src);
	void inputTeacher();
	void outputTeacherInfo();
	void printName();
	virtual double Salary();
	virtual int check();
	virtual string getID();
	virtual string getName();
	virtual int getDaysOff();
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
	//void inputTeacher();
	string getID();
	string getName();
	int check();
	int getDaysOff();
	double Salary();
private:
	int allowance; //phu cap
};