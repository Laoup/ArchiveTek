/*
** parser.h for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin_master
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Sat May  2 21:54:32 2015 pierre jallut
** Last update Sun May  3 03:24:32 2015 pierre jallut
*/

#ifndef PARSER_H_
# define PARSER _H_

#include "nest.h"

/*
** Parser (src/parser)
*/
void	init_struct(t_data *);
int	parsing(t_data *);
int	func_error(t_data *);
char	**get_file(char **);
char	**copy_tab(char **, int);
char	**copie_file(char **, int);
char	**put_line_in_file(char *, char **, char **, int);
char	**clear_file(char **);
char	**start_clear_file(char **, int *);
char	**supr_line_file(char **, char **, int);
int	i_f_comment(char *);
char	*supr_comment(char *, int);
int	get_first_line(char **);
int	search_start_and_end(t_tools *);
int	get_cmd(char *);
int	get_first_part(t_data *, t_tools *);
void	get_first_part_end_while(t_tools *, int *, int *);
int	check_is_room(char **, int);
int	is_pos(char **, int, int);
int	get_room(t_data *, char *);
int	put_word_in_tab(t_data *, char *);
int	put_word_in_tab_part2(t_data *, char *, int);
char	**while_func(char **, char **, int);
int	put_pos_in_tab(t_data *, char *, char *, int);
int	putnbr_in_pos_tab(t_data *, char *);
int	putnbr_in_pos_tab2(t_data *, char *, int, int);
int	**while_func2(int **, int **, int, int);
int	get_start_room(t_data *, t_tools *, int);
int	put_words_in_tab(t_data *, char *);
int	put_poss_in_tab(t_data *, char *, char *, int);
int	putnbr_in_poss_tab(t_data *, char *);
int	get_end_room(t_data *, t_tools *, int);
int	put_worde_in_tab(t_data *, char *);
int	put_pose_in_tab(t_data *, char *, char *, int);
int	putnbr_in_pose_tab(t_data *, char *);
int	get_second_part(t_data *, t_tools *);
int	search_second_part(char **);
int	it_s_tube_def(char *);
int	get_tube(char *, t_data *, int);
char	*get_word_one(char *);
char	*get_word_two(char *);
char	*fmt_line(char *, char *);
int	new_tube(char *, t_data *);
char	**copy_tubes_tab(char **);
int	count_tubes(char **);
int	add_ligne_tab(t_data *, char **, char *, int);
void	get_data_for_graphpart(t_data *);
int	find_doubloon(t_data *);
int	find_doubloon2(t_data *, char *, int);
int	name_error(t_data *);
int	position_error(t_data *);
int	neg_nb_ants(t_data *);
char	*get_word_one2(char *);
char	*get_word_two2(char *);
char	*fmt_line2(char *, char *);
int	tubes_to_room(t_data *);
int	tubes_to_room2(t_data *, int, int, char **);
int	tubes_to_room3(t_data *, char *);
int	tubes_to_room4(t_data *, int, int, char *);
char	**supr_doubloon(char **, int);

#endif
