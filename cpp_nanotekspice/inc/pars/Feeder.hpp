//
// Feeder.hpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Fri Feb 19 10:18:06 2016 AceyT
// Last update Thu Feb 25 00:21:45 2016 AceyT
//

#ifndef PARS_FEEDER_HPP_
# define PARS_FEEDER_HPP_

# include <fstream>
# include "ParsDef.hpp"

class Feeder
{
public:

  Feeder(const std::string &file);
  ~Feeder() { }
  
  void	feedParser(nts::IParser &oParser);
 
private:

  //TARACEBULBA
  std::ifstream		_file;
  std::string		_filename;
};

#endif //PARS_FEEDER_HPP_
