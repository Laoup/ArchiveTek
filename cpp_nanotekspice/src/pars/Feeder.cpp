//
// Feeder.cpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Fri Feb 19 10:24:53 2016 AceyT
// Last update Sat Feb 27 03:31:00 2016 AceyT
//

#include "pars/Feeder.hpp"

#include <stdexcept>
#include <iostream>

Feeder::Feeder(const std::string &file) :
  _file(file.c_str()),
  _filename(file)
{

}

void	Feeder::feedParser(nts::IParser &oParser)
{
  if ( this->_file.is_open() && this->_file.good() && this->_file.eof() != true )
    {
      std::string	sLine;
      while ( std::getline(this->_file, sLine) )
	{
	  if ( !sLine.empty() )
	    {
	      sLine += "\n";
	      oParser.feed(sLine);
	    }
	}
    }
  else if ( this->_file.is_open() == false )
    throw std::logic_error("File [\"" + _filename + "\"] not open");
  else
    throw std::runtime_error("File [\"" + _filename + "\"] encouter a problem while opening");
}
