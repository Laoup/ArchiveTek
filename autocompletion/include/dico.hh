//
// dico.hh for autocompletion in /home/meuric_a/Synthese_TEK2/autocompletion/include
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu Jun 30 11:29:41 2016 Alban Meurice
// Last update Thu Jun 30 12:37:45 2016 Alban Meurice
//

#ifndef DICO_HH_
# define DICO_HH_

#include "my.hh"
#include <string>
#include <list>
#include <utility>

class								Dico
{
  /*  std::list<std::pair<std::string, std::list<std::string>>>	dataBase;*/
  std::list<std::pair<std::string, std::list<std::pair<std::string, std::list<std::string>>>>	dataBase;
  int								ready;

  int	checkAddrLine(std::string &);

public:
  Dico();
  ~Dico();

  int	addDataBase(char *);
};

#endif /* DICO_HH_ */
