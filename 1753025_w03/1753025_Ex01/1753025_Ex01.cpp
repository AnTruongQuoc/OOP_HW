#include "Array.h"
#include <iostream>
using namespace std;

void main()
{
	Array b;
	Fraction sum;
	Fraction max;
	Fraction min;

	b.input("input.txt");
	b.output();

	cout << "Sum: ";
	sum = b.calcSum();
	sum.display();
	cout << endl;

	cout << "Max: ";
	max = b.findMax();
	max.display();
	cout << endl;

	cout << "Min: ";
	min = b.findMin();
	min.display();
	cout << endl;

	cout << "Sort Ascending: ";
	b.sortAscending();
	b.output();

	system("pause");
}