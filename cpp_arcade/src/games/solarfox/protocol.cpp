#include "games/SolarFox.hh"
#include <stdlib.h>
#include <iostream>

void  SolarFox::where_am_i()
{
  size_t                sizeStruct;
  arcade::WhereAmI      *myPos;
  int                   itrPos = 0;
  int                   itr;

  this->writeMap();
  sizeStruct = sizeof(arcade::WhereAmI) + sizeof(arcade::Position);
  if ((myPos = static_cast<arcade::WhereAmI *>(malloc(sizeStruct))))
  {
    myPos->type = arcade::CommandType::WHERE_AM_I;
    myPos->lenght = 1;
    for (itr = 0; itr < this->xSize * this->ySize; itr++)
    {
      if (this->map[itr].t == games::SPACESHIP)
        {
          myPos->position[itrPos].x = itr % this->xSize;
          myPos->position[itrPos].y = itr / this->xSize;
          itrPos++;
          break;
        }
      }
    write(1, myPos, sizeStruct);
  }
}

void  SolarFox::get_map()
{
  size_t          size;
  arcade::GetMap  *map;
  int    itr;

  this->writeMap();
  size = sizeof(arcade::GetMap) + (sizeof(arcade::TileType) * this->xSize * this->ySize);
  if ((map = static_cast<arcade::GetMap *>(malloc(size))))
  {
    map->type = arcade::CommandType::GET_MAP;
    map->width = this->xSize;
    map->height = this->ySize;
    for (itr = 0; itr < this->xSize*this->ySize; itr++)
      map->tile[itr] = this->convertToArcade(this->map[itr].t);
    write(1, map, size);
  }
}

void  SolarFox::setCmd(games::CommandType cmd)
{
  this->cmd = cmd;
}
