#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>

class Client_cl {
private:
  IPaddress ip;
  TCPsocket client;
  bool set_stat;
  char text[100];
  std::string client_mess;
  std::string server_mess;
public:
  Client_cl();
  void client_init();
  void client_contact();
  void client_send(std::string);
  char* client_receive();
  void client_close();
  void client_run();
  ~Client_cl();
};