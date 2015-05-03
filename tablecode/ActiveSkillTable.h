#ifndef ACTIVETABLE_H
#define ACTIVETABLE_H

#include "tinyxml.h"
#include "tinystr.h"
#include <vector>
#include <string>
#include <map>

struct CActiveSkillElement
{
	int m_iID;
	std::string m_name;
	int m_iLevel;
	std::string m_Image;		//技能图标
	int m_iColdDown;			//冷却时间
	int m_iType;				//此技能是伤害技能，还是治疗，还是buff
	int m_iProperty;			//是否可以伤害自己人什么的
	int m_iValue[3];
	int m_iDistance;			//技能的释放范围，像是火球术可以攻击3格，0表示只能对自己释放
	int m_iAffectRange;			//技能的影响范围，像是烈焰风暴可以烧2格，0表示全图
	std::string	m_tip;			//小贴士
};

class CActiveSkillTable
{
public:
	CActiveSkillTable();
	~CActiveSkillTable();
	bool LoadTable();
private:
	std::map<int, CActiveSkillElement> m_activeSkillElement;
};

CActiveSkillTable* GetActiveSkillTable();

#endif