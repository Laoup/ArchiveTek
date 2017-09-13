#include "games/solarfox/Obstacle.hh"

Obstacle::Obstacle(int x, int y)
{
  this->setDirection(games::UNDEFINE);
  this->setCurPos(x, y);
  this->setType(games::OBSTACLE);
  this->setLife(1);
}

Obstacle::~Obstacle()
{
}

void Obstacle::exec(SolarFox *obj)
{
  obj = static_cast<SolarFox *>(obj);
}
