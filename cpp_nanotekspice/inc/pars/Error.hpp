//
// Error.hpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Wed Feb 24 23:01:43 2016 AceyT
// Last update Thu Feb 25 00:05:27 2016 AceyT
//

#ifndef PARS_ERROR_HPP_
# define PARS_ERROR_HPP_

# include <stdexcept>
# include <exception>
# include <string>

namespace err
{
  class	Lexing : public std::exception
  {
    
  public:

    Lexing() noexcept;
    Lexing(const std::string &sErrMsg) noexcept;
    virtual ~Lexing() noexcept;
    virtual const char * what() const noexcept; 

  private:

    std::string _msg;
  };

  class Parsing : public std::exception
  {
  public:

    Parsing() noexcept;
    Parsing(const std::string &sErrMsg) noexcept;
    virtual ~Parsing() noexcept;
    virtual const char * what() const noexcept; 

  private:
    std::string _msg;

  };
}

#endif//PARS_ERROR_HPP_
