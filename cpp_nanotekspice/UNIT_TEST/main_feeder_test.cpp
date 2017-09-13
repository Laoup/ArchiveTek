//
// main_feeder_test.cpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Fri Feb 19 13:16:03 2016 AceyT
// Last update Tue Feb 23 12:34:47 2016 AceyT
//

#include <iostream>
#include <string>
#include <stdexcept>
#include "pars/Feeder.hpp"

struct			PT : nts::IParser
{
			PT() : _stream("") { }
  virtual		~PT() { }
  virtual void		feed(const std::string & input)
  {
    _stream += input;
  }
  virtual void		parseTree(nts::Node &)
  {
    //NOT THE PURPOSE HERE
    std::cout << "DEBUG: CONTENT OF STREAM" << std::endl;
    std::cout << _stream << std::endl;
    _stream = "";
  }
  virtual nts::Node *	createTree()
  {
    //NOT THE PURPOSE HERE
    return (0);
  }

  std::string	_stream;
};

int	main(void)
{
  Feeder	first("../files/and.nts");
  Feeder	second("../files");
  Feeder	third("/etc/sudoers");

  nts::Node	osef(new std::vector<nts::Node *>);

  nts::IParser *	tester = new PT();
  
  first.feedParser(*tester);
  tester->parseTree(osef);
  try
    {
      second.feedParser(*tester);
    }
  catch (std::logic_error &e)
    {
      std::cout << "ERROR" << std::endl;
      std::cout << e.what() << std::endl;
    }
  tester->parseTree(osef);
  try
    {
      third.feedParser(*tester);
    }
  catch (std::exception &e)
    {
      std::cout << "ERROR" << std::endl;
      std::cout << e.what() << std::endl;
    }
  tester->parseTree(osef);

  return(0);

}
