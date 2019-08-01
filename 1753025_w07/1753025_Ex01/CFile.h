#pragma once
#include "CItem.h"

class Cfile :public CItem
{
private:
	string m_ext;
public:
	Cfile(string name, int size);
};