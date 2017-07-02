#include <iostream>
#include <vector>

# include "utils.hpp"

/*****************************************/
class Vertex {
public:
  long long height, excessFlow;

  Vertex (long long h, long long eFlow) {
    this->height = h; this->excessFlow = eFlow;
  };
  virtual ~Vertex (){};
};

class Edge {
public:
  long long flow, capacity;
  long long u, v;

  Edge (long long u, long long v, long long flow, long long capacity) {
    this->flow = flow; this->capacity = capacity;
    this->u = u; this->v = v;
  };
  virtual ~Edge (){};
};

/*****************************************/

class Graph {
private:
  long long n; // |V|
  long long source, sink; // source and sink
  std::vector<Edge> edges;
  std::vector<Vertex> vertexs;

  void initialize_preflow(long long index_source);
  bool push(long long vertex_index_u);
  bool relabel(long long vertex_index_u);

public:
  Graph (long long n) {
    this->n = n;
    vertexs.resize(n, {0, 0});
  };
  virtual ~Graph (){
    std::cout << "Bye Graph" << '\n';
  };

  bool addEdge(long long u, long long v, long long capacity);
  long long pushRelabel(long long source, long long sink);
};

/*****************************************/
// Graph

bool Graph::addEdge(long long u, long long v, long long capacity){
  if (u >= n || v >= n || u < 0 || v < 0) return false;
  edges.push_back(Edge(u, v, 0, capacity));
  return true;
};

void Graph::initialize_preflow(long long s) {

};

bool Graph::push(long long u) {
  if (u < 0 || u >= n) {
    std::cerr << "Invalide vertex index " << u << '\n';
    exit(1);
  }
  return true;
};

bool Graph::relabel(long long u) {
  return true;
};

long long Graph::pushRelabel(long long s, long long t) {
  initialize_preflow(s);

  // loop untill none of the Vertex is in overflow
  //  while (overFlowVertex(ver) != -1)
  //  {
  //      int u = overFlowVertex(ver);
  //      if (!push(u))
  //          relabel(u);
  //  }

  // ver.back() returns last Vertex, whose
  // e_flow will be final maximum flow
  //  return ver.back().e_flow;
  return 1;
};

/*****************************************/

// int main(int argc, char const *argv[]) {
int main() {
  long long n;
  long long s, t, m;
  long long u, v, c;

  while (std::cin >> n) {
    // n == 0 finish
    if (!n) break;

    // get source and sink index
    std::cin >> s >> t >> m;

    /*****************************/
    // Bloco que adiciona arestas no grafo
    Graph graph(n);

    while (m--) {
      std::cin >> u >> v >> c;
      if (!graph.addEdge(u, v, c)){
        std::cerr << "Invalid range of edge\n  u = " << u << "\n  v = " << v << '\n';
        return 1;
      }
      else {
        std::cout << "Add edge to Graph. Edge(" << u << ", " << v << ")\n";
      }
    }
    /*****************************/
    // get max flow with push relabel
    std::cout << graph.pushRelabel(s, t) << '\n';
  }
  return 0;
}
