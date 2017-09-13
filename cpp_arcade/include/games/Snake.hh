//
// Snake.hh for arcade in /home/tarkick/repos/cpp_arcade/src/games/snake
// 
// Made by Pierre Jallut
// Login   <jallut_p@epitech.eu>
// 
// Started on  Sun Apr  3 17:48:43 2016 Pierre Jallut
// Last update Sun Apr  3 23:34:07 2016 Pierre Jallut
//

#ifndef SNAKE_HH_
# define SNAKE_HH_

# include <vector>
# include "games/snake/items/Body.hh"
# include "games/snake/items/Food.hh"
# include "games/IGames.hh"

struct Tile
{
  games::TileType       t;
  games::TileDirection  d;
};

class			Snake : public IGames
{

private:
  std::vector<Tile>     map;
  int			speed;
  int			endGame;
  int			xSize;
  int			ySize;
  games::CommandType	cmd;
  IGraph		*lib;
  Food			*food;
  Body			*snakesHead;
  std::vector<Body *>	snakesBody;
  
public:
  Snake(IGraph *graphicLib);
  ~Snake();

  //SETTERS
  virtual void			setCmd(games::CommandType cmd) { this->cmd = cmd; }

  //Snake ops
  void			createFood();
  void			eatFood();
  
  // IGames methods
  /* run the game */
  virtual int		run();
  /* logic game execution*/
  virtual void		move();
  /* Translator */
  virtual void		where_am_i();
  virtual void		get_map();
  void			initTranslator();
  void			writeScreen();
  void			writeMap();
  void			initMap();
  
  /* Misc */
  virtual std::string	getName() { return ""; }

};

#endif
