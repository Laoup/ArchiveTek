//
// regex.cpp for autocompletion regex in /home/meuric_a/Synthese_TEK2/autocompletionV2(REGEX)/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu Jun 30 15:11:21 2016 Alban Meurice
// Last update Thu Jun 30 18:19:11 2016 Alban Meurice
//

#include "../include/myregex.hh"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MyRegex::MyRegex()
{
  this->match = -1;
  this->nmatch = 0;
  this->pmatch = NULL;
}

MyRegex::~MyRegex()
{
  /*  regfree(this->pReg);*/
}

int	MyRegex::initReg(char *reg)
{
  if (regcomp(&this->pReg, reg, REG_EXTENDED) != 0)
    return (-1);
  this->nmatch = this->pReg.re_nsub;
  if ((this->pmatch = (regmatch_t *)malloc(this->nmatch * sizeof(regmatch_t))) == NULL)
    return (-1);
  return (0);
}

int	MyRegex::searchReg(const char *str)
{
  char	*chr;

  if ((chr = strdup(str)) == NULL)
    return (-1);
  this->match = regexec(&this->pReg, chr, this->nmatch, this->pmatch, 0);
  return (this->match);
}
