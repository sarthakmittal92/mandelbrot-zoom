// Used for storing colour - point mapping

#include "Complex.h"

// node for tree
struct Node {

  Complex c;
  int colour;
  Node* left;
  Node* right;
  Node* parent;

};

// traversals
enum TraversalType_e { PRE_ORDER, IN_ORDER, POST_ORDER };

class BST {

  public:

    // constructor
    BST ();

    // root
    struct Node* root;

    // printers
    void external (TraversalType_e tt, struct Node* myroot);
    void left (TraversalType_e tt, struct Node* myroot);
    void below (TraversalType_e tt, struct Node* myroot);
    void right (TraversalType_e tt, struct Node* myroot);

    // traversal
    void traverse (TraversalType_e tt, struct Node* myroot);

    // insertion
    struct Node* insert (int c, Complex d, struct Node* myroot);

};