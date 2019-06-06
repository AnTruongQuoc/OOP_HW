#include "Time.h"
#include <iostream>
using namespace std;

void main()
{
	Time b, future;
	b.input();
	future = b.future();
	future.output();
	system("pause");
}