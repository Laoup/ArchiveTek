#include "games/solarfox/SFXVEnemy.hh"
#include "games/solarfox/EnemyShoot.hh"
#include <time.h>
#include <stdlib.h>

SFXVEnemy::SFXVEnemy(int x, int y, games::TileDirection direction)
{
  this->setDirection(direction);
  this->setCurPos(x, y);
  this->setType(games::SFX_VENEMY);
  this->setLife(100);
  this->moveDirection = games::UP;
  srand(time(NULL));
}

SFXVEnemy::~SFXVEnemy()
{

}

void SFXVEnemy::move()
{
  if (this->curPos[1] == this->minPos[1])
    this->moveDirection = games::DOWN;
  else if (this->curPos[1] == this->maxPos[1])
    this->moveDirection = games::UP;
  this->shift(this->moveDirection);
}

void SFXVEnemy::exec(SolarFox *obj)
{
  if (rand() % 20 == 1)
    {
      if (this->direction == games::LEFT)
        obj->getPerso()->push_front(new EnemyShoot(this->getXCurPos()+1, this->getYCurPos(), games::RIGHT));
      else
        obj->getPerso()->push_front(new EnemyShoot(this->getXCurPos()-1, this->getYCurPos(), games::LEFT));
      obj->getPerso()->front()->setMinPos(0, 0);
      obj->getPerso()->front()->setMaxPos(obj->getXSize()-1, obj->getYSize()-1);
    }
  this->move();
}
