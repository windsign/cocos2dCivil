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
	std::string m_Image;		//����ͼ��
	int m_iType;				//�˼����ǹ������ͣ��練����ǿ�����Ƿ�����ߣ�����Ӱ��buff
	int m_iProperty;			//�Ƿ�����˺��Լ���ʲô��
	int m_iValue[3];
	int m_iAffectRange;			//���ܵ�Ӱ�췶Χ���⻷�����Լ����ı���
	std::string	m_tip;			//С��ʿ
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