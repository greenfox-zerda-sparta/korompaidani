#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234); //10.27.6.87
  TCPsocket client = SDLNet_TCP_Open(&ip);
  bool set_stat = true;
  char text[100];
  std::string client_mess;
  std::string server_mess;
  while (1) {
    std::cin >> client_mess;
    SDLNet_TCP_Send(client, client_mess.c_str(), client_mess.length() + 1);
    SDLNet_TCP_Recv(client, text, 100);
    server_mess = text;
    std::cout << server_mess << std::endl;
  } 
  SDLNet_TCP_Close(client);
  SDL_Quit();
  return 0;
}