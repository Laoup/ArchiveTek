#ifndef SPACESHIP_HH_
# define SPACESHIP_HH_

#include "games/solarfox/SpaceObject.hh"

class SpaceShip: public SpaceObject
{
public:
  SpaceShip(int, int, games::TileDirection);
  ~SpaceShip();

  virtual void move();
  virtual void exec(SolarFox *obj);
};

#endif /* !SPACESHIP_HH_ */
