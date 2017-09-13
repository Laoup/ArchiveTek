//
// Player.cpp for Player in /home/gianne_n/Coding/tek2/indie-studio_NEW
// 
// Made by Nicolas Giannelos
// Login   <gianne_n@epitech.net>
// 
// Started on  Sat Jun  4 06:10:48 2016 Nicolas Giannelos
// Last update Sun Jun  5 20:02:01 2016 Karine Aknin
//

#include "Player.hh"
#include "Character.hh"
#include "Enemy.hh"

Player::Player(irr::scene::IAnimatedMeshSceneNode *node,
	       OrderControler *control,
	       CharacterType type, int pv, int damage,
	       size_t id)
  : Character(node, type, pv, damage),
    isDead(false), score(0),
    orderControl(control), id(id)
{
}

Player::Player(irr::scene::IAnimatedMeshSceneNode *node,
	       CharacterType type, int pv, int damage)
  : Character(node, type, pv, damage),
    isDead(false), score(0), orderControl(NULL)
{
}


Player::~Player()
{
}

CharacterType Player::getCharacterType() const
{
  return (this->character);
}

size_t		Player::getScore(void) const
{
  return (this->score);
}

void		Player::setScore(size_t score)
{
  this->score += score;
}

bool		Player::getIsDead(void) const
{
  return (this->isDead);
}

void		Player::setIsDead(bool d)
{
  this->isDead = d;
}

long long	Player::getDistance(const irr::core::vector3df
				    &pos, const
				    irr::core::vector3df &target)
{
  return (pos.X - target.X) * (pos.X - target.X) +
    (pos.Z - target.Z) * (pos.Z - target.Z);
}

bool		Player::checkAttack(const irr::core::vector3df
				    &target)
{
  long long	dist;

  dist = getDistance(this->node->getPosition(), target);
  return (dist < ATTACK_RANGE_DEF * ATTACK_RANGE_DEF);
}

bool			Player::attackEnemyPlayer(Enemy **enemies)
{
  irr::core::vector3df	pos;
  UpdatePv		*update;

  pos = this->node->getPosition();
  for (size_t i = 0; i < NB_ENEMY; ++i)
    {
      if (enemies[i])
	{
	  if (checkAttack(enemies[i]->getNode()->getPosition()))
	    {
	      this->node->setMD2Animation(irr::scene::EMAT_ATTACK);
	      enemies[i]->setPv(this->damage);
	      if (!enemies[i]->getPv())
		{
		  update = new UpdatePv(i, this->id, this->damage);
		  orderControl->
		    sendOrder(NewOrder(this->id, PROTOCOLE::CommandType::UPDATE_PV,
				       sizeof(UpdatePv), update));
		  this->score += 42;
		}
	      return (true);
	    }
	  else
	    this->node->setMD2Animation(irr::scene::EMAT_STAND);
	}
    }
  return (true);
}
