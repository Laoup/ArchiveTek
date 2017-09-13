//
// Parser.cpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Fri Feb 19 04:34:43 2016 AceyT
// Last update Thu Feb 25 19:54:59 2016 AceyT
//

#include "pars/Parser.hpp"
#include "pars/TreeCreator.hpp"
#include "pars/Error.hpp"
#include <iostream>

/*
**
** Parser
**
*/


Parser::Parser() :
  _stream("")
{

}

Parser::~Parser()
{

}

void	Parser::feed(const std::string & input)
{
  this->_stream += input;
}

void	Parser::parseTree(nts::Node &root)
{
  (void)root;
  //EXECUTE TREE
}

nts::Node *	Parser::createTree()
{
  nts::Node *		pRoot = new nts::Node(new std::vector<nts::Node *>());
  
  pRoot->type = nts::ASTNodeType::DEFAULT;
  pRoot->lexeme = "ROOT";
  try
    {
      TreeCreator::EvalStream(pRoot, this->_stream);
    }
  catch(err::Lexing &e)
    {
      std::cerr << e.what() << std::endl;
      Parser::FreeNode(pRoot);
      pRoot = nullptr;
    }
  return pRoot;
}

void	Parser::FreeNode(nts::Node *pNode)
{
  if ( pNode != nullptr )
    {
      if ( pNode->children != nullptr )
	{
	  std::vector<nts::Node *>::iterator	it;
	  for ( it = pNode->children->begin() ; it != pNode->children->end() ; ++it)
	    if ( (*it) != nullptr )
	      Parser::FreeNode(*it);
	  delete pNode->children;
	}
      delete pNode;
    }
}
