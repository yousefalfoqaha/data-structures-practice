#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};
Node *front, *rear = NULL;

Node *createNode(int data, Node *next) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = next;

  return newNode;
}

void enqueue(int data) {
  Node *newNode = createNode(data, NULL);

  if (!front) {
    front = newNode;
    rear = newNode;
    return;
  }

  rear->next = newNode;
  rear = newNode;
}

int dequeue() {
  Node *temp = front;
  int dequeuedData = front->data;
  front = front->next;

  if (!front) {
    rear = NULL;
  }

  delete temp;

  return dequeuedData;
}

int peek() {
  return front->data;
}

void printQueue() {
  Node *current = front;

  while (current) {
    cout << current->data << " ";
    current = current->next;
  }
}

int main(){
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  enqueue(6);

  dequeue();
  dequeue();

  printQueue();

  return 0;
}