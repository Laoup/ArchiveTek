/*
** my_ls.c for Project My_ls in /home/meuric_a/Project/My_ls
** 
** Made by alban mourice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Nov 25 13:50:57 2014 alban meurice
** Last update Sat Nov 29 04:13:08 2014 alban meurice
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include "my_ls_save6.h"

int	count_ls(DIR *dirp, struct dirent *entry, char *str)
{
  int	x;

  x = 0;
  dirp = opendir(str);
  while ((entry = readdir(dirp)) != NULL)
    {
      if (entry->d_name[0] != '.')
	x = x + 1;
    }
  return (x);
}

char	aff_name(DIR *dirp, struct dirent *entry, int x)
{
  int	y;

  while (x > 0)
    {
      if (x >= 3)
	y = 3;
      else
	y = x;
      while (x >= 0 && y != 0)
	{
	  if ((entry = readdir(dirp)) != NULL)
	    {
	      if (entry->d_name[0] != '.')
		{
		  my_printf("%s   ", entry->d_name);
		  x--;
		  y--;
		}
	    }
	}
      my_putchar('\n');
    }
}

char		my_ls(char *str)
{
  DIR		*dirp;
  struct dirent	*entry;
  char		*name;
  int		x;

  dirp = opendir(str);
  x = count_ls(dirp, entry, str);
  aff_name(dirp, entry, x);
}

int	main(int argc, char **argv)
{
  int	a;
  int	count;
  
  a = 1;
  if (argc == 1)
    my_ls("./");
  if (argc > 1)
    {
      while (a != argc)
	{
	  if (argv[a][0] != '-')
	    my_ls(argv[a]);
	  a++;
	}
    }
}
