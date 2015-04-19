#ifndef RENDERWORLD_H
#define RENDERWORLD_H

#include <map>

using namespace std;

class CRenderObject;

class CRenderWorld
{
public:
	int AddSixEdgeRenderObject();
private:
	map<int, CRenderObject*> m_mapRenderObject;
};

#endif
