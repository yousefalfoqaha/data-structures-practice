#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node *previous;
};

Node *head = NULL;

Node *createNode(int data, Node *next, Node *previous) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = next;
  newNode->previous = previous;

  return newNode;
}

void insertNodeAtBeginning(int data) {
  Node *newNode = createNode(data, NULL, NULL);

  if(!head) {
    head = newNode;
    return;
  }

  newNode->next = head; // make new first node point at where head is pointing
  head->previous = newNode; //make former first node previous pointer point at new node
  head = newNode; // repoint head to new node
}

int main() {

  return 0;
}