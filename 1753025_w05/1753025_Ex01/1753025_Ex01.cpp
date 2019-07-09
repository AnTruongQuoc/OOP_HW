#include "Company.h"

void main()
{
	NVSanXuat a;
	NVCongNhat b;

	cout << "..........Nhap thong tin NVSanXuat.......... " << endl;
	cout << endl;
	cin >> a;
	cout << endl;
	cout << "........Thong tin Nhan vien San xuat........" << endl;
	cout << endl;
	cout << a << endl;
	cout << "	| Salary: " << a.calcSalary() << "VND |" << endl;
	cout << endl;
	cout << "+-----------------------------------------------+" << endl;
	cout << endl;
	cout << "............Nhap thong tin NVCongNhat............" << endl;
	cout << endl;
	cin.ignore();
	cin >> b;
	cout << endl;
	cout << "..........Thong tin Nhan vien Cong nhat.........." << endl;
	cout << endl;
	cout << b << endl;
	cout << "	| Salary: " << b.calcSalary() << "VND |" << endl;
	system("pause");
}