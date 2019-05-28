#pragma once
class Student
{
private:
	char *ID;
	char *fullName;
	char *address;
	double m_mark;
	int dateOB;
	int monthOB;
	int yearOB;
public:
	Student();
	char*& getID();
	char*& getFullName();
	char* getLastName();
	char*& getAddress();
	double& getMark();
	int& dateOfB();
	int& monthOfB();
	int& yearOfB();
	void output();
	~Student();
};