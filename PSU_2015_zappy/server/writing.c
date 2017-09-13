/*
** writing.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Thu Jun 23 13:55:06 2016 Jaime Dossantos
** Last update Sun Jun 26 23:01:03 2016 Avel Docquin
*/

#include "my.h"
static int sigpipe = 0;

static void sig_handler(int sig)
{
  if (sig == SIGPIPE)
    sigpipe = 1;
}

static int	write_socket(t_client *client, char *str)
{
  int		len;
  int		tmp;
  int		r;

  signal(SIGPIPE, sig_handler);
  tmp = r = strlen(str);
  len = 0;
  r = tmp;
  while (len != r && sigpipe == 0)
    {
      r -= len;
      if ((len = write(client->fd, str + len, r)) == -1 && sigpipe != 1)
	{
	  perror("write socket\n");
	  return (-1);
	}
    }
  return (0);
}

void		free_msg(t_client *client)
{
  t_msg       *msg;

  msg = client->send;
  while (msg->next)
    msg = msg->next;
  if (msg->prev != NULL)
    msg->prev->next = msg->next;
  if (msg->msg)
    free(msg->msg);
  if (msg->prev == NULL)
    client->send = msg->next;
  free(msg);
}

void		reponse(t_client *client, t_param *param)
{
  t_msg		*msg;

  while (client)
    {
      if (client->send != NULL)
	{
	  if (FD_ISSET(client->fd, &param->fd_write))
	    {
	      msg = client->send;
	      while (msg)
		{
		  while (msg != NULL && msg->next != NULL)
		    msg = msg->next;
		  if (msg != NULL)
		    {
		      write_socket(client, msg->msg);
		      free_msg(client);
		      msg = client->send;
		    }
		}
	    }
	}
      client = client->next;
    }
}
