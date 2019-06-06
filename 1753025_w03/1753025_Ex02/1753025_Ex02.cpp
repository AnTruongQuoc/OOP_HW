#include "Array.h"
#include <iostream>
using namespace std;

void main()
{
	Array b;
	Point p;
	b.input("input.txt");
	b.output();
	p.input();
	b.FLD(p).display();
	cout << endl;
	system("pause");
}