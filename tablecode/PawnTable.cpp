#include "PawnTable.h"
#include "cocos2d.h"
#include "TinyXMLLoad.h"

USING_NS_CC;

CPawnTable* g_pPawnTable = 0;
CPawnTable* GetPawnTable()
{
	if (g_pPawnTable == 0)
	{
		g_pPawnTable = new CPawnTable();
	}
	return g_pPawnTable;
}

CPawnTable::CPawnTable()
{

}

CPawnTable::~CPawnTable()
{

}

bool CPawnTable::LoadTable()
{
	/*��vs�¿������У����ǲ�����android�����еĴ���
	//����xml���ݴ�������
	string xmlFile_path = "bg.xml";
	//��ȡ����XML�ļ�
	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
	doc->LoadFile(xmlFile_path.c_str());
	tinyxml2::XMLElement *ani_node = doc->RootElement();
	tinyxml2::XMLElement *action_node = ani_node->FirstChildElement("action");
	*/

	//����xml���ݴ�������
	//std::string xmlFile_path = "bg.xml";
	//����ļ���ϵͳ�ľ���·��
	std::string xmlfilepath = CCFileUtils::sharedFileUtils()->fullPathForFilename("PawnTable.xml");
	if (xmlfilepath.empty()){
		return false;
	}
	//��ȡ���ֽ�������ȡʧ����Ϊ0
	ssize_t len = 0;
	//��ȡ������
	unsigned char *data = CCFileUtils::sharedFileUtils()->getFileData(xmlfilepath.c_str(), "r", &len);
	//��ȡ����XML�ļ�
	TiXmlDocument* doc = new TiXmlDocument();
	doc->Parse((char*)data);
	TiXmlElement *rootElement = doc->RootElement();
	TiXmlElement *pawnElement = rootElement->FirstChildElement("Pawn");
	for (; pawnElement != NULL; pawnElement = pawnElement->NextSiblingElement()) {
		/*
		TiXmlAttribute* attributeOfStudent = studentElement->FirstAttribute();  //���student��name����  
		for (; attributeOfStudent != NULL; attributeOfStudent = attributeOfStudent->Next()) {
			cout << attributeOfStudent->Name() << " : " << attributeOfStudent->Value() << std::endl;
		}
		*/
        CPawnTableElement newPTE;
		TiXmlElement* porpertyElement = pawnElement->FirstChildElement();//���student�ĵ�һ����ϵ��ʽ
        LOADTIXMLELE(porpertyElement, newPTE.m_iID);
        LOADTIXMLELE(porpertyElement, newPTE.m_name);
		LOADTIXMLELE(porpertyElement, newPTE.m_iRace);
        LOADTIXMLELE(porpertyElement, newPTE.m_iLevel);
        LOADTIXMLELE(porpertyElement, newPTE.m_Image);
        LOADTIXMLELE(porpertyElement, newPTE.m_iHealth);
        LOADTIXMLELE(porpertyElement, newPTE.m_iMana);
        LOADTIXMLELE(porpertyElement, newPTE.m_iAttack);
		LOADTIXMLELE(porpertyElement, newPTE.m_iAttackType);
        LOADTIXMLELE(porpertyElement, newPTE.m_iDefence);
        LOADTIXMLELE(porpertyElement, newPTE.m_iMoveCount);
        LOADTIXMLELE(porpertyElement, newPTE.m_iAttackCount);
        for(int i = 0; i < 3; i++)
        {
            LOADTIXMLELE(porpertyElement, newPTE.m_iActiveSkill[i]);
        }
        
        for(int i = 0; i < 7; i++)
        {
            LOADTIXMLELE(porpertyElement, newPTE.m_iPassiveSkill[i]);
        }
      
        LoadTiXMLElement(porpertyElement, newPTE.m_tip);

        std::pair<int, CPawnTableElement> newPair(newPTE.m_iID, newPTE);
        m_pawnElement.insert(newPair);
        
        /* //old read the tinyxml
		for (; porpertyElement != NULL; porpertyElement = porpertyElement->NextSiblingElement()) {
			std::string contactType = porpertyElement->Value();
			std::string contactValue = porpertyElement->GetText();
            int des;
            LoadTiXMLElement(porpertyElement, des);
            printf("%d", des);
		}
         */

	}
	return true;
}

CPawnTableElement* CPawnTable::GetPawnElement(int idx)
{
	std::map<int, CPawnTableElement>::iterator itor = m_pawnElement.find(idx);
	if (itor != m_pawnElement.end())
	{
		return &((*itor).second);
	}
	return NULL;
}
