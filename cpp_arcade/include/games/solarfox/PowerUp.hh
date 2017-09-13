#ifndef POWERUP_HH_
# define POWERUP_HH_

#include "games/solarfox/SpaceObject.hh"

class PowerUp: public SpaceObject
{
public:
  PowerUp(int, int);
  ~PowerUp();

  virtual void move() {};
  virtual void exec(SolarFox *obj);
};

#endif /* !POWERUP_HH_ */
