#include "Server_sr.hpp"

Server_sr::Server_sr() {
  set_stat = true;
  client_mess = "client first m";
  server_mess = "server first m";
}

void Server_sr::server_init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  SDLNet_ResolveHost(&ip, NULL, 1234);
  server = SDLNet_TCP_Open(&ip);
}

void Server_sr::server_contact() {
  while (1) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
      while (client_text[0] != 'q') {
        SDLNet_TCP_Recv(client, client_text, 100);
        client_mess = client_text;
        std::cout << client_text;
        server_mess = client_mess;
        if (set_stat) {
          SDLNet_TCP_Send(client, server_mess.c_str(), server_mess.length() + 1);
          set_stat = false;
        }
      }
      SDLNet_TCP_Close(client);
      break;
    }
  }
}

void Server_sr::server_send(std::string in_server_mess) {
  client = SDLNet_TCP_Accept(server);
  std::cout << std::endl << "Client is connected..." << std::endl;
  if (client) {
    std::cout << std::endl << "before send" << std::endl;
    SDLNet_TCP_Send(client, in_server_mess.c_str(), in_server_mess.length() + 1);
    std::cout << std::endl << "after send" << std::endl;
  }
}

void Server_sr::server_client_open() {
  client = SDLNet_TCP_Accept(server);
}

std::string Server_sr::server_receive() {
  std::cout << std::endl << "before receive" << std::endl;
  SDLNet_TCP_Recv(client, client_text, 100);
  std::cout << std::endl << "before receive" << std::endl;
  std::string str_temp(client_text);
  return str_temp;
}

void Server_sr::server_client_close() {
  SDLNet_TCP_Close(client);
}

void Server_sr::server_close() {
  SDLNet_TCP_Close(server);
  SDL_Quit();
}

void Server_sr::server_run() {

  this->server_init();
  this->server_contact();
  this->server_close();
}

Server_sr::~Server_sr() {
}
