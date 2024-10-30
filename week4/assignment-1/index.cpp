#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;


int searchList(int value) {
  int pos = 0;
  Node *curr = head;
  while (curr != NULL) {
    pos++;
    if (curr->data == value)
      return pos;
    curr = curr->next;
  }

  return -1;
}

int size() {
  int count = 0;
  Node *curr = head;
  while (curr != NULL) {
    count++;
    curr = curr->next;
  }

  return count;
}

void insertFirst(int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

void insertLast(int data) {

  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node *curr = head;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = newNode;
  }
}

void insertAtPos(int data, int pos) {
  if (pos == 1) {
    insertFirst(data);
    return;
  } else if (pos > size()) {
    insertLast(data);
    return;
  }

  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;

  int curPos = 1;
  Node *curr = head;
  Node *prev = NULL;
  while (curPos != pos) {
    prev = curr;
    curr = curr->next;
    curPos++;
  }
  prev->next = newNode;
  newNode->next = curr;
}

void deleteAtPos(int pos) {
  if (pos > size()) {
    // do nothing
    return;
  }

  Node *curr = head;
  int curPos = 1;
  if (head != NULL) {
    if (pos == 1) {
      head = curr->next;
      delete curr;
    } else {
      Node *prev = NULL;
      while (curPos != pos) {
        prev = curr;
        curr = curr->next;
        curPos++;
      }

      prev->next = curr->next;
      delete curr;
    }
  }
}

int findMin() {
  int min = head -> data;

  Node *curr = head;
  while (curr) {
    if (curr->data < min) {
      min = curr->data;
    }
    curr = curr->next;
  }

  return min;
}

void sortAscending()
{
  Node *i, *j;

  for (i = head; i; i = i->next) {
    for (j = i->next; j; j = j->next) {
      if (j->data < i->data) {
        int temp = i->data;
        i->data = j->data;
        j->data = temp;
      }
    }
  }
}

void printList() {
  Node *curr = head;
  while (curr != NULL) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main() {

  insertFirst(10);
  insertFirst(15);
  insertFirst(20);
  insertFirst(25);
  insertLast(50);
  insertLast(13);
  insertAtPos(17, 3);

  printList();
  cout << findMin() << endl;

  sortAscending();
  printList();

  return 0;
}