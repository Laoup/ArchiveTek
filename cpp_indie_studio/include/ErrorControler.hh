//
// ErrorControler.hh for ErrorControler in /home/lucas_k/TEK2/CPP/cpp_indie_studio.VERRYIMPORTANT/indie-studio
// 
// Made by christophe lucas
// Login   <lucas_k@epitech.net>
// 
// Started on  Sun Jun  5 17:23:25 2016 christophe lucas
// Last update Sun Jun  5 17:26:30 2016 christophe lucas
//

#ifndef ERRORCONTROLER_HH_
# define ERRORCONTROLER_HH_

# include <iostream>
# include <list>
# include <string>
# include <stdlib.h>
# include <exception>

struct				ErrorFlag
{
  int				flag;
  std::string			message;
  bool				isexit;
};

struct			ErrorFunction
{
  std::string			name;
  std::list<ErrorFlag *>	flags;
};

class				ErrorControler
{
private:
  std::list<ErrorFunction *>	errors;
  ErrorFunction			*getError(const std::string &);

public:
  /* contructor and destructor */
  ErrorControler() {};
  ~ErrorControler();
  /* members functions */
  bool				addError(const std::string &, int, const std::string &, bool);
  bool				setFlagToError(const std::string &, int, const std::string &, bool);
  const char			*writeError(const std::string &, int);
};

extern ErrorControler		error;

class				Error: public std::exception
{
private:
  std::string			_name;
  int				_flag;

public:
  Error(std::string name, int flag=0) throw(): _name(name), _flag(flag) {};

  virtual const char* what() const throw()
  {
    return error.writeError(_name, _flag);
  }

  virtual ~Error() throw() {};
};

#endif /* !ERRORCONTROLER_HH_ */
