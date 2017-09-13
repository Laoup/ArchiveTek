//
// search3.cpp for search3.cpp autoCompletion in /home/meuric_a/Synthese_TEK2/autocompletionV2(REGEX)/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Tue Jul  5 18:39:06 2016 Alban Meurice
// Last update Wed Jul  6 19:15:10 2016 Alban Meurice
//

#include "my.hh"
#include <iostream>

int						searchAdressName(std::list<AddrLine *> &listAddrTmp, AddrLine &cmd, std::string line)
{
  std::list<AddrLine *>::iterator               it;
  std::list<std::pair<std::string, int> >       select;
  std::list<std::string>                        addrName;
  std::string                                   strLower;
  std::list<std::string>::iterator		it2;
  std::pair<std::string, int>			addr;

  line = cmd.getLine() + line;
  it = listAddrTmp.begin();
  while (it != listAddrTmp.end())
    {
      if (cmd.getCity().compare((*it)->getCity()) == 0)
	{
	  addrName = cutName((*it)->getName());
	  it2 = addrName.begin();
	  while (it2 != addrName.end())
	    {
	      strLower = loweration((*it2));
	      if (strLower.find(loweration(line)) == 0)
		{
		  std::cout << "C = " << (*it2) << std::endl;
		  addr.first = (*it2);
		  addr.second = 0;
		  select.push_back(addr);
		}
	      it2++;
	    }
	}
      it++;
    }
  countOccur(select);
  /*  select = suprDouble(select);*/
  if (select.size() == 1)
    {
      std::cout << "D" << std::endl;
      cmd.addName(select.front().first);
      cmd.addAllInfo(listAddrTmp);
      cmd.printAll();
    }
  else if (select.size() == 2)
    {
      std::cout << "E" << std::endl;
      cmd.addName(select.front().first);/*not 100% okkay for that*/
      cmd.addrUnique(listAddrTmp);
      my_check();
    }
  else
    {
      std::cout << "F" << std::endl;
      cityChoice2(select, cmd);
    }
  return (0);
}

int						takeChoice(std::list<AddrLine *> &listAddrTmp, AddrLine &cmd, std::string line)
{
  std::list<AddrLine>				select;
  std::list<AddrLine>::iterator			it2;
  std::list<AddrLine *>::iterator		it;
  int						c;

  c = 0;
  if (line.compare("1") == 0)
    c = 1;
  else if (line.compare("2") == 0)
    c = 2;
  if (c == 0)
    return (-1);
  it = listAddrTmp.begin();
  std::cout << "city = " << cmd.getCity() << " nameaddr = " << cmd.getName() << " Line = " << cmd.getLine() << std::endl;
  if (cmd.getCity() != "" && cmd.getName() != "")
    {
      std::cout << "Z2" << std::endl;
      while (it != listAddrTmp.end())
	{
	  if ((*it)->getName().find(cmd.getName()) != std::string::npos)
	    {
	      c -= 1;
	      if (c == 0)
		{
		  std::cout << "=> " << (*it)->getLine() << std::endl;
		  cmd.setEnd();
		  return (0);
		}
	    }
	  it++;
	}
      /*cmd.setEnd();*/
      return (1);
    }
  else if (cmd.getCity() != "")
    {
      while (it != listAddrTmp.end())
	{
	  if ((*it)->getCity().find(cmd.getCity()) != std::string::npos)
	    {
	      c -= 1;
	      if (c == 0)
		{
		  std::cout << (*it)->getLine() << std::endl;
		  cmd.setEnd();
		  return (0);
		}
	    }
	  it++;
	}
      /*cmd.setEnd();*/
      return (0);
    }
  cmd.setEnd();
  return (-1);
}

int					compareChoice(std::list<AddrLine> list)
{
  std::list<AddrLine>::iterator		it;
  std::string				elem;
  int					c;

  it = list.begin();
  c = 0;
  while (it != list.end())
    {
      if (c == 0)
	elem = it->getCity();
      if (c == 1)
	{
	  if (elem.compare(it->getCity()) == 0)
	    return (0);
	  return (1);
	}
      c += 1;
      it++;
    }
}
