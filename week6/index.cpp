#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *root = NULL;

Node *createNode(int data, Node *left, Node *right){
  Node *newNode = new Node;
  newNode->data = data;
  newNode->left = left;
  newNode->right = right;

  return newNode;
}

struct QueuedNode {
  Node *node;
  QueuedNode *next;
};

QueuedNode *front = NULL, *rear = NULL;

bool queueIsEmpty(){
  return front == NULL;
}

void enqueue(Node *node) {
  QueuedNode *queuedNode = new QueuedNode;
  queuedNode->node = node;
  queuedNode->next = NULL;

  if (!front){
    front = rear = queuedNode;
    return;
  }

  rear->next = queuedNode;
  rear = queuedNode;
}

Node *dequeue() {
  if (!front) {
    return NULL;
  }

  QueuedNode *tempFront = front;
  Node *node = front->node;

  front = front->next;

  if (!front) {
    rear = NULL;
  }

  delete tempFront;
  return node;
}

void insertNodeInBinaryTree(int data) {
  Node *newNode = createNode(data, NULL, NULL);

  if (!root) {
    root = newNode;
    return;
  }

  enqueue(root);
  while (!queueIsEmpty()) {
    Node *dequeuedNode = dequeue();
    
    if (!dequeuedNode->left) {
      dequeuedNode->left = newNode;
      break;
    } else {
      enqueue(dequeuedNode->left);
    }

    if (!dequeuedNode->right) {
      dequeuedNode->right = newNode;
      break;
    } else {
      enqueue(dequeuedNode->right);
    }
  }
}

void printNodeAndChildren(Node *node) {
  cout << "[" << node->data << "] ";
  if (node->left) {
    cout << "left: " << node->left->data;
  }
  else {
    cout << "leaf";
  }
  if (node->right) {
    cout << ", right: " << node->right->data << endl;
  }
  else
{
    cout << endl;
  }
}

void inOrderBinaryTreeTraversal(Node *root) {
  if (!root) return;

  inOrderBinaryTreeTraversal(root->left);
  printNodeAndChildren(root);
  inOrderBinaryTreeTraversal(root->right);
}

void preOrderBinaryTreeTraversal(Node *root) {
  if (!root) return;

  printNodeAndChildren(root);
  preOrderBinaryTreeTraversal(root->left);
  preOrderBinaryTreeTraversal(root->right);
}

void postOrderBinaryTreeTraversal(Node *root){
  if (!root) return;

  postOrderBinaryTreeTraversal(root->left);
  postOrderBinaryTreeTraversal(root->right);
  printNodeAndChildren(root);
}

int main() {
  insertNodeInBinaryTree(1);
  insertNodeInBinaryTree(2);
  insertNodeInBinaryTree(3);
  insertNodeInBinaryTree(4);
  insertNodeInBinaryTree(5);
  insertNodeInBinaryTree(6);
  insertNodeInBinaryTree(7);

  cout << "In-order traversal of the binary tree: " << endl;
  inOrderBinaryTreeTraversal(root);
  cout << endl;

  cout << endl;
  cout << "Pre-order traversal of the binary tree: " << endl;
  preOrderBinaryTreeTraversal(root);
  cout << endl;

  return 0;
}