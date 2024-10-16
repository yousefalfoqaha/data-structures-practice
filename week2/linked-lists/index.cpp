#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};
Node *head = NULL;

int size(Node *head) {
  int count = 0;
  Node *current = head;
  while (current) {
    count++;
    current = current->next;
  }

  return count;
}

Node *createNode(int data, Node *next) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = next;

  return newNode;
}

void insertNodeAtBeginning(int data) {
  Node *newNode = createNode(data, head);
  head = newNode;
}

void insertNodeAtEnd(int data) {
  if (!head) {
   insertNodeAtBeginning(data); 
   return;
  }

  Node *current = head;
  while (current->next != NULL) {
    current = current -> next;
  }

  Node *newNode = createNode(data, NULL);
  current->next = newNode;
}

void insertNodeAtPosition(int data, int position) {
  if (!head || position == 1) {
    insertNodeAtBeginning(data);
    return;
  }

  if (position >= size(head)) {
    insertNodeAtEnd(data);
    return;
  }

  if (!head || position == 1) { 
    insertNodeAtBeginning(data); return; 
  }

  Node *current = head;
  int count = 1;
  while (count < position - 1 && current) {
    current = current->next;
    count++;
  }
  Node *newNode = createNode(data, current->next);
  current->next = newNode;
}

void printLinkedList(Node *head) {
  int count = 1;
  Node *current = head;
  while (current) {
    cout << count << ": " << current->data << endl;
    current = current->next;
    count++;
  }
}


int main() {
  insertNodeAtBeginning(32);
  insertNodeAtBeginning(69);
  insertNodeAtBeginning(12);
  insertNodeAtEnd(100);
  insertNodeAtEnd(140);
  insertNodeAtPosition(50, 6);

  printLinkedList(head);

  return 0;
}