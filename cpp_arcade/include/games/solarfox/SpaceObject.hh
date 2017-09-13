#ifndef SPACEOBJECT_HH_
# define SPACEOBJECT_HH_

#include "games/SolarFox.hh"

class SolarFox;

class SpaceObject
{
protected:
  games::TileType      type;
  games::TileDirection direction;
  int                  curPos[2];
  int                  minPos[2];
  int                  maxPos[2];
  unsigned int         life;

public:
  /* construtor and destrutor */
  SpaceObject() {};
  ~SpaceObject() {};
  /* setters */
  void setType(games::TileType type) {this->type = type;};
  void setDirection(games::TileDirection direction) {this->direction = direction;};
  void setCurPos(int x, int y);
  void setMinPos(int x, int y);
  void setMaxPos(int x, int y);
  void setLife(int life) {this->life = life;};
  /* getters */
  games::TileType getType() const {return this->type;};
  games::TileDirection getDirection() const {return this->direction;};
  int getXCurPos() const {return this->curPos[0];};
  int getYCurPos() const {return this->curPos[1];};
  int getLife() const {return this->life;};
  /* SpaceObject exec command */
  void shift(games::TileDirection);
  void toDirection(SolarFox *);
  void toCommand(SolarFox *);

  virtual void move() = 0;
  virtual void exec(SolarFox *obj) = 0;
};

#endif /* !SPACEOBJECT_HH_ */
