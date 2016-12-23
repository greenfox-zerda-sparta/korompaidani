#include "waste\stdafx.h"
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "Map.hpp"
#include "Player.hpp"
#include "Scan.hpp"
//#include "Game_engine.hpp"
#include "SDLWindow.hpp"

#ifdef CATCH_CONFIG_MAIN

int main(int argc, char* argv[]) {
  SDL_Window sdl_window(570, 570);
  sdl_window.run();
  return 0;
}
#endif

#ifndef CATCH_CONFIG_MAIN
#include "C:\Users\korom\OneDrive\Programming\TEST\catch.hpp"

void print_map_vector(Map&);

TEST_CASE("get map value by coordinates") {
  Map map(19);
  REQUIRE(map.get_map_value_by_coordinates(4, 4) == 0);
}

TEST_CASE("get map value by coordinates if coords are more than 19") {
  Map map(19);
  REQUIRE(map.get_map_value_by_coordinates(4, 19) == ERR_CODE_9);
}

TEST_CASE("get map value by coordinates if coords are less than 0") {
  Map map(19);
  REQUIRE(map.get_map_value_by_coordinates(-1, -1) == ERR_CODE_9);
}

TEST_CASE("set map value by coordinates") {
  Map map(19);
  int my_num = 2;
  map.set_map_value_by_coordinates(4, 5, my_num);
  REQUIRE(map.get_map_value_by_coordinates(4, 5) == my_num);
}

TEST_CASE("set map value by coordinates edge cases") {
  Map map(19);
  int my_num = 2;
  REQUIRE(map.set_map_value_by_coordinates(4, 19, my_num) == ERR_CODE_8);
}

TEST_CASE("get map visibility test") {
  Map map(19);  
  REQUIRE(map.get_map().size() == 19);
  REQUIRE(map.get_map()[1].size() == 19);
  REQUIRE(map.get_map()[18].size() == 19);
}

TEST_CASE("set values and use get map to print map") {
  Map map(19);
  unsigned int my_num = 5;
  map.set_map_value_by_coordinates(-1, -1, my_num);
  map.set_map_value_by_coordinates(0, 0, my_num);
  map.set_map_value_by_coordinates(19, 19, my_num);
  map.set_map_value_by_coordinates(18, 18, my_num);
  map.set_map_value_by_coordinates(4, 11, my_num);
  
  ///print_map_vector(map);
}

TEST_CASE("using Players two different constructors and get theirs name") {
  Player player1("Joey");
  REQUIRE(player1.get_name() == "Joey");

  Player player2("Chandler", player1);
  REQUIRE(player2.get_name() == "Chandler");
}

TEST_CASE("using two diff instance and the second can see the first one's playername") {
  Player player1("Joey");
  REQUIRE(player1.get_name() == "Joey");

  Player player2("Chandler", player1);
  ///REQUIRE(player2.get_name() == "Joey");
  ///it was worked only in this phase and  after that I had to remove this.
}

TEST_CASE("second player2 which constructed with player1 does have the right player number") {
  Player player1("Joey");
  REQUIRE(player1.get_player_num() == 1);

  Player player2("Chandler", player1);
  REQUIRE(player2.get_player_num() == 2);
}

TEST_CASE("Players choise method") {
  Map map(19);
  Player player1("Joey");
  Player player2("Chandler", player1);
  CHECK(player2.choise(map, 5, 6));
  CHECK(player1.choise(map, 2, 9));
  ///CHECK(player2.choise(map, 2, 9));
  ///print_map_vector(map);
}

TEST_CASE("hello scan class") {
  Map map(19);
  Scan scan;
  //REQUIRE(scan.horizontal(map));
}

TEST_CASE("map horizontal scan find five 1 next to each other") {
  Map map(19);
  Player player1("Joey");
  player1.choise(map, 2, 9);
  player1.choise(map, 3, 9);
  player1.choise(map, 4, 9);
  player1.choise(map, 5, 9);
  player1.choise(map, 7, 9);

  player1.choise(map, 1, 4);
  player1.choise(map, 3, 4);
  player1.choise(map, 7, 4);
  player1.choise(map, 11, 4);
  player1.choise(map, 12, 4);

  player1.choise(map, 2, 18);
  player1.choise(map, 3, 18);
  player1.choise(map, 4, 18);
  player1.choise(map, 5, 18);
  player1.choise(map, 6, 18);

  Scan scan;
 // CHECK(scan.horizontal(map));
}

TEST_CASE("map horizontal scan find five 2 next to each other") {
  Map map(19);
  Player player0("Phoebe");
  Player player1("Joey", player0);
  player0.choise(map, 3, 9);
  player0.choise(map, 4, 9);
  player0.choise(map, 5, 9);
  player0.choise(map, 6, 9);

  player1.choise(map, 2, 18);
  player1.choise(map, 3, 18);
  player1.choise(map, 4, 18);
  player1.choise(map, 5, 18);
  player1.choise(map, 6, 18);

  Scan scan;
  //CHECK(scan.horizontal(map));
}

TEST_CASE("do you see who is the winner?") {
  Map map(19);
  Player player0("Phoebe");
  Player player1("Joey", player0);
  player0.choise(map, 2, 9);
  player0.choise(map, 3, 9);
  player1.choise(map, 4, 9);
  player0.choise(map, 5, 9);
  player0.choise(map, 6, 9);

  player1.choise(map, 7, 18);
  player1.choise(map, 8, 18);
  player1.choise(map, 9, 18);
  player1.choise(map, 10, 18);
  player1.choise(map, 11, 18);

  Scan scan;
  scan.horizontal(map);
//  CHECK(scan.get_win_case().second == 6);
}

TEST_CASE("check the exit is false value") {
  Map map(19);
  Player player0("Phoebe");
  Player player1("Joey", player0);
  player1.choise(map, 2, 18);
  player1.choise(map, 3, 18);
 //player1.choise(map, 4, 18);
  player1.choise(map, 5, 18);
  player1.choise(map, 6, 18);

  player1.choise(map, 8, 11);
  player1.choise(map, 9, 11);
  player0.choise(map, 10, 11);
  player1.choise(map, 11, 11);
  player1.choise(map, 12, 11);

  player1.choise(map, 10, 18);
  player1.choise(map, 11, 18);
  player1.choise(map, 12, 18);
  player1.choise(map, 13, 18);
  player1.choise(map, 14, 18);

  Scan scan;
  //scan.horizontal(map);
  //CHECK(scan.horizontal(map)); 
}

TEST_CASE("map vertical scan find five 1 ") {
  Map map(19);
  Player player0("Phoebe");
  Player player1("Monica", player0);

  player1.choise(map, 4, 7);
  player1.choise(map, 4, 8);
  player1.choise(map, 4, 9);
  player1.choise(map, 4, 10);
  
  player1.choise(map, 4, 14);
  player1.choise(map, 4, 15);
  player1.choise(map, 4, 1);
  player1.choise(map, 4, 17);
  player1.choise(map, 4, 18);

  Scan scan;
  scan.vertical(map);
  std::cout << scan.get_win_case().first << std::endl;
  std::cout << scan.get_win_case().second << std::endl;
  std::cout << scan.get_win_player_num() << std::endl;
  CHECK(scan.vertical(map));
  print_map_vector(map);
}

#endif

void print_map_vector(Map& m_map) {
  for (int i = 0; i < m_map.get_map().size(); i++) {
    for (int j = 0; j < m_map.get_map()[i].size(); j++) {
      std::cout << m_map.get_map()[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}