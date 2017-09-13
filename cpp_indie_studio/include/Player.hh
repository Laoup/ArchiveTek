//
// Player.hh for Player in /home/lucas_k/indie_studio/indie-studio_NEW
// 
// Made by christophe lucas
// Login   <lucas_k@epitech.net>
// 
// Started on  Sat Jun  4 16:30:06 2016 christophe lucas
// Last update Sun Jun  5 17:04:41 2016 christophe lucas
//

#ifndef PLAYER_H_
# define PLAYER_H_

# include "irrlicht.h"
# include "OrderData.hh"
# include "Character.hh"
# include "OrderControler.hh"

# define ATTACK_RANGE_DEF	10.f
# define NB_PLAYER		4

class				Enemy;

class				Player: public Character
{
public:
  Player(irr::scene::IAnimatedMeshSceneNode *, OrderControler *, CharacterType, int, int, size_t);
  Player(irr::scene::IAnimatedMeshSceneNode *, CharacterType, int, int);
  ~Player();
  
  CharacterType			getCharacterType() const;
  size_t			getScore(void) const;
  void				setScore(size_t);
  bool				getIsDead(void) const;
  void				setIsDead(bool);
  bool				attackEnemyPlayer(Enemy **);

private:
  long long			getDistance(const irr::core::vector3df &, const irr::core::vector3df &);
  bool				checkAttack(const irr::core::vector3df &);
  bool				attackPlayer(Player **);
  bool				isDead;
  size_t			score;
  size_t			id;
  OrderControler		*orderControl;
};

#endif // !PLAYER_H_
