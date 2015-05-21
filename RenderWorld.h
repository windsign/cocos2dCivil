#ifndef RENDERWORLD_H
#define RENDERWORLD_H

#include <map>
#include "cocos2d.h"

USING_NS_CC;

using namespace std;

enum EShaderType
{
	eST_Pawn,
	eST_ALL
};

class CRenderObject;

class CRenderWorld
{
public:
	CRenderWorld();
	~CRenderWorld();
	int AddSixEdgeRenderObject(std::string& imageName);
	void Init();
	void InitShaderProgram();
	GLProgram* GetShaderProgram(EShaderType e);
	void Draw(EShaderType eST);
	void SetRenderObjectPos(int idx, EShaderType est);
private:
	map<int, CRenderObject*> m_mapRenderObject[eST_ALL];
	int m_iCurRenderObjectIndex;
	GLProgram* m_pGLProgram[eST_ALL];
};


#endif
