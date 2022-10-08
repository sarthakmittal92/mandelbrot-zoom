// Used to store point-colour mapping

#include <vector>
using namespace std;

class Graph {

  // ---------------------------------------- VARIABLES --------------------------------------

  long long int n;
  long long int m;
  vector<long long int> *adj;

  // ---------------------------------------- FUNCTIONS --------------------------------------

  public:

    // constructor
    Graph (long long int vertices, long long int edges);

    // adding edges
    void addEdge (long long int u, long long int v);

    // traversals
    void bfsdfs (long long int s, bool choice);

    // bipartite check
    bool isBipartite(long long int v, bool visited[], bool color[]);

};