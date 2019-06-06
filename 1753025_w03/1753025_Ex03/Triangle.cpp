#include "Triangle.h"

 Triangle::Triangle()
{
	 a = NULL;
	 b = NULL;
	 c = NULL;
}

 Triangle::Triangle(const Triangle& x) {
	 if (this == &x)
		 return;
	 a = x.a;
	 b = x.b;
	 c = x.c;
 }

 double Triangle::getA() {
	 return a;
 }

 double Triangle::getB() {
	 return b;
 }

 double Triangle::getC() {
	 return c;
 }

 void Triangle::setA(double x) {
	 a = x;
 }

 void Triangle::setB(double x) {
	 b = x;
 }

 void Triangle::setC(double x) {
	 c = x;
 }

 bool Triangle::checkTri() {
	 if (a + b > c&&b + c > a&&a + c > b)
		 return true;
	 return false;
 }

 int Triangle::classify()
 {
	 if (this->checkTri())
	 {
		 if (a*a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a)
			 return 1;
		 else if (a == b && b == c && c == a)
			 return 2;
		 else if ((a*a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a) && (a*a + b * b < c * c || a * a + c * c < b * b || c * c + b * b < a * a))
		 {
			 return 3;
		 }
		 else if (a*a + b * b > c * c || a * a + c * c > b * b || c * c + b * b > a * a)
			 return 4;
		 else if (a*a + b * b < c * c || a * a + c * c < b * b || c * c + b * b < a * a)
			 return 5;
	 }
	 else
		 return -1;
 }