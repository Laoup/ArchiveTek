/*
** check_is_cmd_p.c for corewar asm in /home/meuric_a/CPE_2014_corewar_ODD/asm
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Apr  8 10:43:44 2015 Alban Meurice
** Last update Wed Apr  8 10:51:56 2015 Alban Meurice
*/

int	check_is_cmd_search_separation(char **tab, int x, int y)
{
  if (tab[x][y] == ' ' || tab[x][y] == '\t')
    return (0);
  else if (tab[x][y] == '\0')
    return (0);
  else
    return (-1);
}
