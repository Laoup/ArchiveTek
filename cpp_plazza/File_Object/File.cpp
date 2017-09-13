//
// File.cpp for Plazza in /home/meuric_a/Projet_T2_Test/Plazza/V1
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Sun Apr 17 19:19:00 2016 Alban Meurice
// Last update Mon Apr 18 18:44:46 2016 Alban Meurice
//

#include "File.hh"
#include "enum_file.hh"
#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <regex>

File::File(std::string path, Information type_search)
{
  this->path = path;
  this->type_search = type_search;
}

File::~File()
{
}

void	my_check()
{
  int	i;

  i = 0;
  while (i != 1)
    i = i + 1;
}

std::regex	File::my_regex()
{
  std::regex	reg;

  if (this->type_search == PHONE_NUMBER)
    reg = (R"(([0-9]{2} ){5})");//regex n) tel fr
  else if (this->type_search == EMAIL_ADDRESS)
    reg = (R"(^([a-zA-Z0-9]){1,}\.([a-zA-Z0-9]){1,}@([a-zA-Z0-9]){1,}\.([a-zA-Z0-9]){1,10})");//regex adresse mail
  else
    reg = (R"((^[12]([1-9]){2}\.){4}|(^[12]([1-9]){2}\.){6})");//ip (4 or 6) adresse
  return reg;
}

bool	File::parsing()
{
  std::ifstream	flux;
  std::string	line;
  std::regex	pattern;
  //  std::regex	pattern( "([0-9]{2} ){5}" );
  std::smatch	res;
  unsigned int	i;
  std::string	entry;

  flux.open(this->path.c_str());
  if (!flux)
    {
      std::cerr << "impossible d'ouvrir le fichier " << this->path << std::endl;
      return (false);
    }
  pattern = my_regex();
  while (getline(flux, line))
    {
      entry = "";
      std::regex_search(line, res, pattern);
      //if (res[1].str().length() > 0)
      //std::cout << res[1].str() << std::endl;
      for (i = 0; i < res.length(); ++i)
	entry += res[i];
      this->result.push_back(entry);
    }
  return (true);
}

std::list<std::string>	File::get_result(std::string *dest)
{
  return (this->result);
}

int	main()
{
  File	my_file("my_file.txt", PHONE_NUMBER);

  my_file.parsing();
  return (0);
}

/*bool	File::parsing()
{
  std::ifstream	flux;
  std::string	line;
  std::regex	pattern;
  //  std::regex	pattern( "([0-9]{2} ){5}" );
  std::smatch	res;

  flux.open(this->path.c_str());
  if (!flux)
    {
      std::cerr << "impossible d'ouvrir le fichier " << this->path << std::endl;
      return (false);
    }
  std::cout << "A" << std::endl;
  try
    {
      pattern = my_regex();
    }
  catch (std::regex_error& e)
    {
      
    }
  std::cout << "B" << std::endl;
  while (getline(flux, line))
    {
      std::regex_search(line, res, pattern);
      if (res[1].str().length() > 0)
	std::cout << res[1].str() << std::endl;
    }
  return (true);
}

std::list<std::string>	File::get_result(std::string *dest)
{
}*/
