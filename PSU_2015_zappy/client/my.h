/*
** my.h for my.h in /home/naji_m/rendu/PSU_2015_zappy/client
**
** Made by naji moncef
** Login   <naji_m@epitech.net>
**
** Started on  Wed Jun 22 16:17:33 2016 naji moncef
** Last update Sun Jun 26 23:31:36 2016 Avel Docquin
*/

#ifndef MY_H_
# define MY_H_

# define BUFF_SIZE 4096
# define INVENTSIZE 6
# define LINEMATE 0
# define DERAUMERE 1
# define SIBUR 2
# define MENDIANE 3
# define PHIRAS 4
# define THYSTAME 5
# define AHED 0
# define RIGHT 1
# define LEFT 2
# define SEE 3
# define INVENT 4
# define PICKUP 5
# define PUT 6
# define EXPULSE 7
# define BROADCAST 8
# define INCANT 9
# define FORK 10
# define CONNECTNB 11
# define USAGE "Usage : -p -x -y -n -c -t delai d'execution des actions\n"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include <signal.h>

typedef struct s_socket
{
  struct protoent       *pe;
  struct sockaddr_in    s_in;
  int                   fd;
  char			buff[BUFF_SIZE];
  char                  *host;
  int                   port;
}               t_socket;

typedef struct  s_trantor
{
  char  *team_name;
  char  *num_client;
  int   life;
  int   inventaire[INVENTSIZE];
  char	*obj;
  int   view_size;
  int   level;
  int   is_sib_ready;
}               t_trantor;

typedef struct s_list
{
  t_socket      env;
  t_trantor	player;
}               t_list;

void    	init_tabf(int (*tabf[])(t_list *my));
int     	fct_ahed(t_list *my);
int     	fct_right(t_list *my);
int     	fct_left(t_list *my);
int		fct_see(t_list *my);
int    		 fct_inventory(t_list *my);
int		fct_pickup_obj(t_list *my);
int		fct_put_obj(t_list *my);
int		fct_pickup_obj(t_list *my);
int		fct_expls_ply(t_list *my);
int		fct_broadcast();
int		fct_fork_ply(t_list *my);
int		fct_connect_nbr(t_list *my);
int		fct_incant(t_list *my);
unsigned int	my_compare_tab(const char tab1[], const char tab2[]);
void		pose_for_elev(t_list *my);
int		first_elev(t_list *my);
int		sec_elev(t_list *my);
int		prend_line(t_list *my);
int		prend_derau(t_list *my);
int		prend_sib(t_list *my);
void		add_to_invent(t_list *my, char *obj);
void		rem_to_invent(t_list *my, char *obj);
void		rem_from_invent(t_list *my, char *obj);
int		first_step(int (*tabf[])(t_list *my), t_list *my);
int		fct_alive(int (*tabf[])(t_list *my), t_list *my);
int		fct_needtoeat(int (*tabf[])(t_list *my), t_list *my);
void		init_trantor(t_list *my);
int		pars_arg(char **av, t_list *my);
int		send_myname(t_list *my);
int		init(t_list *my);
void		init_personnage(t_list *my);
int		write_socket(t_list *my, char *str);
int		while_connected(t_list *my);
int		read_socket(t_list *my);
unsigned int	my_strlen(const char* const str);

#endif /* ! MY_H_ */
