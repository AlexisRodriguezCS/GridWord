/***************************************************************
 * File: TestingDoublyLinkedList.cpp
 * Purpose: Contains test cases for the DoublyLinkedList class and related structs.
 * Author: Alexis Rodriguez
 ***************************************************************/

// Include statements
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "DoublyLinkedList.h"

TEST_CASE("Node class") {
  SECTION("Default constructor sets next and prev to nullptr") {
    Node node;
    REQUIRE(node.next == nullptr);
    REQUIRE(node.prev == nullptr);
  }

  SECTION("Constructor sets data, next, and prev") {
    Node node(10);
    REQUIRE(node.data == 10);
    REQUIRE(node.next == nullptr);
    REQUIRE(node.prev == nullptr);
  }
}

TEST_CASE("DoublyLinkedList class") {
  DoublyLinkedList list;

  SECTION("getHead returns nullptr for an empty list") {
    REQUIRE(list.getHead() == nullptr);
  }

  SECTION("getVector returns vector representation of the list") {
    list.append(10);
    list.append(20);
    list.append(30);
    vector<int>* vec = list.getVector();
    REQUIRE(vec->size() == 3);
    REQUIRE((*vec)[0] == 10);
    REQUIRE((*vec)[1] == 20);
    REQUIRE((*vec)[2] == 30);
    delete vec;
  }

  SECTION("isEmpty returns true for an empty list") {
    REQUIRE(list.isEmpty() == true);
  }

  SECTION("isEmpty returns false for a non-empty list") {
    list.append(10);
    REQUIRE(list.isEmpty() == false);
  }

  SECTION("deleteAllNodes deletes all nodes in the list") {
    list.append(10);
    list.append(20);
    list.append(30);
    list.deleteAllNodes();
    REQUIRE(list.isEmpty() == true);
  }

  SECTION("append adds data to the tail of the list") {
    list.append(10);
    REQUIRE(list.getHead()->data == 10);
    REQUIRE(list.getHead()->next == nullptr);
    REQUIRE(list.getHead()->prev == nullptr);

    list.append(20);
    REQUIRE(list.getHead()->data == 10);
    REQUIRE(list.getHead()->next->data == 20);
    REQUIRE(list.getHead()->next->prev->data == 10);
    REQUIRE(list.getHead()->next->next == nullptr);

    list.append(30);
    REQUIRE(list.getHead()->data == 10);
    REQUIRE(list.getHead()->next->data == 20);
    REQUIRE(list.getHead()->next->prev->data == 10);
    REQUIRE(list.getHead()->next->next->data == 30);
    REQUIRE(list.getHead()->next->next->prev->data == 20);
    REQUIRE(list.getHead()->next->next->next == nullptr);
  }

  SECTION("appendNode adds a node to the tail of the list") {
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);

    list.appendNode(node1);
    REQUIRE(list.getHead()->data == 10);
    REQUIRE(list.getHead()->next == nullptr);
    REQUIRE(list.getHead()->prev == nullptr);

    list.appendNode(node2);
    REQUIRE(list.getHead()->data == 10);
    REQUIRE(list.getHead()->next->data == 20);
    REQUIRE(list.getHead()->next->prev->data == 10);
    REQUIRE(list.getHead()->next->next == nullptr);

    list.appendNode(node3);
    REQUIRE(list.getHead()->data == 10);
    REQUIRE(list.getHead()->next->data == 20);
    REQUIRE(list.getHead()->next->prev->data == 10);
    REQUIRE(list.getHead()->next->next->data == 30);
    REQUIRE(list.getHead()->next->next->prev->data == 20);
    REQUIRE(list.getHead()->next->next->next == nullptr);
  }

  SECTION("deleteFirstNode deletes the first node in the list") {
    list.append(10);
    list.append(20);
    list.append(30);

    list.deleteFirstNode();
    REQUIRE(list.getHead()->data == 20);
    REQUIRE(list.getHead()->next->data == 30);
    REQUIRE(list.getHead()->next->prev->data == 20);
    REQUIRE(list.getHead()->next->next == nullptr);
  }

  SECTION("deleteLastNode deletes the last node in the list") {
    list.append(10);
    list.append(20);
    list.append(30);

    list.deleteLastNode();
    REQUIRE(list.getHead()->data == 10);
    REQUIRE(list.getHead()->next->data == 20);
    REQUIRE(list.getHead()->next->prev->data == 10);
    REQUIRE(list.getHead()->next->next == nullptr);
  }

  SECTION("deleteNode deletes the specified node from the list") {
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);

    list.appendNode(node1);
    list.appendNode(node2);
    list.appendNode(node3);

    list.deleteNode(node2);
    REQUIRE(list.getHead()->data == 10);
    REQUIRE(list.getHead()->next->data == 30);
    REQUIRE(list.getHead()->next->prev->data == 10);
    REQUIRE(list.getHead()->next->next == nullptr);
  }

  SECTION("getRootValue returns the value of the head node") {
    list.append(10);
    list.append(20);
    list.append(30);
    REQUIRE(list.getRootValue() == 10);
  }

  SECTION("printList prints the contents of the list") {
    list.append(10);
    list.append(20);
    list.append(30);
    // Test the output of printList using Catch's capture output
    Catch::StringMaker<std::ostream&>::run(list.printList());
  }
}

TEST_CASE("District struct") {
  SECTION("Constructor initializes population and List") {
    District district;
    REQUIRE(district.population == 0);
    REQUIRE(district.List.isEmpty() == true);
  }
}

TEST_CASE("Person struct") {
  SECTION("Constructor initializes id, alive, x, and y") {
    Person person(1, 10, 20);
    REQUIRE(person.id == 1);
    REQUIRE(person.alive == true);
    REQUIRE(person.x == 10);
    REQUIRE(person.y == 20);
  }

  SECTION("setNullAndDelete sets pointer to nullptr and deletes it") {
    Person person(1, 10, 20);
    person.setNullAndDelete();
    REQUIRE(person.pointer == nullptr);
  }
}
