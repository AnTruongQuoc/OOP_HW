#include "library.h"

void main() {
	Library a;
	int type;

	menu();
	do {
		cin >> type;
		switch (type)
		{
		case 1:
			system("cls");
			a.addReader();
			break;
		case 2:
			system("cls");
			a.printListReader();
			break;
		case 3:
			system("cls");
			a.sumFees();
			break;
		case 4:
			system("cls");
			a.findMaxFee();
			break;
		case 5:
			system("cls");
			a.countRNorAndRVIP();
			break;
		case 6:
			system("cls");
			a.argFee();
			break;
		case 7:
			system("cls");
			a.feeGreater30K();
			break;
		case 8:
			system("cls");
			a.findReaderByID();
			break;
		case 9:
			system("cls");
			a.findReaderByName();
			break;
		case 10:
			system("cls");
			a.ExpiredIn2017();
			break;
		}
	} while (type != 0);

	
	system("pause");
}