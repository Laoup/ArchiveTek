/*
** ressources_0.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Fri Jun 24 17:30:51 2016 Jaime Dossantos
** Last update Fri Jun 24 17:50:22 2016 Jaime Dossantos
*/

#include "my.h"

void		my_strcat(char *str1, char *str2, char **ret)
{
  int		i;
  int		ii;

  i = 0;
  while (str1[i])
    {
      (*ret)[i] = str1[i];
      i++;
    }
  ii = 0;
  while (str2[ii])
    {
      (*ret)[i + ii] = str2[ii];
      ii++;
    }
  (*ret)[i + ii] = '\0';
}

int		my_strcmp(char *str, char *strb)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != strb[i])
	return (-1);
      i++;
    }
  return (0);
}
