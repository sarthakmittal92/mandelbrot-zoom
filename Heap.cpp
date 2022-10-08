#include "Heap.h"

// in-place swapper
void swap (double &x, double &y) {

  double temp = x;
  x = y;
  y = temp;

}

// constructor
Heap::Heap (int capacity) {

  maxSize = capacity;
  n = 0;
  H = new double[maxSize];

}

// parent index
int Heap::parent (int i) {

  return (i - 1) / 2;

}

// left child
int Heap::left (int i) {

  return 2 * i + 1;

}

// right child
int Heap::right (int i) {

  return 2 * (i + 1);

}

// insertion
void Heap::insert (double e) {

  if (n != maxSize) {

    H[n] = e;
    int i = n;
    n++;

    while (i != 0 && H[parent(i)] > H[i]) {

      swap(H[i],H[parent(i)]);
      i = parent(i);

    }

  }

}

// find minimum
double Heap::min () {

  if (n != 0) {
   return H[0];
  }
  return -1;

}

// heapify
void Heap::Heapify (int root) {

  int l = left(root);
  int r = right(root);
  int s = root;

  if (l < n && H[l] < H[root]) {
    s = l;
  }

  if (r < n && H[r] < H[s]) {
    s = r;
  }

  if (s != root) {
    swap(H[root],H[s]);
    Heapify(s);
  }

}

// delete minimum
void Heap::deleteMin () {

  if (n > 0) {

    if (n == 1) {
      H = new double[maxSize];
      n = 0;
    }

    else {
      n--;
      H[0] = H[n];
      Heapify(0);
    }

  }

}