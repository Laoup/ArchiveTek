#include "games/solarfox/SFXHEnemy.hh"
#include "games/solarfox/EnemyShoot.hh"
#include <time.h>
#include <stdlib.h>

SFXHEnemy::SFXHEnemy(int x, int y, games::TileDirection direction)
{
  this->setDirection(direction);
  this->setCurPos(x, y);
  this->setType(games::SFX_HENEMY);
  this->setLife(100);
  this->moveDirection = games::LEFT;
  srand(time(NULL));
}

SFXHEnemy::~SFXHEnemy()
{
}

void SFXHEnemy::move()
{
    if (this->curPos[0] == this->minPos[0])
      this->moveDirection = games::RIGHT;
    else if (this->curPos[0] == this->maxPos[0])
      this->moveDirection = games::LEFT;
    this->shift(this->moveDirection);
}

void SFXHEnemy::exec(SolarFox *obj)
{
  if (rand() % 20 == 1)
    {
      if (this->direction == games::UP)
        obj->getPerso()->push_front(new EnemyShoot(this->getXCurPos(), this->getYCurPos()+1, games::DOWN));
      else
        obj->getPerso()->push_front(new EnemyShoot(this->getXCurPos(), this->getYCurPos()-1, games::UP));
      obj->getPerso()->front()->setMinPos(1, 1);
      obj->getPerso()->front()->setMaxPos(obj->getXSize()-1, obj->getYSize()-1);
    }
  this->move();
}
