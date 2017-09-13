//
// main_treecreator_test.cpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Thu Feb 25 03:00:53 2016 AceyT
// Last update Sat Feb 27 03:29:58 2016 AceyT
//

#include <string>
#include <iostream>

#include "pars/Feeder.hpp"
#include "pars/Parser.hpp"
#include "pars/TreeCreator.hpp"
#include "pars/Error.hpp"

void	affTab(int iMax)
{
  for (int i = 0 ; i < iMax ; ++i)
    std::cout << "---";
}

void	displayChild(nts::Node *pNode)
{
  static int	cnt = 0;

  if (pNode != nullptr)
    {
      ++cnt;
      if (pNode->type == nts::ASTNodeType::DEFAULT)
	std::cout << "ROOT [";
      else if (pNode->type == nts::ASTNodeType::SECTION)
	std::cout << "SECTION [";
      else if (pNode->type == nts::ASTNodeType::COMPONENT)
	std::cout << "COMPONENT ID [" << pNode->value << "] & TYPE [";  
      else if (pNode->type == nts::ASTNodeType::LINK)
	std::cout << "LINK pin ["<< pNode->value << "] & ID [";
      else if (pNode->type == nts::ASTNodeType::LINK_END)
	std::cout << "with LINK pin [" << pNode->value << "] & ID [";
      else
	std::cout << "UNKNOWN [";
      std::cout << pNode->lexeme << "]";
      if (pNode->children != nullptr)
	{
	  std::cout << "> Children :";
	  std::vector<nts::Node *>::iterator	it, end;
	  end = pNode->children->end();
	  for (it = pNode->children->begin() ; it != end ; ++it)
	    {
	      std::cout << std::endl;
	      affTab(cnt);
	      displayChild(*it);
	    }
	  std::cout << std::endl;
	}
      --cnt;
    }
}

int	main(void)
{
  Feeder		file("../files/ccho.nts");
  Parser		pars;
  nts::Node *		pResult;
  nts::IParser *	pPars;

  try
    {
      pPars = &pars;
      file.feedParser(*pPars);  
      pResult = pars.createTree();
      if (pResult != nullptr)
	{
	  displayChild(pResult);
	  Parser::FreeNode(pResult);
	}
    }
  catch(std::logic_error &e)
    {
      std::cerr << "An error with the file has been caught:" << std::endl;
      std::cerr << e.what() << std::endl;
    }
  catch(err::Lexing &e)
    {
      std::cerr << "An Error in createTree occured while parsing :" << std::endl;
      std::cerr << e.what() << std::endl;
    }
  catch(std::exception &e)
    {
      std::cerr << "An unexpected error has occured :" << std::endl;
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
