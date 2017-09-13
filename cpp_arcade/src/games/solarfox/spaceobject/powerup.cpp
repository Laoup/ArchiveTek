#include "games/solarfox/PowerUp.hh"

PowerUp::PowerUp(int x, int y)
{
  this->setDirection(games::UNDEFINE);
  this->setCurPos(x, y);
  this->setType(games::POWERUP);
  this->setLife(1);
}

PowerUp::~PowerUp()
{
}

void PowerUp::exec(SolarFox *obj)
{
  obj = static_cast<SolarFox *>(obj);
}
