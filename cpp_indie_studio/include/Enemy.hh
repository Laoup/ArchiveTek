//
// Enemy.hh for Enemy in /home/lucas_k/indie_studio/indie-studio_NEW
// 
// Made by christophe lucas
// Login   <lucas_k@epitech.net>
// 
// Started on  Sat Jun  4 16:28:21 2016 christophe lucas
// Last update Sun Jun  5 23:23:26 2016 Karine Aknin
//

#ifndef ENEMY_H_
# define ENEMY_H_ 

# include "irrlicht.h"
# include "OrderData.hh"
# include "Character.hh"

# define ENEMY_MOVEMENT_SPEED_DEF	250.f
# define ENEMY_ATTACK_RANGE		7
# define NB_ENEMY			30

class					Player;

class					Enemy : public Character
{
public:
					Enemy(irr::scene::IAnimatedMeshSceneNode *, CharacterType, int, int);
					~Enemy();
  void					Ai(Player **);

private:
  long long				getDistance(const irr::core::vector3df &, const irr::core::vector3df &);
  bool					checkAttack(const irr::core::vector3df &);
  void					move(const irr::core::vector3df &);
  bool					attackPlayer(Player *);

  int					los;
};

#endif // !ENEMY_H_
