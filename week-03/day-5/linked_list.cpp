#include <iostream>
using namespace std;

struct Node {
  double data;
  Node* next = NULL;
};

Node* list_construct_one(double value) {
  Node* new_node = new Node;
  new_node->data = value;
  new_node->next = NULL;
  return new_node;
};

unsigned int list_length(Node& head) {
  unsigned int length = 1;
  Node* temp = head.next;
  while (temp != NULL) {
    temp = temp->next;
    length++;
  }
  return length;
};

Node* list_get_last(Node& head) {
  Node* temp = head.next;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  return temp;
};

void list_print(Node& head) {
  cout << "your list: " ;
  Node* temp = &head;
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
};

int main() {
  Node* head = list_construct_one(1);
  Node* second = list_construct_one(2);
  head->next = second;
  Node* third = list_construct_one(9);
  second->next = third;

  double arr1[7] =  {1.1, 1.2, 2.5, 5.9, 1, 2, 3};

  list_print(*head);

  cout << list_length(*head);


  Node* last_node = list_get_last(*head);
  cout << endl << last_node->data;


  return 0;
}


/*
Linked list

Implement a linked list using structs that stores doubles A struct called Node
should represent one node in the list. The linked lists should stored by a pointer that points to it's head.

Construct One
Node* list_construct_one(double value);
It should set the next element to nullptr
It should set it's value

Length
unsigned int list_length(Node& head);
It should return the size of the list

Get Last
Node* list_get_last(Node& head);
It should return the last node

Append
void list_append(Node& head, double value);
It should append a new node to the end of the list with the given value

At
Node* list_at(Node& head, unsigned int index);
It should return the node with the given index counted from it's head

Insert
void list_insert(Node& head, unsigned int index, double value);
It should insert a node to the given index
Find

unsigned int list_find(Node& head, double value);
It should return the index of the given value

Remove
void list_remove(Node& head, double value);
It should remove the node with the given value

Concat
void list_concat(Node& head, Node& other_list);
It should concat the other list to the and of the list
*/
