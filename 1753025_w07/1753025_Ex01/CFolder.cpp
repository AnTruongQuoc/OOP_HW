#include "CFolder.h"
#include "Cfile.h"

CFolder::CFolder(string name) :CItem(name) {};
void CFolder::add(CItem* obj)
{
	m_list.push_back(obj);
	this->getSize() += obj->getSize();
}

void CFolder::print(bool choose)
{
	if (choose == 0)
	{
		CItem::print();
	}
	else
	{
		CItem::print();
		for (int i = 0; i < m_list.size(); i++)
		{
			if (typeid(*m_list[i]) == typeid(Cfile))
				m_list[i]->print();
			else
			{
				CFolder* temp = dynamic_cast<CFolder*>(m_list[i]);
				temp->print(1);
			}
		}
	}
}
CItem* CFolder::removeByName(string name)
{
	CItem* temp = NULL;
	for (int i = 0; i < m_list.size(); i++)
	{
		if (m_list[i]->checkName(name))
		{
			temp = m_list[i];
			m_list[i] = m_list[m_list.size() - 1];
			m_list[m_list.size() - 1] = temp;
			m_list.pop_back();
			this->getSize() -= temp->getSize();
			return temp;
		}
		else if (typeid(*m_list[i]) == typeid(CFolder))
		{
			CFolder* tempF = dynamic_cast<CFolder*>(m_list[i]);
			temp = tempF->removeByName(name);
		}
	}
	return temp;
}
CItem* CFolder::findByname(string name)
{
	CItem* temp = NULL;
	for (int i = 0; i < m_list.size(); i++)
	{
		if (m_list[i]->checkName(name))
		{
			return m_list[i];
		}
		else if (typeid(*m_list[i]) == typeid(CFolder))
		{
			CFolder* tempF = dynamic_cast<CFolder*>(m_list[i]);
			temp = tempF->findByname(name);
			if (temp != NULL)
				return temp;
		}
	}
	return temp;
}
void CFolder::setHidden(bool folder, bool item)
{
	CItem::setHidden(folder);
	for (int i = 0; i < m_list.size(); i++)
	{
		if (typeid(*m_list[i]) == typeid(Cfile))
		{
			m_list[i]->setHidden(item);
		}
		else
		{
			CFolder* tempF = dynamic_cast<CFolder*>(m_list[i]);
			tempF->setHidden(folder, item);
		}
	}
}