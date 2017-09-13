//
// main_error_test.cpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Thu Feb 25 00:04:50 2016 AceyT
// Last update Thu Feb 25 00:16:14 2016 AceyT
//

#include <iostream>
#include "pars/Error.hpp"

int	main(void)
{

  try
    {
      throw err::Lexing("INVALID TOKEN");
    }
  catch(err::Lexing &e)
    {
      std::cout << "Exception caught :" << std::endl;
      std::cout << e.what() << std::endl;
    }

  try
    {
      throw err::Parsing("INVALID DATA");
    }
  catch(err::Parsing &e)
    {
      std::cout << "Exception caught :" << std::endl;
      std::cout << e.what() << std::endl;
    }

  try
    {
      throw err::Lexing();
    }
  catch(std::exception &e)
    {
      std::cout << "Exception caught :" << std::endl;
      std::cout << e.what() << std::endl;
    }

  try
    {
      throw err::Parsing();
    }
  catch(std::exception &e)
    {
      std::cout << "Exception caught :" << std::endl;
      std::cout << e.what() << std::endl;
    }

  std::cout << "ALL EXCEPTION CAUGHT" << std::endl;
  return(0);
}
