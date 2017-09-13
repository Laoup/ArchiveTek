//
// format.cpp for autocompletion in /home/meuric_a/Synthese_TEK2/autocompletionV2(REGEX)/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Mon Jul  4 10:46:15 2016 Alban Meurice
// Last update Wed Jul  6 19:02:23 2016 Alban Meurice
//

#include "../include/my.hh"
#include <locale>

std::string			loweration(std::string str)
{
  std::string			newStr;
  std::locale			loc;
  std::string::size_type	i;

  i = 0;
  while (i != str.length())
    {
      newStr += tolower(str[i], loc);
      i++;
    }
  return (newStr);
}

std::string			upperage(std::string str)
{
  std::string			newStr;
  std::locale			loc;
  std::string::size_type	i;

  i = 0;
  while (i != str.length())
    {
      newStr += toupper(str[i], loc);
      i++;
    }
  return (newStr);
}

