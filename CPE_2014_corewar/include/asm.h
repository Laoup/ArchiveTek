/*
** asm.h for asm in /home/guzman_y/prog/epitech/rendu/prog_elem/CPE_2014_corewar/asm
**
** Made by yoann guzman
** Login   <guzman_y@guzman-y-pc>
**
** Started on  Mon Mar 23 14:40:14 2015 yoann guzman
** Last update Sun Apr 12 22:13:55 2015 Moisset Raphael
*/

/* il manque les fonctions de raph: conver.c convert_func.c create_cor.c my_base_cor.c treat.c ... */

#ifndef ASM_H_
# define ASM_H_

# include "op.h"

typedef struct	s_commande
{
  char		*str;
}		t_cmd;

typedef	struct	s_label_or_commande_line
{
  int		x;
  int		y;
  int		loc;
  char		**tab_label;
}		t_locl;

typedef	struct	s_hexaline_and_tools
{
  int		*hexa_line;
  int		*bin_line;
  char		*word;
  int		nb;
  int		nb_r;
  int		nb_dir;
  int		nb_ind;
}		t_hex_t;

typedef struct	s_line_cmd
{
  int		*w_bin;
  int		n_elem;
  int		tru_e;
  int		y_pos_save;
}		t_lc;

typedef struct	s_put_cmd
{
  int		size;
  int		ver;
  int		res_w;
  int		*w_int;
  int		i;
  int		k;
  int		count;
  int		rep;
}		t_pc;

int		my_asm(char *);
char		**copy_file_in_tab(int);
char		**copy_tab(char **, int);
char		**put_line_in_tab(char *, char **, char **, int);
char		**clear_tab(char **);
int		line_null(char **, int);
int		my_pars(char *);
int		**write_hex_code(char **);
int		**convert_block(char **, t_locl *);
t_locl		*begining_instruction(char **, t_locl *);
t_locl		*put_in_tab_label(char *, t_locl *);
char		**copy_tab_label(t_locl *, int);
char		**put_label_in_tab(char **, int, char *);
void		search_first_line(char **, t_locl *);
int		its_my_line(char **, t_locl *);
int		check_is_cmd(char **, int, int);
int		check_is_cmd_search_separation(char **, int, int);
int		check_is_label(char **, int, int);
int		check_is_next_instruction(char **, t_locl *);
int		bad_caractere(char **, t_locl *);
int		jump_line(char **, t_locl *);
int		*convert_line_hexa(char **, t_locl *);
char		*recup_first_word(char **, t_locl *);
int		cmd_is_true(char *);
int		line_cmd_is_true(char **, t_hex_t *, t_locl *);
int		check_op_tab(int, int, args_type_t);
int		*put_in_bin_line(int *, int *, int);
int		*put_cmd_in_line(t_hex_t *, t_locl *, char **);
int		size_malloc(t_hex_t *);
int		convert_bin_in_dec(t_hex_t *);
int		convert_bin_in_dec_by2(int *);
int		val(t_locl *, char **, int);
int		return_val_type(t_locl *, char **);
int		**put_in_hexa_tab(int *, int **);
void		my_check();
int		convert_int(int);
int		my_read_av(char *, int, int);
int		transform_magic_number();
int		my_taille();
header_t*	my_read_s(char **, int);
int		line_cmd_istrue1(char **, t_hex_t *, t_locl *, t_lc *);
int		put_cmd_inline1(t_hex_t *, t_locl *, char **, t_pc *);
int		put_cmd_inline2(t_hex_t *, t_pc *);
int		my_print_hexa(int **, int);

#endif /* !ASM_H_ */
