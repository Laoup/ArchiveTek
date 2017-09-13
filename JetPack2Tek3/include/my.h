/*
** my.h for My JetPack in /home/meuric_a/Synthese_TEK2/JetPack2Tek3/include
** 
** Made by Alban Meurice
** Login   <meuric_a@epitech.net>
** 
** Started on  Thu Jul  7 18:32:15 2016 Alban Meurice
** Last update Wed Jul 13 20:07:25 2016 Alban Meurice
*/

#ifndef MY_H_
# define MY_H_

# define BUFFSIZE	4096
# define NBR_CMD	8

# include <sys/select.h>

/*int	(*fct)(int *)[*/

typedef	struct	s_info
{
  int		fdClient;
  int		idClient;

  int		fire;
  int		coin;
  int		ready;
  int		start;
  int		winner;

  int		x;
  int		y;

  int		score;

  char		msg[2][10];
}		t_info;

typedef	struct	s_param
{
  int		port;
  int		largeur;
  int		hauteur;
  int		gravity;
  int		nbrClient;
  /* long	delai;*/

  int		fdServer;
  int		fdMax;
  fd_set	fdRead;
  fd_set	fdWrite;

  char		*map;

  int		(*fct[NBR_CMD])(t_info *, struct s_param *);
  char		*tabCmd[NBR_CMD];
}		t_param;

int		initParam(char **, t_param *);
int		initTabCmd(t_param *);
int		initClientTab(t_info **, int);
int		returnFct(int, int);

void		my_check();

/*
**search.c**
*/

int		search(char **, char *);
char		*fileMap(char **, char *);
int		getMap(char *, char **);
int		infoMap(char *, t_param *);
char		*readMap(char *, int, int);

/* 
**
*/

/* 
**funcSocket.c**
*/

int	createSocket(int);
int	returnCloseClient(int, t_info *);

/* 
**
*/

/* 
**select.c**
*/

int	selectManager(t_param *, t_info *);
int	initFd(t_param *, t_info *);

/* 
**
*/

/* 
**tabFunc.c**
*/

/*char	**manipTabClient(t_param *, t_info *, char *);*/
int	manipTabClient(t_param *, t_info *, char *);
char	**initTabMsg();
int	initTabClient(t_info **);
int	addClient(t_info *, int);

/* 
**
*/

/* 
**execute.c**
*/

int	executeCmd(t_param *, t_info */*, char ** */);
int	searchFunc(t_param *, char *);

/* 
**
*/

/* 
**fct.c**
*/

int	getId(t_info *, t_param *);
int	sendMap(t_info *, t_param *);
int	readyReceive(t_info *, t_param *);
int	fireReceive(t_info *, t_param *);

/* 
**
*/

/* 
**misc.c**
*/

char	*convertNbr(int);
void	cutBuff(t_info *, char *);
int	countLineJump(char *);
char	*revStr(char *);

/* 
**
*/

/* 
**fctAnswer.c**
*/

int	answer(t_param *, t_info *, int);
int	sendStart(t_info *, t_param *);
int	sendPlayer(t_info *, t_param *);
int	sendFinish(t_info *, t_param *);
int	sendCoin(t_info *, t_param *);

/* 
**
*/

/* 
**map.c**
*/

int	execMap(t_param *, t_info *);
int	movePlayer(t_param *, t_info *, int);
void	setWinner(t_info *);

/* 
**
*/

#endif /* MY_H_ */
