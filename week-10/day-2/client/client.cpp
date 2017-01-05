#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>

using namespace std;

bool is_quit(char*);

int main_m(int argc, char** argv) {
  ///cout << "hello, this is the client" << endl;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234); //Mate10.27.6.60 local127.0.0.1 fruzsi10.27.6.38 kinga10.27.6.61 dani10.27.6.221
  TCPsocket client = SDLNet_TCP_Open(&ip);
  string client_text = "client_mess"; ///
  char text[100];
  while (1) {
    SDLNet_TCP_Recv(client, text, 100);
    if (is_quit(text)) {
      break;
    }
    else {
      std::cout << text << endl;
    }
  }
  SDLNet_TCP_Close(client);
  SDL_Quit();
  return 0;
}

bool is_quit(char* text) {
  const char* quit = "quit";
  for (int i = 0; i < 4; i++) {
    if (quit[i] != text[i]) {
      return false;
    }
  }
}

// Create Server and Client Applications based on the sample code written by egdice
// that send and receive numeric messages. The messages should include a clientID
// a step ID and a timestemp. Or better yet; Think about this: What kind of information do You need
// to send in a message so that:
//   - Each message is definitely unique
//   - Each can be identified eg.: to which client it belongs
//   - Each tells a certain step in an amoeba game so that it's quite certain what happened :)
// Make it so, that the server application prints them to the onsole and logs then into a file.
// The file should have a name that makes it unique and ties it to a specific starting date & time.