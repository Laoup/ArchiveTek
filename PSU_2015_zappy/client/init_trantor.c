/*
** init_trantor.c for init_trantor.c in /home/naji_m/rendu/PSU_2015_zappy/client
**
** Made by naji moncef
** Login   <naji_m@epitech.net>
**
** Started on  Wed Jun 22 16:20:31 2016 naji moncef
** Last update Sun Jun 26 22:24:16 2016 Avel Docquin
*/

#include "my.h"

int     pars_arg(char **av, t_list *my)
{
  int   i;

  i = 0;
  while (av[i] != NULL)
    {
      if (strcmp(av[i], "-n") == 0)
        my->player.team_name = av[i + 1];
      else if (strcmp(av[i], "-p") == 0)
        my->env.port = atoi(av[i + 1]);
      else if (strcmp(av[i], "-h") == 0)
        my->env.host = av[i + 1];
      i++;
    }
  if (my->player.team_name == NULL)
    return (1);
  if (my->env.port == 0)
    return (1);
  if (my->env.host == NULL)
    return (1);
  if (init(my) == -1)
    return (1);
  return (0);
}

int     send_myname(t_list *my)
{
  int   i;
  char  *team_name;

  i = 0;
  while (my->player.team_name[i])
    i++;
  if (!(team_name = malloc(sizeof(char) * i + 2)))
    return (-1);
  i = 0;
  while (my->player.team_name[i])
    {
      team_name[i] = my->player.team_name[i];
      i++;
    }
  team_name[i] = '\n';
  team_name[i + 1] = '\0';
  if (write_socket(my, team_name) == -1)
    return (-1);
  return (0);
}
