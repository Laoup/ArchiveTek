/*
** tubes.c for lem-in in /home/jallut_p/git_repos/Piscine/lemin/CPE_2014_lemin
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Sun May  3 21:17:15 2015 pierre jallut
** Last update Sun May  3 21:52:26 2015 pierre jallut
*/

#include <stdlib.h>
#include "nest.h"

/*
** Add a link to a fourmiz room
*/
int		assign_links(char *r_link, char *l_link, t_fourmiz *root)
{
  t_fourmiz	*r_room;
  t_fourmiz	*l_room;

  if (!(r_room = find_room_by_id(root, r_link)))
      return (-1);
  if (!(l_room = find_room_by_id(root, l_link)))
    return (-1);
  r_room->links = realloc(r_room->links, sizeof(t_fourmiz *) *
			  (r_room->offset_links + 2));
  r_room->links[r_room->offset_links] = l_room;
  ++r_room->offset_links;
  r_room->links[r_room->offset_links] = 0;
  return (0);
}

int	recompose_tubes(t_data *test, t_fourmiz *root)
{
  char	*r_link;
  char	*l_link;
  int	tubes_i;
  int	c;
  int	b;

  if (!(r_link = malloc(sizeof(char) * 15)) ||
      !(l_link = malloc(sizeof(char) * 15)))
    return (-1);
  tubes_i = -1;
  while (test->tubes[++tubes_i])
    {
      b = -1;
      while (test->tubes[tubes_i][++b] != ';' &&
	     test->tubes[tubes_i][b])
	r_link[b] = test->tubes[tubes_i][b];
      r_link[b] = 0;
      c = 0;
      while (test->tubes[tubes_i][++b])
	l_link[c++] = test->tubes[tubes_i][b];
      l_link[c] = 0;
      if (assign_links(r_link, l_link, root) == -1)
	return (-1);
    }
  return (0);
}
