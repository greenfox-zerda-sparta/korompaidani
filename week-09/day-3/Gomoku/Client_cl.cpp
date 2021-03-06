#include "Client_cl.hpp"

Client_cl::Client_cl() {
  set_stat = true;
}

void Client_cl::client_init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  client = SDLNet_TCP_Open(&ip);
}

void Client_cl::client_contact() {
  while (1) {
    std::cout << "at this point ok " << std::endl;
    std::cin >> client_mess;
    SDLNet_TCP_Send(client, client_mess.c_str(), client_mess.length() + 1);
    SDLNet_TCP_Recv(client, text, 100);
    server_mess = text;
    std::cout << server_mess << std::endl;
  }
}

void Client_cl::client_send(std::string client_mess) {
  std::cout << std::endl << "before send" << std::endl;
  SDLNet_TCP_Send(client, client_mess.c_str(), client_mess.length() + 1);
  std::cout << std::endl << "before send" << std::endl;
}

std::string Client_cl::client_receive() {
  std::cout << std::endl << "before receive" << std::endl;
  SDLNet_TCP_Recv(client, text, 100);
  std::cout << std::endl << "after receive" << std::endl;
  std::string str_temp(text);
  return str_temp;
}

void Client_cl::client_close() {
  SDLNet_TCP_Close(client);
  SDL_Quit();
}

void Client_cl::client_run() {
  this->client_init();
  this->client_contact();
  this->client_close();
}


Client_cl::~Client_cl() {
}
