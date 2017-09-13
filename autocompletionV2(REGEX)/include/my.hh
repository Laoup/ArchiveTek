//
// my.hh for my.hh in /home/meuric_a/Synthese_TEK2/autocompletion/include
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu Jun 30 10:53:20 2016 Alban Meurice
// Last update Wed Jul  6 19:02:17 2016 Alban Meurice
//

#ifndef MY_HH_
# define MY_HH_

#include "addrline.hh"
#include "myregex.hh"
#include <list>
#include <string>
#include <utility>

typedef struct	s_letter
{
  char		letter;
  int		nb;
  bool		unique;
}		t_let;

void	my_check();

int	autocompletion(char *);
int	openFile(char *, std::list<AddrLine *> &);

int	searchPossibility(std::list<AddrLine *> &, AddrLine &, std::string);
int	moreFrequence(std::list<AddrLine *> &);
bool	compare_nocase(char &, char &);
void	fiveLetters(std::list<t_let> &);
int	searchMax(std::list<t_let> &);

int				searchCity(std::list<AddrLine *> &, AddrLine &, std::string);
std::pair<std::string, int>	convertList(std::list<std::string> &);
std::list<std::pair<std::string, int> >	suprDouble(std::list<std::pair<std::string, int> >);
std::string			loweration(std::string);
std::string			upperage(std::string);
void				countOccur(std::list<std::pair<std::string, int> > &);
std::list<std::string>		cutName(std::string);
void				cityChoice(std::list<std::pair<std::string, int> >, AddrLine &);
void				cityChoice2(std::list<std::pair<std::string, int> >, AddrLine &);

int				searchAdressName(std::list<AddrLine *> &, AddrLine &, std::string);

int				compareChoice(std::list<AddrLine>);
int				takeChoice(std::list<AddrLine *> &, AddrLine &, std::string);

int	delBadAddr(std::list<AddrLine *> &, std::string);
/*int	delSizeAddr(std::list<AddrLine *> &, int);*/

#endif /* MY_HH_ */
