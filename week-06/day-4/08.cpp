#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string greenfox = "GREENFOX";
  vector<char> v(8);
  for (unsigned int i = 0; i < v.size(); i++) {
    cout << "Please type the " << i + 1 << ". char: ";
    cin >> v[i];
    do {
      if (v[i] != greenfox[i]) {
        cout << "The correct answer is: " << greenfox[i] << "!" << endl;
        cin >> v[i];
      }
    }
    while (v[i] != greenfox[i]);
  }

	//create a vector of characters with the size of 8
	//ask the user to fill this vector with characters one by one
	//at the end make sure the vector holds the letters of "GREENFOX"
	//so correct the user if he/she gives a different letter from the one we want them to give :)

  return 0;
}
