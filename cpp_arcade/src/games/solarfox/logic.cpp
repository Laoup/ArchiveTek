#include "games/SolarFox.hh"
#include <stdio.h>
#include <iostream>

void SolarFox::writeMap()
{
  std::list<SpaceObject *>::iterator itr;
  unsigned int i;
  int pos;

  for (i=0; i < this->map.size(); i++)
  {
    this->map[i].t = games::EMPTY;
    this->map[i].d = games::UNDEFINE;
  }
  for (itr = this->perso.begin();itr != this->perso.end(); itr++)
    {
      if ((pos = ((*itr)->getXCurPos()+(*itr)->getYCurPos()*this->xSize)) &&
          (pos < (this->xSize*this->ySize) && pos > 0))
        {
          this->map[pos].t = (*itr)->getType();
          this->map[pos].d = (*itr)->getDirection();
        }
    }
}

int SolarFox::resistance(SpaceObject *objLeft, SpaceObject *objRight)
{
  switch (objLeft->getType())
  {
    case games::SPACESHIP:
      switch (objRight->getType()) {
        case games::ENEMY_SHOOT:
          return 1; break;
        case games::OBSTACLE: return 1; break;
        case games::MY_SHOOT: return -1; break;
        case games::POWERUP: return 0; break;
        default: return -1; break;
      }
    break;

    case games::ENEMY_SHOOT:
      switch (objRight->getType()) {
        case games::ENEMY_SHOOT: return -1; break;
        case games::MY_SHOOT: return 2; break;
        case games::SPACESHIP: return 2; break;
        default: return -1; break;
      }
    break;

    case games::OBSTACLE:
      switch (objRight->getType()) {
        case games::SPACESHIP: return 0; break;
        case games::MY_SHOOT: return 0; break;
        default: return -1; break;
      } break;

    case games::MY_SHOOT:
      switch (objRight->getType()) {
        case games::ENEMY_SHOOT: return 2; this->point += 100; break;
        case games::MY_SHOOT: return -1; break;
        case games::SPACESHIP: return 1; break;
        case games::POWERUP: this->point += 500; return 0;break;
        default: return -1; break;
      } break;

    case games::POWERUP:
      if (objRight->getType() == games::SPACESHIP)
        {
          this->point += 500;
          return 1;
        } break;
    default: return -1; break;
  }
  return -1;
}

void SolarFox::collision()
{
  std::list<SpaceObject *>::iterator itrLeft;
  std::list<SpaceObject *>::iterator itrRight;

  for (itrLeft = this->perso.begin();itrLeft != this->perso.end(); itrLeft++)
    {
      for (itrRight = this->perso.begin();itrRight != this->perso.end(); itrRight++)
        {
          if ((*itrLeft)->getXCurPos() == (*itrRight)->getXCurPos() &&
              (*itrLeft)->getYCurPos() == (*itrRight)->getYCurPos() &&
              (*itrLeft) != (*itrRight))
            {
              switch (resistance((*itrLeft), (*itrRight)))
              {
                case 0:
                  (*itrRight)->setLife((*itrRight)->getLife() - 1); break;
                case 1:
                  (*itrLeft)->setLife((*itrLeft)->getLife() - 1); break;
                case 2:
                  (*itrRight)->setLife((*itrRight)->getLife() - 1);
                  (*itrLeft)->setLife((*itrLeft)->getLife() - 1); break;
                default: break;
              }
            }
        }
    }
}

void SolarFox::rmLooser()
{
  std::list<SpaceObject *>::iterator itr;

  for (itr = this->perso.begin();itr != this->perso.end(); itr++)
    {
      if ((*itr)->getType()== games::SPACESHIP)
          this->life = (*itr)->getLife();
      if ((*itr)->getLife() <= 0)
        itr = this->perso.erase(itr);
    }
}

void SolarFox::move()
{
  std::list<SpaceObject *>::iterator itr;

  for (itr = this->perso.begin();itr != this->perso.end(); itr++)
    (*itr)->exec(this);
  this->collision();
  if (this->graphic)
    for (itr = this->perso.begin();itr != this->perso.end(); itr++)
      if ((*itr)->getType()== games::MY_SHOOT)
        (*itr)->exec(this);
  this->collision();
  this->rmLooser();
  this->writeMap();
}
