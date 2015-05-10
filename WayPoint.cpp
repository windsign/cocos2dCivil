struct WayPoint
{
     CLPoint2D point;
     int restMoveCount;
     bool IsOptimization;
     std::vector<CLPoint2D> wayPoints;
};

std::set<WayPoint > way;

void GetWayPoints(WayPoint curPos,CPawnMove* mt, std::set<WayPoint>& way)
{
     if(curPos.restMoveCount <= 0)
          return;
     
     CLPoint2D respoint[6];
     GetAdjacentCell(curPoint.point, CLPoint2D respoint[]);
     for(int i = 0; i < 6; i++)
     {
          std::vector<CLPoint2D>::reverse_iterator ritor;
          bool inPath = false;
          for(ritor = curPos.wayPoints.rbegin(); ritor = curPos.wayPoints.rend(); ritor++)
          {
               if((*vitor).point == respoint[i])
               {
                    inPath = true;
                    break;
               }
          }
          if(inPath)
          {
               continue;
          }
          OneTerrainCell* tCell = GetTerrainCell(respoint[i]); 
          int consumeMoveCount = CalMoveConsume(mt, tCell);
          int restMoveCount = curPoint.restMoveCount - consumeMoveCount;
          std::set<WayPoint>::iterator itor;
          bool hasPass = false;
          bool wayNeed = false;
          for(itor = way.begin(); itor != way.end(); itor++)
          {
               if((*itor).point == respoint[i])
               {
                    hasPass = true;
                    if(resMoveCount > (*itor).restMoveCount)
                    {
                         (*itor).wayPoints = curPos.wayPoints;
                         (*itor).wayPoints.push_back(curPos.point);                         
                         wayNeed = true;
                    }
                    break;
               }
               
          }
          if(!hasPass)
          {
               wayNeed = true;
               WayPoint newWayPoint;
               newWayPoint.
          }
     }
}   

int CalMoveConsume(CPawnMove* mt, OneTerrainCell* tc)
{
     
}