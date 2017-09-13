//
// addrgest.cpp for autocompletion in /home/meuric_a/Synthese_TEK2/autocompletionV2(REGEX)/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Fri Jul  1 11:49:21 2016 Alban Meurice
// Last update Fri Jul  1 12:19:50 2016 Alban Meurice
//

#include "../include/my.hh"

int					delBadAddr(std::list<AddrLine *> &listAddrTmp, std::string line)
{
  std::list<AddrLine *>::iterator	it;

  /*sizeLine = line.length();
  delSizeAddr(listAddrTmp, sizeLine);*/
  it = listAddrTmp.begin();
  while (it != listAddrTmp.end())
    {
      if (it.find(line) == std::string::npos)
	listAddrTmp.erase(it);
      else
	it++;
    }
}



/*int					delSizeAddr(std::list<AddrLine *> &listAddrTmp, int sizeLine)
{
  std::list<AddrLine *>::iterator	it;

  it = listAddrTmp.begin();
  while (it != listAddrTmp.end())
    {
      if (it->line.length() < sizeLine)
	
      it++;
    }
    }*/
