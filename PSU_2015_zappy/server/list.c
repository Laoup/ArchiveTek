/*
** list.c for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Fri Jun 10 10:58:05 2016 Jaime Dossantos
** Last update Sun Jun 26 22:54:39 2016 Avel Docquin
*/

#include "send.h"
#include "my.h"

void		close_client(t_client **list, int fd)
{
  t_client	*ptr;

  ptr = *list;
  while (ptr != NULL && ptr->fd != fd)
    ptr = ptr->next;
  if (ptr != NULL)
    {
      close(ptr->fd);
      if (ptr->prev != NULL)
	ptr->prev->next = ptr->next;
      if (ptr->next != NULL)
	ptr->next->prev = ptr->prev;
      if (ptr->prev == NULL)
	*list = ptr->next;
      free(ptr);
    }
}

void		init_tab_fct(char *(*tab[])())
{
  tab[0] = avance;
  tab[1] = droite;
  tab[2] = gauche;
  tab[3] = voir;
  tab[4] = inventaire;
  tab[5] = prend;
  tab[6] = pose;
  tab[7] = expulse;
  tab[8] = broadcast;
  tab[9] = incantation;
  tab[10] = forking;
}

int		add_an_order(t_client *elem, const t_infos* const infos)
{
  t_order	*order;
  char		*(*tab[11])();

  if (list_size(elem->order) >= 10)
    return (0);
  init_tab_fct(tab);
  if ((order = malloc(sizeof(t_order))) == NULL)
    return (-1);
  order->next = elem->order;
  order->prev = NULL;
  if (elem->order != NULL)
    elem->order->prev = order;
  order->fct = tab[infos->order];
  order->sentence = infos->str;
  order->ressource = infos->ressource;
  gettimeofday(&order->before, 0);
  gettime_exec(order, infos);
  elem->order = order;
  return (0);
}

static int		add_order_list(t_client **list, int fd, char* buf,
				       t_param *param)
{
  socklen_t		c_length;
  ssize_t		r;
  t_client		*tmp;

  c_length = (socklen_t)sizeof(struct sockaddr_in);
  r = recvfrom(fd, buf, BUFFER, 0, (struct sockaddr*)&(*list)->sin, &c_length);
  if (r == -1 && errno == ENOMEM)
    {
      perror("client recvfrom");
      return (-1);
    }
  else if (r == -1 || r == 0)
    close_client(list, fd);
  tmp = *list;
  while (tmp != NULL && tmp->fd != fd)
    tmp = tmp->next;
  if (tmp && tmp->connected == 1)
    {
      if (parse_order(tmp, buf) == -1)
	return (-1);
    }
  else if (tmp)
    first_dial(tmp, buf, param, list);
  return (0);
}

int		manip_list(t_client **list, t_param *param, char* buf)
{
  int		i;

  i = 0;
  while (i <= param->fd_max)
    {
      if (FD_ISSET(i, &param->fd_read))
	{
	  if (i == param->fd_server)
            add_client(list, i);
	  else if (add_order_list(list, i, buf, param) == -1)
	    return (-1);
	}
      i++;
    }
  return (0);
}
