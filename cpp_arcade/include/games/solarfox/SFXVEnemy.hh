#ifndef SFXVENEMY_HH_
# define SFXVENEMY_HH_

#include "games/solarfox/SpaceObject.hh"

class SFXVEnemy: public SpaceObject
{
private:
  games::TileDirection moveDirection;

public:
  SFXVEnemy(int, int, games::TileDirection);
  ~SFXVEnemy();

  virtual void move();
  virtual void exec(SolarFox *obj);
};

#endif /* !SFXVENEMY_HH_ */
