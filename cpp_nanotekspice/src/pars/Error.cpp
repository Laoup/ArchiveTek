//
// Error.cpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Wed Feb 24 23:58:29 2016 AceyT
// Last update Thu Feb 25 00:17:26 2016 AceyT
//

#include "pars/Error.hpp"

err::Lexing::Lexing() noexcept :
  _msg("Error:\ncreateTree failed")
{

}

err::Lexing::Lexing(const std::string &sErrMsg) noexcept :
  _msg("Error\ncreateTree failed:\n" + sErrMsg)
{
  
}

err::Lexing::~Lexing() noexcept
{

}

const char *	err::Lexing::what() const noexcept
{
  return (this->_msg.c_str());
}


err::Parsing::Parsing() noexcept :
  _msg("Error:\nparseTree failed")
{

}

err::Parsing::Parsing(const std::string &sErrMsg) noexcept :
  _msg("Error\nparseTree failed:\n" + sErrMsg)
{
  
}

err::Parsing::~Parsing() noexcept
{

}

const char *	err::Parsing::what() const noexcept
{
  return (this->_msg.c_str());
}
