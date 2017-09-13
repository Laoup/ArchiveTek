#include "games/solarfox/EnemyShoot.hh"

EnemyShoot::EnemyShoot(int x, int y, games::TileDirection direction)
{
  this->setDirection(direction);
  this->setCurPos(x, y);
  this->setType(games::ENEMY_SHOOT);
  this->setLife(1);
}

EnemyShoot::~EnemyShoot()
{
}

void EnemyShoot::move()
{
  this->shift(this->direction);
  if ((this->curPos[0] <= this->minPos[0]) ||
      (this->curPos[1] <= this->minPos[1]) ||
      (this->curPos[0] >= this->maxPos[0]) ||
      (this->curPos[1] >= this->maxPos[1]))
    this->life -= 1;
}

void EnemyShoot::exec(SolarFox *obj)
{
  obj = obj;
  this->move();
}
