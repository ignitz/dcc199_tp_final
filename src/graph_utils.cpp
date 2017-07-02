#include "graph_utils.hpp"

// returns index of overflowing Vertex
int Graph::overFlowVertex(std::vector<Vertex>& ver) {
  // ignore index 0?
  // TODO: make dynamic source and sink
  for (long long i = 1; i < n-1; i++)
  if (ver[i].excessFlow > 0)
    return i;

  // -1 if no overflowing Vertex
  return -1;
};

// Update reverse flow for flow added on ith Edge
void Graph::updateReverseEdgeFlow(int i, long long flow) {
  int u, v;
  u = edges[i].v; v = edges[i].u;

  for (unsigned int j = 0; j < edges.size(); j++) {
    if (edges[j].v == v && edges[j].u == u) {
      edges[j].flow -= flow;
      return;
    }
  }

  // adding reverse Edge in residual graph
  addEdge(u, v, 0, flow);
};
