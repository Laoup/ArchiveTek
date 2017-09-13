//
// Parser.hpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Fri Feb 19 04:38:44 2016 AceyT
// Last update Thu Feb 25 02:49:40 2016 AceyT
//

#ifndef PARS_PARSER_HPP_
# define PARS_PARSER_HPP_

# include "ParsDef.hpp"

class Parser : public nts::IParser
{

public:
  Parser();
  virtual ~Parser();

  virtual void		feed(const std::string & input);
  virtual void		parseTree(nts::Node & root);
  virtual nts::Node *	createTree();

  static void		FreeNode(nts::Node *root);

private:
  
  std::string		_stream;
};

#endif //PARS_PARSER_HPP_
