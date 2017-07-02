#include "utils.hpp"
#include "graph.hpp"
#include "graph_utils.hpp"

#include <iostream>

// int main(int argc, char const *argv[]) {
int main() {
  int n;
  int s, t, m;
  int u, v;
  long long c;

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
    graph.printInfoGraph();
    /*****************************/
    // get max flow with push relabel
    std::cout << graph.pushRelabel(s, t) << '\n';
    graph.printInfoGraph();
  }
  return 0;
}
