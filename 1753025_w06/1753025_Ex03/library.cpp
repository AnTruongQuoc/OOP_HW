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
void Reader::inputReaderInfo()
{
	cout << "Enter reader ID: ";
	cin.ignore();
	getline(cin, ID);
	cout << "Enter reader name: ";
	//cin.ignore();
	getline(cin, FullName);
	cout << "Expired Date (dd/mm/yyyy): "; expDate.input();
	cout << "Sex: ";
	cin.ignore();
	getline(cin, sex);
}

void Reader::outputReaderInfo()
{
	cout << "\nReader ID: " << ID << endl;
	cout << "Reader name: " << FullName << endl;
	cout << "Expired Date ";  expDate.output();
	cout << "Sex: " << sex << endl;
}
string Reader::getSex()
{
	return this->sex;
}

string Reader::getName()
{
	return this->FullName;
}

string Reader::getID()
{
	return this->ID;
}

int Reader::getExpYear()
{
	return this->expDate.y;
}
//ostream& operator << (ostream &os, Reader src) {
//	//os << "\nINFORMATION OF READER\n" << endl;
//	os << "Reader ID: " << src.ID << endl;
//	os << "Reader name: " << src.FullName << endl;
//	os << "Expired Date ";  src.expDate.output();
//	os << "Sex: " << src.sex << endl;
//	return os;
//}
//
//istream& operator >> (istream &is, Reader &src) {
//	//cout << "\nENTER READER INFORMATION" << endl;
//	cout << "Enter reader ID: ";
//	//is.ignore();
//	getline(is, src.ID);
//	cout << "Enter reader name: ";
//	//is.ignore();
//	getline(is, src.FullName);
//	cout << "Expired Date (dd/mm/yyyy): "; src.expDate.input();
//	cout << "Sex: ";
//	is.ignore();
//	getline(is, src.sex);
//	return is;
//}


//RNormal
RNormal::RNormal() {
	borrowBooks = 0;
}

RNormal::RNormal(const RNormal &src) {
	this->borrowBooks = src.borrowBooks;
}

unsigned int RNormal::calcMoney() {
	return (this->borrowBooks * 5000);
}

void RNormal::inputReaderInfo()
{
	Reader::inputReaderInfo();
	cout << "Borrowed book: ";
	cin >> this->borrowBooks;
}

int RNormal::check()
{
	return 1;
}
int RNormal::getExpYear()
{
	return this->Reader::getExpYear();
}
//RVIP
RVIP::RVIP() {}

RVIP::RVIP(const RVIP &src) {}

unsigned int RVIP::calcMoney() {
	return 50000;
}

string RVIP::getName()
{
	return this->Reader::getName();
}

string RVIP::getID()
{
	return this->Reader::getID();
}

void RVIP::inputReaderInfo()
{
	Reader::inputReaderInfo();
}

void RVIP::outputReaderInfo()
{
	Reader::outputReaderInfo();
}
int RVIP::check()
{
	return 2;
}
int RVIP::getExpYear()
{
	return this->Reader::getExpYear();
}

//Libray
Library::Library(){}
Library::~Library(){}

void Library::addReader()
{
	int k = 0;
	Reader *p;
	do {
		system("cls");
		cout << "1. Nhap thong tin doc gia" << endl;
		cout << "2. Nhap thong tin doc gia VIP" << endl;
		cout << "0. Back to menu" << endl;
		cout << "Your choice: "; cin >> k;		
		p = nullptr;


		switch (k) {
		case 1:
			system("cls");
			p = new RNormal;
			p->inputReaderInfo();
			R.push_back(p);
			break;
		case 2:
			system("cls");
			p = new RVIP;
			p->inputReaderInfo();
			R.push_back(p);
			break;
		case 0:
			system("cls");
			menu();
		}
	} while (k != 0);
}

void Library::printListReader()
{
	int k = 0;
	cout << "*****Danh sach Doc gia*****\n" << endl;

	for (int i = 0; i < R.size(); i++)
	{
		R[i]->outputReaderInfo();
		cout << endl;
	}

	if (R.size() == 0) {
		cout << "!IMPORTANT : Chua cap nhat danh sach doc gia" << endl;
	}
	do {
		cout << "\nPress 0 to return ! ";
		cin >> k;
		if (k == 0)
		{
			system("cls");
			menu();
		}
	} while (k != 0);
}

void Library::sumFees()
{
	double sum = 0;
	int k;

	for (int i = 0; i < R.size(); i++)
	{
		sum += R[i]->calcMoney();
	}
	cout.precision(14);
	cout << "Tong le phi: " << sum << "VND" << endl;
	do {
		cout << "Press 0 to return to the menu" << endl;
		cin >> k;
		switch (k) {
		case 0:
			system("cls");
			menu();
			break;
		}
	} while (k != 0);
}

