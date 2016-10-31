#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

void conv(char&f_o_case, char&player_num);
void field_drawer(char* numbase);
void fill_cell(char* numbase, char player_num);
int char_to_num(char player_num); // for controlnum function
void controlnum_arrfiller(int realnum, int* controlnum_res, int* round_counter, bool type_control, char* numbase, char&player_num, bool&ai_perm);
bool type_control(int realnum, int* controlnum);
void failuremess(char&player_num);
void test(int round_counter, int controlnum[], char numbase[], char player_num, bool wingame, bool&testmode, int&test_mode_counter);
char ai(char* numbase, bool ai_perm, int* controlnum, int* ai_round_counter);
bool win_eval (char* numbase);
void winner_case(bool&wingame, char* numbase);

int main(int argc, char** argv) {
  bool testmode = false;
  int test_mode_counter = 0;
  char numbase [] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int controlnum [] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int round_counter = 0;
  char player_num;
  bool exist;
  char fo;
  int fo_counter = 0;
  bool ai_perm = false;
  int ai_round_counter = 8;
  bool wingame = false;

do {
  fo_counter == 0 ? fo = 'f' : fo = 'o';
  fo_counter++;
  conv(fo, player_num);
  controlnum_arrfiller(char_to_num(player_num), controlnum, &round_counter, type_control(char_to_num(player_num), controlnum), numbase, player_num, ai_perm);
  cout << "My answer: " << endl;
  field_drawer(numbase);
  wingame = win_eval(numbase);
  winner_case(wingame, numbase);
  if(wingame == true) {
    break;
  }
  ai(numbase, ai_perm, controlnum, &ai_round_counter);
  cout << "The Computer's answer: " << endl;
  field_drawer(numbase);
  wingame = win_eval(numbase);
  winner_case(wingame, numbase);
  test(round_counter, controlnum, numbase, player_num, wingame, testmode, test_mode_counter);
  }
  while (wingame == false);
  return 0;
}

void conv(char&f_o_case, char&player_num) {
  switch(f_o_case) {
  case 'f':
    cout << "Hi! Please give me a number between 1-9 and press Enter: ";
    cin >> player_num;
    cout << endl;
    break;
  case 'o':
    cout << "Enter the next number: ";
    cin >> player_num;
    cout << endl;
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

void controlnum_arrfiller(int realnum, int* controlnum, int* round_counter, bool type_control_res, char* numbase, char&player_num, bool&ai_perm) {
  int round_counter_temp = *round_counter;
  if (type_control_res == false) {
    fill_cell(numbase, player_num);
    controlnum[*round_counter] = realnum;
    round_counter_temp++;
    *round_counter = round_counter_temp;
    ai_perm = true;
  }
  else {
    failuremess(player_num);
    controlnum_arrfiller(char_to_num(player_num), controlnum, round_counter, type_control(char_to_num(player_num), controlnum), numbase, player_num, ai_perm);
  }
};

bool type_control(int realnum, int* controlnum) {
  for(int i = 0; i < 9; i++) {
    if(controlnum[i] == realnum) {
      return true;
      break;
    }
  }
  return false;
};

void failuremess (char&player_num) {
  cout << endl << ">>FAIL<< You have already given this number!" << endl;
  cout << "Choise an other number: ";
  cin >> player_num;
  cout << endl;

};

char ai(char* numbase, bool ai_perm, int* controlnum, int* ai_round_counter) {
  int i;
  int aiconttemp = *ai_round_counter;
  for (i = 0; i < 9; i++) {
    if (ai_perm == true && numbase[i] != 'X' && numbase[i] != 'O') {
      break;
    }
  }
  numbase[i] = 'O';
  controlnum[aiconttemp] = i + 1;
  aiconttemp--;
  *ai_round_counter = aiconttemp;
};

bool win_eval (char* numbase) {
  for (int i = 0; i < 9; i++) {
    if (((numbase[i] == numbase[i + 3]) && (numbase[i] == numbase[i + 6])) || ((numbase[i] == numbase[i + 1]) && (numbase[i] == numbase[i + 2]))) {
      return true;
    }
    else if((numbase[0] == numbase[4]) && (numbase[0] == numbase[9]) || (numbase[2] == numbase[4]) && (numbase[2] == numbase[6])) {
      return true;
    }
  }
  return false;
};

void winner_case(bool&wingame, char* numbase) {
  int x_counter = 0;
  int o_counter = 0;
  if(wingame == true) {
    for (int i = 0; i < 9; i++) {
      if(numbase[i] == 'X') {
        x_counter++;
      }
      else if(numbase[i] == 'O') {
        o_counter++;
      }
    }
    system("color A1");
    x_counter > o_counter ? cout << "\n\n>>>You have won, congratulations!<<<\n\n" : cout << "\n\n>>>The Computer has won, the rise of machines has been begun...<<<\n\n";
  }
};

void test(int round_counter, int controlnum[], char numbase[], char player_num, bool wingame, bool&testmode, int&test_mode_counter) {
  char answer;
  if (test_mode_counter == 0) {
    test_mode_counter++;
    cout << "Would you like to run this game in test mode?(y/n) ";
    cin >> answer;
    switch(answer) {
      case 'y':
        testmode = true;
        break;
      case 'n':
        testmode = false;
        break;
      default:
        test_mode_counter = 0;
        cout << "\nPlease type only \"y\" or \"n\"! \n";
        test(round_counter, controlnum, numbase, player_num, wingame, testmode, test_mode_counter);
    }
  }
  if (testmode == true) {
    cout << "\n***********\t*<<TEST>>*\t***********\n" << "The wingame value is:\t\t" << wingame << endl;
    cout << "players number is:\t\t" << player_num;
    cout << "\nround counter value is:\t\t" << round_counter;
    cout << "\ncontrol numbers are:\t";
    for(int i = 0; i < 9; i++) {
      cout << controlnum [i] << " ";
    }
    cout << "\nnumbase numbers are:\t";
    for(int i = 0; i < 9; i++) {
      cout << numbase [i] << " ";
    }
    cout << "\n***********\t*<<TEST>>*\t***********\n" << endl;
  }
};
