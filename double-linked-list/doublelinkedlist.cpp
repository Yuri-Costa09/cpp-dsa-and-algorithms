#include "iostream"
#include <ostream>

class Node {
public:
  int data;
  Node *prev;
  Node *next;

  Node(int value) {
    data = value;
    prev = nullptr;
    next = nullptr;
  }
};

class LinkedList {
public:
  Node *head;
  Node *tail;

  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

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

    if (tail == nullptr) {
      head = newNode;
      tail = newNode;
      return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  void insertAtHead(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = newNode;
      tail = newNode;
      return;
    }

    if (head->next == nullptr) {
      newNode->next = head;
      head->prev = newNode;
      head = tail;
      head = newNode;
      return;
    }
  }

  void deleteHead() {
    Node *nextNode = head->next;
    nextNode->prev = nullptr;
    delete head;
    head = nextNode;
  }

  void deleteTail() {
    if (tail == nullptr) {
      std::cout << "There's no elements in this list." << std::endl;
      return;
    }

    tail->prev = nullptr;
    delete tail;
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