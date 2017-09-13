/*
** File containe Games interface
*/
#ifndef IGAMES_HH_
# define IGAMES_HH_

#include <string>
#include "Arcade.hh"
#include "graphic/IGraph.hh"
#include "Translator.hh"

class IGames: public Translator
{
public:
  virtual ~IGames() {};
  virtual void  move() = 0;
  virtual int   run() = 0;
  virtual std::string getName() = 0;
};

extern "C" IGames *creatGame(IGraph *);

#endif /* !IGAMES_HH_ */
