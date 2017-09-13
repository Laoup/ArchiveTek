/*
** my_strcpy.c for my_strcpy in /home/guzman_y/lib/my
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Wed Nov 12 18:35:22 2014 yoann guzman
** Last update Thu Nov 20 13:15:43 2014 yoann guzman
*/

char	*my_strcpy(char *dest, char *src)
{
  int	counter;

  counter = 0;
  while (src[counter] != '\0')
    {
      dest[counter] = src[counter];
      counter = counter + 1;
    }
  return (dest);
}
