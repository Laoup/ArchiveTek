//
// Enemy.cpp for Enemy in /home/gianne_n/Coding/tek2/indie-studio_NEW
// 
// Made by Nicolas Giannelos
// Login   <gianne_n@epitech.net>
// 
// Started on  Sat Jun  4 01:52:51 2016 Nicolas Giannelos
// Last update Sun Jun  5 22:19:28 2016 christophe lucas
//

#include <iostream>
#include "Character.hh"
#include "Enemy.hh"
#include "Player.hh"

Enemy::Enemy(irr::scene::IAnimatedMeshSceneNode *node,
	     CharacterType type, int pv , int damage)
  : Character(node, type, pv, damage), los(LOS)
{
}

Enemy::~Enemy()
{
}

long long	Enemy::getDistance(const irr::core::vector3df &pos,
				   const irr::core::vector3df &target)
{
  return (pos.X - target.X) * (pos.X - target.X) + (pos.Z - target.Z) * (pos.Z - target.Z);
}

bool	Enemy::attackPlayer(Player *player)
{
  if (getDistance(player->getNode()->getPosition(),
		  node->getPosition()) < ENEMY_ATTACK_RANGE * ENEMY_ATTACK_RANGE)
    {
      player->setPv(this->damage);
      return (true);
    }
  return (false);
}

void	Enemy::Ai(Player **players)
{
  
  if(!pv)
    {
      this->node->setMD2Animation(irr::scene::EMAT_CROUCH_DEATH);
    }
  else
    { 
      for (size_t i = 0; i < 4; ++i)
	{
	  if (!players[i] || players[i]->getIsDead())
	    continue;
	  if (checkAttack(players[i]->getNode()->getPosition()))
	    {
	      move(players[i]->getNode()->getPosition());
	      if (attackPlayer(players[i]))
		return;
	    }
	  else
	    this->node->setMD2Animation(irr::scene::EMAT_STAND);
	}
    }
}

bool		Enemy::checkAttack(const irr::core::vector3df &target)
{
  long long	dist;

  dist = getDistance(this->node->getPosition(), target);
  return (dist < (this->los * this->los));
}

void			Enemy::move(const irr::core::vector3df &target)
{
  irr::core::vector3df	position;
  irr::core::vector3df	rotation;

  position = this->node->getPosition();
  if (ABS(target.Z - position.Z) > ABS(target.X - position.X))
    {
      if (target.Z > position.Z)
	{
	  position.Z += ENEMY_MOVEMENT_SPEED_DEF *
	    Character::deltaTime;	  
	  rotation.Y = 270;
	}
      else
	{
	  position.Z -= ENEMY_MOVEMENT_SPEED_DEF *
	    Character::deltaTime;
	  rotation.Y = 90;
	}
    }
  else
    {
      if (target.X > position.X)
	{
	  position.X += ENEMY_MOVEMENT_SPEED_DEF *
	    Character::deltaTime;
	  rotation.Y = 0;
	}
      else
	{
	  position.X -= ENEMY_MOVEMENT_SPEED_DEF *
	    Character::deltaTime;
	  rotation.Y = 180;
	}
    }
  this->node->setPosition(position);
  this->node->setRotation(rotation);
  this->node->setMD2Animation(irr::scene::EMAT_RUN);
}
