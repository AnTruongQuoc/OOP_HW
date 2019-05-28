#include "Student.h"
#include <iostream>
using namespace std;
Student::Student()
{
	ID = NULL;
	address = NULL;
	fullName = NULL;
	m_mark = 0;
	dateOB = 0;
	monthOB = 0;
	yearOB = 0;
}
char*& Student::getID()
{
	return ID;
}
char*& Student::getFullName()
{
	return fullName;
}
char* Student::getLastName()
{
	char *temp = NULL;
	int begin = 0;
	int end = 0;
	for (int i = 0; fullName[i] != ' '; i++)
	{
		begin = i + 2;
	}
	temp = new char[strlen(fullName) - begin];
	for (int i = begin; i < strlen(fullName); i++)
	{
		temp[end] = fullName[i];
		end++;
	}
	temp[end] = '\0';
	return temp;
}
char*& Student::getAddress()
{
	return address;
}
double& Student::getMark()
{
	return m_mark;
}
int& Student::dateOfB()
{
	return dateOB;
}
int& Student::monthOfB()
{
	return monthOB;
}
int& Student::yearOfB()
{
	return yearOB;
}
void Student::output()
{
	cout << "Name: " << fullName << endl;
	cout << "ID: " << ID << endl;
	cout << "Address: " << address << endl;
	cout << "DOB: " << dateOB << "/" << monthOB << "/" << yearOB << endl;
	cout << "Mark: " << m_mark << endl;
}
Student::~Student()
{
	delete[]address;
	delete[]fullName;
	delete[]ID;
}