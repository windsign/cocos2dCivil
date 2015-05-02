#ifndef PASSIVETABLE_H
#define PASSIVETABLE_H

#include "tinyxml.h"
#include "tinystr.h"
#include <vector>
#include <string>
#include <hash_map>

struct CPassiveSkillElement
{
	int m_iID;
	std::string m_name;
	int m_iLevel;
	std::string m_Image;		//技能图标
	int m_iType;				//此技能是攻击类型，如反击加强，还是防御提高，还是影响buff
	int m_iProperty;			//是否可以伤害自己人什么的
	int m_iValue[3];
	int m_iAffectRange;			//技能的影响范围，光环还是自己带的被动
	std::string	m_tip;			//小贴士
};

class CPassiveSkillTable
{
public:
	CPassiveSkillTable();
	~CPassiveSkillTable();
	bool LoadTable();
private:
	std::hash_map<int, CPassiveSkillElement> m_activeSkillElement;
};

CPassiveSkillTable* GetPassiveSkillTable();

#endif