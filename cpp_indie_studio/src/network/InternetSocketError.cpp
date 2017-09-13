//
// InternetSocketError.cpp for InternetSocketError in /home/lucas_k/TEK2/CPP/cpp_indie_studio.VERRYIMPORTANT/indie-studio
// 
// Made by christophe lucas
// Login   <lucas_k@epitech.net>
// 
// Started on  Sun Jun  5 15:48:32 2016 christophe lucas
// Last update Sun Jun  5 15:57:59 2016 christophe lucas
//

#include "InternetSocket.hh"

void InternetSocket::InitError()
{
  error.addError("WSAStartup", 0,"WSAStartup failed: ", true);
  error.addError("getprotobyname",0,"getprotobyname failed", true);
  error.addError("socket", 0, "create failed", true);
  error.addError("bind", 0, "bind failed", true);
  error.addError("listen", 0, "listen failed", true);
  error.addError("gethostbyname", 0, "ip error", true);
  error.addError("connect", 0, "connect failed", true);
  error.addError("receive", 0, "header not receive", true);
}
