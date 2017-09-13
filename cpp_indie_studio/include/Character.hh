//
// Enemy.hh for Enemy in /home/gianne_n/Coding/tek2/indie-studio_NEW/include
// 
// Made by Nicolas Giannelos
// Login   <gianne_n@epitech.net>
// 
// Started on  Sat Jun  4 01:16:43 2016 Nicolas Giannelos
// Last update Sun Jun  5 16:58:14 2016 christophe lucas
//

#ifndef CHARACTER_HH_
# define CHARACTER_HH_

# include "irrlicht.h"
# include "OrderData.hh"
# include <vector>

# define LOS 75
# define ABS(X) (((X) >= 0) ? (X) : -(X))

class					Character
{
public:
					Character(irr::scene::IAnimatedMeshSceneNode *, CharacterType, int, int);
					~Character();
  int					getPv(void) const;
  void					setPv(int);
  irr::scene::IAnimatedMeshSceneNode	*getNode(void) const;

  static irr::u32			startTime;
  static irr::f32			deltaTime;

protected:
  irr::scene::IAnimatedMeshSceneNode	*node;
  int					pv;
  int					damage;
  CharacterType				character;
};

#endif /* !CHARACTER_HH_ */
