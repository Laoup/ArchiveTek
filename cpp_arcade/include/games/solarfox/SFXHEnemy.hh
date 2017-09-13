#ifndef SFXHENEMY_HH_
# define SFXHENEMY_HH_

#include "games/solarfox/SpaceObject.hh"

class SFXHEnemy: public SpaceObject
{
private:
  games::TileDirection moveDirection;

public:
  SFXHEnemy(int, int, games::TileDirection);
  ~SFXHEnemy();

  virtual void move();
  virtual void exec(SolarFox *obj);
};

#endif /* !SFXHENEMY_HH_ */
