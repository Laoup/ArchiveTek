/*
** nest_graph.h for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Wed Apr 22 15:45:35 2015 pierre jallut
** Last update Sun May  3 19:30:26 2015 pierre jallut
*/

#ifndef NEST_GRAPH_H_
# define NEST_GRAPH_H

# define ABS(x) ((x < 0) ? (-x) : (x))
# define INCR(x) ((x > 0) ? (1) : (-1))
# define SCALE 5

# include <SDL/SDL.h>
# include "nest.h"

/* 
** Init (src/bonus/init/)
*/
int		graphic_init(t_fourmiz *, t_1001 **);

/* 
** Misc (src/bonus/misc)
*/
int		handle_events();
char		*download_profile_pic(char *);
char		*get_login_from_pos(int, int);
SDL_Rect	follow_line(SDL_Rect *, SDL_Rect *);

/* 
** Utils (src/bonus/utils)
*/
char		*resize_mask(char *);
int		prepare_graphic_ants(t_fourmiz *, t_1001 **);
int		print_ants(SDL_Surface *, t_1001 **);
int		print_tubes(SDL_Surface *, t_fourmiz *);
void		print_nodes(t_fourmiz *, SDL_Surface *);
void		print_authors(SDL_Surface *);
int		refresh_screen(SDL_Surface *, t_1001 **, t_fourmiz *);

#endif
