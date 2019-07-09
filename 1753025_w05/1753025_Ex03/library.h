#pragma once
#include <iostream>
#include <string>

using namespace std;
struct ED {
	int d, m, y;
	void input() {
		char temp;
		cin >> d >> temp >> m >> temp >> y;
	}
	void output() {
		cout << d << "/" << m << "/" << y << endl;
	}
};
class Reader {
public:
	Reader();
	Reader(const Reader &src);
	friend ostream& operator << (ostream &os, Reader src);
	friend istream& operator >> (istream &is, Reader &src);
	unsigned int calcMoney();
private:
	string ID;
	string FullName;
	ED expDate;
	string sex;
};

class RNormal : public Reader {
public:
	RNormal();
	RNormal(const RNormal &src);
	unsigned int calcMoney();
	void input() {
		cout << "Borrowed Books: ";
		cin >> borrowBooks;
	}
	void output() {
		cout << "Borrowed Books: " << borrowBooks << endl;
	}
private:
	int borrowBooks;
};

class RVIP : public Reader {
public:
	RVIP();
	RVIP(const RVIP &src);
	int calcMoney();
};