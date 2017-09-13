/*
** connection.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Fri Jun 24 13:16:46 2016 Jaime Dossantos
** Last update Fri Jun 24 17:51:38 2016 Jaime Dossantos
*/

#include "my.h"

void	check_team(t_client *client, char *buff, t_param *param)
{
  int	i;

  i = 0;
  while (buff[i] != ' ' && buff[i] != '\n' && buff[i])
    i++;
  buff[i] = '\0';
  i = 0;
  while (param->equipe[i] != NULL)
    {
      if (strcmp(param->equipe[i], buff) == 0)
	client->equipe = param->equipe[i];
      i++;
    }
}

char	*getnbrslot(int nbr, char *str)
{
  int	div;
  int	i;

  div = 1;
  while (nbr / div > 9)
    div = div * 10;
  i = 0;
  while (div > 0)
    {
      str[i] = nbr / div;
      nbr = nbr - (str[i] * div);
      str[i] = str[i] + 48;
      div = div / 10;
      i++;
    }
  str[i] = '\n';
  str[i + 1] = '\0';
  return (str);
}

void	send_x_y(t_param *param, char **x, char **y, t_client *client)
{
  char	*msg;
  int	i;

  *x = getnbrslot(param->largeur, *x);
  *y = getnbrslot(param->hauteur, *y);
  i = 0;
  while ((*x)[i] != '\n' && (*x)[i] != '\0')
    i++;
  (*x)[i] = ' ';
  if ((msg = malloc(strlen(*x) + strlen(*y) + 2)) != NULL)
    {
      my_strcat(*x, *y, &msg);
      free(*x);
      free(*y);
      new_msg(client, msg);
      client->connected = 1;
    }
}

void	feedmy(char **x, char **y, t_param *param, t_client *client)
{
  int	i;

  i = 0;
  while (i < 15)
    {
      (*x)[i] = 0;
      (*y)[i] = 0;
      i++;
    }
  send_x_y(param, x, y, client);
}

void	hello_or_gb(t_param *param, char *equipe, t_client **list
		    , t_client *client)
{
  int	i;
  char	*slot;
  char	*x;
  char	*y;

  i = -1;
  while (param->equipe[++i])
    {
      if (my_strcmp(equipe, param->equipe[i]) == 0 && param->free_slot[i] > 0)
	{
	  if ((slot = malloc(10)) != NULL && ((x = malloc(15)) != NULL)
	      && ((y = malloc(15)) != NULL))
	    {
	      slot = getnbrslot(param->free_slot[i], slot);
	      new_msg(client, slot);
	      feedmy(&x, &y, param, client);
	      param->free_slot[i]--;
	    }
	}
      else if (my_strcmp(equipe, param->equipe[i]) == 0)
	{
	  close_client(list, client->fd);
	  break;
	}
    }
}
