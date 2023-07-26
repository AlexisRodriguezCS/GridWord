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
        Node node; // Create a Node object using the default constructor
        REQUIRE(node.next == nullptr); // Check if 'next' pointer is nullptr
        REQUIRE(node.prev == nullptr); // Check if 'prev' pointer is nullptr
    }

    SECTION("Constructor sets data, next, and prev") {
        Node node(10); // Create a Node object using the parameterized constructor with data = 10
        REQUIRE(node.data == 10); // Check if 'data' member is set to 10
        REQUIRE(node.next == nullptr); // Check if 'next' pointer is nullptr
        REQUIRE(node.prev == nullptr); // Check if 'prev' pointer is nullptr
    }
}

TEST_CASE("DoublyLinkedList class") {
    DoublyLinkedList list; // Create a DoublyLinkedList object

    SECTION("getHead returns nullptr for an empty list") {
        REQUIRE(list.getHead() == nullptr); // Check if 'getHead' returns nullptr for an empty list
    }

    SECTION("getVector returns vector representation of the list") {
        list.append(10); // Append data 10 to the list
        list.append(20); // Append data 20 to the list
        list.append(30); // Append data 30 to the list
        vector<int>* vec = list.getVector(); // Get a vector representation of the list
        REQUIRE(vec->size() == 3); // Check if the size of the vector is 3
        REQUIRE((*vec)[0] == 10); // Check if the first element of the vector is 10
        REQUIRE((*vec)[1] == 20); // Check if the second element of the vector is 20
        REQUIRE((*vec)[2] == 30); // Check if the third element of the vector is 30
        delete vec; // Free the memory occupied by the vector
    }

    // More test cases for the DoublyLinkedList class...

}

TEST_CASE("District struct") {
    SECTION("Constructor initializes population and List") {
        District district; // Create a District object using the default constructor
        REQUIRE(district.population == 0); // Check if 'population' is initialized to 0
        REQUIRE(district.List.isEmpty() == true); // Check if 'List' is an empty DoublyLinkedList
    }
}

TEST_CASE("Person struct") {
    SECTION("Constructor initializes id, alive, x, and y") {
        Person person(1, 10, 20); // Create a Person object using the parameterized constructor
        REQUIRE(person.id == 1); // Check if 'id' member is set to 1
        REQUIRE(person.alive == true); // Check if 'alive' member is set to true
        REQUIRE(person.x == 10); // Check if 'x' member is set to 10
        REQUIRE(person.y == 20); // Check if 'y' member is set to 20
    }

    SECTION("setNullAndDelete sets pointer to nullptr and deletes it") {
        Person person(1, 10, 20); // Create a Person object using the parameterized constructor
        person.setNullAndDelete(); // Call the 'setNullAndDelete' method on the Person object
        REQUIRE(person.pointer == nullptr); // Check if the 'pointer' member is set to nullptr
    }
}
