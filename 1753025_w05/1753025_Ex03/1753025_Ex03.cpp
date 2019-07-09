#include "library.h"

void main() {
	Reader a;
	RNormal x;
	RVIP y;

	cout << "ENTER INFORMATION OF NORMAL READER\n" << endl;
	cin >> x;
	x.input();
	cout << "\nINFORMATION OF NORMAL READER\n" << endl;
	cout << x;
	x.output();
	cout << "Fee: " << x.calcMoney() << "VND" << endl;

	cout << "\nENTER INFORMATION OF VIP READER\n" << endl;
	cin.ignore();
	cin >> y;
	cout << "\nINFORMATION OF VIP READER\n" << endl;
	cout << y;
	cout << "Fee: " << y.calcMoney() << "VND"<< endl;
	system("pause");
}