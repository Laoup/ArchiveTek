//
// dico.cpp for autocompletion in /home/meuric_a/Synthese_TEK2/autocompletion/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu Jun 30 11:25:30 2016 Alban Meurice
// Last update Thu Jun 30 12:44:55 2016 Alban Meurice
//

#include "dico.hh"
#include <fstream>

Dico::Dico()
{
  this->ready = 0;
}

Dico::~Dico()
{
}

int	Dico::addDataBase(char *dicoName)
{
  std::fstream	fs;
  std::string	line;
  char		c;

  fs.open(dicoName, std::fstream::in);
  if (fs.is_open)
    {
      while (fs.get(c))
	{
	  if (c == '\n')
	    {
	      line += '\0';
	      if (this->checkAddrLine(line) == -1)
		return (-1);
	    }
	  else
	    line += c;
	}
    }
  return (-1);
}

int	Dico::checkAddrLine(std::string &addr)
{
  std::string::iterator	it;
  int			l;

  if (addr.empty() == 0)
    return (-1);
  it = addr.begin();
  if (*it < 'A' || *it > 'z')
    return (-1);
  while (*it != ',')
    {
      if (it == addr.end())
	return (-1);
      it++;
    }
  while (*it < '0' || *it > '9')
    {
      if (it == addr.end())
	return (-1);
      it++;
    }
  l = -1;
  while (it != addr.end())
    {
      if (*it >= 'A' || *it <= 'z')
	l = 0;
      it++;
    }
  return (l);
}
