#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>
#include <cstring>

using namespace std;

int main_1(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip); //listening
  TCPsocket client;
  bool set_stat = true;
  char client_text[100];
  std::string client_mess = "client first m";
  std::string server_mess = "server first m";
  while (1) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
      std::cout << "client is connected ";
      while (client_text[0] != 'q') {
        SDLNet_TCP_Recv(client, client_text, 100);
        client_mess = client_text;        
        std::cout << client_text;
        server_mess = "9,9"; 
        SDLNet_TCP_Send(client, server_mess.c_str(), server_mess.length() + 1); 
      }
      break;
    }
  }
  SDLNet_TCP_Close(client);
  SDLNet_TCP_Close(server);
  SDL_Quit();
  return 0;
}