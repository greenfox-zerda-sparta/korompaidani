#include "Client_cl.hpp"

Client_cl::Client_cl() {
  set_stat = true;
}

void Client_cl::client_init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  set = SDLNet_AllocSocketSet(2);
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  this->client = SDLNet_TCP_Open(&ip);
  SDLNet_TCP_AddSocket(set, client);
  this->activeSockets = SDLNet_CheckSockets(set, 10);
  std::cout << "my activeSockets number is: " << this->activeSockets << std::endl;
}

void Client_cl::client_contact() {
  while (1) {
    server_mess = server_chars;
    int activeSockets = SDLNet_CheckSockets(set, 10);
    if (activeSockets != 0) {
      int gotMessage = SDLNet_SocketReady(client);
      if (gotMessage != 0) {
        SDLNet_TCP_Recv(client, server_chars, 100);
        if (server_mess == "exit" || server_mess == "quit") {
          break;
        }
        std::cout << server_mess << std::endl;
      }
    }
    if (_kbhit() != 0) {
      getline(std::cin, client_mess);
      client_chars = client_mess.c_str();
      SDLNet_TCP_Send(client, client_chars, client_mess.length() + 1);
      if (client_mess == "exit" || client_mess == "quit") {
        break;
      }
    }
  }
}

void Client_cl::client_send(std::string client_mess) {
  std::cout << std::endl << "before send" << std::endl;
  SDLNet_TCP_Send(client, client_mess.c_str(), client_mess.length() + 1);
  std::cout << std::endl << "before send" << std::endl;
}

std::string Client_cl::client_receive() {
  while (1) {
    this->activeSockets = SDLNet_CheckSockets(set, 10);
    if (this->activeSockets != 0) {
      gotMessage = SDLNet_SocketReady(client);
      if (gotMessage != 0) {  
        SDLNet_TCP_Recv(client, server_chars, 100);
        server_mess = server_chars;
        break;
      }
    }
  }
  return server_mess;
}

void Client_cl::client_close() {
  SDLNet_TCP_Close(client);
  SDLNet_FreeSocketSet(set);
  SDL_Quit();
}

void Client_cl::client_run() {
  this->client_init();
  this->client_contact();
  this->client_close();
}


Client_cl::~Client_cl() {
}
