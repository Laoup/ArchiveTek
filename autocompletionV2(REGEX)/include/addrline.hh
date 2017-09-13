//
// addrline.hh for addrline.hh autocompletion in /home/meuric_a/Synthese_TEK2/autocompletionV2(REGEX)/include
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu Jun 30 15:40:11 2016 Alban Meurice
// Last update Wed Jul  6 18:19:11 2016 Alban Meurice
//

#ifndef ADDRLINE_HH_
# define ADDRLINE_HH_

#include <string>
#include <list>

class	AddrLine
{
  std::string	line;
  std::string	city;
  std::string	type;
  std::string	number;
  std::string	name;

  bool		statut;
  bool		activeChoice;
  bool		end;

public:
  AddrLine();
  ~AddrLine();

  int		addLine(std::string);

  void		searchInfo(std::list<AddrLine *> &);
  void		cityUnique(std::list<AddrLine *> &);
  void		fillElemWithElem(AddrLine &);
  void		searchNameStreet(std::list<AddrLine *> &);
  void		printSelectionLetterName(std::list<struct s_letter> &, std::string);

  int		setCity();
  int		setNumber(int);
  int		setType(int);
  int		setName(unsigned int);
  void		setStatut(bool);
  void		setChoice(bool);
  void		setEnd();

  void		accuLine(std::string);
  void		changeLine(std::string);

  void		addCity(std::string);

  void		addName(std::string);

  void		addAllInfo(std::list<AddrLine *>);

  void		addrUnique(std::list<AddrLine *> &);

  std::string	getLine();
  std::string	getCity();
  std::list<std::pair<char, bool> >	getBestCityLetter(std::list<AddrLine *> &);
  std::string	getType();
  std::string	getNumber();
  std::string	getName();
  bool		getStatut();
  bool		getActiveChoice();
  bool		getEnd();
  std::list<std::pair<char, bool> >	getBestNameStreetLetter(std::list<AddrLine *> &);

  void		printAll();
};

#endif /* ADDRLINE_HH_ */
