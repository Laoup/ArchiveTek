/*
** nest.h for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Fri Apr 17 18:52:15 2015 pierre jallut
** Last update Sun May  3 22:38:07 2015 pierre jallut
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# define WIN_SIZE_H 900
# define WIN_SIZE_W 1600
# define NEST_SIZE 8
# define TO_READ 1
# define EPI_SERVER "https://cdn.local.epitech.eu/userprofil/profilview/"
# define LOGIN_PATH "res/img/logins"

typedef struct		s_1001
{
  char			*login;
  int			path;
  int			which_path_room;
  int			id;
  int			printed;
}			t_1001;

typedef struct		s_fourmiz
{
  char			*id;
  struct s_fourmiz	**links;
  struct s_fourmiz	*father;
  t_1001		**ants;
  struct s_fourmiz	*nest_copy;
  int			nb_ants;
  int			offset_links;
  int			nb_rooms;
  float			x_scale;
  float			y_scale;
  int			size;
  struct s_fourmiz	*next;
  struct s_fourmiz	*prev;
}			t_fourmiz;

typedef struct		s_data
{
  char			**name_room;
  char			**tubes;
  int			nb_rooms;
  int			x_max;
  int			y_max;
  int			nb_ants;
  int			**pos_room;
}			t_data;

typedef struct	s_tools
{
  char		**file;
  int		line_start;
  int		line_end;
}		t_tools;

/*
** Init (src/nest_init/init)
*/
t_fourmiz	*init_nest(t_data *);
t_fourmiz	*init_root();
t_1001		**init_ants(t_fourmiz *);
int		recompose_tubes(t_data *, t_fourmiz *);
int		assign_links(char *, char *, t_fourmiz *);

/*
** Misc (src/nest_init/misc)
*/
t_fourmiz	*find_room_by_id(t_fourmiz *, char *);

/*
** Utils (src/nest_init/utils)
*/
int		morgan_freeman(t_data *);
int		print_turn(t_fourmiz *, t_1001 **);
int		add_room(t_fourmiz *, char *);
t_fourmiz	*search_room_by_nb(t_1001 *, t_fourmiz **);
int		check_doublon(char **);

/*
** PathFinding (src/pathfinding)
*/
t_fourmiz	*fill_check(t_fourmiz ***, t_fourmiz *, t_fourmiz *);
void		aff_list(t_fourmiz *);
int		is_check(t_fourmiz *, t_fourmiz *);
t_fourmiz	**get_path(t_fourmiz *);
void		aff_path(t_fourmiz ***);
t_fourmiz	***realloc_paths(t_fourmiz ***, int);
t_fourmiz	*add_pile(t_fourmiz *, t_fourmiz *);
t_fourmiz	*get_pile(t_fourmiz **);
int		show_file(t_fourmiz *);
t_fourmiz	***src_path(t_fourmiz *, t_fourmiz *);
int		repart_ants(t_fourmiz ***, t_1001 **);
void		aff_ants(t_1001 **);
void		simple_repart_ants(t_fourmiz ***, t_1001 **);

/*
** Lib functions
*/
void		my_putstr(char *);
void		my_putchar(char);
void		my_putnbr(int);
int		my_getnbr(char *);
int		my_strlen(char *);
void		my_printf(char *, ...);
char		*get_next_line(const int);
char		*my_realloc(char *, int);
char		*my_strcpy(char *, char *);
char		*my_strcat2(char *, char *);
char		*my_strcat(char *, char *);
int		my_dblen(char **);
int		my_putchar_error(char);
int		my_puterror(char *);
char		*my_strdup(char *);
int		my_putchar_error(char);
int		my_puterror(char *);
int		my_strcmp(char *, char *);
char		*my_strdup(char *);
void		*ver_maloc(char *, void *);
int		my_dblenf(t_fourmiz **);

#endif
