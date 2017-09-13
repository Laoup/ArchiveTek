/*
** misc.c for MY JETPACK in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Sat Jul  9 14:05:50 2016 Alban Meurice
** Last update Wed Jul 13 14:14:56 2016 Alban Meurice
*/

#include "../include/my.h"
#include <stdlib.h>
#include <string.h>

char	*convertNbr(int nb)
{
  char	*str;
  int	d;
  int	c;

  str = NULL;
  if (nb < 0)
    nb = nb * -1;
  if ((str = malloc(1 * sizeof(char))) == NULL)
    return (NULL);
  d = 1;
  c = 0;
  while (nb / d > 9)
    d = d * 10;
  while (d > 0)
    {
      if ((str = realloc(str, c + 2 * sizeof(char))) == NULL)
	return (NULL);
      str[c] = (nb / d) % 10 + 48;
      str[c + 1] = '\0';
      d = d / 10;
      c = c + 1;
    }
  return (str);
}

int	countLineJump(char *line)
{
  int	i;
  int	c;

  i = c = 0;
  while (line[i] != '\0')
    {
      if (line[i] == '\n')
	c = c + 1;
      i = i + 1;
    }
  return (c);
}

void	cutBuff(t_info *client, char *buff)
{
  int	i;
  int	nb;
  int	l;
  int	i2;

  i = 0;
  l = 0;
  nb = countLineJump(buff);
  while (nb != 0)
    {
      i2 = 0;
      while (buff[i] != '\n')
	{
	  client->msg[l][i2] = buff[i];
	  i = i + 1;
	  i2 = i2 + 1;
	}
      client->msg[l][i2] = '\n';
      client->msg[l][i2 + 1] = '\0';
      l = l + 1;
      nb = nb - 1;
      i = i + 1;
    }
}

char	*revStr(char *str)
{
  int	size;
  char	*nStr;
  int	i;

  size = strlen(str);
  if ((nStr = malloc(size + 1 * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (size != 0)
    {
      nStr[i] = str[size];
      size = size - 1;
      i = i + 1;
    }
  nStr[i] = '\0';
  return (nStr);
}
