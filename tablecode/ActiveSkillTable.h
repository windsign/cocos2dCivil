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
	std::string m_Image;		//����ͼ��
	int m_iColdDown;			//��ȴʱ��
	int m_iType;				//�˼������˺����ܣ��������ƣ�����buff
	int m_iProperty;			//�Ƿ�����˺��Լ���ʲô��
	int m_iValue[3];
	int m_iDistance;			//���ܵ��ͷŷ�Χ�����ǻ��������Թ���3��0��ʾֻ�ܶ��Լ��ͷ�
	int m_iAffectRange;			//���ܵ�Ӱ�췶Χ����������籩������2��0��ʾȫͼ
	std::string	m_tip;			//С��ʿ
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