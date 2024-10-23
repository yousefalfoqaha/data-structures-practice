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

void insertNodeAtEnd(int data) {
  if(!head) {
    insertNodeAtBeginning(data);
    return;
  }

  Node *current = head;
  while (current) {
    if (!current->next) {
      Node *newNode = createNode(data, NULL, current);
      current->next = newNode;
      return;
    }
    current = current->next;
  }
}

void printLinkedList() {
  Node *current = head;

  int position = 1;
  while(current) {
    cout << position << ": " << current->data << endl;
    current = current->next;
    position++;
  }
}

int main() {

  insertNodeAtBeginning(3);
  insertNodeAtBeginning(2);
  insertNodeAtBeginning(1);
  insertNodeAtEnd(4);
  printLinkedList();
  return 0;
}