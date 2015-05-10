#ifndef TERRAINTABLE_H
#define TERRAINTABLE_H

#include <string>

struct CTerrainWeather
{
     int m_iID;
     std::string m_name;
     std::string m_image;
};

struct CTerrainCell
{
     int m_iID;
     std::string m_name;
     std::string m_image;
};

struct CTerrainResource
{
     int m_iID;
     std::string m_name;
     std::string m_image;
     int m_iProductType[3];
     int m_iProductQulity[3];
};

struct CTerrainBuilding
{
     int m_iID;
     std::string m_name;
     std::string m_image;
     int m_iProductType[3];
     int m_iProductQulity[3];
};
#endif