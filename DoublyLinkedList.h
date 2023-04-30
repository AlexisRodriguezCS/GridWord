#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node() {
    this->next = nullptr;
    this->prev = nullptr;
  }

  Node(int data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;

public:
  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }
  Node* getHead(){
    if(head==nullptr){
      return nullptr;
    }
    return head;
  }
  // returns the contents of the list as a vector starting from the head
  vector<int>* getVector() const {
    vector<int>* returnVector = new vector<int>();
    Node* curr = head;
    while(curr != nullptr){
      returnVector->push_back(curr->data);
      curr = curr->next;
    }
    return returnVector;
  }

  // Checks if the DoublyLinkedList is empty
  bool isEmpty(){
    return(head == nullptr && tail == nullptr);
  }

  // Clean up DoublyLinkedList
  void deleteAllNodes() {
    if (head != nullptr) {
      Node *curr = head;
      Node *next = nullptr;

      while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
      }
      head = nullptr;
      tail = nullptr;
    }
  }

  // Adds data to either the front or tail
  void append(int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  void appendNode(Node* newNode){
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  // Deletes the first node
  void deleteFirstNode() {
    if (head == nullptr) {
      return;
    }
    if (head == tail) {
      delete head;
      head = nullptr;
      tail = nullptr;
      return;
    }
    Node *temp = head->next;
    temp->prev = nullptr;
    delete head;
    head = temp;
  }

  // Deletes the last node
  void deleteLastNode() {
    if (head == nullptr) {
      return;
    }
    if (head == tail) {
      delete head;
      head = nullptr;
      tail = nullptr;
      return;
    }
    Node *temp = tail->prev;
    temp->next = nullptr;
    delete tail;
    tail = temp;
  }

  // Deletes a node my passing a pointer
  void deleteNode(Node *node) {
    if (head == node) {
      deleteFirstNode();
      return;
    }
    if (tail == node) {
      deleteLastNode();
      return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
  }

  // Gets the root value
  int getRootValue() {
    if (head == nullptr) {
      return -1;
    }
    return head->data;
  }

  // Debugging purposes
  void printList() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

struct District {
  // Population in *this* district
  int population;
  // Will hold & keep track of seniority of IDS(people in district)
  DoublyLinkedList List;
  // Constructor for District
  District() {
    population = 0;
    List = DoublyLinkedList();
  }
};

struct Person {
  int id;
  int x;
  int y;
  Node *pointer;
  bool alive;
  // Constructor for Person
  Person(int idNumber, int xAxis, int yAxis) {
    id = idNumber;
    alive = true;
    x = xAxis;
    y = yAxis;
  }
  void setNullAndDelete() {
    pointer = nullptr;
    delete pointer;
  }
};

#endif