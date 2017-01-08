#include "Client_cl.hpp"

Client_cl::Client_cl() {
  set_stat = true;
}

void Client_cl::client_init() {
  SDL_Init(SDL_INIT_EVERYTHING);

  SDLNet_Init();
  IPaddress ip2;
  
  SDLNet_SocketSet set2;
  
  set = SDLNet_AllocSocketSet(2);
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  TCPsocket client2;
  
  client = SDLNet_TCP_Open(&ip);
  SDLNet_TCP_AddSocket(set, client);

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
  /*int activeSockets = SDLNet_CheckSockets(set, 10);
  int gotMessage;
  if (activeSockets != 0) {
    while (1) {
      gotMessage = SDLNet_SocketReady(client);
      SDLNet_TCP_Recv(client, server_chars, 100);
      if (gotMessage != 0) {
        break;
      }
    }
    server_mess = server_chars;
    std::cout << server_mess << std::endl;
  }*/
  
  while (1) {
    
    //server_mess = server_chars;
    int activeSockets = SDLNet_CheckSockets(set, 10);
    
    if (activeSockets != 0) {
      std::cout << std::endl << "active socket" << std::endl;
      int gotMessage = SDLNet_SocketReady(client);
      if (gotMessage != 0) {
      std::cout << std::endl << "catch the shit" << std::endl;  

        SDLNet_TCP_Recv(client, server_chars, 100);
        //if (server_mess == "exit" || server_mess == "quit") {
          
        //}
        server_mess = server_chars;
        std::cout << server_mess << std::endl;
        break;
      }
      else {
        gotMessage = SDLNet_SocketReady(client);
        std::cout << std::endl << "catch nothing" << std::endl;
      }
    }
    else {
      activeSockets = SDLNet_CheckSockets(set, 10);
      std::cout << std::endl << "try new nothing" << std::endl;
    }
    
    /*if (_kbhit() != 0) {
      getline(std::cin, client_mess);
      client_chars = client_mess.c_str();
      SDLNet_TCP_Send(client, client_chars, client_mess.length() + 1);
      if (client_mess == "exit" || client_mess == "quit") {
        break;
      }
    }*/
  }
  std::cout << std::endl << "afta' ya" << std::endl;
  ///server_mess = "3,2";
 /* SDLNet_TCP_Recv(client, server_chars, 100);
  std::cout << std::endl << "after receive" << std::endl;
  std::string str_temp(server_chars);*/
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
