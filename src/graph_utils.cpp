#include "graph_utils.hpp"

// returns index of overflowing Vertex
int Graph::overFlowVertex() {
  // ignore index 0?
  // TODO: make dynamic source and sink
  for (unsigned int i = 0; i < vertexs.size(); i++) {
    if (i == source || i == sink) continue;
    if (vertexs[i].excessFlow > 0) return i;
  }

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

// For DEBUG purpose
void Graph::printInfoGraph() {
  std::cout << "\n=======================================================================\n";
  std::cout << OKBLUE << "Vertexs:\n";
  std::cout << "height\t excessFlow\n";
  // print vertexs
  for(auto &ver : this->vertexs) {
    std::cout << ver.height << '\t' << ver.excessFlow << '\n';
  }

  std::cout << OKGREEN << "\nEdges:\n";
  std::cout << "u\tv\tflow\tcapacity\n";
  // print edges
  for(unsigned int i = 0; i < this->edges.size(); i++) {
    Edge edge = this->edges[i];
    std::cout << edge.u << '\t' << edge.v << '\t' << edge.flow << '\t' << edge.capacity << '\n';
  }
  std::cout << "--------------------------------------------------------------------------\n" << ENDC;
}
