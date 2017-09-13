/*
** File containe Game type for comunication to graphic library
*/
#ifndef ARCADE_HH_
# define ARCADE_HH_

namespace games
{
  enum CommandType
  {
    PLIB,
    NLIB,
    PGAME,
    NGAME,
    RGAME,
    MENU,
    QUIT,
    PAUSE,
    PLAY,
    GO_UP,
    GO_DOWN,
    GO_LEFT,
    GO_RIGHT,
    GO_FORWARD,
    SHOOT,
    ILLEGAL,
    CTSIZE,
  };

  /* SOLAR FOX == SFX */
  /* SNAKE == SNK */
  enum TileType
  {
    /* MAP */
    EMPTY,
    SPACESHIP,
    POWERUP,
    OBSTACLE,
    /* SOLAR FOX == SFX */
    SFX_HENEMY,
    SFX_VENEMY,
    /* SHOOT */
    ENEMY_SHOOT,
    MY_SHOOT,
    EXPLODE,
    /* SNAKE == SNK */
    SNK_HEAD,
    SNK_BODY,
    SNK_TAIL,
    SNK_FOOD,
    /* map border */
    CORNER,
    BORDER,
    OTHER,
    TTSIZE
  };

  enum TileDirection
  {
    UNDEFINE = 0,
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
  };
}

#endif /* ARCADE_HH_ */
