#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>
#include <cstring>

using namespace std;

int main_n(int argc, char** argv) {
  ///cout << "hi, this is the server" << endl;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  string text;
  char rec_text[100]; ///
  while (1) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
      while (1) {
        getline(cin, text);
        if (text == "exit") {
          break;
        }
        else {
          SDLNet_TCP_Send(client, text.c_str(), text.length() + 1);
        }
      }
      SDLNet_TCP_Close(client);
      break;
    }
  }
  SDL_Quit();
  return 0;
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