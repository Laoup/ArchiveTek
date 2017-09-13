#ifndef OBSTACLE_HH_
# define OBSTACLE_HH_

#include "games/solarfox/SpaceObject.hh"

class Obstacle: public SpaceObject
{
public:
  Obstacle(int, int);
  ~Obstacle();

  virtual void move() {};
  virtual void exec(SolarFox *obj);
};

#endif /* !OBSTACLE_HH_ */
