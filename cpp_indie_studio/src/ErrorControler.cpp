//
// ErrorControler.cpp for ErrorControler in /home/aknin_k/rendu/tek2/cpp/indie/project/indie-studio/src
// 
// Made by Karine Aknin
// Login   <aknin_k@epitech.net>
// 
// Started on  Sun Jun  5 15:33:05 2016 Karine Aknin
// Last update Sun Jun  5 17:54:32 2016 christophe lucas
//

#include "ErrorControler.hh"

ErrorControler::~ErrorControler()
{
  while (!this->errors.empty())
    {
      while (!this->errors.front()->flags.empty())
	{
	  delete this->errors.front()->flags.front();
	  this->errors.front()->flags.pop_front();
	}
      delete this->errors.front();
      this->errors.pop_front();
    }
}

ErrorFunction	*ErrorControler::getError(const std::string &name)
{
  std::list<ErrorFunction *>::iterator	itr;
  
  for (itr = this->errors.begin(); itr != this->errors.end()
	 && (*itr)->name != name; itr++);
  if (itr == this->errors.end())
    return NULL;
  return (*itr);
}

bool	ErrorControler::addError(const std::string &name, int flag,
				 const std::string &message, bool isexit)
{
  if (!getError(name))
    {
      this->errors.push_front(new ErrorFunction);
      this->errors.front()->name = name;
    }
  return this->setFlagToError(name, flag, message, isexit);
}

bool	ErrorControler::setFlagToError(const std::string &name,
				       int flag,
				       const std::string
				       &message, bool isexit)
{
  std::list<ErrorFlag *>::iterator	itrFlag;
  ErrorFunction				*fctPtr;

  if ((fctPtr = getError(name)))
    {
      for (itrFlag = fctPtr->flags.begin(); itrFlag !=
	     fctPtr->flags.end()
	     && (*itrFlag)->flag != flag; itrFlag++);
      if (itrFlag == fctPtr->flags.end())
	{
	  fctPtr->flags.push_front(new ErrorFlag);
	  fctPtr->flags.front()->flag = flag;
	  fctPtr->flags.front()->message = message;
	  fctPtr->flags.front()->isexit = isexit;
	}
      else
	{
	  (*itrFlag)->flag = flag;
	  (*itrFlag)->message = message;
	  (*itrFlag)->isexit = isexit;
	}
      return true;
    }
  return false;
}

const char  *ErrorControler::writeError(const std::string &name,
					int flag)
{
  ErrorFunction				*fctPtr;
  std::list<ErrorFlag *>::iterator	itrFlag;
  std::string				*message = NULL;
  
  if ((fctPtr = getError(name)))
    {
      for (itrFlag = fctPtr->flags.begin();
	   itrFlag != fctPtr->flags.end()
	     && (*itrFlag)->flag != flag; itrFlag++);
      if (itrFlag != fctPtr->flags.end())
	{
	  message = new std::string
	    (fctPtr->name + "(" +
	     std::to_string((*itrFlag)->flag) +
	     "):" + (*itrFlag)->message);
	  return message->c_str();
	}
    }
  message = new std::string
    (name + "(" + std::to_string(flag)
     + "): unknow error !");
  return message->c_str();
}
