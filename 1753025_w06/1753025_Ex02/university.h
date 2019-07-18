#pragma once
#include "Teacher.h"

using namespace std;
class Uni {
public:
	//vector<Teacher*> count();
	Uni();
	~Uni();
	void addTeacher();
	void printListTeacher();
	void sumSalary();
	void findMaxSalary();
	void countNorTeacherAndHRTeacher();
	void argSalary();
	void findSalaryGreater10M();
	void findTeacherByID();
	void findTeacherByName();
	void DaysOffTooMuch();
private:
	vector<Teacher*> T;
};
