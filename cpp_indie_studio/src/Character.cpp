//
// Character.cpp for Character in /home/gianne_n/Coding/tek2/indie-studio_NEW
// 
// Made by Nicolas Giannelos
// Login   <gianne_n@epitech.net>
// 
// Started on  Sat Jun  4 01:41:15 2016 Nicolas Giannelos
// Last update Sun Jun  5 15:22:24 2016 Karine Aknin
//

#include <iostream>
#include "Character.hh"

irr::f32 Character::deltaTime;
irr::u32 Character::startTime;

Character::Character(irr::scene::IAnimatedMeshSceneNode *node,
		     CharacterType type, int pv, int damage)
  : node(node), character(type), pv(pv), damage(damage)
{
}

Character::~Character()
{
}

int		Character::getPv(void) const
{
  return (this->pv);
}

void		Character::setPv(int damage)
{
  this->pv = ((this->pv - damage) < 0) ? (0) : (this->pv - damage);
}

irr::scene::IAnimatedMeshSceneNode	*Character::getNode() const
{
  return (this->node);
}
