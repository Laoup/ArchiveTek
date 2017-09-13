//
// Snake.hh for arcade in /home/tarkick/repos/cpp_arcade/src/games/snake
// 
// Made by Pierre Jallut
// Login   <jallut_p@epitech.eu>
// 
// Started on  Sun Apr  3 17:48:43 2016 Pierre Jallut
// Last update Sun Apr  3 20:45:52 2016 Pierre Jallut
//

#ifndef BODY_HH_
# define BODY_HH_

# include "games/snake/items/Item.hh"

class		Body : public Item
{

public:
  Body(int x, int y) : Item(x, y) {}
  ~Body() {};
  
  //Movements
  static void	go_left(void *);
  static void	go_down(void *);
  static void	go_right(void *);
  static void	go_up(void *);
    
};

#endif
