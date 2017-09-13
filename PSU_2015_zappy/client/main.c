/*
** main.c for main.c in /home/naji_m/rendu/PSU_2015_zappy/client
**
** Made by naji moncef
** Login   <naji_m@epitech.net>
**
** Started on  Wed Jun 22 16:15:53 2016 naji moncef
** Last update Sun Jun 26 23:22:45 2016 Avel Docquin
*/

#include "my.h"

int     init(t_list *my)
{
  my->env.pe = getprotobyname("TCP");
  if (!my->env.pe)
    return (-1);
  my->env.fd = socket(AF_INET, SOCK_STREAM, my->env.pe->p_proto);
  if (my->env.fd == -1)
    return (-1);
  my->env.s_in.sin_family = AF_INET;
  my->env.s_in.sin_port = htons(my->env.port);
  my->env.s_in.sin_addr.s_addr = inet_addr(my->env.host);
  if (connect(my->env.fd, (struct sockaddr *)&my->env.s_in,
              sizeof(my->env.s_in))== -1)
    {
      if (close(my->env.fd) == -1)
        return (-1);
      return (-1);
    }
  if (send_myname(my) == -1 || while_connected(my) == -1)
    return (-1);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_list	my;
  int		(*tabf[11])(t_list *my);

  if (env == NULL)
    return (-1);
  if (ac != 7)
    {
      write(1, USAGE, my_strlen(USAGE));
      return (-1);
    }
  init_tabf(tabf);
  pars_arg(av + 1, &my);
  init_trantor(&my);
  first_step(tabf, &my);
  if (close(my.env.fd) == -1)
    return (1);
  return (0);
}
