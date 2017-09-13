//
// TreeCreator.cpp
// 
// Made by AceyT
// Login   <aceyt@epitech.net>
// 
// Started on  Thu Feb 25 02:50:01 2016 AceyT
// Last update Sat Feb 27 03:35:46 2016 AceyT
//

#include "pars/TreeCreator.hpp"
#include "pars/Error.hpp"
#include "pars/Parser.hpp"
#include "tls/StringTLS.hpp"
#include <cctype>
/*
**
** TreeCreator
**
*/


std::string	TreeCreator::Num(std::string::const_iterator &cit)
{
  if ( isdigit(*cit) )
    {
      std::string::const_iterator	cit_end = cit;
      while ( isdigit(*cit_end) )
	++cit_end;
      std::string			sResult(cit, cit_end);
      cit = cit_end;
      return sResult;
    }
  return "";
}

std::string	TreeCreator::String(std::string::const_iterator &cit)
{
  if ( isalnum(*cit) || (*cit) == '_' )
    {
      std::string::const_iterator	cit_end = cit;
      while ( isalnum(*cit_end) || (*cit_end) == '_' )
	++cit_end;
      std::string			sResult(cit, cit_end);
      cit = cit_end;
      return sResult;
    }
  return "";
}

void		TreeCreator::Separator(std::string::const_iterator &cit)
{
    while ( (*cit) == ' ' || (*cit) == '\t')
      ++cit;
}

void		TreeCreator::Comment(std::string::const_iterator &cit)
{
  TreeCreator::Separator(cit);
  if ( (*cit) == '#')
    while ( (*cit) != '\n' )
      ++cit;
}

void		TreeCreator::EndLine(std::string::const_iterator &cit)
{
  TreeCreator::Comment(cit);
  if ( (*cit) == '\n')
    ++cit;
}

nts::Node *    	TreeCreator::Component(std::string::const_iterator &cit)
{
  std::string::const_iterator	check, backup = cit;
  
  std::string	lex = TreeCreator::String(cit);
  TreeCreator::Separator(cit);
  std::string	value = TreeCreator::String(cit);
  do
    {
      check = cit;
      TreeCreator::EndLine(cit);
    }while (check != cit);
  if ( !lex.empty() && !value.empty() )
    {
      nts::Node *	       	pComponent = new nts::Node(nullptr);
      pComponent->lexeme = lex;
      pComponent->value = value;
      pComponent->type = nts::ASTNodeType::COMPONENT;
      return pComponent;
    }
  else
    {
      cit = backup;
      return nullptr;
    }
}

nts::Node *		TreeCreator::ChipsetSection(std::string::const_iterator &cit)
{
  nts::Node *		pChipsetSection = new nts::Node( new std::vector<nts::Node *>() );

  std::string		lex = TreeCreator::String(cit);
  if ( lex.empty() )
    {
      Parser::FreeNode(pChipsetSection);
      throw err::Lexing("Expected chipsets section\nNo string found instead");
    }
  else if (lex != "chipsets")
    {
      Parser::FreeNode(pChipsetSection);
      throw err::Lexing("Expected chipsets section\n[" + std::string(lex + "] found instead"));
    }
  pChipsetSection->type = nts::ASTNodeType::SECTION;
  pChipsetSection->lexeme = lex;
  if ( (*cit) == ':')
    {
      ++cit;
      std::string::const_iterator	check = cit;
      TreeCreator::EndLine(cit);
      if (check == cit)
	{
	  Parser::FreeNode(pChipsetSection);
	  throw err::Lexing("No termination after chipsets section defined\n");
	}
      do
	{
	  check = cit;
	  TreeCreator::EndLine(cit);
	}while (check != cit);
      nts::Node *	pChild;
      while ( (pChild = TreeCreator::Component(cit)) != nullptr )
	pChipsetSection->children->push_back(pChild);
      return pChipsetSection;
    }
  else
    {
      Parser::FreeNode(pChipsetSection);
      throw err::Lexing("Invalid end token for chipsets section\nExpected[:], got [" + std::string(*cit +"] instead"));
    }
}

