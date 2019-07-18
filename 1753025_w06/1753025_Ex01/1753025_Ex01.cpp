#include "Company.h"

void menu() {
	cout << "1. Nhap nhan vien" << endl;
	cout << "2. Xuat danh sach nhan vien" << endl;
	cout << "3. Tinh tong tien luong cua tat ca nhan vien" << endl;
	cout << "4. Nhan vien co luong cao nhat" << endl;
	cout << "5. So NVSX trong cong ty" << endl;
	cout << "6. So NVCN trong cong ty" << endl;
	cout << "7. Tinh luong trung binh trong cong ty" << endl;
	cout << "8. Danh sach nhan vien co luong < 3.000.000" << endl;
	cout << "9. Nhap ID, tim nhan vien tuong ung" << endl;
	cout << "10. Nhap ten, tim nhan vien tuong ung" << endl;
	cout << "11. So nhan vien sinh trong thang 5" << endl;
	cout << "0. Thoat ra" << endl;
	cout << "\nYour choice : ";
}

void inputEmp(vector<NhanVien*> &NV) {
	int k = 0;
	NhanVien *p;
	do {
		system("cls");
		cout << "1. Nhan Vien San Xuat" << endl;
		cout << "2. Nhan Vien Cong Nhat" << endl;
		cout << "0. Back to menu" << endl;
		cout << "Your choice: "; cin >> k;

		p = nullptr;

		switch (k) {
		case 1:
			system("cls");
			p = new NVSanXuat;
			p->input();
			NV.push_back(p);
			break;
		case 2:
			system("cls");
			p = new NVCongNhat;
			p->input();
			NV.push_back(p);
			break;
		case 0:
			system("cls");
			menu();
		}
	} while (k != 0);
}

void outputEmp(vector<NhanVien*> NV) {
	int k;
	cout << "*****Danh sach Nhan vien*****\n" << endl;
	for (int i = 0; i < NV.size(); i++) {
		NV[i]->output();
	}
	if (NV.size() == 0) {
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

void sumAllSalary(vector<NhanVien*> NV) {
	int sum = 0;
	int k;
	for (int i = 0; i < NV.size(); i++)
	{
		sum += NV[i]->calcSalary();
	}
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

void findMaxSalary(vector<NhanVien*> NV) {
	int max = 0;
	int k;
	for (int i = 0; i < NV.size(); i++) {
		if (max < NV[i]->calcSalary())
			max = NV[i]->calcSalary();
	}
	cout << "\nNhan vien co luong cao nhat" << endl;
	for (int i = 0; i < NV.size(); i++) {
		if (NV[i]->calcSalary() == max)
			NV[i]->output();
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

void avgSalary(vector<NhanVien*> NV) {
	double avg;
	int sum = 0;
	int k;
	for (int i = 0; i < NV.size(); i++)
	{
		sum += NV[i]->calcSalary();
	}
	avg = sum / (NV.size());
	cout.precision(12);
	cout << "Luong trung binh cua cong ty: " << avg << "VND" << endl;
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

void findLower3M(vector<NhanVien*> NV) {
	int c = 0;
	int k;
	cout << "Danh sach nhan vien co luong < 3.000.000\n" << endl;
	for (int i = 0; i < NV.size(); i++) {
		if (NV[i]->calcSalary() < 3000000) {
			NV[i]->output();
			c++;
		}
	}

	if (c == 0)
		cout << "!NOTICE Khong co Nhan Vien nao luong < 3.000.000" << endl;
	
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

void findByID(vector<NhanVien*> NV) {
	int k;
	string ID;

	cout << "Input ID: ";
	cin.ignore();
	getline(cin, ID);

	cout << "\nResult: " << endl;
	for (int i = 0; i < NV.size(); i++) {
		if (ID == NV[i]->getID()) {
			NV[i]->output();
			break;
		}
		else if (i == (NV.size()-1))
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

void findByName(vector<NhanVien*> NV) {
	int k;

	string name;

	cout << "Input fullname: ";
	cin.ignore();
	getline(cin, name);

	cout << "\nResult: " << endl;
	for (int i = 0; i < NV.size(); i++) {
		if (name == NV[i]->getName())
			NV[i]->output();
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

void countDobInM5(vector<NhanVien*> NV) {
	int count = 0;
	int k;

	for (int i = 0; i < NV.size(); i++) {
		if (NV[i]->getMonth() == 5)
		{
			NV[i]->output();
			count++;
		}
	}
	
	cout << "\nSo nhan vien sinh trong thang 5: " << count << endl;
	
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

void countNVSX(vector<NhanVien*> NV) {
	int c = 0;
	int k;
	//NVSX == 1
	for (int i = 0; i < NV.size(); i++) {
		if (NV[i]->check() == 1)
			c++;
	}

	cout << "So NVSX trong cong ty: " << c << endl;

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

void countNVCN(vector <NhanVien*> NV) {
	int c = 0;
	int k;
	//NVCN == 2
	for (int i = 0; i < NV.size(); i++) {
		if (NV[i]->check() == 2)
			c++;
	}

	cout << "So NVCN trong cong ty: " << c << endl;

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
void main()
{
	vector<NhanVien*> NV;
	int type = 0;
	/*
		1. Nhập, xuất danh sách các nhân viên.
		2. Tính tổng tiền lương của tất cả nhân viên.
		3. Tìm nhân viên có lương cao nhất
		4. Có bao nhiêu NVSX trong công ty
		5. Có bao nhiêu NVCN trong công ty
		6. Tính lương trung bình trong công ty
		7. Liệt kê các nhân viên có lương thấp hơn 3.000.000
		8. Nhập vào mã, tìm nhân viên tương ứng
		9. Nhập vào tên, tìm nhân viên tương ứng
		10. Có bao nhiêu nhân viên sinh trong tháng 5
	*/
	
	menu();
	do {
		cin >> type;
		switch (type)
		{
		case 1:
			system("cls");
			inputEmp(NV);
			break;
		case 2:
			system("cls");
			outputEmp(NV);
			break;
		case 3:
			system("cls");
			sumAllSalary(NV);
			break;
		case 4:
			system("cls");
			findMaxSalary(NV);
			break;
		case 5:
			system("cls");
			countNVSX(NV);
			break;
		case 6:
			system("cls");
			countNVCN(NV);
			break;
		case 7:
			system("cls");
			avgSalary(NV);
			break;
		case 8:
			system("cls");
			findLower3M(NV);
			break;
		case 9:
			system("cls");
			findByID(NV);
			break;
		case 10:
			system("cls");
			findByName(NV);
			break;
		case 11:
			system("cls");
			countDobInM5(NV);
			break;
		}

	} while (type != 0);

	//system("pause");
}