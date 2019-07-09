#include "library.h"

Reader::Reader() {
	ID = FullName = "";
	expDate.d = expDate.m = expDate.y = 0;
	sex = "";
}

Reader::Reader(const Reader &src) {
	ID = src.ID;
	FullName = src.FullName;
	expDate = src.expDate;
	sex = src.sex;
}

ostream& operator << (ostream &os, Reader src) {
	//os << "\nINFORMATION OF READER\n" << endl;
	os << "Reader ID: " << src.ID << endl;
	os << "Reader name: " << src.FullName << endl;
	os << "Expired Date ";  src.expDate.output();
	os << "Sex: " << src.sex << endl;
	return os;
}

istream& operator >> (istream &is, Reader &src) {
	//cout << "\nENTER READER INFORMATION" << endl;
	cout << "Enter reader ID: ";
	//is.ignore();
	getline(is, src.ID);
	cout << "Enter reader name: ";
	//is.ignore();
	getline(is, src.FullName);
	cout << "Expired Date (dd/mm/yyyy): "; src.expDate.input();
	cout << "Sex: ";
	is.ignore();
	getline(is, src.sex);
	return is;
}

unsigned int Reader::calcMoney() {
	return 0;
}

RNormal::RNormal() {
	borrowBooks = 0;
}

RNormal::RNormal(const RNormal &src) {
	this->borrowBooks = src.borrowBooks;
}

unsigned int RNormal::calcMoney() {
	return (this->borrowBooks * 5000);
}

RVIP::RVIP() {}

RVIP::RVIP(const RVIP &src) {}

int RVIP::calcMoney() {
	return 50000;
}