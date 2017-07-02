#include "graph.hpp"

/*****************************************/
// Graph

bool Graph::addEdge(int u, int v, long long capacity){
  return addEdge(u, v, capacity, 0);
};

bool Graph::addEdge(int u, int v, long long capacity, long long flow){
  if (u >= n || v >= n || u < 0 || v < 0) return false;
  edges.push_back(Edge(u, v, capacity, flow));
  return true;
};

void Graph::initialize_preflow(int s) {
  // Making h of source Vertex equal to no. of vertices
  // Height of other vertices is 0.
  vertexs[s].height = vertexs.size();

  for (int i = 0; i < edges.size(); i++)
  {
    // // If current edge goes from source
    // if (edge[i].u == s)
    // {
    //   // Flow is equal to capacity
    //   edge[i].flow = edge[i].capacity;
    //
    //   // Initialize excess flow for adjacent v
    //   ver[edge[i].v].e_flow += edge[i].flow;
    //
    //   // Add an edge from v to s in residual graph with
    //   // capacity equal to 0
    //   edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, s));
    // }
  }
};

bool Graph::push(int u) {
  if (u < 0 || u >= n) {
    std::cerr << "Invalide vertex index " << u << '\n';
    exit(1);
  }
  return true;
};

bool Graph::relabel(int u) {
  return true;
};

long long Graph::pushRelabel(int s, int t) {
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
