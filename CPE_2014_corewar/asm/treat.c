/*
** treat.c for lel in /home/moisse_r/rendu/CPE_2014_corewar/asm
**
** Made by Moisset Raphael
** Login   <moisse_r@epitech.net>
**
** Started on  Sun Mar 29 23:27:58 2015 Moisset Raphael
** Last update Sun Apr 12 21:55:20 2015 Moisset Raphael
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

char		*my_read_comment(char *buff)
{
  int		x;
  int		i;
  header_t	*str;

  x = 0;
  i = 0;
  if ((str = malloc(sizeof(header_t))) == NULL)
    return (my_put_error_null("Can't perform malloc\n"));
  while (buff[x] != '"')
    x++;
  x++;
  while (buff[x] != '"')
    str->comment[i++] = buff[x++];
  str->comment[i] = '\0';
  return (str->comment);
}

char		*my_read_name(char *buff)
{
  int		x;
  int		i;
  header_t	*str;

  x = 0;
  i = 0;
  if ((str = malloc(sizeof(header_t))) == NULL)
    return (my_put_error_null("Can't perform malloc\n"));
  while (buff[x] != '"')
    x++;
  x++;
  while (buff[x] != '"')
    str->prog_name[i++] = buff[x++];
  str->prog_name[i] = '\0';
  return (str->prog_name);
}

header_t	*my_read_s(char **tab, int fd)
{
  int		x;
  int		y;
  header_t	*struc;

  x = 0;
  y = 0;
  if ((struc = malloc(sizeof(header_t))) == NULL)
    return (my_put_error_null("Can't perform malloc\n"));
  if ((struc->magic = transform_magic_number()) == -1)
    return (NULL);
  while (tab[y][x] != ' ')
    x++;
  if ((my_strncmp(tab[y], NAME_CMD_STRING, x)) == -1)
    return (NULL);
  my_strcpy(&(struc->prog_name[0]), my_read_name(tab[y]));
  if ((struc->prog_size = my_taille()) == -1)
    return (NULL);
  x = 0;
  while (tab[y + 1][x] != ' ')
    x++;
  if ((my_strncmp(tab[y + 1], COMMENT_CMD_STRING, x)) == -1)
    return (NULL);
  my_strcpy(&(struc->comment[0]), my_read_comment(tab[y + 1]));
  if ((write(fd, struc, sizeof(header_t))) == -1)
    return (NULL);
  return (struc);
}
