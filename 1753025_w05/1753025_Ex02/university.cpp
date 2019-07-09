#include "university.h"

Teacher::Teacher() {
	ID = FullName = "";
	cs = 0;
	basicSalary = 100000;
	daysOff = 0;
}

Teacher::Teacher(const Teacher& src) {
	this->ID = src.ID;
	this->FullName = src.FullName;
	this->cs = src.cs;
	this->basicSalary = src.basicSalary;
	this->daysOff = src.daysOff;
}

Teacher::Teacher(int basicSalary, int daysOff) {
	this->basicSalary = basicSalary;
	this->daysOff = daysOff;
};

Teacher::Teacher(int basicSalary) {
	this->basicSalary = basicSalary;
};

Teacher::Teacher(float cs, int basicSalary, int daysOff) {
	this->basicSalary = basicSalary;
	this->daysOff = daysOff;
	this->cs = cs;
};

double Teacher::Salary() {
	return (this->cs*this->basicSalary - this->daysOff * 100000);
}
ostream& operator <<(ostream &os, Teacher src) {
	os << "Information of teacher\n" << endl;
	os << "Teacher ID: " << src.ID << endl;
	os << "Teacher name: " << src.FullName << endl;
	os << "Coffients salary: " << src.cs << endl;
	os << "Basic Salary: " << src.basicSalary << endl;
	os << "Days off: " << src.daysOff << endl;
	return os;
}
istream& operator >>(istream &is, Teacher &src) {
	cout << "Input information of teacher: " << endl;
	cout << "Enter teacher ID: ";
	getline(is, src.ID);
	cout << "Enter teacher fullname: ";
	is.ignore();
	getline(is, src.FullName);
	cout << "Enter coeffients salary: ";
	is >> src.cs;
	cout << "Enter the days off: ";
	is >> src.daysOff;
	return is;
}
HomeroomTeacher::HomeroomTeacher() {
	allowance = 500000;
}
HomeroomTeacher::HomeroomTeacher(const HomeroomTeacher& src){
	this->allowance = src.allowance;
}HomeroomTeacher::HomeroomTeacher(int a) {
	if (a == 500000)
		this->allowance = a;
	else
		this->allowance = 500000;
}
HomeroomTeacher::HomeroomTeacher(int a, int b) {
	if (a == 500000 || b == 500000) {
		this->allowance = 500000;
	} 
	else {
		this->allowance = 500000;
	}
}
double HomeroomTeacher::Salary() {
	return (Teacher::Salary() + this->allowance);
}