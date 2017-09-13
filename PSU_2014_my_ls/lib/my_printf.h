/*
** my_printf.h for my_printf in /home/meuric_a/my_printf
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Nov 13 01:24:12 2014 alban meurice
** Last update Sat Nov 15 02:18:55 2014 alban meurice
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdarg.h>

typedef struct	s_tab
{
  char		flag;
  void		(*fct)(va_list);
}		t_tab;

int	my_printf(const char *, ...);
void	flag_d(va_list);
void	flag_c(va_list);
void	flag_s(va_list);
void	flag_p(va_list);
void	flag_B(va_list);
void	flag_b(va_list);
void	flag_x(va_list);
void	flag_o(va_list);
void	flag_S(va_list);
int	my_putnbr_bin(int nb);
int	my_putnbr_hexa(int nb);
int	my_putnbr_octal(int nb);

#endif /* !MY_PRINTF_H_ */
