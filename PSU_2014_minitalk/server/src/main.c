/*
** main.c for Minitalk server in /home/meuric_a/Project/Minitalk/V2.0/src_serveur
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Mar 18 18:35:03 2015 Alban Meurice
** Last update Thu Mar 19 12:53:57 2015 Alban Meurice
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "my_glob.h"
#include "minitalk.h"
#include "my.h"

void		put_in_tab(char nb)
{
  char		c;
  static int	i = 7;

  g_char[i--] = nb;
  if (i == -1)
    {
      i = 0;
      c = conv_dec();
      while (i != 7)
	g_char[i++] = 0;
      g_char[i] = 0;
      my_putchar((c == '\0')? '\n' : c);
    }
}

void		catch_sigusr1(int a)
{
  (void)a;
  put_in_tab(0);
}

void		catch_sigusr2(int a)
{
  (void)a;
  put_in_tab(1);
}

int		main()
{
  if ((g_char = malloc(8 * sizeof(char))) == NULL)
    return (-1);
  my_put_nbr(getpid());
  my_putchar('\n');
  while (42)
    {
      signal(SIGUSR1, &catch_sigusr1);
      signal(SIGUSR2, &catch_sigusr2);
      pause();
    }
}
