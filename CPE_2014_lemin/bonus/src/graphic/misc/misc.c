/*
** misc.c for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin/src/bonus/misc
** 
** Made by pierre jallut
** Login   <jallut_p@epitech.net>
** 
** Started on  Wed Apr 22 16:15:41 2015 pierre jallut
** Last update Sun May  3 22:52:54 2015 pierre jallut
*/

#include <SDL/SDL.h>
#include <sys/types.h>
#include <unistd.h>
#include "nest.h"
#include "nest_graph.h"

int		handle_events()
{
  SDL_Event	event;

  if (SDL_PollEvent(&event))
    if (event.type == SDL_QUIT)
      {
	system("rm res/img/logins/*");
	exit(1);
      }
  return (0);
}

/*
** Download a profile picture from epitech's intranet
*/
char	*download_profile_pic(char *login)
{
  char	*wget_command;
  char	*path_login_img;

  if (!(wget_command = malloc(sizeof(char) *
			      (40 + my_strlen(LOGIN_PATH) +
				my_strlen(EPI_SERVER) +
				my_strlen(login)))))
    return (NULL);
  wget_command[0] = 0;
  wget_command = my_strcat2(wget_command, "wget -q --no-check-certificate -P ");
  wget_command = my_strcat2(wget_command, LOGIN_PATH);
  wget_command = my_strcat2(wget_command, " ");
  wget_command = my_strcat2(wget_command, EPI_SERVER);
  wget_command = my_strcat2(wget_command, login);
  wget_command = my_strcat2(wget_command, ".jpg");
  if (system(wget_command) == -1)
    return (NULL);
  if (!(path_login_img = resize_mask(login)))
    return (NULL);
  path_login_img[my_strlen(path_login_img) - 3] = 'p';
  path_login_img[my_strlen(path_login_img) - 2] = 'n';
  path_login_img[my_strlen(path_login_img) - 1] = 'g';
  return (path_login_img);
}

char	*get_login_from_pos(int logins_fd, int random_login)
{
  int	i;
  char	*login;

  i = 0;
  get_next_line(-1);
  while (i < random_login)
    {
      if (!(login = get_next_line(logins_fd)))
	return (NULL);
      i++;
      if (i != random_login)
	free(login);
    }
  if (lseek(logins_fd, 0, SEEK_SET) == -1)
    return (NULL);
  get_next_line(-1);
  return (login);
}
