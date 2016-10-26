#include <iostream>
using namespace std;

void safeUnion(int *a, int l_a, int *b, int l_b, int *result, int l_res) {
  // Implement this function to create the union of a and b into the array result!
  int end_a = 0;
  for (int i = 0; i < l_a; i++){
    result [i] = a [i];
    end_a = i;
  }
  for (int i = 0; i < l_b; i++){
    result [end_a + 1] = b [i];
    end_a++;
  }
}

int main(int argc, char** argv) {
	int a[3] = {1,2,3};
	int b[3] = {4,5,6};
	int c[6];
	safeUnion(a,3,b,3,c,6);
	for (int i = 0; i<6; i++) cout <<c[i] << endl;

}
