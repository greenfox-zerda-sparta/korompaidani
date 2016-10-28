#include <iostream>
#include <string.h>

using namespace std;

void convmess(char&f_o_case, bool&launch_contr, char&player_num);
void field_drawer(char* numbase);
void fill_cell(char* numbase, char player_num);
int char_to_num(char player_num); // for controlnum function
void controlnum_arrfiller(int realnum, int* controlnum, int* round_counter);
bool type_control(int realnum, int* controlnum);
void failuremess();
void test(int round_counter, int controlnum[], char numbase[], char player_num);

int main(int argc, char** argv) {
  const int testround = 5;
  char numbase [] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int controlnum [] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int round_counter = 0;
  char player_num;
  bool launch_contr;
  char fo;

  for ( int i = 0; i < testround; i++){
    i == 0 ? fo = 'f' : fo = 'o';
    convmess(fo, launch_contr, player_num);
    controlnum_arrfiller(char_to_num(player_num), controlnum, &round_counter);
    type_control(char_to_num(player_num), controlnum) == launch_contr ? fill_cell(numbase, player_num) : failuremess();
    field_drawer(numbase);
  }
    test(round_counter, controlnum, numbase, player_num);
  return 0;
}

void convmess(char&f_o_case, bool&launch_contr, char&player_num) {
  switch(f_o_case) {
  case 'f':
    cout << "Hi! Please coise a number between 1-9 and press Enter: ";
    cin >> player_num;
    cout << endl;
    launch_contr = true;
    break;
  case 'o':
    cout << "Enter the next number: ";
    cin >> player_num;
    cout << endl;
    launch_contr = false;
    break;
  default:
    cout << "First / Others parameter error!";
  }
};

void field_drawer(char* numbase) {
  int row = 0;
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << '|' << numbase[j + row];
    }
    cout << '|' << endl;
    row += 3;
  }
  cout << endl;
};

void fill_cell(char* numbase, char player_num) {
  for (int i = 0; i < 9; i++) {
    player_num ==  numbase[i] ? numbase[i] = 'X' : numbase[i] = numbase[i];
  }
};

int char_to_num(char player_num) {
  char c = player_num;
  int realnum = (int)c;
  return realnum -= 48;
};

void controlnum_arrfiller(int realnum, int* controlnum, int* round_counter) {
  int round_counter_temp = *round_counter;
  int temp;
  bool  exist = true;
  for(int i = 0; i < 9; i ++) {
    if (controlnum[i] == realnum) {
      exist = true;
      break;
    }
    else {
      exist = false;
      temp = realnum;
    }
  }
  if (exist == false) {
    controlnum[*round_counter] = temp;
    round_counter_temp++;
    *round_counter = round_counter_temp;
    }
};

bool type_control(int realnum, int* controlnum) {
  for(int i = 0; i < 9; i++) {
    if(controlnum[i] == realnum) {
      return true;
    }
    else {
      return false;
    }
  }
};

void failuremess () {
  cout << endl << "You have to type an other number!" << endl;
};

void test(int round_counter, int controlnum[], char numbase[], char player_num){
  cout << endl << "round counter value is:\t\t" << round_counter << endl;
  cout << "char to num value is:\t\t" << player_num << endl;
  cout << "controlnums are:\t";
  for(int i = 0; i < 9; i++) {
    cout << controlnum [i] << " ";
  }
  cout << "\nnumbase numbers are:\t";
  for(int i = 0; i < 9; i++) {
    cout << numbase [i] << " ";
  }
};
