/*
** init.c for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Fri Apr 17 18:47:48 2015 pierre jallut
** Last update Sun May  3 22:38:31 2015 pierre jallut
*/

#include <stdlib.h>
#include "nest.h"

/*
** Init all the ants from the number parsed from the input
*/
t_1001		**init_ants(t_fourmiz *root)
{
  t_1001	**ants;
  int		i;

  if (!(ants = malloc(sizeof(t_1001 *) * (root->nb_ants + 1))))
    return (NULL);
  i = -1;
  while (++i < root->nb_ants)
    {
      if (!(ants[i] = malloc(sizeof(t_1001))))
	return (NULL);
      ants[i]->printed = 0;
      ants[i]->path = 0;
      ants[i]->id = i + 1;
      ants[i]->which_path_room = 0;
    }
  ants[i] = NULL;
  return (ants);
}

/*
** Init the root item for the fourmiz doubly circular linked list
*/
t_fourmiz	*init_root()
{
  t_fourmiz	*root;

  if (!(root = malloc(sizeof(t_fourmiz))))
    return ((t_fourmiz *) -1);
  root->prev = root;
  root->next = root;
  root->size = 0;
  root->links = NULL;
  root->id = NULL;
  return (root);
}

t_fourmiz	*create_nest(t_data *test)
{
  t_fourmiz	*root;
  int		i;

  if (!(root = init_root()))
    return (NULL);
  if (add_room(root, test->name_room[0]) == -1)
    return (NULL);
  i = 2;
  while (test->name_room[i])
    {
      if (add_room(root, test->name_room[i]) == -1)
	return (NULL);
      i++;
    }
  if (add_room(root, test->name_room[1]) == -1)
    return (NULL);
  root->nb_ants = test->nb_ants;
  if (recompose_tubes(test, root) == -1)
    return (NULL);
  return (root);
}

/*
** Init the doubly circular linked list
*/
t_fourmiz	*init_nest(t_data *test)
{
  t_fourmiz	*root;
  t_fourmiz	*root_cpy;

  if (check_doublon(test->name_room))
    {
      my_printf("Identical rooms detected ! \n");
      return (NULL);
    }
  if (!(root = create_nest(test)))
    return (NULL);
  root_cpy = create_nest(test);
  root->nest_copy = root_cpy;
  root->nb_rooms = test->nb_rooms;
  if (!test->x_max)
    test->x_max += 10;
  if (!test->y_max)
    test->y_max += 10;
  root->x_scale = WIN_SIZE_W / test->x_max;
  root->y_scale = WIN_SIZE_H / test->y_max;
  root->nest_copy->x_scale = WIN_SIZE_W / test->x_max;
  root->nest_copy->y_scale = WIN_SIZE_H / test->y_max;
  morgan_freeman(test);
  return (root);
}
