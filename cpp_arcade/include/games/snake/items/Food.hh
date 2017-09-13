//
// Snake.hh for arcade in /home/tarkick/repos/cpp_arcade/src/games/snake
// 
// Made by Pierre Jallut
// Login   <jallut_p@epitech.eu>
// 
// Started on  Sun Apr  3 17:48:43 2016 Pierre Jallut
// Last update Sun Apr  3 22:04:59 2016 Pierre Jallut
//

#ifndef FOOD_HH_
# define FOOD_HH_

class		Food : public Item
{

private:
  bool		isAte;
  
public:
  Food(int x, int y) : Item(x, y), isAte(false) {}
  ~Food() {}

  bool		getIsAte() { return isAte; }
  void		setIsAte(bool isAte) { this->isAte = isAte; }
  
};

#endif
