#ifndef TERRAIN_H
#define TERRAIN_H

#include "Point2D.h"
#include <vector>

struct OneTerrainCell
{
	CLPoint2D m_logicPosition;
	int m_iTerrain;
	int m_iResource;              //永久地形资源，
	int m_iBuild;
};

class CTerrain
{
public:

private:
	std::vector<std::vector<OneTerrainCell> > m_oddTerrainCell;
	std::vector<std::vector<OneTerrainCell> > m_evenTerrainCell;

	int m_iOddHeight;
	int m_iOddWidth;
	int m_iEvenHeight;
	int m_iEvenWidth;
};

#endif
