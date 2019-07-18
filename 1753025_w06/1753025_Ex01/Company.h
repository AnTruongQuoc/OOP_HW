#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DoB {
	int day, month, year;
	void inputDOB() {
		char temp;
		cout << "Enter DOB (dd/mm/yyyy)        : ";
		cin >> day >> temp >> month >> temp >> year;
	}
	void outputDOB() {
		cout << day << "/" << month << "/" << year << endl;
	}
};

struct EmpInfo {
	string ID;
	string FullName;
	DoB DOB;
	string address;
	
	void inputEmpInfo() {
		cout << "Enter ID                      : ";
		cin.ignore();
		getline(cin, ID);
		cout << "Enter employee name           : ";
		//cin.ignore();
		getline(cin, FullName);
		DOB.inputDOB();
		cout << "Enter address                 : ";
		cin.ignore();
		getline(cin, address);
	}
	void outputEmpInfo() {
		cout << "\nEmployee ID          : " << ID << endl;
		cout << "Employee name        : " << FullName << endl;
		cout << "Date of birth        : "; DOB.outputDOB();
		cout << "Address              : " << address << endl;
	}
};

class NhanVien {
public:
	NhanVien();
	//NhanVien(string &ID, string &FN, DoB &DOB, string &addr);
	//NhanVien(const NhanVien& src);
	//NhanVien(string &ID, string &FN);
	//NhanVien(string &ID, string &FN, string &addr);
	//friend ostream& operator <<(ostream &os, const NhanVien &src);
	//friend istream& operator >>(istream &in, NhanVien &src);
	virtual int calcSalary() = 0;
	virtual void input()     = 0;
	virtual void output()    = 0;
	virtual string getID()   = 0;
	virtual string getName() = 0;
	virtual int getMonth()   = 0;
	virtual int check()      = 0;
};

class NVSanXuat : public NhanVien 
{
public:
	NVSanXuat();
	NVSanXuat(const NVSanXuat& src);
	NVSanXuat(int t);
	NVSanXuat(string &ID, string &FN);
	NVSanXuat(string &ID, string &FN, int &t);
	void enterProducts();
	void input();
	void output();
	string getID();
	string getName();
	int calcSalary();
	int getMonth();
	int check();
	~NVSanXuat();
private:
	int products;
	EmpInfo NVSX;
};

class NVCongNhat : public NhanVien
{
public:
	NVCongNhat();
	NVCongNhat(const NVCongNhat& src);
	NVCongNhat(int t);
	NVCongNhat(string &ID, string &FN);
	NVCongNhat(string &ID, string &FN, int &t);
	void enterWdays();
	int calcSalary();
	int getMonth();
	int check();
	void input();
	void output();
	string getID();
	string getName();
	~NVCongNhat();
private:
	int Wdays;
	EmpInfo NVCN;
};