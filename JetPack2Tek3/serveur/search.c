/*
** search.c for My JetPack in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Jul  7 19:50:25 2016 Alban Meurice
** Last update Wed Jul 13 22:05:06 2016 Alban Meurice
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

int	search(char **args, char *flag)
{
  int	i;

  i = 0;
  while (args[i])
    {
      if (args[i][0] == '-' && args[i][1] == flag[1])
	if (args[i + 1] != NULL)
	  if (args[i + 1][0] != '-')
	    return (atoi(args[i + 1]));
      i = i + 1;
    }
  return (-1);
}

char	*fileMap(char **args, char *flag)
{
  char	*file;
  int	i;
  int	nbr;

  i = 0;
  /*  file = NULL; IF USE THAT 26 LINES !! DESTRUCT THIS LINE IF YOU DON'T NEED IT*/
  while (args[i] != NULL)
    {
      if (args[i][0] == '-' && args[i][1] == flag[1] && args[i + 1] != NULL)
	{
	  nbr = 1;
	  while (args[i + 1] != NULL && args[i + 1][nbr])
	    nbr = nbr + 1;
	  if ((file = malloc((nbr + 1) * sizeof(char))) == NULL)
	    return (NULL);
	  nbr = 0;
	  while (args[i + 1][nbr])
	    {
	      file[nbr] = args[i + 1][nbr];
	      nbr = nbr + 1;
	    }
	  file[nbr] = '\0';
	}
      i = i + 1;
    }
  return (file);
}

int	getMap(char *file, char **map)
{
  FILE	*fd;
  char	c;
  int	size;
  int	i;

  /*  map = NULL;*/
  if ((fd = fopen(file, "r")) == NULL)
    return (-1);
  size = i = 0;
  while (fgetc(fd) != EOF)
    size = size + 1;
  fclose(fd);
  if (size == 0)
    return (-1);
  if (((*map) = malloc((size + 1) * sizeof(char))) == NULL)
    return (-1);
  if ((fd = fopen(file, "r")) == NULL)
    return (-1);
  while (size != 0)
    {
      c = (char)fgetc(fd);
      (*map)[i] = c;
      i = i + 1;
      size = size - 1;
    }
  (*map)[i] = '\0';
  return (0);
}

int	infoMap(char *map, t_param *param)
{
  int	sizeCurrentLine;
  int	i;

  param->largeur = param->hauteur = i = 0;
  while (map[i] != '\0')
    {
      sizeCurrentLine = 0;
      while (map[i] != '\0' && map[i] != '\n')
	{
	  if (map[i] != '_' && map[i] != 'c' && map[i] != 'e')
	    return (-1);
	  sizeCurrentLine = sizeCurrentLine + 1;
	  i = i + 1;
	}
      if (param->largeur == 0)
	param->largeur = sizeCurrentLine;
      else if (param->largeur != sizeCurrentLine)
	return (-1);
      param->hauteur = param->hauteur + 1;
      if (map[i] != '\0')
	i = i + 1;
    }
  return (0);
}

char	*readMap(char *map, int largeur, int hauteur)
{
  char	*newMap;
  int	i;
  int	i2;

  i = i2 = 0;
  while (map[i] != '\0')
    {
      if (map[i] != '\n')
	i2 = i2 + 1;
      i = i + 1;
    }
  printf("Size is %d && L * l = %d\n", i2, (hauteur * largeur));
  if ((newMap = malloc((hauteur * largeur + 3) * sizeof(char))) == NULL)
    return (NULL);
  i = i2 = 0;
  while (map[i] != '\0')
    {
      if (map[i] != '\n')
	{
	  newMap[i2] = map[i];
	  i2 = i2 + 1;
	}
      i = i + 1;
    }
  newMap[i2] = '\0';
  return (newMap);
}
