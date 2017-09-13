//
// addrLine.cpp for addrLine in /home/meuric_a/Synthese_TEK2/autocompletionV2(REGEX)/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu Jun 30 16:05:05 2016 Alban Meurice
// Last update Wed Jul  6 20:13:37 2016 Alban Meurice
//

#include "../include/my.hh"
#include <vector>

#include <cstring>
#include <iostream>

AddrLine::AddrLine()
{
  this->line = "";
  this->city = "";
  this->type = "";
  this->number = "";
  this->name = "";
  this->statut = false;
  this->activeChoice = false;
  this->end = false;
}

AddrLine::~AddrLine()
{
}

void					AddrLine::cityUnique(std::list<AddrLine *> &listAddrTmp)
{
  std::list<AddrLine>			select;
  std::list<AddrLine>::iterator		it2;
  std::list<AddrLine *>::iterator	it;
  int					count;

  count = 0;
  it = listAddrTmp.begin();
  while (it != listAddrTmp.end())
    {
      /*      if (this->city.compare((*it)->getCity()) == 0)
	{
	  count += 1;
	  select.push_back(*(*it));
	  }*/
      if ((*it)->getCity().find(this->city) != std::string::npos)
	{
	  count += 1;
	  select.push_back(*(*it));
	}
      it++;
    }
  if (count == 1)
    {
      /*      std::cout << "fillElem" << std::endl;*/
      this->fillElemWithElem(select.front());
      std::cout << "=> " << this->line << std::endl;
      this->end = true;
    }
  else if (count == 2)
    {
      count = 1;
      it2 = select.begin();
      while (it2 != select.end())
	{
	  if (compareChoice(select) == 0)
	    std::cout << "{" << count << " :  " << it2->getLine() << "} ";
	  else
	    std::cout << "{" << count << " :  " << it2->getCity() << "} ";
	  count += 1;
	  it2++;
	}
      std::cout << std::endl;
      this->setChoice(true);
      /*      std::cout << "Here is comming a new function for take a decision" << std::endl;*/
      /* proposer un choix */
    }
  else
    this->searchNameStreet(listAddrTmp);
}

void					AddrLine::addrUnique(std::list<AddrLine *> &listAddrTmp)
{
  std::list<AddrLine>			select;
  std::list<AddrLine>::iterator		it2;
  std::list<AddrLine *>::iterator	it;
  int					count;

  count = 0;
  it = listAddrTmp.begin();
  while (it != listAddrTmp.end())
    {
      if ((*it)->getCity().find(this->city) != std::string::npos && (*it)->getName().find(this->name) != std::string::npos)
	{
	  std::cout << "G = " << this->name << std::endl;
	  count += 1;
	  select.push_back(*(*it));
	}
      it++;
    }
  if (count == 1)
    {
      std::cout << "H" << std::endl;
      /*      std::cout << "fillElem" << std::endl;*/
      this->fillElemWithElem(select.front());
      std::cout << this->line << std::endl;
    }
  else if (count == 2)
    {
      std::cout << "I" << std::endl;
      count = 1;
      it2 = select.begin();
      while (it2 != select.end())
	{
	  std::cout << "{" << count << " :  " << it2->getLine() << "} ";
	  count += 1;
	  it2++;
	}
      std::cout << std::endl;
      this->setChoice(true);
      /*      std::cout << "Here is comming a new function for take a decision" << std::endl;*/
      /* proposer un choix */
    }
  /*  else
      this->searchNameStreet(listAddrTmp);*/
}

void					AddrLine::searchNameStreet(std::list<AddrLine *> &listAddrTmp)
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
      if (this->city.compare((*it)->getCity()) == 0)
	{
	  letter = (*it)->getBestNameStreetLetter(listAddrTmp);
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
	}
      it++;
    }
  this->printSelectionLetterName(listLetter, this->city);
}

void					AddrLine::printSelectionLetterName(std::list<t_let> &listLetter, std::string cityName)
{
  std::list<char>			select;
  std::list<t_let>::iterator		it;
  char					l;
  int					count;
  int					max;

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
	  std::cout << "{" << upperage(cityName) << ", " << select.front() << "} ";
          select.pop_front();
        }
      else
        {
          select.sort(compare_nocase);
          while (count != 5 && select.empty() == false)
            {
	      std::cout << "{" << upperage(cityName) << ", " << select.front() << "} ";
              select.pop_front();
              count += 1;
            }
        }
    }
  std::cout << std::endl;
}

void					AddrLine::fillElemWithElem(AddrLine &elem)
{
  this->line = elem.getLine();
  this->city = elem.getCity();
  this->type = elem.getType();
  this->number = elem.getNumber();
  this->name = elem.getName();
}

void					AddrLine::searchInfo(std::list<AddrLine *> &listAddrTmp)
{
  if (this->city != "")
    {
      std::cout << "A2" << std::endl;
      this->statut = true;
      this->cityUnique(listAddrTmp);
    }
}

void					AddrLine::addAllInfo(std::list<AddrLine *> listAddr)
{
  std::list<AddrLine *>::iterator	it;

  it = listAddr.begin();
  while (it != listAddr.end())
    {
      if (this->city.compare((*it)->getCity()) == 0 && (*it)->getName().find(this->name) != std::string::npos)
	{
	  this->line = (*it)->getLine();
	}
	/*this = (it); it's okay */
      it++;
    }
}

