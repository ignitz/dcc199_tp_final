#include "graph.hpp"

/*****************************************/
// Graph

bool Graph::addEdge(int u, int v, long long capacity){
  return addEdge(u, v, capacity, 0);
};

bool Graph::addEdge(int u, int v, long long capacity, long long flow){
  std::cout << OKGREEN << "Add edge to Graph. Edge(" << u << ", " << v << ") " << capacity << " " << flow << "\n" << ENDC;
  if (u >= n || v >= n || u < 0 || v < 0) return false;
  edges.push_back(Edge(u, v, capacity, flow));
  return true;
};

void Graph::initialize_preflow(int s, int t) {
  source = s;
  sink = t;
  // Making h of source Vertex equal to no. of vertices
  // Height of other vertices is 0.
  vertexs[s].height = vertexs.size();

  for (unsigned int i = 0; i < edges.size(); i++) {
    // If current edge goes from source
    if (edges[i].u == s) {
      // Flow is equal to capacity
      edges[i].flow = edges[i].capacity;

      // Initialize excess flow for adjacent v
      vertexs[edges[i].v].excessFlow += edges[i].flow;

      // Add an edges from v to s in residual graph with
      // capacity equal to 0
      std::cout << "edges[i].flow " << edges[i].flow << '\n';
      addEdge(edges[i].v, s, 0, -edges[i].flow);
    }
  }
};

// To push flow from overflowing vertex u
bool Graph::push(int u) {
  // insanity check
  if (u < 0 || u >= n) {
    std::cerr << "Invalide vertex index " << u << '\n';
    exit(1);
  }

  // Traverse through all edges to find an adjacent (of u)
  // to which flow can be pushed
  for (unsigned int i = 0; i < edges.size(); i++) {
      // Checks u of current edge is same as given
      // overflowing vertex
      if (edges[i].u == u) {
          // if flow is equal to capacity then no push
          // is possible
          if (edges[i].flow == edges[i].capacity)
              continue;

          // Push is only possible if height of adjacent
          // is smaller than height of overflowing vertex
          if (vertexs[u].height > vertexs[edges[i].v].height) {
              // Flow to be pushed is equal to minimum of
              // remaining flow on edge and excess flow.
              int flow = std::min(edges[i].capacity - edges[i].flow,
                             vertexs[u].excessFlow);

              // Reduce excess flow for overflowing vertex
              vertexs[u].excessFlow -= flow;

              // Increase excess flow for adjacent
              vertexs[edges[i].v].excessFlow += flow;

              // Add residual flow (With capacity 0 and negative
              // flow)
              edges[i].flow += flow;

              updateReverseEdgeFlow(i, flow);

              return true;
          }
      }
  }
  return false;
};

bool Graph::relabel(int u) {
  // Initialize minimum height of an adjacent
  int mh = INT_MAX;

  // Find the adjacent with minimum height
  for (unsigned int i = 0; i < edges.size(); i++)
  {
      if (edges[i].u == u)
      {
          // if flow is equal to capacity then no
          // relabeling
          if (edges[i].flow == edges[i].capacity)
              continue;

          // Update minimum height
          if (vertexs[edges[i].v].height < mh)
          {
              mh = vertexs[edges[i].v].height;

              // updating height of u
              vertexs[u].height = mh + 1;
          }
      }
  }
  // I don't know what to do with this boolean
  return true;
};

long long Graph::pushRelabel(int s, int t) {
  initialize_preflow(s, t);

  // Main loop
  // while there is a vertex v != s, t with \alpha_f(v) > 0; do
  while (overFlowVertex() != -1) {

    // choose such a vertex v with the maximum height h(v)
    int u = overFlowVertex();
    // there is an outgoing edge (v, w) of v in G_f with h(v) = h(w) + 1
    if (!push(u))
    relabel(u);
  }

  // ver.back() returns last Vertex, whose
  // e_flow will be final maximum flow
  return vertexs[sink].excessFlow;
};

/*****************************************/
