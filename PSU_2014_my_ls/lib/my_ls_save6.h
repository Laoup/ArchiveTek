/*
** my_ls.h for Project My_ls in /home/meuric_a/Project/My_ls
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Nov 27 01:03:42 2014 alban meurice
** Last update Sat Nov 29 03:34:19 2014 alban meurice
*/

#ifndef MY_LS_H_
# define MY_LS_H_

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

char	my_ls(char *str);
char	aff_name(DIR *dirp, struct dirent *entry, int x);
int	count_ls(DIR *dirp, struct dirent *entry, char *str);

#endif /* MY_LS_H_ */
