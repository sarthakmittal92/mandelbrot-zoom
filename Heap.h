// Used for storing and sorting ratios for zoom point

class Heap {

  // ---------------------------------------- VARIABLES --------------------------------------

  double* H;
  int maxSize;
  int n;

  // ---------------------------------------- FUNCTIONS --------------------------------------
  
  public:

    // constructor
    Heap (int capacity);

    // parent index
    int parent (int i);

    // left child index
    int left (int i);

    // right child index
    int right (int i);

    // insert element
    void insert (double e);

    // minimum element
    double min ();

    // heapify
    void Heapify (int root);

    // delete minimum
    void deleteMin ();

};