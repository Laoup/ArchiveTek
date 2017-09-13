/*
** utils.c for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin/src/bonus/utils
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Wed Apr 29 18:19:43 2015 pierre jallut
** Last update Sun May  3 22:47:16 2015 pierre jallut
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <SDL/SDL_image.h>
#include "nest_graph.h"

/*
** Resize a login picture by 40%
*/
char	*create_resize_call(char *login)
{
  char	*resize;

  if (!(resize = malloc(sizeof(char) *
		      (50 + ((my_strlen(LOGIN_PATH) + my_strlen(login)) * 2)))))
    return (NULL);
  resize[0] = 0;
  resize = my_strcat2(resize, "convert ");
  resize = my_strcat2(resize, LOGIN_PATH);
  resize = my_strcat2(resize, "/");
  resize = my_strcat2(resize, login);
  resize = my_strcat2(resize, ".jpg");
  resize = my_strcat2(resize, " -resize 35x35 ");
  resize = my_strcat2(resize, LOGIN_PATH);
  resize = my_strcat2(resize, "/");
  resize = my_strcat2(resize, login);
  resize = my_strcat2(resize, ".jpg");
  return (resize);
}

/*
** Create a circle image mask with the package imagemagick
*/
char	*create_mask_call(char *login)
{
  char	*mask;

  if (!(mask = malloc(sizeof(char) *
		      (200 + ((my_strlen(LOGIN_PATH) + my_strlen(login)) * 2)))))
    return (NULL);
  mask[0] = 0;
  mask = my_strcat2(mask, "convert -size 35x35 xc:none -fill ");
  mask = my_strcat2(mask, LOGIN_PATH);
  mask = my_strcat2(mask, "/");
  mask = my_strcat2(mask, login);
  mask = my_strcat2(mask, ".jpg");
  mask = my_strcat2(mask, " -draw 'circle 17.5, 17.5, 5, 5' ");
  mask = my_strcat2(mask, LOGIN_PATH);
  mask = my_strcat2(mask, "/");
  mask = my_strcat2(mask, login);
  mask = my_strcat2(mask, ".png");
  return (mask);
}

/*
** Call all the image manipulations functions
*/
char	*resize_mask(char *login)
{
  char	*path;
  char	*resize;
  char	*mask;

  if (!(path = malloc(sizeof(char) *
		      (my_strlen(LOGIN_PATH) + my_strlen(login) + 7))))
    return (NULL);
  path[0] = 0;
  path = my_strcat2(path, LOGIN_PATH);
  path = my_strcat2(path, "/");
  path = my_strcat2(path, login);
  path = my_strcat2(path, ".jpg");
  if (!access(path, F_OK))
    {
      mask = create_mask_call(login);
      resize = create_resize_call(login);
      system(resize);
      system(mask);
      free(mask);
      free(resize);
    }
  return (path);
}

/*
** Prepare the ants to be shown graphically
*/
int     prepare_graphic_ants(t_fourmiz *root, t_1001 **ants)
{
  int	i;
  int	random_login;
  int	logins_fd;
  char	*path_login_img;
  char	*login;

  i = -1;
  if ((logins_fd = open("logins", O_RDONLY)) == -1)
    return (-1);
  while (ants[++i])
    {
      random_login = rand() % (1410 + 1);
      random_login += (!random_login ? 1 : 0);
      if (!(login = get_login_from_pos(logins_fd, random_login)))
	  return (-1);
      if (!(path_login_img = download_profile_pic(login)))
	return (-1);
      if (!access(path_login_img, R_OK | F_OK))
	ants[i]->sprite = IMG_Load(path_login_img);
      else
	ants[i]->sprite = IMG_Load(path_login_img);
      ants[i]->login = login;
      ants[i]->pos = root->next->pos;
    }
  return (0);
}
