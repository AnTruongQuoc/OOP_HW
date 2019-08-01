#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CItem
{
private:
	string m_name;
	bool m_readOnly;
	int m_size;
public:
	CItem(string name);
	CItem(string name, int size);
	int& getSize() { return m_size; }
	virtual void print();
	bool checkName(string name) { return m_name == name; }
	virtual void setHidden(bool i) { m_readOnly = !i; }
};