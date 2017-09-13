/*
** main.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Thu Jun  9 14:11:45 2016 Jaime Dossantos
** Last update Thu Jul  7 19:43:23 2016 Alban Meurice
*/

#include "my.h"
#include "map.h"

static void	free_env(t_client *list, t_param *param)
{
  int		i;
  int		ii;
  t_client	*tmp;

  while (list)
    {
      tmp = list;
      close(list->fd);
      free_orders(tmp->order);
      free_messages(tmp->send);
      list = list->next;
      free(tmp);
    }
  if (param->map)
    {
      i = -1;
      while (param->map[++i])
	{
	  ii = -1;
	  while (param->map[i][++ii])
	    free(param->map[i][ii]);
	  free(param->map[i]);
	}
      free(param->map);
    }
}

static int		create_socket(int port)
{
  int                   s;
  struct sockaddr_in    sin;

  if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    return (-1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) < 0)
    return (-1);
  if (listen(s, MAX_CLIENT) < 0)
    return (-1);
  return (s);
}

int			add_client(t_client **list, int fd_server)
{
  t_client		*elem;
  int			cs;
  socklen_t		client_sin_len;

  client_sin_len = sizeof((*list)->sin);
  if ((cs = accept(fd_server, (struct sockaddr *)&(*list)->sin, &client_sin_len)) > 0)
    {
      if ((elem = malloc(sizeof(t_client))) == NULL)
	return (-1);
      elem->order = NULL;
      elem->send = NULL;
      elem->fd = cs;
      elem->x = 0;
      elem->y = 0;
      elem->equipe = NULL;
      elem->connected = 0;
      elem->direction = 0;
      elem->next = *list;
      elem->prev = NULL;
      init_joueur(elem);
      if (*list != NULL)
	(*list)->prev = elem;
      *list = elem;
    }
  return (0);
}

int		init_param(char **arg, t_param *param)
{
  int		slot;

  if ((param->port = search(arg, "-p")) < 0)
    return (putstrr(USAGE1));
  if ((param->largeur = search(arg, "-x")) < 0)
    return (putstrr(USAGE2));
  if ((param->hauteur = search(arg, "-y")) < 0)
    return (putstrr(USAGE3));
  if ((slot = search_team(param, arg, "-n", 0)) < 0)
    return (putstrr(USAGE4));
  if ((param->nbr_client = search(arg, "-c")) < 0)
    return (putstrr(USAGE5));
  if ((param->delai = search(arg, "-t")) < 0)
    return (putstrr(USAGE6));
  param->nbr_slot = MAX_CLIENT;
  if ((param->free_slot = malloc((slot + 1) * sizeof(int))) == NULL)
    return (-1);
  if ((param->point = malloc((slot + 1) * sizeof(int))) == NULL)
    return (-1);
  param->free_slot[slot] = -1;
  param->point[slot] = -1;
  feed(&param->free_slot, param->nbr_client, slot);
  feed(&param->point, 0, slot);
  return (0);
}

int			main(int ac, char **av)
{
  t_client		*list;
  t_param		param;

  (void)ac;
  list = NULL;
  if (init_param(av, &param) < 0)
    return (-1);
  if (init_map(&param) == -1)
    return (-1);
  if ((param.fd_server = create_socket(param.port)) == -1)
    return (-1);
  if (select_manager(&list, &param) == -1)
    return (-1);
  free_env(list, &param);
  close(param.fd_server);
  return (0);
}
