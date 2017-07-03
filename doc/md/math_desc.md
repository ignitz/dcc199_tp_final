## Push-Relabel

O algoritmo de *push-relabel* pode ser visualizado através de uma analogia: as arestas são canos de água e os vértices são suas junções, cada uma a uma altura diferente. A fonte é considerada como a junção mais alta e o sumidouro a mais baixa. Cada junção manda água para as adjacentes. Uma vez que alguma junção possua um excesso de água, ela envia (operação de *push*) água para alguma outra de altura menor. Se a água ficar presa em alguma junção, a sua altura deve ser aumentada (operação de *relabel*).

Dessa forma, duas variáveis são associadas a cada vértice: a sua altura, que é usada para determinar se ele pode enviar fluxo para algum dos seus adjacentes ou não, e o excesso de fluxo, que é a diferença entre o fluxo total que entra no vértice e o fluxo total que sai dele. Abaixo segue o *struct* em C.

```c
typedef struct{
  int height, eFlow;
} Vertex;
```

Dado o vértice $v$, definimos que:  

- $height = h(v)$ é altura do vértice
- $eFlow = e(v)$ o excesso de fluxo no vértice.

Dado $u,v \in V-\{s\}$, temos que o excesso de fluxo é

$$e(u) = \sum\limits_{v\; \in \;V} {f(v,\;u)}  - \sum\limits_{v\; \in \;V} {f(u,\;v)} $$

Mas aplicaremos uma relaxação na restrição de conservação de fluxo.

$$\sum\limits_{v\; \in \;V} {f(v,\;u)}  - \sum\limits_{v\; \in \;V} {f(u,\;v)} \ge 0 \Rightarrow e(u) \ge 0$$

O que nos dará mais flexibilidade pois nos dara a liberdade de aumentar o fluxo olhando apenas em um vértice e suas arestas adjacentes.

*Overflowing* é definido quando $e(u) > 0$.

Cada aresta também tem das variáveis associadas: o fluxo, que indica a quantidade atual de fluxo que passa por ela, e a capacidade, que indica qual o valor máximo de fluxo na aresta.

```c
typedef struct{
  int flow, capacity;
  int u, v;
}Edge;
```

Dado dois vértices $(u, v)$, definimos que:

- $flow = f(u,v)$ é o fluxo na aresta
- $capacity = c_f(u, v)$ a capacidade máxima de fluxo

Como consequência, $f(u,v) \le c_f(u, v)$.

O algoritmo conta com três operações principais: o *preflow*, o *push* e o *relabel*.

#### preflow

O *preflow* inicializa os valores do grafo para que as demais operações possam ser feitas com sucesso. A altura e o excesso de fluxo de cada vértice é inicializado com $0$, já que nenhum deles possui fluxo no início de execução. Ele define a altura da fonte igual ao número de vértices no grafo, já que ela deve possuir a maior altura da rede.

$$h(u) = \left\{ {\begin{array}{*{20}{c}}
{|V|}&{{\rm{if }}u = s}\\
0&{\forall u \ne s}
\end{array}} \right.$$

O fluxo de cada aresta é inicializado com $0$, já que não há fluxo em nenhuma delas. Finalmente, são identificados os vértices adjacentes à fonte. Nas arestas que os ligam, o fluxo recebe o valor da sua capacidade, e o vértice recebe um excesso de fluxo com o mesmo valor.  

$$f(u,v) = \left\{ {\begin{array}{*{20}{c}}
{c(u,v)}&{{\rm{if }}u = s}\\
0&{\forall u \ne s}
\end{array}} \right.$$

#### push

A operação de *push* é utilizada para retirar fluxo de algum vértice com excesso. Se houver algum vértice adjacente com altura menor, o fluxo é deslocado dele para o adjacente. O valor deslocado é definido pelo menor valor entre o excesso do vértice e a capacidade restante da aresta.

\setlength\parindent{0pt}
$\Delta  = \min (e(u),\;{c_f}(u,v))$  
**if** $(u, v) \in E$  
**then** $f(u,v) = f(u,v) + \Delta$  
**else** $f(u,v) = f(u,v) - \Delta$  
**endif**  
$e(u) = e(u) - \Delta$  
$e(v) = e(v) + \Delta$  
\setlength\parindent{24pt}

A condição $e(u) \ge 0$ sempre se mantém .

#### relabel

O *relabel* é utilizado quando algum vértice possuir um excesso de fluxo mas nenhum dos seus adjacentes tiver uma menor altura. Nesse caso devemos aumentar a sua altura. Seu novo valor é dado pela menor altura adjacente, somada a um.

$h(u) = 1 + min\{h(v) : (u,v) \in E_f\}$

O algoritmo chega ao fim quando não houverem mais vértices com excesso de fluxo. A distribuição corrente do fluxo será a distribuição otimizada para o problema. O valor do fluxo máximo é dado pelo valor de excesso de fluxo na fonte.
