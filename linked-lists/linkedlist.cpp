#include "iostream"
#include <ostream>

class Node {
public:
  int data;
  Node *next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class LinkedList {
public:
  Node *head;

  LinkedList() { head = nullptr; }

  ~LinkedList() {
    Node *temp = head;

    while (temp != nullptr) {
      Node *next = temp->next;
      delete temp;
      temp = next;
    }
  }

  void printLinkedList() {
    Node *temp = head;

    while (temp != nullptr) {
      std::cout << temp->data << std::endl;
      temp = temp->next; // o temp vai ser igual ao proximo Node.
    }
  }

  void insertAtPosition(int value, int pos) {
    if (pos < 0) {
      std::cout << "posicao nao permitida!" << std::endl;
      return;
    }

    if (pos == 0) {
      insertAtHead(value);
      return;
    }

    Node *newNode = new Node(value);
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }
    Node *targetValue = temp->next;
    temp->next = newNode;
    newNode->next = targetValue;
  }

  void insertAtTail(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = newNode;
      return;
    }

    Node *temp = head;

    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void insertAtHead(int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  void deleteHead() { delete head; }

  void deleteTail() {
    Node *temp = head;

    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }
};

int main() {
  LinkedList list;

  int x, y, z;

  x = 10;
  y = 5;
  z = 2;

  list.insertAtTail(x);
  list.insertAtTail(y);
  list.insertAtTail(z);
  list.printLinkedList();

  std::cout << "\n";

  int newHead = 50;

  list.insertAtHead(newHead);
  list.printLinkedList();

  std::cout << "\n";

  int newNodeAtPosition = 75;

  list.insertAtPosition(newNodeAtPosition, 2);
  list.printLinkedList();

  std::cout << "\n";

  list.deleteTail();
  list.printLinkedList();
}