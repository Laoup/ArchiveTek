//
// main.cpp for autocompletion in /home/meuric_a/Synthese_TEK2/autocompletion/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu Jun 30 10:54:42 2016 Alban Meurice
// Last update Thu Jun 30 19:31:16 2016 Alban Meurice
//

#include "../include/my.hh"
#include "../include/myregex.hh"
#include "../include/addrline.hh"
#include <fstream>
#include <string.h>
#include <list>

#include <iostream>

int		main(int argc, char **argv)
{
  if (argc != 2)
    return (-1);
  autocompletion(argv[1]);
}

int		autocompletion(char *dicoName)
{
  std::list<AddrLine *>	listAddr;
  AddrLine		*curent;
  MyRegex		reg;
  std::fstream		fs;
  std::string		line;
  char			c;
  int			ret;

  fs.open(dicoName, std::fstream::in);
  if (fs.is_open())
    {
      while (fs.get(c))
	{
	  if (c == '\n' || c == '\0')
	    {
	      curent = new (AddrLine);
	      if ((ret = curent->addLine(line)) != 0)
		{
		  if (ret == 1)
		    {
		      std::cerr << line << std::endl;
		      line = "";
		    }
		  else
		    {
		      std::cout << "X" << std::endl;
		      return (-1);
		    }
		}
	      listAddr.push_back(curent);
	      line = "";
	    }
	  else
	    line += c;
	}
      while (listAddr.empty() == false)
	{
	  std::cout << listAddr.front() << std::endl;
	  listAddr.pop_front();
	}
      return (0);
    }
  return (-1);
}
