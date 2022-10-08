#include "BST.h"
#include <iostream>
using namespace std;

// constructor
BST::BST () {
  root = NULL;
}

// ---------------------------------------- PRINTERS --------------------------------------

// print leaf
void BST::external (TraversalType_e tt, struct Node* myroot) {

  if (myroot == NULL) {
    return;
  }
  
  // print the complex number
  cout << myroot -> c.get()[0] << " + i" << myroot -> c.get()[1] << endl;

}

// printer for pre order
void BST::left (TraversalType_e tt, struct Node* myroot) {

  if (tt == PRE_ORDER) {
    external(tt,myroot);
  }

}

// printer for post order
void BST::right (TraversalType_e tt, struct Node* myroot) {

  if (tt == POST_ORDER) {
    external(tt,myroot);
  }

}

// printer for in order
void BST::below (TraversalType_e tt,struct Node* myroot) {

  if (tt == IN_ORDER) {
    external(tt,myroot);
  }

}

// ---------------------------------------- HELPERS --------------------------------------

// traversal for BST
void BST::traverse (TraversalType_e tt, struct Node* myroot) {

  if (myroot == NULL) {
    return;
  }

  // pre order
  if (tt == PRE_ORDER) {
    left(tt,myroot);
    traverse(tt,myroot -> left);
    traverse(tt,myroot -> right);
  }

  // post order
  else if (tt == IN_ORDER) {
    traverse(tt,myroot -> left);
    below(tt,myroot);
    traverse(tt,myroot -> right);
  }

  // in order
  else if (tt == POST_ORDER) {
    traverse(tt,myroot -> left);
    traverse(tt,myroot -> right);
    right(tt,myroot);
  }

}

// insert colour point pair
struct Node* BST::insert (int c, Complex d, struct Node* myroot) {

  if (myroot == NULL) {

    // new root
    struct Node* x = new struct Node;
    x -> c = d;
    x -> colour = c;
    x -> left = NULL;
    x -> right = NULL;
    x -> parent = NULL;
    root = x;
    return x;

  }

  // insertion as per colour
  if (c < myroot -> colour) {
    struct Node* x = insert(c,d,myroot -> left);
    myroot -> left = x;
    x -> parent = myroot;
  }

  else if (c > myroot -> colour) {
    struct Node* x = insert(c,d,myroot -> right);
    myroot -> right = x;
    x -> parent = myroot;
  }

  root = myroot;
  return myroot;

}