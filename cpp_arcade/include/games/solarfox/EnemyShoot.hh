#ifndef ENEMYSHOOT_HH_
# define ENEMYSHOOT_HH_

#include "games/solarfox/SpaceObject.hh"

class EnemyShoot: public SpaceObject
{
public:
  EnemyShoot(int, int, games::TileDirection);
  ~EnemyShoot();

  virtual void move();
  virtual void exec(SolarFox *obj);
};

#endif /* !ENEMYSHOOT_HH_ */
