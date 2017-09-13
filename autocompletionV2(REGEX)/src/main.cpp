//
// main.cpp for autocompletion in /home/meuric_a/Synthese_TEK2/autocompletion/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu Jun 30 10:54:42 2016 Alban Meurice
// Last update Wed Jul  6 19:47:16 2016 Alban Meurice
//

#include "../include/my.hh"
#include "../include/myregex.hh"
#include <fstream>
#include <iostream>

int				main(int argc, char **argv)
{
  if (argc != 2)
    return (-1);
  return (autocompletion(argv[1]));
}

int				autocompletion(char *dicoName)
{
  std::list<AddrLine *>		listAddr;
  std::list<AddrLine *>		listAddrTmp;
  /*std::list<std::string>	cmd;*/
  AddrLine			cmd;
  std::string			line;
  int				l;

  if (openFile(dicoName, listAddr) != 0)
    return (-1);
  listAddrTmp = listAddr;
  line = "";
  searchPossibility(listAddrTmp, cmd, line);
  l = 0;
  while (l == 0 && cmd.getEnd() == false)
    {
      std::cin >> line;
      l = searchPossibility(listAddrTmp, cmd, line);
    }
  std::cout << line << std::endl;
  return (0);
}

int				openFile(char *dicoName, std::list<AddrLine *> &listAddr)
{
  AddrLine			*curent;
  MyRegex			reg;
  std::fstream			fs;
  std::string			line;
  int				ret;
  
  fs.open(dicoName, std::fstream::in);
  if (fs.is_open())
    {
      while (getline(fs, line))
	{
	  curent = new (AddrLine);
	  if ((ret = curent->addLine(line)) != 0)
	    {
	      if (ret == 1)
		std::cerr << line << std::endl;
	      else
		return (-1);
	      line = "";
	    }
	  else
	    {
	      listAddr.push_back(curent);
	      line = "";
	    }
	}
    }
  fs.close();
  return (0);
  /*while (listAddr.empty() == false)
    {
    curent = listAddr.front();
    std::cout << curent->getName() << std::endl;
    listAddr.pop_front();
    }*/
}
