#pragma once
#include <iostream>
using namespace std;
class IntArray
{
private:
	int *m_array;
	int m_length;
public:
	IntArray();
	IntArray(int size);
	IntArray(int *a, int size);
	IntArray(const IntArray& p);
	IntArray& operator =(IntArray p);
	friend istream& operator >>(istream& in, IntArray& p);
	friend ostream& operator <<(ostream& out, const IntArray& p);
	int& operator [](int index);
	explicit operator int();
	~IntArray();
};