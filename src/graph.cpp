#include "graph.hpp"

/*****************************************/
// Graph

bool Graph::addEdge(long long u, long long v, long long capacity){
  return addEdge(u, v, capacity, 0);
};

bool Graph::addEdge(long long u, long long v, long long capacity, long long flow){
  if (u >= n || v >= n || u < 0 || v < 0) return false;
  edges.push_back(Edge(u, v, capacity, flow));
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

  // // Main loop
  // // while there is a vertex v != s, t with \alpha_f(v) > 0; do
  //  while (overFlowVertex(ver) != -1) {
  //
  //    // choose such a vertex v with the maximum height h(v)
  //    int u = overFlowVertex(ver);
  //    // there is an outgoing edge (v, w) of v in G_f with h(v) = h(w) + 1
  //    if (!push(u))
  //        relabel(u);
  //  }
  //
  // // ver.back() returns last Vertex, whose
  // // e_flow will be final maximum flow
  // //  return ver.back().e_flow;
  return 1;
};

/*****************************************/
