#include"Array.h"

IntArray::IntArray()
{
	m_array = NULL;
	m_length = 0;
}
IntArray::IntArray(int size)
{
	m_length = size;
	m_array = new int[m_length];
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = 0;
	}
}
IntArray::IntArray(int *a, int size)
{
	m_length = size;
	m_array = new int[m_length];
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = a[i];
	}
}
IntArray::IntArray(const IntArray& p)
{
	m_length = p.m_length;
	m_array = new int[m_length];
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = p.m_array[i];
	}
}
IntArray& IntArray::operator =(IntArray p)
{
	delete[] m_array;
	m_length = p.m_length;
	m_array = new int[m_length];
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = p.m_array[i];
	}
	return *this;
}
IntArray::operator int()
{
	int sum = 0;
	for (int i = 0; i < m_length; i++)
	{
		sum = sum + m_array[i];
	}
	return sum;
}
IntArray::~IntArray()
{
	delete[]m_array;
}
int& IntArray::operator [](int index)
{
	if (index >= m_length || index < 0)
	{
		cout << "Error index." << endl;
		int *a = NULL;
		*a = 22;
		return *a;
	}
	return m_array[index];
}
istream& operator >>(istream& in, IntArray &p)
{
	cout << "Enter length: ";
	in >> p.m_length;

	delete[]p.m_array;
	p.m_array = new int[p.m_length];
	for (int i = 0; i < p.m_length; i++)
	{
		cout << "Enter [" << i << "]: ";
		in >> p.m_array[i];
	}
	return in;
}
ostream& operator <<(ostream& out, const IntArray& p)
{
	for (int i = 0; i < p.m_length; i++)
	{
		out << p.m_array[i] << " ";
	}
	out << endl;
	return out;
}