#include "utils.hpp"
#include "graph.hpp"

#include <iostream>

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
