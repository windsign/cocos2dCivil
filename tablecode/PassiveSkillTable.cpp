#include "PassiveSkillTable.h"
#include "cocos2d.h"

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
		TiXmlElement* porpertyElement = skillElement->FirstChildElement();
		for (; porpertyElement != NULL; porpertyElement = porpertyElement->NextSiblingElement())
		{
			std::string contactType = porpertyElement->Value();
			std::string contactValue = porpertyElement->GetText();
		}
	}
	return true;
}
