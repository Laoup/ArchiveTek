/*
** convert.c for corewar in /home/guzman_y/lol/test_corewar
** 
** Made by yoann guzman
** Login   <guzman_y@epitech.net>
** 
** Started on  Sat Apr  4 17:22:34 2015 yoann guzman
** Last update Sat Apr  4 20:01:47 2015 yoann guzman
*/

int	convert_int(int nbr)
{
  int	b;
  int	c;
  int	d;
  int	convert_nbr;

  convert_nbr = 0;
  b = nbr << 8;
  c = nbr >> 8;
  d = nbr >> 24;
  b = b & 16711680;
  c = c & 65280;
  d = d & 255;
  convert_nbr = convert_nbr ^ b;
  convert_nbr = convert_nbr ^ c;
  convert_nbr = convert_nbr ^ d;
  return (convert_nbr);
}
