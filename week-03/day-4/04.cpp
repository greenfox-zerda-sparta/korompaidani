#include <string>
#include <iostream>

using namespace std;

struct Pirate {
  string name;
  bool has_wooden_leg;
  short int gold_count;
};

int sum_gold(Pirate* pirates, int length);

float* counter_average_gold(Pirate* pirates, int length);

void print_bool(Pirate* p, float* inputarr, int length);

string richest_woody(Pirate* p, int length);

string find_the_richest_with_wooden_leg(Pirate* pirates, int length);

// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates

// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate

// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg

int main() {
  Pirate pirates[] = {
    {"Jack", false, 18},
    {"Uwe", true, 8},
    {"Hook", true, 12},
    {"Halloween kid", false, 0},
    {"Sea Wolf", true, 14},
    {"Morgan", false, 1}
  };

  cout << "The sum of gold is: " << sum_gold(pirates, 6) << endl;
  float* average_of_golds = counter_average_gold(pirates, 6);
  print_bool(pirates, average_of_golds, 6);
  cout << "\nThe richest guy is: " << richest_woody(pirates, 6);
  delete[] average_of_golds;
  cout << find_the_richest_with_wooden_leg(pirates, 6) << endl;

  return 0;
}

int sum_gold(Pirate* pirates, int length) {
  short int temp_gold_counter = 0;
  for(int i = 0; i < length; i++) {
    temp_gold_counter += pirates[i].gold_count;
  }
  return temp_gold_counter;
};

float* counter_average_gold(Pirate* pirates, int length) {
  float* averages = new float[length];
  for(int i = 0; i < length; i++) {
    averages[i] = ((float)sum_gold(pirates, length) / length) / pirates[i].gold_count;
  }
  return averages;
};

void print_bool(Pirate* p, float* inputarr, int length) {
  for(int i = 0; i < length; i++) {
    cout << p[i].name <<"'s gold aver. is:\t\t" << inputarr[i] << endl;
  }
};

string richest_woody(Pirate* p, int length) {
  string temp;
  int wood_leg_counter = 0;
  int richest_index;
  for(int i = 0; i < length; i++) {
    if(p[i].has_wooden_leg == true) {
      wood_leg_counter++;
    }
  }
  Pirate* tempirate = new Pirate[wood_leg_counter];
  wood_leg_counter = 0;
  for(int i = 0; i < length; i++) {
    if(p[i].has_wooden_leg == true) {
      tempirate[wood_leg_counter].gold_count = p[i].gold_count;
      tempirate[wood_leg_counter].name = p[i].name;
      wood_leg_counter++;
    }
  }
  for(int i = 0; i < wood_leg_counter; i++) {
    for(int j = i + 1; j < wood_leg_counter; j++){
      if(tempirate[i].gold_count > tempirate[j].gold_count) {
        richest_index = i;
        break;
      }
      else {
        richest_index = j;
        break;
      }
    }
  }
  return tempirate[richest_index].name;
  delete[] tempirate;
};

string find_the_richest_with_wooden_leg(Pirate* pirates, int length) {
  int golds = 0; //Pirate richet = {"", false, 0};
  string name = "";
  for (int i = 0; i < length; i++) {
    if (pirates[i].has_wooden_leg && pirates[i].gold_count > golds) {
      golds = pirates[i].gold_count;
      name = pirates[i].name;
    }
  }
  return name;
}
