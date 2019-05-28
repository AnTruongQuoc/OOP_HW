#pragma once
#include "Student.h"
class Array
{
private:
	Student* array;
	int length;
public:
	Array();
	void input(const char* nameFile);
	void sortName();
	void swapStudent(Student &b, Student &y);
	void output();
	void output(const char* nameFile);
	~Array();
};