/*
** my.h for  in /home/dossan_a/rendu/PSU_2015_zappy/server
**
** Made by Jaime Dossantos
** Login   <dossan_a@epitech.net>
**
** Started on  Thu Jun  9 15:12:12 2016 Jaime Dossantos
** Last update Sun Jun 26 22:58:39 2016 Avel Docquin
*/

#ifndef MY_H_
# define MY_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "parser/str_to_tab.h"

# define FD_FREE 0
# define FD_CLIENT 1
# define MAX_CLIENT 42
# define BUFFER 4096
# define USAGE1 "Usage : -p numero de port -x -y -n -c -t\n"
# define USAGE2 "Usage : -p -x largeur du Monde -y -n -c -t\n"
# define USAGE3 "Usage : -p -x -y hauteur du Monde -n -c -t\n"
# define USAGE4 "Usage : -p -x -y -n nom_de_equipe_1 nom_de_equipe_2.. -c -t\n"
# define USAGE5 "Usage : -p -x -y -n -c clients par équipe au départ -t\n"
# define USAGE6 "Usage : -p -x -y -n -c -t delai d'execution des actions\n"

typedef struct		s_order
{
  char *		(*fct)();
  char			*sentence;
  int			ressource;
  long			milliseconds;
  long			exec;
  struct timeval	before;
  struct s_order	*next;
  struct s_order	*prev;
}			t_order;

typedef struct		s_msg
{
  char			*msg;
  struct s_msg		*next;
  struct s_msg		*prev;
}			t_msg;

typedef struct		s_infos
{
  int			order;
  char*			str;
  int			ressource;
}			t_infos;

typedef struct		s_client
{
  struct sockaddr_in	sin;
  int			fd;
  int			connected;
  char			*equipe;
  t_order		*order;
  t_msg			*send;
  int			x;
  int			y;
  int			direction;
  int			lvl;
  int			inventaire[7];

  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef struct	s_param
{
  int			port;
  int			largeur;
  int			hauteur;
  char			**equipe;
  int			*free_slot;
  int			nbr_client;
  int			*point;
  long			delai;

  struct timeval	tv;
  int			fd_server;
  int			fd_max;
  fd_set		fd_read;
  fd_set		fd_write;
  int			nbr_slot;
  int			***map;
}			t_param;

int	parse_order(t_client* const elem, char* buf);
int	select_manager(t_client **list, t_param *param);
int	init_fd(t_client *list, t_param *param);
int	manip_list(t_client **, t_param *, char* buf);
int	search(char **, char *);
int	search_team(t_param *, char **, char *, int);
int	putstrr(char *);
int	add_client(t_client **, int);
int	first_dial(t_client *, char *, t_param *, t_client **);
int	new_msg(t_client *, char *);
int	add_an_order(t_client*, const t_infos* const);
int	list_size(t_order *);
int	my_strcmp(char *, char *);
int	execute(t_client **list, t_param *param);
int	it_time(t_order *order, t_param *param);
void	feed(int **, int, int);
void	my_strcat(char *, char *, char **);
void	free_orders(t_order *);
void	free_messages(t_msg *);
void	reponse(t_client *, t_param *);
void	init_joueur(t_client *);
void	check_team(t_client *, char *, t_param *);
void	hello_or_gb(t_param *, char *, t_client **, t_client *);
void	close_client(t_client **, int);
void    gettime_exec(t_order *, t_infos const *);

#endif /* !MY_H_ */
