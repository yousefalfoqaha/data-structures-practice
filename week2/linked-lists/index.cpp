#include<stdio.h>
#include<iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};
Node *head = NULL;

Node* createNode(int data, Node *next) {
  Node *newNode = new Node;
  newNode->data = data; 
  newNode->next = next; 

  return newNode;
}

void insertNodeAtBeginning(int data) {
  Node *newNode = createNode(3, head);
  head = newNode;
}

int nodeCount(Node *head) {
    int count = 0;
    Node *current = head;
    
    while (current) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
  insertNodeAtBeginning(3);
  insertNodeAtBeginning(69);

  cout << nodeCount(head) << endl;
  return 0;
}