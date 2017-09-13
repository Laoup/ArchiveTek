/*
** conv_dec.c for Minitalk server in /home/meuric_a/Project/Minitalk/V2.0/src_serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Mar 18 22:19:10 2015 Alban Meurice
** Last update Thu Mar 19 12:54:19 2015 Alban Meurice
*/

#include "minitalk.h"
#include "my_glob.h"
#include "my.h"

char	conv_dec()
{
  char	res;
  int	i;
  int	pui;
  
  i = 0;
  pui = 1;
  res = 0;
  while (i <= 7)
    {
      pui = 1 << i;
      res = res + (pui * g_char[i]);
      i = i + 1;
    }
  return (res);
}
