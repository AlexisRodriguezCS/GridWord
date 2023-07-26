/***************************************************************
 * Filename: TestingGridWorld.cpp
 * Purpose:  Test cases for the GridWorld class using Catch2 framework
 * Author:   Alexis Rodriguez
 ***************************************************************/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "GridWorld.h"

// Test cases for the GridWorld class
TEST_CASE("GridWorld class") {

  // Test case for the Constructor
  SECTION("Constructor") {
    GridWorld grid(3, 3);
    REQUIRE(grid.num_rows() == 3);
    REQUIRE(grid.num_cols() == 3);
    REQUIRE(grid.population() == 0);
  }

  // Test case for the Birth method
  SECTION("Birth") {
    GridWorld grid(3, 3);
    int idNum;
    REQUIRE(grid.birth(0, 0, idNum) == true);
    REQUIRE(grid.population() == 1);
    REQUIRE(idNum == 0);

    REQUIRE(grid.birth(1, 1, idNum) == true);
    REQUIRE(grid.population() == 2);
    REQUIRE(idNum == 1);

    // Invalid birth positions
    REQUIRE(grid.birth(-1, 1, idNum) == false);
    REQUIRE(grid.birth(4, 4, idNum) == false);
  }

  // Test case for the Death method
  SECTION("Death") {
    GridWorld grid(3, 3);
    int idNum;
    grid.birth(0, 0, idNum);
    grid.birth(1, 1, idNum);
    grid.birth(2, 2, idNum);

    REQUIRE(grid.death(0) == true);
    REQUIRE(grid.population() == 2);

    // Trying to kill a dead person
    REQUIRE(grid.death(0) == false);

    // Trying to kill a person with an invalid ID
    REQUIRE(grid.death(5) == false);
  }

  // Test case for the Whereis method
  SECTION("Whereis") {
    GridWorld grid(3, 3);
    int idNum;
    grid.birth(1, 2, idNum);

    int row, col;
    REQUIRE(grid.whereis(0, row, col) == false); // Invalid ID
    REQUIRE(grid.whereis(1, row, col) == true);
    REQUIRE(row == 1);
    REQUIRE(col == 2);
  }

  // Test case for the Move method
  SECTION("Move") {
    GridWorld grid(3, 3);
    int idNum;
    grid.birth(0, 0, idNum);

    REQUIRE(grid.move(0, 2, 2) == true);
    int row, col;
    REQUIRE(grid.whereis(0, row, col) == true);
    REQUIRE(row == 2);
    REQUIRE(col == 2);

    // Moving a dead person
    REQUIRE(grid.move(1, 1, 1) == false);

    // Moving to an invalid position
    REQUIRE(grid.move(0, -1, 1) == false);
    REQUIRE(grid.move(0, 4, 4) == false);
  }

  // Test case for the Members method
  SECTION("Members") {
    GridWorld grid(3, 3);
    int idNum;
    grid.birth(0, 0, idNum);

    std::vector<int> *members = grid.members(0, 0);
    REQUIRE(members->size() == 1);
    REQUIRE((*members)[0] == 0);
    delete members;

    members = grid.members(1, 1);
    REQUIRE(members->empty());
    delete members;

    members = grid.members(2, 2);
    REQUIRE(members->empty());
    delete members;

    members = grid.members(-1, 0);
    REQUIRE(members->empty());
    delete members;
  }

  // Test case for the Population method
  SECTION("Population") {
    GridWorld grid(3, 3);
    int idNum;
    grid.birth(0, 0, idNum);
    grid.birth(1, 1, idNum);
    grid.birth(2, 2, idNum);

    REQUIRE(grid.population() == 3);
    REQUIRE(grid.population(0, 0) == 1);
    REQUIRE(grid.population(1, 1) == 1);
    REQUIRE(grid.population(2, 2) == 1);
    REQUIRE(grid.population(-1, 0) == 0);
    REQUIRE(grid.population(3, 3) == 0);
  }
}
