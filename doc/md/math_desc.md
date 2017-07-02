## Formulação matemática

Dado um grafo $G(V, E)$, definimos $s, t \in V$ vértices da fonte e sumidouro respectivamente do grafo.

$G_f$ é o grafo residual.

IMAGEM EXEMPLO?

### preflow

Definimos, preflow $\{ {f_e}\}  \in E$ satisfaz:

1. $0 \le {f_e} \le {u_e},\;\forall e \in E$
2. $\sum\limits_{v\; \in \;V} {f(v,\;u)}  \ge \sum\limits_{v\; \in \;V} {f(u,\;v)} $. flow_in >= flow_out

Definimos $e(v)$ a quantidade de fluxo excedida do vértice $v$. É a diferença entre o fluxo de entrada e o fluxo de saída no vértice $u$.

$$e(u) = \sum\limits_{v\; \in \;V} {f(v,u)}  - \sum\limits_{v\; \in \;V} {f(u,v)} \geq 0$$

Nota: pre_flow é um fluxo se só tiver $e(u) > 0$

Agora vamos discutir como modificamos, pre_flow no algoritmo:

Podemos violar as restrições de conservação, assim temos mais flexibilidade

Em que $f$ é uma função $V \times V \rightarrow R$ que satisfaz a restrição de capacidade:

Para evitar cálculos errados contendo ciclos, o push_relabel segue a seguinte estratégia.

Mantém $s$ e $t$ disconectado do residual network atual.

1. $h(s) = |V|$
2. $h(t) = 0$
3. $\forall (v, w) \in G_f, h(v) \leq h(w) + 1$.

### Passos

##### Inicialização

Se inicia com:

- $h(s) \leftarrow n$
- $h(t) \leftarrow 0,\;\forall v \in \{ V - s\}$
- ${f_e} \leftarrow {u_e},\;\forall e \in E$ que tenha um arco que venha de $s$
- ${f_e} \leftarrow 0$ para todos os

##### Push

Push é uma sub-rotina que faz o seguinte:
- Escolhe uma aresta $(v, w)$ que contenha no grafo residual $G_f$
- $\Delta \leftarrow min\{e(v), c_f(v, w)\}$. Escolhe o mínimo entre os dois para que mantenha a restrição.
- $e(v) \leftarrow e(v) - \Delta$
- $e(w) \leftarrow e(w) + \Delta$
- 

Aqui há uma peculiaridade que diferencia de outros algoritmos. Na escolha do $\Delta$ temos a restrição da capacidade e .... não vou falar... embolo todo. Tem como objetivo deixar $e(v) \geq 0$.
