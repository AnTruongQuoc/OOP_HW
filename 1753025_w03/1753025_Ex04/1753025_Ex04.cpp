#include "Date.h"
#include <iostream>
using namespace std;

void main()
{
	Date b;
	b.inputTime();
	Date tomorrow = b.theNextDay();
	tomorrow.display();
	Date yesterday = b.theDayBefore();
	yesterday.display();
	system("pause");
}