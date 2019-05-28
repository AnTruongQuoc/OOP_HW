#include "Point.h"
#include <iostream>
using namespace std;


Point::Point()
{
	x = 0;
	y = 0;
}

double& Point::getX()
{
	return x;
}
double& Point::getY()
{
	return y;
}
void Point::input()
{
	cout << "Enter point x y: ";
	cin >> x >> y;
}
void Point::display()
{
	cout << "(" << x << "," << y << ")" << " ";
}
double Point::distance(Point p)
{
	return sqrt((pow(this->x - p.x, 2) + pow(this->y - p.y, 2)));
}

