/*
** corewar.h for corewar in /home/guzman_y/test_corewar
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Tue Mar 31 15:28:12 2015 yoann guzman
** Last update Sat Apr  4 18:41:21 2015 yoann guzman
*/

#ifndef COREWAR_H__
# define COREWAR_H__

# include "op.h"

typedef struct	players_s
{
  header_t	player;
}		players_t;

int		check_arg(int ac, char **av);
int		check_extension(char **av);
int		fill_my_struct_player(int ac, char **av, header_t *tab);
int		convert_int(int nbr);

#endif /* !COREWAR_H__ */
