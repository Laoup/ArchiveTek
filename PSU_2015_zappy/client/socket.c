/*
** socket.c for socket in /home/naji_m/rendu/PSU_2015_zappy/client
**
** Made by naji moncef
** Login   <naji_m@epitech.net>
**
** Started on  Tue Jun 21 18:09:30 2016 naji moncef
** Last update Sun Jun 26 23:19:49 2016 Avel Docquin
*/

#include "my.h"

static int sigpipe = 0;

unsigned int	my_strlen(const char* const str)
{
  unsigned int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

static void sig_handler(int sig)
{
  if (sig == SIGPIPE)
    sigpipe = 1;
}

int	write_socket(t_list *my, char *str)
{
  int len;
  int tmp;
  int r;

  signal(SIGPIPE, sig_handler);
  tmp = r = strlen(str);
  len = 0;
  r = tmp;
  while (len != r && sigpipe == 0)
    {
      r -= len;
      if ((len = write(my->env.fd, str + len, r)) == -1 && sigpipe != 1)
	{
	  perror("write socket\n");
	  return (-1);
	}
    }
  return (0);
}

int	read_socket(t_list *my)
{
  ssize_t	r;
  socklen_t	s_length;

  if (!memset(my->env.buff, 0, BUFF_SIZE))
    {
      perror("memset read\n");
      return (-1);
    }
  s_length = (socklen_t)sizeof(struct sockaddr_in);
  r = recvfrom(my->env.fd, my->env.buff, BUFF_SIZE, 0,
	       (struct sockaddr *)&my->env.s_in, &s_length);
  if (r == -1 && my->env.fd != 1 && errno == ENOMEM)
    {
      perror("read\n");
      return (-1);
    }
  if (r != 0)
    my->env.buff[r] = '\0';
  return (r);
}

unsigned int	my_compare_tab(const char tab1[], const char tab2[])
{
  unsigned int	i;

  i = 0;
  while (tab1[i] && tab2[i])
    {
      if (tab1[i] == tab2[i])
        ++i;
      else
        return (1);
    }
  if (tab1[i] || tab2[i])
    return (1);
  return (0);
}
