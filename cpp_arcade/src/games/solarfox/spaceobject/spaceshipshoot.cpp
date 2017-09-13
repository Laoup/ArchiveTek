#include "games/solarfox/SpaceShipShoot.hh"

SpaceShipShoot::SpaceShipShoot(int x, int y, games::TileDirection direction)
{
  this->setDirection(direction);
  this->setCurPos(x, y);
  this->setType(games::MY_SHOOT);
  this->setLife(1);
}

SpaceShipShoot::~SpaceShipShoot()
{
}

void SpaceShipShoot::move()
{
  this->shift(this->direction);
  if ((this->curPos[0] == this->minPos[0]) ||
      (this->curPos[1] == this->minPos[1]) ||
      (this->curPos[0] == this->maxPos[0]) ||
      (this->curPos[1] == this->maxPos[1]))
    this->life -= 1;
}

void SpaceShipShoot::exec(SolarFox *obj)
{
  obj = obj;
  this->move();
}
