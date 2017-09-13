#ifndef SPACESHIPSHOOT_HH_
# define SPACESHIPSHOOT_HH_

#include "games/solarfox/SpaceObject.hh"

class SpaceShipShoot: public SpaceObject
{
public:
  SpaceShipShoot(int, int, games::TileDirection);
  ~SpaceShipShoot();

  virtual void move();
  virtual void exec(SolarFox *obj);
};

#endif /* !SPACESHIPSHOOT_HH_ */
