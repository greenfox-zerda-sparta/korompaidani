
#ifndef GAMELOGIC_H_

#define GAMELOGIC_H_

#include <vector>

#include "SDLwindow.h"



using namespace std;



class GameLogic {

private:

  vector <vector<int>> V;

public:

  GameLogic();

  bool check_row(vector <vector<int>> V);

  bool check_column(vector <vector<int>> V);

  bool check_diagonal_right(vector <vector<int>> V);

  vector <vector<int>>& get_V();

  void set_grid_value(int, int, int gamer);

  void draw_vector();

};



#endif /* GAMELOGIC_H_ */