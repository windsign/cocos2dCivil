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
	/*在vs下可以运行，但是不能再android下运行的代码
	//根据xml数据创建动画
	string xmlFile_path = "bg.xml";
	//读取动作XML文件
	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
	doc->LoadFile(xmlFile_path.c_str());
	tinyxml2::XMLElement *ani_node = doc->RootElement();
	tinyxml2::XMLElement *action_node = ani_node->FirstChildElement("action");
	*/

	//根据xml数据创建动画
	//std::string xmlFile_path = "bg.xml";
	//获得文件在系统的绝对路径
	std::string xmlfilepath = CCFileUtils::sharedFileUtils()->fullPathForFilename("PawnTable.xml");
	if (xmlfilepath.empty()){
		return false;
	}
	//读取的字节数，读取失败则为0
	ssize_t len = 0;
	//读取的内容
	unsigned char *data = CCFileUtils::sharedFileUtils()->getFileData(xmlfilepath.c_str(), "r", &len);
	//读取动作XML文件
	TiXmlDocument* doc = new TiXmlDocument();
	doc->Parse((char*)data);
	TiXmlElement *rootElement = doc->RootElement();
	TiXmlElement *pawnElement = rootElement->FirstChildElement("Pawn");
	for (; pawnElement != NULL; pawnElement = pawnElement->NextSiblingElement()) {
		/*
		TiXmlAttribute* attributeOfStudent = studentElement->FirstAttribute();  //获得student的name属性  
		for (; attributeOfStudent != NULL; attributeOfStudent = attributeOfStudent->Next()) {
			cout << attributeOfStudent->Name() << " : " << attributeOfStudent->Value() << std::endl;
		}
		*/
		TiXmlElement* porpertyElement = pawnElement->FirstChildElement();//获得student的第一个联系方式 
		for (; porpertyElement != NULL; porpertyElement = porpertyElement->NextSiblingElement()) {
			std::string contactType = porpertyElement->Value();
			std::string contactValue = porpertyElement->GetText();
		}

	}
	return true;
}