nts::Node *    			TreeCreator::Link(std::string::const_iterator &cit)
{
  std::string::const_iterator	check, backup = cit;

  std::string			lex_l1 = TreeCreator::String(cit);
  if ( (*cit) != ':' )
    {
      cit = backup;
      return nullptr;
    }
  ++cit;
  std::string			val_l1 = TreeCreator::Num(cit);
  TreeCreator::Separator(cit);
  std::string			lex_l2 = TreeCreator::String(cit);
  if ( (*cit) != ':' )
    {
      cit = backup;
      return nullptr;
    }
  ++cit;
  std::string			val_l2 = TreeCreator::Num(cit);
  do
    {
      check = cit;
      TreeCreator::EndLine(cit);
    }while (check != cit);
  if ( !lex_l1.empty() && !val_l1.empty() && !lex_l2.empty() && !val_l2.empty() )
    {
      nts::Node *		pLink = new nts::Node( new std::vector<nts::Node *>() );
      nts::Node *		pLink_end = new nts::Node(nullptr);

      pLink->type = nts::ASTNodeType::LINK;
      pLink->lexeme = lex_l1;
      pLink->value = val_l1;
      pLink_end->type = nts::ASTNodeType::LINK_END;
      pLink_end->lexeme = lex_l2;
      pLink_end->value = val_l2;
      pLink->children->push_back(pLink_end);
      return pLink;
    }
  else
    {
      cit = backup;
      return nullptr;
    }
}

nts::Node *    	TreeCreator::LinkSection(std::string::const_iterator &cit)
{
  nts::Node *	pLinkSection = new nts::Node( new std::vector<nts::Node *>() );

  std::string		lex = TreeCreator::String(cit);
  if ( lex.empty() )
    {
      Parser::FreeNode(pLinkSection);
      throw err::Lexing("Expected links section\nNo string found instead");
    }
  else if (lex != "links")
    {
      Parser::FreeNode(pLinkSection);
      throw err::Lexing("Expected links section\n[" + std::string(lex + "] found instead"));
    }
  pLinkSection->type = nts::ASTNodeType::SECTION;
  pLinkSection->lexeme = lex;
  if ( (*cit) == ':' )
    {
      ++cit;
      std::string::const_iterator	check = cit;
      TreeCreator::EndLine(cit);
      if (check == cit)
	{
	  Parser::FreeNode(pLinkSection);
	  throw err::Lexing("No termination after links section defined\n");
	}
      do
	{
	  check = cit;
	  TreeCreator::EndLine(cit);
	}while (check != cit);
      nts::Node *	pChild;
      while ( (pChild = TreeCreator::Link(cit)) != nullptr)
	pLinkSection->children->push_back(pChild);
      return pLinkSection;
    }
  else
    {
      Parser::FreeNode(pLinkSection);
      throw err::Lexing("Invalid end token for links section\nExpected[:], got [" +std::string(*cit +"] instead"));
    }
}



void		TreeCreator::EvalStream(nts::Node * pRoot, const std::string & sStream)
{
  std::string::const_iterator	cit, check;

  cit = sStream.cbegin();
  check = cit;
  while ( (*cit) != '.')
    {
      std::string::const_iterator	check = cit;
      TreeCreator::EndLine(cit);
      if ( cit == check)
	throw err::Lexing("No chipsets section found");
      else
	check = cit;
    }
  ++cit;
  pRoot->children->push_back(TreeCreator::ChipsetSection(cit));
  while ( (*cit) != '.' )
    {
      std::string::const_iterator	check = cit;
      TreeCreator::EndLine(cit);
      if ( cit == check)
	throw err::Lexing("No links section found");
      else
	check = cit;
    }
  ++cit;
  pRoot->children->push_back(TreeCreator::LinkSection(cit));
}