int					AddrLine::addLine(std::string str)
{
  MyRegex				reg;
  char					*exp;
  int					pos;

  exp = strdup("^[A-Za-z\\ ]+\\,\\ [0-9]{1,3}\\ [A-Za-z\\é]{1,}\\ [a-zA-Z\\ ]+");
  if (reg.initReg(exp) == -1)
    return (-1);
  if (reg.searchReg(str.c_str()) != 0)
    return (1);
  this->line = str;
  pos = 0;
  pos = this->setCity();
  pos = this->setNumber(pos);
  if ((pos = this->setType(pos)) == -1)
    return (-1);
  this->setName(pos);
  return (0);
}

int					AddrLine::setCity()
{
  int					pos;
  std::string				city;

  pos = 0;
  while (this->line[pos] != ',')
    {
      city += this->line[pos];
      pos = pos + 1;
    }
  this->city = city;
  pos += 2;
  return (pos);
}

int					AddrLine::setNumber(int pos)
{
  while (this->line[pos] != ' ')
    {
      this->number += this->line[pos];
      pos += 1;
    }
  pos += 1;
  return (pos);
}

int					AddrLine::setType(int pos)
{
  std::vector<std::string>		v;
  unsigned int				it;

  while (this->line[pos] != ' ')
    {
      this->type += this->line[pos];
      pos += 1;
    }
  pos += 1;
  v.push_back("allée");
  v.push_back("avenue");
  v.push_back("boulevard");
  v.push_back("chemin");
  v.push_back("impasse");
  v.push_back("place");
  v.push_back("quai");
  v.push_back("rue");
  v.push_back("square");
  for (it = 0; it != v.size(); it++)
    if (this->type.compare(v[it]) == 0)
      return (pos);
  return (-1);
}

int					AddrLine::setName(unsigned int pos)
{
  while (pos != this->line.size())
    {
      this->name += this->line[pos];
      pos += 1;
    }
  return (pos);  
}

void					AddrLine::setStatut(bool y)
{
  this->statut = y;
}

void					AddrLine::setChoice(bool y)
{
  this->activeChoice = y;
}

void					AddrLine::setEnd()
{
  this->end = true;
}

void					AddrLine::accuLine(std::string str)
{
  this->line += str;
}

void					AddrLine::changeLine(std::string str)
{
  this->line = str;
}

void					AddrLine::addCity(std::string str)
{
  this->city = str;
}

void					AddrLine::addName(std::string str)
{
  this->name = str;
}

std::string				AddrLine::getLine()
{
  return (this->line);
}

std::string				AddrLine::getCity()
{
  return (this->city);
}

bool					AddrLine::getStatut()
{
  return (this->statut);
}

std::list<std::pair<char, bool> >      	AddrLine::getBestCityLetter(std::list<AddrLine *> &list)
{
  std::list<std::pair<char, bool> >	listLetter;
  std::pair<char, bool>			letter;
  std::list<AddrLine *>::iterator	it;
  std::size_t				it2;
  std::size_t				it3;
  int					l;

  it2 = 0;
  while (it2 != this->city.size())
    {
      letter.first = this->city[it2];
      letter.second = false;
      l = 0;
      it = list.begin();
      while (it != list.end() && l == 0)
	{
	  if (this->line.compare((*it)->line) != 0)
	    {
	      it3 = 0;
	      while (it3 != (*it)->getCity().size() && l == 0)  
		{
		  if (this->city[it2] == (*it)->getCity()[it3])
		    l = 1;
		  if ((it3 = (*it)->getCity().find(" ", it3)) == std::string::npos)
		    it3 = (*it)->getCity().size();
		  else
		    it3++;
		}
	    }
	  it++;
	}
      if (l == 0)
	letter.second = true;
      if ((it2 = this->city.find(" ", it2)) == std::string::npos)
	it2 = this->city.size();
      else
	it2++;
      listLetter.push_back(letter);
    }
  return (listLetter);
}

std::list<std::pair<char, bool> >      	AddrLine::getBestNameStreetLetter(std::list<AddrLine *> &list)
{
  std::list<std::pair<char, bool> >	listLetter;
  std::pair<char, bool>			letter;
  std::list<AddrLine *>::iterator	it;
  std::size_t				it2;
  std::size_t				it3;
  int					l;

  it2 = 0;
  while (it2 != this->name.size())
    {
      letter.first = loweration(this->name)[it2];
      letter.second = false;
      l = 0;
      it = list.begin();
      while (it != list.end() && l == 0)
	{
	  if (this->line.compare((*it)->line) != 0 && this->city.compare((*it)->city) == 0)
	    {
	      it3 = 0;
	      while (it3 != (*it)->getName().size() && l == 0)  
		{
		  if (loweration(this->name)[it2] == loweration((*it)->getName())[it3])
		    l = 1;
		  if ((it3 = (*it)->getName().find(" ", it3)) == std::string::npos)
		    it3 = (*it)->getName().size();
		  else
		    it3++;
		}
	    }
	  it++;
	}
      if (l == 0)
	letter.second = true;
      if ((it2 = this->name.find(" ", it2)) == std::string::npos)
	it2 = this->name.size();
      else
	it2++;
      listLetter.push_back(letter);
    }
  return (listLetter);
}

std::string				AddrLine::getType()
{
  return (this->type);
}

std::string				AddrLine::getNumber()
{
  return (this->number);
}

std::string				AddrLine::getName()
{
  return (this->name);
}

bool					AddrLine::getActiveChoice()
{
  return (this->activeChoice);
}

bool					AddrLine::getEnd()
{
  return (this->end);
}

void					AddrLine::printAll()
{
  std::cout << this->line << std::endl;
  this->end = true;
}
