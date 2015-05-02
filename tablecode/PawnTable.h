#ifndef PAWNTABLE_H
#define PAWNTABLE_H

#include "tinyxml.h"
#include "tinystr.h"
#include <vector>
#include <string>
#include <hash_map>

struct CPawnTableElement
{
	int m_iID;
	std::string m_name;
	int m_iLevel;
	std::string m_Image;
	int m_iHealth;
	int m_iMana;
	int m_iAttack;
	int m_iDefence;
	int m_iMoveCount;
	int m_iAttackCount;
	int m_iActiveSkill[3];
	int m_iPassiveSkill[7];
	std::string m_tip;
};


class CPawnTable
{
public:
	CPawnTable();
	~CPawnTable();
	bool LoadTable();
private:
	std::hash_map<int,CPawnTableElement> m_pawnElement;
};

CPawnTable* GetPawnTable();
#endif