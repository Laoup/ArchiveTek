/*
** select.c for zappy in /home/docqui_a/PSU_2015_zappy/server/
**
** Made by Avel Docquin
** Login   <docqui_a@epitech.net>
**
** Started on  Mon Jun 20 22:36:14 2016 Avel Docquin
** Last update Sun Jun 26 23:29:29 2016 Avel Docquin
*/

#include "my.h"

static int	end = 0;

int		init_fd(t_client *list, t_param *param)
{
  int		ret;

  param->tv.tv_sec = 0;
  param->tv.tv_usec = 1000;
  ret = param->fd_server;
  FD_ZERO(&param->fd_read);
  FD_ZERO(&param->fd_write);
  FD_SET(param->fd_server, &param->fd_read);
  while (list != NULL)
    {
      FD_SET(list->fd, &param->fd_read);
      if (list->send != NULL)
	FD_SET(list->fd, &param->fd_write);
      if (list->fd > ret)
        ret = list->fd;
      list = list->next;
    }
  return (ret);
}

static void	sig_handler(int sig)
{
  if (sig == SIGINT)
    end = 1;
}

int	check_winner(t_param *param)
{
  int	i;
  int	win;

  win = 1;
  i = 0;
  while (param->point[i] != -1)
    {
      if (param->point[i] >= 6)
	{
	  write(1, "Six players of Team ", my_strlen("Six players of Team "));
	  write(1, param->equipe[i], my_strlen(param->equipe[i]));
	  write(1, " as reached the ", my_strlen(" as reached the "));
	  write(1, "eight'th level\n", my_strlen("eight'th level\n"));
	  win = 0;
	}
      i++;
    }
  return (win);
}

int	select_manager(t_client **list, t_param *param)
{
  char	buf[BUFFER];

  signal(SIGINT, sig_handler);
  while (end != 1 && check_winner(param) != 0)
    {
      if (!memset(buf, 0, BUFFER))
	return (-1);
      param->fd_max = init_fd(*list, param);
      if (select(param->fd_max + 1, &param->fd_read, &param->fd_write, NULL, &param->tv) == -1)
	{
	  if (errno == EINTR)
	    break;
	  else
	    break;
	}
      if (manip_list(list, param, buf) < 0)
	break;
      if (execute(list, param) < 0)
	break;
      reponse(*list, param);
    }
  return (0);
}
