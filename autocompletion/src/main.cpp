//
// main.cpp for autocompletion in /home/meuric_a/Synthese_TEK2/autocompletion/src
// 
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
// 
// Started on  Thu Jun 30 10:54:42 2016 Alban Meurice
// Last update Thu Jun 30 11:30:35 2016 Alban Meurice
//

#include "my.hh"
#include "dico.hh"
#include <string.h>

int		main(int argc, char **argv)
{
  if (argc != 2)
    return (-1);
  autocompletion(argv[1]);
}

int		autocompletion(char *dicoName)
{
  std::string	dico;

  dico = openDico(dicoName);
  
}
