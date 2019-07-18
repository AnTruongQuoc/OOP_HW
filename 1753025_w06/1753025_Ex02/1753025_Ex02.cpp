#include "university.h"


void main() {
	Uni a;
	int type;
	//a.addTeacher();
	//a.printListTeacher();
	//a.findMaxSalary();

	menu();
	do {
		cin >> type;
		switch (type)
		{
		case 1:
			system("cls");
			a.addTeacher();
			break;
		case 2:
			system("cls");
			a.printListTeacher();
			break;
		case 3:
			system("cls");
			a.sumSalary();
			break;
		case 4:
			system("cls");
			a.findMaxSalary();
			break;
		case 5:
			system("cls");
			a.countNorTeacherAndHRTeacher();
			break;
		case 6:
			system("cls");
			a.argSalary();
			break;
		case 7:
			system("cls");
			a.findSalaryGreater10M();
			break;
		case 8:
			system("cls");
			a.findTeacherByID();
			break;
		case 9:
			system("cls");
			a.findTeacherByName();
			break;
		case 10:
			system("cls");
			a.DaysOffTooMuch();
			break;
		}
	} while (type != 0);
	
	system("pause");
}