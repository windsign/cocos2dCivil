#ifndef TINYXMLLOAD_H
#define TINYXMLLOAD_H

#include <string>
#include "tinyxml.h"
#include "tinystr.h"

#define LOADTIXMLELE(ele, des)      \
    LoadTiXMLElement(ele, des);     \
    porpertyElement = porpertyElement->NextSiblingElement()

bool LoadTiXMLElement(TiXmlElement* curElement, std::string& des);
bool LoadTiXMLElement(TiXmlElement* curElement, int& des);
bool LoadTiXMLElement(TiXmlElement* curElement, float& des);



#endif
