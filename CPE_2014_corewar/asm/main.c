/*
** main.c for Corewar meuric_a moisset_r asm in /home/meuric_a/Project/Corewar
**
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
**
** Started on  Wed Mar 25 22:26:47 2015 Alban Meurice
** Last update Sun Apr 12 22:10:01 2015 Moisset Raphael
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "op.h"
#include "my.h"

int		my_print_hexa(int **tabint, int fd)
{
  int		y;
  int		x;

  y = 0;
  while (tabint[y] != NULL)
    {
      x = 0;
      while (tabint[y][x] != 0)
	{
	  if ((write(fd, &tabint[y][x], sizeof(int))) == -1)
	    return (-1);
	  x++;
	}
      y++;
    }
  return (0);
}

int		my_asm(char *file)
{
  int		fd;
  int		fd_cor;
  header_t	*str;
  char		**tab;
  int		**hexa_file;

  str = NULL;
  if ((fd_cor = my_pars(file)) == -1)
    return (my_put_error("Error : The file is not a '.s'\n", -1));
  if ((fd = open(file, O_RDONLY)) == -1)
    return (my_put_error("Error : File file_name not accessible\n", -1));
  if ((tab = copy_file_in_tab(fd)) == NULL)
    return (my_put_error("Error : Failure on creating tab\n", -1));
  if ((str = my_read_s(tab, fd_cor)) == NULL)
    return (my_put_error("Error : Failure on structure\n", -1));
  if ((hexa_file = write_hex_code(tab)) == NULL)
    return (my_put_error("Error : Failure on hexa file\n", -1));
  if ((my_print_hexa(hexa_file, fd_cor)) == -1)
    return (my_put_error("Error : Failure on writing command line\n", -1));
  return (0);
}

  int	main(int argc, char **argv)
{
  if (argc == 2)
    {
      if (my_asm(argv[1]) == -1)
	return (-1);
    }
  else
    return (my_put_error("Please Give a File\n", -1));
  return (0);
}
