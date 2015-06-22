#ifndef TERRAINTYPE_H
#define TERRAINTYPE_H

enum EWeatherType
{
     eTT_Plane,       //平原
     eTT_Grass,     //草原  
     eTT_Swamp,     //沼泽
     eTT_Desert,     //沙漠
     eTT_Snow,       //雪地
     eTT_Lava,       //熔岩之地
     eTT_AllWeather
};
 
enum ETerrainType
{
     eTT_Normal,     //平原
     eTT_Hill,      //丘陵    
     eTT_Mountain,  //山峰   
     eTT_Lake,       //湖泊
     eTT_AllTerrain
};

enum EResourceType
{
     eRT_None,
     eRT_Gold,
     eRT_Silver,
     eRT_Iron,
     eRT_Jewel,
     eRT_Wind,
     eRT_Fire,
     eRT_Earth,
     eRT_Water,
     eRT_AllResource
};

#endif