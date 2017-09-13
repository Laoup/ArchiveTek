//
// search.cpp for autocompletio n in /home/meuric_a/Synthese_TEK2/autocompletionV2(REGEX)/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Fri Jul  1 12:47:07 2016 Alban Meurice
// Last update Wed Jul  6 18:43:06 2016 Alban Meurice
//

#include "../include/my.hh"
#include "../include/addrline.hh"
#include <utility>
#include <iostream>

int					searchPossibility(std::list<AddrLine *> &listAddrTmp, AddrLine &cmd, std::string line)
{
  if (cmd.getLine() == "" && line== "")
    moreFrequence(listAddrTmp);
  else if (line.compare("ABORT\0") == 0)
    {
      cmd.setEnd();
      return (0);
    }
  else if (cmd.getActiveChoice() == true)
    {
      return (takeChoice(listAddrTmp, cmd, line));
    }
  else if (cmd.getCity() == "")
    {
      std::cout << "A" << std::endl;
      searchCity(listAddrTmp, cmd, line);
    }
  else if (cmd.getCity() != "" && cmd.getName() == "")
    {
      std::cout << "B = " << cmd.getCity() <<std::endl;
      if (cmd.getStatut() == true)
	{
	  cmd.setStatut(false);
	  cmd.changeLine("");
	}
      searchAdressName(listAddrTmp, cmd, line);
    }
  return (0);
}

int					moreFrequence(std::list<AddrLine *> &listAddrTmp)
{
  std::list<AddrLine *>::iterator	it;
  std::list<t_let>::iterator		it2;
  std::list<t_let>			listLetter;
  t_let					tup;
  std::list<std::pair<char, bool> >	letter;
  int					k;

  it = listAddrTmp.begin();
  while (it != listAddrTmp.end())
    {
      letter = (*it)->getBestCityLetter(listAddrTmp);
      while (letter.empty() == false)
	{
	  k = 0;
	  it2 = listLetter.begin();
	  while (it2 != listLetter.end() && k == 0)
	    {
	      if (it2->letter == letter.front().first)
		{
		  k = 1;
		  it2->nb += 1;
		}
	      it2++;
	    }
	  if (k == 0)
	    {
	      tup.letter = letter.front().first;
	      tup.nb = 1;
	      tup.unique = letter.front().second;
	      listLetter.push_back(tup);
	    }
	  letter.pop_front();
	}
      it++;
    }

  fiveLetters(listLetter);
  return (0);
}

int				searchMax(std::list<t_let> &listLetter)
{
  std::list<t_let>::iterator	it;
  int				max;

  max = 0;
  it = listLetter.begin();
  while (it != listLetter.end())
    {
      if (it->nb > max)
	max = it->nb;
      it++;
    }
  return (max);
}

bool				compare_nocase(char &a, char &b)
{
  return (a < b);
}

void				fiveLetters(std::list<t_let> &listLetter)
{
  std::list<char>		select;
  std::list<t_let>::iterator	it;
  char				l;
  int				count;
  int				max;

  count = max = 0;
  it = listLetter.begin();
  while (it != listLetter.end())
    {
      if (it->letter >= 'A' && it->letter <= 'Z')
	it->letter += 32;
      it++;
    }
  while (count != 5 && listLetter.empty() == false)
    {
      max = searchMax(listLetter);
      it = listLetter.begin();
      while (it != listLetter.end())
	{
	  if (it->nb == max)
	    {
	      l = it->letter;
	      select.push_back(l);
	      it = listLetter.erase(it);
	    }
	  else
	    it++;
	}
      if (select.size() == 1)
	{
	  count += 1;
	  std::cout << "{" << select.front() << "} ";
	  select.pop_front();
	}
      else
	{
	  select.sort(compare_nocase);
	  while (count != 5 && select.empty() == false)
	    {
	      std::cout << "{" << select.front() << "} ";
	      select.pop_front();
	      count += 1;
	    }
	}
    }
  std::cout << std::endl;
}
