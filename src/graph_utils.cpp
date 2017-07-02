#include "graph_utils.hpp"

// returns index of overflowing Vertex
long long Graph::overFlowVertex(std::vector<Vertex>& ver) {
  // ignore index 0?
  for (long long i = 1; i < n-1; i++)
  if (ver[i].excessFlow > 0)
    return i;

  // -1 if no overflowing Vertex
  return -1;
};

// Update reverse flow for flow added on ith Edge
void Graph::updateReverseEdgeFlow(long long i, long long flow) {
  long long u, v;
  u = edges[i].v; v = edges[i].u;

  long long how_many_edges = (long long) edges.size();

  for (long long j = 0; j < how_many_edges; j++) {
    if (edges[j].v == v && edges[j].u == u) {
      edges[j].flow -= flow;
      return;
    }
  }

  // adding reverse Edge in residual graph
  addEdge(u, v, 0, flow);
};
