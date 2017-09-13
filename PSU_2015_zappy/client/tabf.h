/*
** tabf.h for tabf.h in /home/masson_q/rendu/PSU_2015_zappy/src
** 
** Made by masson mathieu
** Login   <masson_q@epitech.net>
** 
** Started on  Thu Jun 16 11:35:37 2016 masson mathieu
** Last update Wed Jun 22 17:44:19 2016 masson mathieu
*/

#ifndef TABF_H_
# define TABF_H_

# define AHED 0
# define RIGHT 1
# define LEFT 2
# define SEE 3
# define INVENT 4
# define PICKUT 5
# define PUT 6
# define EXPULSE 7
# define BROADCAST 8
# define INCANT 9
# define FORK 10
# define CONNECTNB 11

#include "my.h"
#include "server_com.h"

void	init_tabf(int (*tabf[])(t_list *my));
int	fct_ahed(t_list *my);
int	fct_right(t_list *my);
int	fct_left(t_list *my);
int	fct_see(t_list *my);
int	fct_inventory(t_list *my);
int	fct_pickup_obj(t_list *my);
int	fct_put_obj(t_list *my);
int	fct_pickup_obj(t_list *my);
int	fct_expls_ply(t_list *my);
int	fct_broadcast(t_list *my);
int	fct_fork_ply(t_list *my);
int	fct_connect_nbr(t_list *my);
int	fct_incant(t_list *my);

#endif /* !TABF_H_ */
