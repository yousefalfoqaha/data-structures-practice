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