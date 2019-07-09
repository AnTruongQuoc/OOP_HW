#include "university.h"

void main() {
	Teacher a;
	HomeroomTeacher b;
	cin >> b;
	cout << "\n+--------------------------------------+\n" << endl;
	cout << b;
	cout.precision(9);
	//cout << "+---------------------------------+" << endl;
	cout << "\n| Salary: " << b.Salary() << "VND |" << endl;
	//cout << "+---------------------------------+" << endl;
	system("pause");
}