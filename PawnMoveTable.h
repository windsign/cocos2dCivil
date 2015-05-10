#ifndef PAWNMOVETABLE_H
#define PAWNMOVETABLE_H

struct CPawnMove
{
     int m_iPlaneConsume;
     int m_iGrassConsume;
     int m_iSwampConsume;
     int m_iDesertConsume;
     int m_iSnowConsume;
     int m_iLavaConsume;
     //
     int m_iNormalTerrainConsume;
     int m_iHillConsume;
     int m_iMountainConsume;
     int m_iLakeConsume;
     //
     int m_iForestConsume;
};


#endif