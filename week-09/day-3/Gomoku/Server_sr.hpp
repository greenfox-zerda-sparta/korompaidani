#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>
#include <cstring>

class Server_sr {
private:
  IPaddress ip;
  TCPsocket server;
  TCPsocket client;
  bool set_stat;
  char client_text[100];
  std::string client_mess;
  std::string server_mess;
public:
  Server_sr();
  void server_init();
  void server_contact();
  void server_send(std::string);
  void server_client_open();
  std::string server_receive();
  void server_client_close();
  void server_close();
  void server_run();
  ~Server_sr();
};