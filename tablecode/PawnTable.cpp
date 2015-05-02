#include "PawnTable.h"
#include "cocos2d.h"

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
		TiXmlElement* porpertyElement = pawnElement->FirstChildElement();//���student�ĵ�һ����ϵ��ʽ 
		for (; porpertyElement != NULL; porpertyElement = porpertyElement->NextSiblingElement()) {
			std::string contactType = porpertyElement->Value();
			std::string contactValue = porpertyElement->GetText();
		}

	}
	return true;
}
