/*
** convert.c for lel in /home/moisse_r/rendu/CPE_2014_corewar/asm
**
** Made by Moisset Raphael
** Login   <moisse_r@epitech.net>
**
** Started on  Mon Apr  6 22:18:17 2015 Moisset Raphael
** Last update Sun Apr 12 20:19:23 2015 Moisset Raphael
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "asm.h"

int		transform_magic_number()
{
  header_t	*stt;

  if ((stt = malloc(sizeof(header_t))) == NULL)
    return (my_put_error("Can't perform malloc\n", -1));
  stt->magic = COREWAR_EXEC_MAGIC;
  stt->magic = convert_int(stt->magic);
  return (stt->magic);
}

int		my_taille()
{
  header_t	*size;
  int		nb;

  nb = 989;
  if ((size = malloc(sizeof(header_t))) == NULL)
    return (my_put_error("Can't perform malloc\n", -1));
  size->prog_size = nb;
  size->prog_size = convert_int(size->prog_size);
  return (size->prog_size);
}

int	convert_int(int nbr)
{
  int	convert_nbr;
  int	b;
  int	c;
  int	d;

  convert_nbr = 0;
  b = nbr << 8;
  c = nbr >> 8;
  d = nbr << 24;
  b = b & 16711680;
  c = c & 65280;
  d = d & 4278190080;
  convert_nbr = convert_nbr ^ b;
  convert_nbr = convert_nbr ^ c;
  convert_nbr = convert_nbr ^ d;
  return (convert_nbr);
}
