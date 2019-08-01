#include "CItem.h"
CItem::CItem(string name)
{
	m_name = name;
	m_readOnly = 1;
	m_size = 0;
}
CItem::CItem(string name, int size)
{
	m_name = name;
	m_readOnly = 1;
	m_size = size;
}
void CItem::print()
{
	cout << "Name: " << m_name << endl;
	cout << "Size: " << m_size << endl;
	cout << "Read only: " << m_readOnly << endl;
}