#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DoB {
	int day, month, year;
};

class NhanVien {
public:
	NhanVien();
	NhanVien(string &ID, string &FN, DoB &DOB, string &addr);
	NhanVien(const NhanVien& src);
	NhanVien(string &ID, string &FN);
	NhanVien(string &ID, string &FN, string &addr);
	friend ostream& operator <<(ostream &os, const NhanVien &src);
	friend istream& operator >>(istream &in, NhanVien &src);
	int calcSalary();
private:
	//vector<NhanVien> NV;
	string ID;
	string FullName;
	DoB DOB;
	string address;
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
	int calcSalary();
	~NVSanXuat();
private:
	int products;
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
	~NVCongNhat();
private:
	int Wdays;
};