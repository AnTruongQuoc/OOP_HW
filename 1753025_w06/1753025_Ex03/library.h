#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void menu();
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
	virtual void inputReaderInfo();
	virtual void outputReaderInfo();
	virtual string getSex();
	virtual string getID();
	virtual string getName();	
	virtual unsigned int calcMoney() = 0;
	virtual int check() = 0;
	virtual int getExpYear();
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
	void inputReaderInfo();
	void outputReaderInfo() {
		Reader::outputReaderInfo();
		cout << "Borrowed Books: " << borrowBooks << endl;
	}
	int check(); //1
	int getExpYear();
private:
	int borrowBooks;
};

class RVIP : public Reader {
public:
	RVIP();
	RVIP(const RVIP &src);
	string getName();
	string getID();
	int getExpYear();
	void inputReaderInfo();
	void outputReaderInfo();
	unsigned int calcMoney();
	int check(); //2
};

class Library {
public:
	Library();
	~Library();
	void addReader();
	void printListReader();
	void sumFees();
	void findMaxFee();
	void countRNorAndRVIP();
	void argFee();
	void feeGreater30K();
	void findReaderByID();
	void findReaderByName();
	void ExpiredIn2017();
private:
	vector<Reader*> R;
};