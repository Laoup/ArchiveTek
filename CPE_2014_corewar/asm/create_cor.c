/*
** create_cor.c for lel in /home/moisse_r/rendu/CPE_2014_corewar/asm
**
** Made by Moisset Raphael
** Login   <moisse_r@epitech.net>
**
** Started on  Fri Mar 27 01:55:19 2015 Moisset Raphael
** Last update Sun Apr 12 20:24:22 2015 Moisset Raphael
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "asm.h"

int	create_cor(char *str)
{
  char	*name;
  int	i;
  int	fd;

  i = 0;
  if ((name = malloc(sizeof(char) * (my_strlen(str) + 5))) == NULL)
    return (my_put_error("Can't perform malloc'\n", -1));
  while (str[i] != '\0')
    {
      name[i] = str[i];
      i++;
    }
  name[i] = '.';
  name[i + 1] = 'c';
  name[i + 2] = 'o';
  name[i + 3] = 'r';
  name[i + 4] = '\0';
  if ((fd = open(name, O_WRONLY | O_CREAT, S_IRWXO | S_IRWXU | S_IRWXG)) == -1)
    return (my_put_error("Failure at .cor creation\n", -1));
  return (fd);
}

int	my_read_av(char *file, int l, int i)
{
  int	x;
  int	fd;
  char	*name;

  x = 0;
  if ((name = malloc(sizeof(char) * l)) == NULL)
    return (my_put_error("Can't perform malloc'\n", -1));
  while (file[i] != '.')
    name[x++] = file[i++];
  name[x] = '\0';
  if ((fd = create_cor(name)) == -1)
    return (my_put_error("Error : Failure on creating .cor file\n", -1));
  return (fd);
}
