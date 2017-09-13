/*
** flo_get_env.c for lolololol in /home/meuric_a/Project/Minishell1/V1.0/src
** 
** Made by alban meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Wed Jan 21 00:38:50 2015 alban meurice
** Last update Fri Jan 30 17:48:23 2015 alban meurice
*/

#include <stdlib.h>
#include <my.h>

char	*my_get_env(char *str, char *env)
{
  int	j;
  int	k;
  char	*ret;

  k = 0;
  j = 0;
  ret = NULL;
  while (env[j] == str[j])
    {
      if ((str[j + 1] == '\0') && (env[j + 1] == '='))
	{
	  if ((ret = malloc((my_strlen(env) - my_strlen(str))
			    * sizeof(char))) == NULL)
	    return (NULL);
	  j = j + 2;
	  while (env[j])
	    ret[k++] = env[j++];
	  ret[k] = '\0';
	}
      ++j;
    }
  return (ret);
}

char	*my_getenv(char *str, char **env)
{
  int	i;
  char	*str2;

  i = 0;
  str2 = NULL;
  while ((env[i] != NULL) && (str2 == NULL))
    str2 = my_get_env(str, env[i++]);
  if (str2 != NULL)
    return (str2);
  else
    my_putstr("N'a pas trouvé la variable d'env recherchée\n");
  return (NULL);
}
