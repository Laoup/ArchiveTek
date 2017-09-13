//
// regex.hh for autocompletion in /home/meuric_a/Synthese_TEK2/autocompletionV2(REGEX)/include
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu Jun 30 15:04:15 2016 Alban Meurice
// Last update Thu Jun 30 16:16:37 2016 Alban Meurice
//

#ifndef MYREGEX_HH_
# define MYREGEX_HH_

#include <regex.h>
#include <stdlib.h>

class		MyRegex
{
  regex_t	pReg;
  int		match;

  size_t	nmatch;
  regmatch_t	*pmatch;

public:
  MyRegex();
  ~MyRegex();

  int	initReg(char *);
  int	searchReg(const char *);
};

#endif /* MYREGEX_HH_ */
