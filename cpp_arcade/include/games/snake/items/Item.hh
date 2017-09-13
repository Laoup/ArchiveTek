//
// Snake.hh for arcade in /home/tarkick/repos/cpp_arcade/src/games/snake
// 
// Made by Pierre Jallut
// Login   <jallut_p@epitech.eu>
// 
// Started on  Sun Apr  3 17:48:43 2016 Pierre Jallut
// Last update Mon Apr  4 00:10:30 2016 Pierre Jallut
//

#ifndef ITEM_HH_
# define ITEM_HH_

class		Item
{

public:
  Item(int x, int y) : x(x), y(y) {} 
  ~Item() {}

  int		x;
  int		y;

  
};

#endif
