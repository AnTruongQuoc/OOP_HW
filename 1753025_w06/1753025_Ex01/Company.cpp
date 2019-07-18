#include "Company.h"


NhanVien::NhanVien(){}
/*
NhanVien::NhanVien(const NhanVien& src)
{
	this->ID = src.ID;
	this->DOB = src.DOB;
	this->FullName = src.FullName;
	this->address = src.address;
}
NhanVien::NhanVien(string &ID, string &FN, DoB &DOB, string &addr)
{
	this->ID = ID;
	this->DOB = DOB;
	this->FullName = FN;
	this->address = addr;
}
NhanVien::NhanVien(string &ID, string &FN)
{
		this->ID = ID;
		this->FullName = FN;
}

NhanVien::NhanVien(string &ID, string &FN, string &addr)
{
		this->ID = ID;
		this->FullName = FN;
		this->address = addr;
}

istream& operator >>(istream &is, NhanVien &src)
{
	char temp;

	cout << "Enter Employee ID               : ";
	getline(is, src.ID);
	cout << "Enter Employee Full Name        : ";
	//is.ignore();
	getline(is, src.FullName);
	cout << "Enter Date of Birth (dd/mm/yyyy): ";
	is >> src.DOB.day >> temp >> src.DOB.month >> temp >> src.DOB.year;
	cout << "Enter Address                   : ";
	is.ignore();
	getline(is, src.address);
	return is;
}

ostream& operator <<(ostream &os, const NhanVien &src)
{
	os << "	  Employee ID: " << src.ID << endl;
	os << "	  Full Name: " << src.FullName << endl;
	os << "	  Date of Birth: " << src.DOB.day << "/" << src.DOB.month<<"/"<<src.DOB.year << endl;
	os << "	  Address: " << src.address << endl;
	return os;
}
*/
int NhanVien::calcSalary()
{
	return 0;
}

NVSanXuat::NVSanXuat() {
	products = 0;
}
NVSanXuat::NVSanXuat(int t) {
	this->products = t;
}
NVSanXuat::NVSanXuat(const NVSanXuat& src)
{
	this->products = src.products;
}
NVSanXuat::NVSanXuat(string &ID, string &FN, int &t)
{
	this->products = t;
}
NVSanXuat::NVSanXuat(string &ID, string &FN)
{

}
void NVSanXuat::enterProducts()
{
	cout << "Enter the number of Products  : ";
	cin >> products;
	cout << endl;
}

void NVSanXuat::input()
{
	cout << "INPUT INFORMATION OF PRODUCTION WORKER\n" << endl;
	NVSX.inputEmpInfo();
	enterProducts();
}

void NVSanXuat::output()
{
	NVSX.outputEmpInfo();
	cout << "Number of Products   : " << this->products << endl;
	cout << endl;
}

int NVSanXuat::calcSalary()
{
	//enterProducts();
	return products * 20000;
}
string NVSanXuat::getID() {
	return this->NVSX.ID;
}

string NVSanXuat::getName() {
	return this->NVSX.FullName;
}

int NVSanXuat::getMonth() {
	return this->NVSX.DOB.month;
}

int NVSanXuat::check() {
	return 1;
}

void NVCongNhat::enterWdays()
{
	cout << "Enter the number of worked-day: ";
	cin >> Wdays;
	cout << endl;
}

NVCongNhat::NVCongNhat()
{
	Wdays = 0;
}
NVCongNhat::NVCongNhat(int t)
{
	this->Wdays = t;
}
NVCongNhat::NVCongNhat(const NVCongNhat& src)
{
	this->Wdays = src.Wdays;
}
NVCongNhat::NVCongNhat(string &ID, string &FN)
{
	
}
NVCongNhat::NVCongNhat(string &ID, string &FN, int &t) {
	this->Wdays = t;
}

int NVCongNhat::calcSalary()
{
	//enterWdays();
	return Wdays * 300000;
}
void NVCongNhat::input()
{
	cout << "INPUT INFORMATION OF DAY LABORER\n" << endl;
	NVCN.inputEmpInfo();
	enterWdays();
}

void NVCongNhat::output()
{
	NVCN.outputEmpInfo();
	cout << "Number of Worked-days: " << this->Wdays << endl;
	cout << endl;
}

string NVCongNhat::getID() {
	return this->NVCN.ID;
}
string NVCongNhat::getName() {
	return this->NVCN.FullName;
}
int NVCongNhat::getMonth() {
	return this->NVCN.DOB.month;
}
int NVCongNhat::check() {
	return 2;
}
NVSanXuat::~NVSanXuat(){}
NVCongNhat::~NVCongNhat(){}