void Library::findMaxFee()
{
	double max = 0;
	int k;
	for (int i = 0; i < R.size(); i++) {
		if (max < R[i]->calcMoney())
			max = R[i]->calcMoney();
	}

	cout << "\nDoc gia co le phi cao nhat\n" << endl;
	
	for (int i = 0; i < R.size(); i++) {
		if (R[i]->calcMoney() == max)
		{
			cout << R[i]->getName();
			cout.precision(14);
			cout << "\t\t" << max << endl;
		}
	}
	do {
		cout << "Press 0 to return to the menu" << endl;
		cin >> k;
		switch (k) {
		case 0:
			system("cls");
			menu();
			break;
		}
	} while (k != 0);
}

void Library::countRNorAndRVIP()
{
	int k;
	int NR = 0, VR = 0;
	for (int i = 0; i < R.size(); i++)
	{
		if (R[i]->check() == 1)
			NR++;
		else
			VR++;
	}

	cout << "So doc gia thuong: " << NR << endl;
	cout << "So doc gia VIP   : " << VR << endl;

	do {
		cout << "Press 0 to return to the menu" << endl;
		cin >> k;
		switch (k) {
		case 0:
			system("cls");
			menu();
			break;
		}
	} while (k != 0);
}

void Library::argFee()
{
	double sum = 0;

	int k;

	for (int i = 0; i < R.size(); i++)
	{
		sum += R[i]->calcMoney();
	}
	cout.precision(14);
	cout << "Le phi trung binh: " << (sum / (R.size() - 1)) << " VND" << endl;
	do {
		cout << "Press 0 to return to the menu" << endl;
		cin >> k;
		switch (k) {
		case 0:
			system("cls");
			menu();
			break;
		}
	} while (k != 0);
}

void Library::feeGreater30K()
{
	int k;

	cout << "**Danh sach doc gia co le phi tren 30.000 VND**\n" << endl;
	for (int i = 0; i < R.size(); i++)
	{
		if (R[i]->calcMoney() > 30000)
			R[i]->outputReaderInfo();
	}
	do {
		cout << "Press 0 to return to the menu" << endl;
		cin >> k;
		switch (k) {
		case 0:
			system("cls");
			menu();
			break;
		}
	} while (k != 0);
}

void Library::findReaderByID()
{
	int k;
	string ID;
	cout << "[+] Nhap ID doc gia muon tim: ";
	cin.ignore();
	getline(cin, ID);

	if (R.size() == 0)
		cout << "Chua nhap danh sach doc gia" << endl;
	else 
		cout << "\nResult\n" << endl;
	for (int i = 0; i < R.size(); i++)
	{
		if (R[i]->getID() == ID) {
			R[i]->outputReaderInfo();
			break;
		}
		else if (i == (R.size() - 1))
			cout << "\n!NOTICE Khong tim thay ket qua." << endl;

	}

	do {
		cout << "Press 0 to return to the menu" << endl;
		cin >> k;
		switch (k) {
		case 0:
			system("cls");
			menu();
			break;
		}
	} while (k != 0);
}

void Library::findReaderByName()
{
	int k;

	string name;
	cout << "[+] Nhap ten doc gia muon tim: ";
	cin.ignore();
	getline(cin, name);

	if (R.size() == 0)
		cout << "\nChua nhap danh sach doc gia\n" << endl;
	else
		cout << "\nResult: " << endl;
	for (int i = 0; i < R.size(); i++)
	{
		if (R[i]->getName() == name)
		{
			R[i]->outputReaderInfo();
			break;
		}
		else if (i == (R.size() - 1))
			cout << "\n!NOTICE Khong tim thay ket qua." << endl;
	}

	do {
		cout << "Press 0 to return to the menu" << endl;
		cin >> k;
		switch (k) {
		case 0:
			system("cls");
			menu();
			break;
		}
	} while (k != 0);
}

void Library::ExpiredIn2017()
{
	int k;
	int count = 0;

	for (int i = 0; i < R.size(); i++)
	{
		if (R[i]->getExpYear() == 2017)
			count++;
	}

	cout << "\nSo doc gia het han trong nam 2017: " << count << endl;
	do {
		cout << "Press 0 to return to the menu" << endl;
		cin >> k;
		switch (k) {
		case 0:
			system("cls");
			menu();
			break;
		}
	} while (k != 0);
}

void menu() {
	cout << "1. Nhap thong tin doc gia" << endl;
	cout << "2. Xuat danh sach doc gia" << endl;
	cout << "3. Tinh tong phi cua doc gia" << endl;
	cout << "4. Doc gia co le phi cao nhat" << endl;
	cout << "5. So doc gia thuong va VIP" << endl;
	cout << "6. Tinh phi doc gia trung binh trong thu vien" << endl;
	cout << "7. Liet ke cac doc gia co phi tren 30.000" << endl;
	cout << "8. Nhap ID, tim doc gia tuong ung" << endl;
	cout << "9. Nhap ten, tim doc gia tuong ung" << endl;
	cout << "10. Co bao nhieu doc gia het han trong nam 2017" << endl;
	cout << "0. Thoat ra" << endl;
	cout << "\nYour choice : ";
}