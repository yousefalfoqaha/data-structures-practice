void insertNodeAtPosition(int data, int position) {
  if (!head || position == 1) { insertNodeAtBeginning(data); return; }
  if (position > size(head)) { insertNodeAtEnd(data); return; }

  Node *current = head;
  int count = 1;
  while (current) {
    Node *previous = current->next;
    if (count == position) {
      Node *newNode = createNode(data, previous);
      previous->next = newNode;
      return;
    }
    current = current->next;
    count++;
  }
  cout << "Position cannot be undefined, 0, or negative." << endl;
}