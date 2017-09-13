/*
** cover_paths.c for  in /home/grosso_a/workspace/lem_in
** 
** Made by Arthur Grosso
** Login   <grosso_a@epitech.net>
** 
** Started on  Fri May  1 15:18:27 2015 Arthur Grosso
** Last update Sun May  3 22:29:05 2015 pierre jallut
*/

#include <stdlib.h>
#include "nest.h"

t_fourmiz	*get_links(t_fourmiz *tmp, t_fourmiz *check, t_fourmiz *file)
{
  int		i;

  i = 0;
  while (tmp->links[i] != NULL)
    {
      if ((is_check(tmp->links[i], check) == 0) &&
	  (is_check(tmp->links[i], file) == 0) &&
	  (tmp->links[i] != tmp))
	{
	  tmp->links[i]->father = tmp;
	  file = add_pile(file, tmp->links[i]);
	}
      i++;
    }
  return (file);
}

int		cover_tree(t_fourmiz *check, t_fourmiz *in, t_fourmiz *out)
{
  t_fourmiz	*file;
  t_fourmiz	*tmp;

  file = NULL;
  in->father = NULL;
  file = add_pile(file, in);
  while (file != NULL)
    {
      tmp = get_pile(&file);
      if ((is_check(out, file) == 1) || (tmp == out))
	return (1);
      else if (is_check(tmp, check) == 0)
	{
	  file = get_links(tmp, check, file);
	  check = add_pile(check, tmp);
	}
    }
  return (0);
}

int		len_line_tab(t_fourmiz **line)
{
  int		i;

  i = 0;
  while (line[i] != NULL)
    {
      i++;
    }
  return (i);
}

int	my_path(t_fourmiz ****paths, int nb_path, t_fourmiz *out)
{
  (*paths)[nb_path] = get_path(out);
  if ((*paths = realloc_paths(*paths, nb_path + 1)) == NULL)
    return (1);
  if (len_line_tab((*paths)[nb_path]) == 2)
    return (1);
  return (0);
}

t_fourmiz	***src_path(t_fourmiz *in, t_fourmiz *out)
{
  t_fourmiz	***paths;
  t_fourmiz	*check;
  int		nb_path;
  int		end;

  end = 0;
  nb_path = 0;
  check = NULL;
  if ((paths = malloc(sizeof(t_fourmiz **))) == NULL)
    return (NULL);
  while (end != 1)
    {
      if (cover_tree(check, in, out) != 0)
	{
	  if (my_path(&paths, nb_path, out))
	    return (paths);
	  check = fill_check(paths, in, out);
	}
      else
	end = 1;
      nb_path++;
    }
  paths[nb_path - 1] = NULL;
  return (paths);
}
