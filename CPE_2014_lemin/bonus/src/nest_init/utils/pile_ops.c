/*
** utils.c for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Fri Apr 17 18:48:54 2015 pierre jallut
** Last update Sun May  3 21:23:41 2015 Arthur Grosso
*/

#include <string.h>
#include <stdlib.h>
#include <nest.h>

/*
** Add item to the end of chained list
*/
int		add_room(t_fourmiz *root, char *id, int *pos_room)
{
  t_fourmiz	*new_room;

  if (!(new_room = malloc(sizeof(t_fourmiz))) ||
      !(new_room->id = malloc(sizeof(char) * (my_strlen(id) + 1))))
    return (-1);
  root->prev->next = new_room;
  new_room->prev = root->prev;
  root->prev = new_room;
  new_room->next = root;
  new_room->id[0] = 0;
  new_room->id = strcpy(new_room->id, id);
  new_room->pos.x = pos_room[0];
  new_room->pos.y = pos_room[1];
  new_room->offset_links = 0;
  ++root->size;
  new_room->father = 0;
  if (!(new_room->links = malloc(sizeof(t_fourmiz *) * 1)))
    return (-1);
  new_room->links[0] = NULL;
  return (0);
}

/*
** Return the fourmiz room with the id given in params
*/
t_fourmiz	*find_room_by_id(t_fourmiz *root, char *id)
{
  t_fourmiz	*tmp;

  tmp = root->next;
  while (tmp != root && strcmp(tmp->id, id) != 0)
    tmp = tmp->next;
  if (tmp == root)
    {
      my_printf("No room with this id (%s)\n", id);
      return (NULL);
    }
  return (tmp);
}
