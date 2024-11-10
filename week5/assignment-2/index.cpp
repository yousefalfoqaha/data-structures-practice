#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void printList(Node *head)
{
  Node *curr = head;
  while (curr->next != NULL)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }

  cout << curr->data << " ";
  cout << endl;
}

int size(Node *head)
{
  int count = 0;
  Node *curr = head;
  while (curr != NULL)
  {
    count++;
    curr = curr->next;
  }

  return count;
}

int searchList(Node *head, int value)
{
  int pos = 1;
  Node *curr = head;
  while (curr != NULL)
  {
    if (curr->data == value)
      return pos;
    pos++;
    curr = curr->next;
  }
  return -1;
}

Node *insertFirst(Node *head, int data)
{
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }

  return head;
}

Node *insertLast(Node *head, int data)
{
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    Node *curr = head;
    while (curr->next != NULL)
      curr = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
  }

  return head;
}

Node *insertAtPos(Node *head, int data, int pos)
{
  if (pos == 1)
  {
    head = insertFirst(head, data);
    return head;
  }
  else if (pos > size(head))
  {
    head = insertLast(head, data);
    return head;
  }
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  int curPos = 1;

  Node *curr = head;
  Node *prev = NULL;
  while (curPos != pos)
  {
    prev = curr;
    curr = curr->next;
    curPos++;
  }
  prev->next = newNode;
  newNode->prev = prev;
  newNode->next = curr;
  curr->prev = newNode;

  return head;
}

Node *deleteAtPos(Node *head, int pos)
{
  if (pos > size(head))
    return head; // do nothing
  Node *curr = head;
  int curPos = 1;
  if (head != NULL)
  {
    if (pos == 1)
    {
      head = curr->next;
      head->prev = NULL;
      delete curr;
    }
    else
    {
      Node *prev = NULL;
      while (curPos != pos)
      {
        prev = curr;
        curr = curr->next;
        curPos++;
      }
      prev->next = curr->next;
      if (curr->next != NULL)
        curr->next->prev = prev;
      delete curr;
    }
  }

  return head;
}

Node *createNode(int data, Node *next, Node *prev) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  return newNode;
}

void concatenate(Node *list1Head, Node *list2Head, Node *list3Head) {
  Node *list3Current = list1Head;
  
  while (list3Current) {
    Node *newList3Node = createNode(
      list3Current->data,
      list3Current->next,
      list3Current->prev
    );
    list3Current = list3Current->next;
  }

  list3Current->next = list2Head;

  while (list3Current) {
    Node *newList3Node = createNode(
      list3Current->data,
      list3Current->next,
      list3Current->prev
    );
    list3Current = list3Current->next;
  }
}

int main()
{
  Node *list1Head = NULL;
  Node *list2Head = NULL;
  Node *list3Head = NULL;

  list1Head = insertFirst(list1Head, 10);
  list1Head = insertFirst(list1Head, 15);
  list1Head = insertFirst(list1Head, 20);
  list1Head = insertFirst(list1Head, 13);

  list2Head = insertFirst(list2Head, 20);
  list2Head = insertFirst(list2Head, 15);
  list2Head = insertFirst(list2Head, 25);
  list2Head = insertLast(list2Head, 13);
  list2Head = insertLast(list2Head, 15);

  cout << "List 1: ";
  printList(list1Head);
  cout << "List 2: ";
  printList(list2Head);

  concatenate(list1Head, list2Head, list3Head);

  cout << "List 3: ";
  printList(list3Head);


  return 0;
}