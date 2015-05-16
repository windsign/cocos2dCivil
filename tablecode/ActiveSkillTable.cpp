#include "ActiveSkillTable.h"
#include "cocos2d.h"

USING_NS_CC;

CActiveSkillTable* g_pActiveSkillTable = 0;

CActiveSkillTable* GetActiveSkillTable()
{
	if (g_pActiveSkillTable == 0)
	{
		g_pActiveSkillTable = new CActiveSkillTable;
	}
	return g_pActiveSkillTable;
}

CActiveSkillTable::CActiveSkillTable()
{

}

CActiveSkillTable::~CActiveSkillTable()
{

}

bool CActiveSkillTable::LoadTable()
{
	std::string xmlfilepath = CCFileUtils::sharedFileUtils()->fullPathForFilename("ActiveSkillTable.xml");
	if (xmlfilepath.empty()){
		return false;
	}
	ssize_t len = 0;
	unsigned char *data = CCFileUtils::sharedFileUtils()->getFileData(xmlfilepath.c_str(), "r", &len);

	TiXmlDocument* doc = new TiXmlDocument();
	doc->Parse((char*)data);
	TiXmlElement *rootElement = doc->RootElement();
	TiXmlElement *skillElement = rootElement->FirstChildElement("ActiveSkill");
	for (; skillElement != NULL; skillElement = skillElement->NextSiblingElement()) 
	{
		CActiveSkillElement newASE;
		TiXmlElement* porpertyElement = skillElement->FirstChildElement();
		LOADTIXMLELE(porpertyElement, newASE.m_iID);
		LOADTIXMLELE(porpertyElement, newASE.m_name);
		LOADTIXMLELE(porpertyElement, newASE.m_iLevel);
		LOADTIXMLELE(porpertyElement, newASE.m_Image);
		LOADTIXMLELE(porpertyElement, newASE.m_iColdDown);
		LOADTIXMLELE(porpertyElement, newASE.m_iType);
		LOADTIXMLELE(porpertyElement, newASE.m_iProperty);
		for(int i = 0; i < 3; i++)
		{
			LOADTIXMLELE(porpertyElement, newASE.m_iValue[i]);
		}
		LOADTIXMLELE(porpertyElement, newASE.m_iDistance);
		LOADTIXMLELE(porpertyElement, newASE.m_iAffectRange);

		LoadTiXMLElement(porpertyElement, newASE.m_tip);
		std::pair<int, CActiveSkillElement> newPair(newASE.m_iID, newASE);
		m_activeSkillElement.insert(newPair);
		/*
		for (; porpertyElement != NULL; porpertyElement = porpertyElement->NextSiblingElement()) 
		{
			std::string contactType = porpertyElement->Value();
			std::string contactValue = porpertyElement->GetText();
		}
		*/

	}
	return true;
}


