#include "games/solarfox/SpaceShip.hh"
#include "games/solarfox/SpaceShipShoot.hh"

SpaceShip::SpaceShip(int x, int y, games::TileDirection direction)
{
  this->setDirection(direction);
  this->setCurPos(x, y);
  this->setType(games::SPACESHIP);
  this->setLife(LIFE);
}

SpaceShip::~SpaceShip()
{
}

bool inverDirection(games::TileDirection save, games::TileDirection current)
{
  if ((save == games::UP && current == games::DOWN) ||
      (save == games::DOWN && current == games::UP) ||
      (save == games::LEFT && current == games::RIGHT) ||
      (save == games::RIGHT && current == games::LEFT))
    return true;
  else
    return false;
}

void SpaceShip::move()
{
  this->shift(this->direction);
  if ((this->curPos[0] == this->minPos[0]) ||
      (this->curPos[1] == this->minPos[1]) ||
      (this->curPos[0] == this->maxPos[0]) ||
      (this->curPos[1] == this->maxPos[1]))
    this->life -= 1;
}

void SpaceShip::exec(SolarFox *obj)
{
  games::TileDirection save = this->direction;
  if (obj->getCmd() == games::SHOOT)
    {
      obj->getPerso()->push_front(new SpaceShipShoot(this->getXCurPos(), this->getYCurPos(), this->getDirection()));
      obj->getPerso()->front()->setMinPos(0, 0);
      obj->getPerso()->front()->setMaxPos(obj->getXSize()-1, obj->getYSize()-1);
      obj->getPerso()->front()->move();
      this->toDirection(obj);
    }
  else
    {
      this->toCommand(obj);
      if (obj->getIgraph() && inverDirection(save, this->direction))
        this->direction = save;
      this->move();
    }
}
