 /*
** minitalk.h for minitalk in /home/meuric_a/Project/Minitalk/V1.0/include
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Tue Mar 17 20:30:51 2015 Alban Meurice
** Last update Wed Mar 18 22:24:08 2015 Alban Meurice
*/

#ifndef MINITALK_H_
# define MINITALK_H_

int	check_string(char *);
int	client(int, char *);
int	send_letter(int *, int);
int	*conv_bin(char);
void	catch_sigusr1(int);
void	catch_sigusr2(int);
void	put_in_tab(char);
char	conv_dec();

#endif /* !MINITALK_H_ */
