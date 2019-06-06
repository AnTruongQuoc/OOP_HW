#include "Array.h"
#include <iostream>
using namespace std;

void main()
{
	Array b;
	b.input("input.txt");
	b.sortName();
	b.output();
	b.output("output.xml");
	system("pause");
}