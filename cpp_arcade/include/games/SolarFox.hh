#ifndef SOLARFOX_HH_
# define SOLARFOX_HH_

#include <list>
#include <vector>
#include <unistd.h>
#include "IGames.hh"
#include "Protocol.hpp"
#include "games/solarfox/SpaceObject.hh"

# define LIFE 4

class SpaceObject;

struct Tile
{
  games::TileType       t;
  games::TileDirection  d;
};

class SolarFox: public IGames
{
private:
  std::vector<Tile>         map;
  std::list<SpaceObject *>  perso;

  games::CommandType    cmd;
  IGraph                *graphic;
  int                   quit;
  int                   xSize;
  int                   ySize;
  unsigned int          life;
  unsigned int          point;

  static void go_left(void *dt);
  static void go_right(void *dt);
  static void go_up(void *dt);
  static void go_down(void *dt);
  static void fire(void *dt);
  static void quit_game(void *dt);
  static void restart_game(void *dt);

  void        writeScreen();
  void        initMap();
  void        writeMap();
  void        initTranslator();
  void        write_backend();
  void        collision();
  void        rmLooser();
  int         resistance(SpaceObject *, SpaceObject *);

public:
  /* constructor and destructor */
  SolarFox(IGraph *);
  virtual ~SolarFox();
  /* getters and setters */
  int getXSize() const {return this->xSize;};
  int getYSize() const {return this->ySize;};
  IGraph  *getIgraph() const {return this->graphic;};
  std::list<SpaceObject *> *getPerso() {return &(this->perso);};
  /* run the game */
  virtual int   run();
  /* logic game execution*/
  virtual void  move();
  /* Translator */
  virtual void  where_am_i();
  virtual void  get_map();
  virtual void  setCmd(games::CommandType cmd);

  games::CommandType  getCmd() const {return this->cmd;};
  void                creatShoot(games::TileType,games::TileDirection,int,int);

  virtual std::string getName();
};

#endif /* !SOLARFOX_HH_ */
