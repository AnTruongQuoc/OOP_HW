#pragma once
#include "CItem.h"

class CFolder : public CItem
{
private:
	vector <CItem *> m_list;
public:
	CFolder(string name);
	void add(CItem *obj);
	int sizeList() { return m_list.size(); }
	void print(bool choose);
	CItem* removeByName(string name);
	CItem* findByname(string name);
	void setHidden(bool folder, bool item);
};