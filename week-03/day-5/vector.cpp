#include <iostream>

using namespace std;

struct DoubleVector {
  int size = 0;
  double* data = NULL;
};

DoubleVector* vector_construct(double input[], int size) {
  DoubleVector* new_ptr =  new DoubleVector;
  new_ptr->data = new double[size];
  for (int i = 0; i < size; i++) {
    new_ptr->data[i] = input[i];
  }
  new_ptr->size = size;
  return new_ptr;
};

double vector_at(DoubleVector& v, unsigned int index) {
  return index > v.size ? 0 : v.data[index];
};

void vector_insert(DoubleVector& v, unsigned int index, double value) {
  v.size++;
  double* new_vector = new double[v.size];
  for (int i = 0; i < v.size; i++) {
   if (i < index) {
    new_vector[i] = v.data[i];
   }
   else if (i == index) {
    new_vector[i] = value;
   }
   else if (i > index && index < v.size) {
    new_vector[i] = v.data[i - 1];
   }
  }
  delete[] v.data;
  v.data = new_vector;
};

void vector_remove(DoubleVector& v, unsigned int index){
  v.size--;
  double* new_vector = new double[v.size];
  for (int i = 0; i < v.size; i++) {
    if (i < index) {
      new_vector[i] = v.data[i];
    }
    else if (i >= index) {
      new_vector[i] = v.data[i + 1];
    }
  }
  delete[] v.data;
  v.data = new_vector;
};

DoubleVector* vector_concat(DoubleVector& v1, DoubleVector v2) {
  DoubleVector* concat_vector_ptr = new DoubleVector;
  concat_vector_ptr->size = v1.size + v2.size;
  concat_vector_ptr->data = new double[concat_vector_ptr->size];
  for (int i = 0; i < concat_vector_ptr->size; i++) {
    if (i < v1.size) {
      concat_vector_ptr->data[i] = v1.data[i];
    }
    else if (i >= v1.size) {
      concat_vector_ptr->data[i] = v2.data[i - v1.size];
    }
  }
  return  concat_vector_ptr;
};

void print_vector(DoubleVector& input_vector) {
  cout << "\nThe vector size is: " << input_vector.size << endl;
  for (int i =0; i <  input_vector.size; i++) {
    cout << "Value on " << i << ". index is: " << input_vector.data[i] << endl;
  }
};

int main() {

  double arr[4] = {1, 2, 4, 5};
  double arr2[5] = {100, 200, 40, 51, 90.88};

  DoubleVector* vector1 = vector_construct(arr,  4);
  DoubleVector* vector2 = vector_construct(arr2,  5);

  vector_insert(*vector1, 2, 10);
  vector_insert(*vector1, 1, 0);
  vector_remove(*vector1, 3);

  DoubleVector* vector_1_and_2_concat = vector_concat(*vector1, *vector2);
  print_vector(*vector_1_and_2_concat);

  return 0;
}

/*Vector

Implement an array like data structure called DoubleVector, that behaves like an array but
it have some predefined operations in functions. It should store doubles.
It should have an inner array of doubles that stores the values.
Each vector should have size property that stores how many elements are in the stack.

Functions

Construct
Vector* vector_construct(double input[], int size);
It should dynamically allocate the Vector instance
It should set the size
It should dynamically allocate the double array

At
double vector_at(Vector& v, unsigned int index);
It should return the value inder the given index
It should return zero if the value is out of bound

Insert
void vector_insert(Vector& v, unsigned int index, double value);
It should insert the value to the given index like:
array: {1, 2, 3, 4}
index: 2
value: 8
result: {1, 2, 8, 3, 4}
It should increment the size by one
It should reallocate the array

Remove
void vector_remove(Vector& v, unsigned int index);
It should remove the element under the index
It should reallocate the array

Concat
Vector* vector_concat(Vector& v1, Vector v2);
It should return a new Vector that has all the elements of v1 and v2 like:
v1: {1, 2}
v2: {3, 4}
return: {1, 2, 3, 4}
It should have the sum size of the vectors*/
