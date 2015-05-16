#include "PassiveSkillTable.h"
#include "cocos2d.h"
#include "TinyXMLLoad.h"

USING_NS_CC;

CPassiveSkillTable* g_pPassiveSkillTable = 0;

CPassiveSkillTable* GetPassiveSkillTable()
{
	if (g_pPassiveSkillTable == 0)
	{
		g_pPassiveSkillTable = new CPassiveSkillTable;
	}
	return g_pPassiveSkillTable;
}


CPassiveSkillTable::CPassiveSkillTable()
{

}

CPassiveSkillTable::~CPassiveSkillTable()
{

}

bool CPassiveSkillTable::LoadTable()
{
	std::string xmlfilepath = CCFileUtils::sharedFileUtils()->fullPathForFilename("PassiveSkillTable.xml");
	if (xmlfilepath.empty()){
		return false;
	}
	ssize_t len = 0;
	unsigned char *data = CCFileUtils::sharedFileUtils()->getFileData(xmlfilepath.c_str(), "r", &len);

	TiXmlDocument* doc = new TiXmlDocument();
	doc->Parse((char*)data);
	TiXmlElement *rootElement = doc->RootElement();
	TiXmlElement *skillElement = rootElement->FirstChildElement("PassiveSkill");
	for (; skillElement != NULL; skillElement = skillElement->NextSiblingElement())
	{
		CPassiveSkillElement newPSE;
		TiXmlElement* porpertyElement = skillElement->FirstChildElement();
		LOADTIXMLELE(porpertyElement, newPSE.m_iID);
		LOADTIXMLELE(porpertyElement, newPSE.m_name);
		LOADTIXMLELE(porpertyElement, newPSE.m_iLevel);
		LOADTIXMLELE(porpertyElement, newPSE.m_Image);
		LOADTIXMLELE(porpertyElement, newPSE.m_iType);
		LOADTIXMLELE(porpertyElement, newPSE.m_iProperty);
		for (int i = 0; i < 3; ++i)
		{
			LOADTIXMLELE(porpertyElement, newPSE.m_iValue[i]);
			/* code */
		}
		LOADTIXMLELE(porpertyElement, newPSE.m_iAffectRange);
		LoadTiXMLElement(porpertyElement, newPSE.m_tip);
		std::pair<int, CPassiveSkillElement> newPair(newPSE.m_iID, newPSE);
		m_passiveSkillElement.insert(newPair);
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
