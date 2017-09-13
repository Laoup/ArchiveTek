#include "games/solarfox/SpaceObject.hh"
#include <iostream>

void SpaceObject::setCurPos(int x, int y)
{
  this->curPos[0] = x;
  this->curPos[1] = y;
}

void SpaceObject::setMinPos(int x, int y)
{
  this->minPos[0] = x;
  this->minPos[1] = y;
}

void SpaceObject::setMaxPos(int x, int y)
{
  this->maxPos[0] = x;
  this->maxPos[1] = y;
}

void SpaceObject::shift(games::TileDirection direction)
{
  switch (direction)
  {
    case games::UP:
      if (this->curPos[1] > this->minPos[1])
        this->curPos[1] -= 1;
      break;

    case games::DOWN:
      if (this->curPos[1] < this->maxPos[1])
        this->curPos[1] += 1;
      break;

    case games::LEFT:
      if (this->curPos[0] > this->minPos[0])
        this->curPos[0] -= 1;
      break;

    case games::RIGHT:
      if (this->curPos[0] < this->maxPos[0])
        this->curPos[0] += 1;
      break;
  }
}

void SpaceObject::toDirection(SolarFox *obj)
{
  switch (this->getDirection()) {
    case games::UP: obj->setCmd(games::GO_UP); break;
    case games::DOWN: obj->setCmd(games::GO_DOWN); break;
    case games::LEFT: obj->setCmd(games::GO_LEFT); break;
    case games::RIGHT: obj->setCmd(games::GO_RIGHT); break;
  }
}

void   SpaceObject::toCommand(SolarFox *obj)
{
  switch (obj->getCmd()) {
    case games::GO_UP:
      this->setDirection(games::UP); break;
    case games::GO_DOWN:
      this->setDirection(games::DOWN); break;
    case games::GO_LEFT:
      this->setDirection(games::LEFT); break;
    case games::GO_RIGHT:
      this->setDirection(games::RIGHT); break;
    default: break;
  }
}
