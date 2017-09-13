//
// File.hh for plazza in /home/meuric_a/Projet_T2_Test/Plazza/V1
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Sun Apr 17 19:19:04 2016 Alban Meurice
// Last update Mon Apr 18 16:41:14 2016 Alban Meurice
//

#ifndef FILE_HH_
# define FILE_HH_

#include <string>
#include <list>
#include <iostream>
#include <regex>
#include "enum_file.hh"

class	File
{
  std::string	path;
  Information	type_search;

  std::list<std::string>	result;

public:
  File(std::string path, Information type_search);
  ~File();

  std::regex	my_regex();

  bool          parsing();
  std::list<std::string>       	get_result(std::string *dest);
};

#endif /* FILE_HH_ */
