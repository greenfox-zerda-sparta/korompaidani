

#include "GameLogic.h"

#include <iostream>



GameLogic::GameLogic() {

  this->V = vector <vector<int> >(19, vector<int>(19, 0));

}



vector <vector<int>>& GameLogic::get_V() {

  return V;

}



void GameLogic::set_grid_value(int x, int y, int gamer) {

  (gamer % 2) ? V[y / 30][x / 30] = 1 : V[y / 30][x / 30] = 2;

}



bool GameLogic::check_row(vector <vector<int>> V) {

  int player1 = 0;

  int player2 = 0;

  bool iswinner = false;

  for (unsigned int i = 0; i < V.size(); i++) {

    for (unsigned int j = 0; j < V.size(); j++) {

      if (V[i][j] == 1 && player1 < 5) {

        player1++;

      }

      else if (V[i][j] == 2 && player2 < 5) {

        player2++;

      }

      else if (player1 == 5 || player2 == 5) {

        iswinner = 1;

        break;

      }

      else {

        iswinner = 0;

        player1 = 0;

        player2 = 0;

      }

    }

    if (iswinner) break;

  }

  return iswinner;

}



bool GameLogic::check_column(vector <vector<int>> V) {

  int player1 = 0;

  int player2 = 0;

  bool iswinner = false;

  for (unsigned int i = 0; i < V.size(); i++) {

    for (unsigned int j = 0; j < V.size(); j++) {

      if (V[j][i] == 1 && player1 < 5) {

        player1++;

      }

      else if (V[j][i] == 2 && player2 < 5) {

        player2++;

      }

      else if (player1 == 5 || player2 == 5) {

        iswinner = 1;

        break;

      }

      else {

        iswinner = 0;

        player1 = 0;

        player2 = 0;

      }

    }

    if (iswinner) break;

  }

  return iswinner;

}



void GameLogic::draw_vector() {

  for (unsigned int i = 0; i < V.size(); i++) {

    for (unsigned int j = 0; j < V.size(); j++) {

      std::cout << V[i][j] << " ";

    }

    std::cout << endl;

  }

  std::cout << "-------------------- " << endl;

}