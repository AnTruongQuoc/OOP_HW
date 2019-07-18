#include "university.h"

Uni::Uni()
{
	
}
Uni::~Uni()
{
	

}

void Uni::addTeacher()
{
	int k = 0;
	Teacher *p;
	do {
		system("cls");
		cout << "1. Nhap thong tin giao vien" << endl;
		cout << "2. Nhap thong tin GVCN" << endl;
		cout << "0. Back to menu" << endl;
		cout << "Your choice: "; cin >> k;		p = nullptr;
		p = nullptr;

		
		switch (k) {
		case 1:
			system("cls");
			p = new Teacher;
			p->inputTeacher();
			T.push_back(p);
			break;
		case 2:
			system("cls");
			HomeroomTeacher *q;
			q = new HomeroomTeacher;
			q->inputTeacher();
			T.push_back(q);
			break;
		case 0:
			system("cls");
			menu();
		}
	} while (k != 0);

}
void Uni::printListTeacher()
{
	int k = 0;
	cout << "*****Danh sach Giao vien*****\n" << endl;

	for (int i = 0; i < T.size(); i++)
	{
		T[i]->outputTeacherInfo();
		cout << endl;
	}

	if (T.size() == 0) {
		cout << "!IMPORTANT : Chua cap nhat danh sach nhan vien" << endl;
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

void Uni::sumSalary()
{
	double sum = 0;
	int k;

	for (int i = 0; i < T.size(); i++)
	{
		sum += T[i]->Salary();
	}
	cout.precision(14);
	cout << "Tong tien luong: " << sum << "VND" << endl;
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

void Uni::findMaxSalary()
{
	double max = 0;
	int k;
	for (int i = 0; i < T.size(); i++) {
		if (max < T[i]->Salary())
			max = T[i]->Salary();
	}
	cout << "\nGiao vien co luong cao nhat\n" << endl;
	for (int i = 0; i < T.size(); i++) {
		if (T[i]->Salary() == max)
		{
			T[i]->printName();
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

void Uni::countNorTeacherAndHRTeacher()
{
	int k;
	int NT = 0, HT = 0;
	for (int i = 0; i < T.size(); i++)
	{
		if (T[i]->check() == 1)
			NT++;
		else
			HT++;
	}

	cout << "So giao vien khong chu nhiem: " << NT << endl;
	cout << "So giao vien chu nhiem      : " << HT << endl;

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

void Uni::argSalary()
{
	double sum = 0;
	
	int k;

	for (int i = 0; i < T.size(); i++)
	{
		sum += T[i]->Salary();
	}
	cout.precision(14);
	cout << "Tien luong trung binh: " << (sum/(T.size()-1)) << " VND" << endl;
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

void Uni::findSalaryGreater10M()
{
	int k;

	cout << "**Danh sach Giao vien co tien luong tren 10.000.000 VND**\n" << endl;
	for (int i = 0; i < T.size(); i++)
	{
		if (T[i]->Salary() > 10000000)
			T[i]->outputTeacherInfo();
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

void Uni::findTeacherByID() {
	int k;
	string ID;
	cout << "[+] Nhap ID giao vien muon tim: ";
	cin.ignore();
	getline(cin, ID);

	cout << "\nResult\n" << endl;
	for (int i = 0; i < T.size(); i++)
	{
		if (T[i]->getID() == ID) {
			T[i]->outputTeacherInfo();
			break;
		}
		else if (i == (T.size() - 1) || T.size() == 0)
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

void Uni::findTeacherByName() {
	int k;

	string name;
	cout << "[+] Nhap ten GV muon tim: ";
	cin.ignore();
	getline(cin, name);

	if (T.size() == 0)
		cout << "\nChua nhap danh sach giao vien\n" << endl;
	else 
		cout << "\nResult: " << endl;
	for (int i = 0; i < T.size(); i++)
	{
		if (T[i]->getName() == name)
		{
			T[i]->outputTeacherInfo();
			break;
		}
		else if (i == (T.size() - 1))
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

void Uni::DaysOffTooMuch() {
	int k;
	int count = 0;

	for (int i = 0; i < T.size(); i++)
	{
		if (T[i]->getDaysOff() > 4)
			count++;
	}

	cout << "So giao vien nghi qua 4 ngay trong 1 thang: " << count << endl;

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
	cout << "1. Nhap thong tin giao vien" << endl;
	cout << "2. Xuat danh sach giao vien" << endl;
	cout << "3. Tinh tong tien luong cua tat ca giao vien" << endl;
	cout << "4. Giao vien co luong cao nhat" << endl;
	cout << "5. So GV va GVCN trong truong" << endl;
	cout << "6. Tinh luong trung binh tat ca GV trong truong" << endl;
	cout << "7. Liet ke GV co luong tren 10.000.000" << endl;
	cout << "8. Nhap ID, tim giao vien tuong ung" << endl;
	cout << "9. Nhap ten, tim giao vien tuong ung" << endl;
	cout << "10. So GV nghi qua 4 ngay trong thang" << endl;
	cout << "0. Thoat ra" << endl;
	cout << "\nYour choice : ";
}