#include "TinyXMLLoad.h"

bool LoadTiXMLElement(TiXmlElement* curElement, std::string& des)
{
	des = curElement->GetText();
	return true;
}

bool LoadTiXMLElement(TiXmlElement* curElement, int& des)
{
    /*
	int ret = curElement->QueryIntAttribute("int", &des);
	if(ret == TIXML_SUCCESS)
		return true;
	return false;
     */
    std::string intTex;
    intTex = curElement->GetText();
    des = atoi(intTex.c_str());
    return true;
}

bool LoadTiXMLElement(TiXmlElement* curElement, float& des)
{
    /*
	int ret = curElement->QueryFloatAttribute("float", &des);
	if(ret == TIXML_SUCCESS)
		return true;
	return false;
    */
    std::string intTex;
    intTex = curElement->GetText();
    des = atof(intTex.c_str());
    return true;
}
