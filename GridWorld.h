
#ifndef _GRID_WORLD_H
#define _GRID_WORLD_H

#include "DoublyLinkedList.h"
#include <iostream>
#include <vector>
using std::vector;
using namespace std;

class GridWorld {

private:
  // private stuff goes here!
  //   typedefs
  //   data members
  //   private helper functions
  //   etc.
  vector<vector<District>> Grid;
  int gridPopulation;
  int nRows;
  int nCols;
  int idCounter;
  vector<Person> ID;
  DoublyLinkedList Dead;

public:
  
  /**
   * constructor:  initializes a "world" with nrows and
   *    ncols (nrows*ncols districtcs) in which all
   *    districtricts are empty (a wasteland!).
   */
  GridWorld(unsigned nrows, unsigned ncols) {
    // your constructor code here!
    vector<District> singleRow(ncols, District());
    vector<vector<District>> temp(nrows, singleRow);
    Grid = temp;  
    gridPopulation = 0;
    idCounter = 0;
    nRows = nrows;
    nCols = ncols;
    Dead = DoublyLinkedList();
  }

  ~GridWorld() {
    // your destructor code here.
    // Sets all the ID pointers to null and deletes them
    for (int i = 0; i < ID.size(); i++) {
      ID.at(i).setNullAndDelete();
    }
    // Go through every district and delete the DoublyLinkedList
    for (int i = 0; i < Grid.size(); i++) {
      for (int j = 0; j < Grid[i].size(); j++) {
        Grid[i][j].List.deleteAllNodes();
      }
    }
    // Deletes the dead DoublyLinkedList
    Dead.deleteAllNodes();
  }

  /*
   * function: birth
   * description:  if row/col is valid, a new person is created
   *   with an ID according to rules in handout.  New person is
   *   placed in district (row, col)
   *
   * return:  indicates success/failure
   */
  bool birth(int row, int col, int &idNum) {
    if(row < 0 || row > nRows || col < 0 || col > nCols){
      return false; 
    } 
    // Checks if there's any dead people( get one of ther ids )
    if (Dead.isEmpty()) {
      // No dead people just use the idCounter
      idNum = idCounter;
      idCounter++;
      Person newPerson(idNum, row, col);
      ID.push_back(newPerson);
    } else {
      // Get the front value(id) of Dead list and set the id to that
      idNum = Dead.getRootValue();
      // Then delete the front value since the id is no longer dead
      Dead.deleteFirstNode();
      // Update location of reused ID
      ID.at(idNum).x = row;
      ID.at(idNum).y = col;
    }
    // Pointer to the node in District Doubly Linked List
    Node* newNode = new Node(idNum);
    ID.at(idNum).pointer = newNode;
    ID.at(idNum).alive = true;
    gridPopulation++;
    Grid[row][col].population += 1;
    Grid[row][col].List.appendNode(newNode);
    return true;
  }

  /*
   * function: death
   * description:  if given person is alive, person is killed and
   *   data structures updated to reflect this change.
   *
   * return:  indicates success/failure
   */
  bool death(int personID) {
    // Checks if person is alive or id is out of bounds.
    // For example if only 3 people have been born then ID 200928 is out of bounds
    if (ID.at(personID).alive == false || personID > idCounter) {
     return false;
    }
    // If the person is alive 
    int xAxis = ID.at(personID).x;
    int yAxis = ID.at(personID).y;
    // Subtract District's population
    Grid[xAxis][yAxis].population--;
    gridPopulation--;
    // Delete the node in the District's Doubly Linked List
    Grid[xAxis][yAxis].List.deleteNode(ID.at(personID).pointer);
    ID.at(personID).alive = false;
    ID.at(personID).pointer = nullptr;
    // Add to Dead Linked List
    Dead.append(personID);
    return true;
  }

  /*
   * function: whereis
   * description:  if given person is alive, his/her current residence
   *   is reported via reference parameters row and col.
   *
   * return:  indicates success/failure
   */
  bool whereis(int id, int &row, int &col) const {
    // Checks if person is alive or id is out of bounds.
    // For example if only 3 people have been born then ID 200928 is out of bounds
    if (ID.at(id).alive == false || id > idCounter) {
     return false;
    }
    row = ID.at(id).x;
    col = ID.at(id).y;
    return true;
  }

  /*
   * function: move
   * description:  if given person is alive, and specified target-row
   *   and column are valid, person is moved to specified district and
   *   data structures updated accordingly.
   *
   * return:  indicates success/failure
   *
   * comment/note:  the specified person becomes the 'newest' member
   *   of target district (least seniority) --  see requirements of members().
   */
  bool move(int id, int targetRow, int targetCol) {
    // Checking if person is alive
    if (ID.at(id).alive == false) {
     return false;
    }
    // Checking for out of bounds
    if (targetRow < 0 || targetCol < 0 || targetRow >= nRows || targetCol >= nCols) {
      return false;
    }
    // Delete them from the old District Doubly Linked List
    int oldX = ID.at(id).x;
    int oldY = ID.at(id).y;
    Grid[oldX][oldY].List.deleteNode(ID.at(id).pointer);
    Grid[oldX][oldY].population--;
    // Set the Person's x, y to the new District x, y 
    Node* newNode = new Node(id);
    ID.at(id).pointer = newNode;
    ID.at(id).x = targetRow;
    ID.at(id).y = targetCol;
    //Add them no the new District LinkedList
    Grid[targetRow][targetCol].List.appendNode(newNode);
    Grid[targetRow][targetCol].population++;
    return true; 
    }

  /*
   * function: members
   * description:  creates and populates an integer vector with a
   *   snapshot of the current residents of a district specified by
   *   the parameters row and col.  The vector musted by ordered in
   *   descending order of seniority (the person who has lived in the
   *   district the longest must be first).
   *
   *
   * return:  a pointer to the vector created
   *
   * comment/note:  If there is no such district (row, col), a vector is
   *   still created and returned, but it is empty.  An empty vector is
   *   also returned if there is no one living the in specified vector.
   */
  std::vector<int> *members(int row, int col) const {
    vector<int> * empty;
    if (row < 0 || col < 0 || row >= nRows || col >= nCols) {
      // If there is no such district
      return empty;
    }
    return Grid[row][col].List.getVector();
  }

  /*
   * function: population
   * description:  returns the current (living) population of the world.
   */
  int population() const { 
    return gridPopulation; 
    }

  /*
   * function: population(int,int)
   * description:  returns the current (living) population of specified
   *   district.  If district does not exist, zero is returned
   */
  int population(int row, int col) const {
    // Checking for out of bounds
    if (row < 0 || col < 0 || row >= nRows || col >= nCols) {
      return 0;
    }
    return Grid[row][col].population;
  }

  /*
   * function: num_rows
   * description:  returns number of rows in world
   */
  int num_rows() const { return nRows; }

  /*
   * function: num_cols
   * description:  returns number of columns in world
   */
  int num_cols() const { return nCols; }
};

#endif
