Como $e(x) > 0, x \in U$, então $\sum\limits_{u \in U}{e(u)} > 0$, o que nos leva a:  
$\sum\limits_{u \in U} {\sum\limits_{v \in \{ V - U\} } {f(v,u)} }  - \sum\limits_{u \in U} {\sum\limits_{v \in \{ V - U\} } {f(u,v)} }  > 0 \Rightarrow \sum\limits_{u \in U} {\sum\limits_{v \in \{ V - U\} } {f(v,u)} }  > 0$  
Então deve existir pelo menos um par de vértices tal que $f(u',v') > 0$, então existe uma aresta residual $(u', v')$, o que significa que também existe um caminho $x \rightarrow u'$ e depois pra $v'$, o que contradiz a definição do conjunto $U$.

6. Seja $G=(V,E)$; um fluxo de rede com fonte $s$ e sumidouro $t$. Durante a execução Push-Relabel em $G$, temos $h(u) \le 2|V| - 1~ ~\forall u \in V$.  
**Demonstração:** A altura da fonte $s$ e do sumidouro $t$ nunca muda porque estes vértices são por definição $e(s), e(t) \le 0$. Logo, sempre teremos $h(s) = |V|$ e $h(t) = 0$, e ambos não são maiores que $2|V| - 1$.  
Agora considere qualquer vértice $u \in V - {s,t}$. Inicialmente temos $h(u)=0$. Iremos mostrar que a cada *relabel*, ainda teremos $h(u) \le 2|V|-1$.
Quando $u$ passa pelo processo de *relabel*, $e(u) > 0$, e pelo lema anterior, existe um caminho simples até $s$ no grafo residual.
Seja $p$ um vetor contendo os vértices no caminho de $u$ até $s$, temos que $p$ tem dimensão menor que $|V|-1$ pois é caminho simples e representaremos $p = (v_0, v_1, v_k)$.
Para cada $(v_i, v_{i+1}) \in E_f$, e pelo lema sobre as alturas, $h(v_i) \le h(v_{i+1}) + 1$, expandindo estas inequações de $v_0$ $k$ vezes, temos:  
$h(u) = h(v_0) \le h(v_k) + k \le h(s) + (|V| - 1) = 2|V| - 1$.  
