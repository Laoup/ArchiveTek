/*
** fill_struct.c for corewar in /home/guzman_y/test_corewar/srcs
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Tue Mar 31 16:35:42 2015 yoann guzman
** Last update Sat Apr  4 18:43:34 2015 yoann guzman
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "corewar.h"

int		fill_my_struct_player(int ac, char **av, header_t *tab)
{
  int		fd;
  int		i;
  int		j;

  j = 0;
  i = 1;
  while (ac - 1 > 0)
    {
      if ((fd = open(av[i], O_RDONLY)) == -1)
	return (my_put_error("Open fail", -1));
      if ((read(fd, &tab[j], sizeof(header_t))) != sizeof(header_t))
	return (my_put_error("Bad file", -1));
      tab[j].magic = convert_int(tab[j].magic);
      tab[j].prog_size = convert_int(tab[j].prog_size);
      if (close(fd) == -1)
	return (my_put_error("Close fail", -1));
      i++;
      j++;
      ac--;
    }
  j++;
  return (0);
}
