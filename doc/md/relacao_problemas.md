Um dos primeiros algoritmos propostos para a solução desse problema foi o Ford-Fulkerson. Esse método utiliza uma estratégia gulosa para procurar um caminho da fonte ao sumidouro pelo grafo residual. Uma vez identificado, um fluxo igual à menor capacidade das arestas é enviado por ele. Uma implementação específica do Ford-Fulkerson é o algoritmo de Edmonds-Karp, que define o método de busca de caminhos através de uma busca em largura.

Esse trabalho por sua vez fez uma implementação do algoritmo de push-relabel. Em comparação aos descritos anteriormente, esse método desloca o fluxo de vértice em vértice, identificando qual o excesso de fluxo em cada um, e movimentando esse excesso para os adjacentes. Para isso, um grafo dirigido modela o problema:

Seja $G=\left( V,A \right)$ um grafo com $s,t\in V$ respectivamente a fonte e o sumidouro do problema.

A capacidade de uma aresta $\left( u,v \right)\in E$ é denominada $c\left( u,v \right):E\to \mathbb{Z} | c\left( u,v \right) > 0$ e representa o fluxo máximo que pode passar por ela.

O fluxo de uma aresta $\left( u,v \right)\in E$  é denominado $f\left( u,v \right):E\to \mathbb{Z} | f\left( u,v \right) > 0$. Ele possui as seguintes restrições:

- Restrição de capacidade: $f\left( u,v \right)\le c\left( u,v \right)$, ou seja, o fluxo de uma aresta não pode exceder a sua capacidade
- Conservação de fluxo: $\underset{u:\left( u,v \right)\in E}{\overset{{}}{\mathop \sum }}\,f\left( u,v \right)~=~\underset{u:\left( v,u \right)\in E}{\overset{{}}{\mathop \sum }}\,f\left( v,u \right)~,~\forall v\in V\backslash \left\{ s,t \right\}$, ou seja, o fluxo total que entra em um vértice deve ser igual ao fluxo total que sai dele, exceto para a fonte e para o sumidouro.

O valor do fluxo f é definido como $f=\underset{v:\left( s,v \right)\in E}{\overset{{}}{\mathop \sum }}\,f\left( s,v \right)$, onde s é a fonte de G. Ele representa a quantidade de fluxo total que passa da fonte para o sumidouro.

O problema de fluxo máximo é maximizar $f$, ou seja, achar o maior fluxo possível de $s$ para $t$.
