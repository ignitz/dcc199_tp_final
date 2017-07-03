## Corretude

Deve-se provar que se o algoritmo terminar, o pré-fluxo f é fluxo máximo.

1. Sabemos que a altura $h\left( u \right)~|~u\in V$ nunca diminui e que ocorre um relabel no vértice $u$, a sua altura $h(u)$ aumenta em pelo menos 1.  
**Demonstração:** Se $u$ sofre um *relabel*, então para todo vértice $v$ tal que $\left( u,v \right)\in E_f$ temos que $h\left( u \right)\le h\left( v \right)$. Logo, $h\left( u \right)\le min\{h\left( v \right)|\left( u,v \right)\in E_f\}$. Portanto o relabel aumenta o valor de $h(u)$.

2. Seja $G=(V,E)$ um fluxo com fonte $s$ e sumidouro $t$. Durante a execução do algoritmo, $h$ se mantém como uma função de altura.  
**Demonstração:** Por indução: em uma aresta residual $\left( u,v \right)\in E_f$, após o relabel temos que $h\left( u \right)\le h\left( v \right)+1$. Considerando outra aresta residual, esta $(w,u)$, por **(1)**, $h\left( w \right)\le h\left( u \right)+1$ antes do relabel implica em $h(w)<h(u)$ após a operação. Logo, no relabel $h$ é uma função de altura. Considerando a operação de push, ela pode adicionar uma aresta $(v,u)$ ou remover uma aresta $(u,v)$. No primeiro caso,  $h\left( v \right)~=~h\left( u \right)-1<h\left( u \right)+1$, e a variável $h$ continua uma função de altura. No segundo caso, essa restrição é removida, e a variável $h$ ainda continua uma função de altura.

3. Seja $G=(V,E)$ um fluxo em rede com fonte $s$ e sumidouro $t$, seja $f$ um pré-fluxo em $G$ e seja $h$ uma função de altura em $V$. Então não existe nenhum caminho de $s$ até $t$ na rede residual $G_f$.
**Demonstração:** Por contradição, suponha que exista um caminho $p=\left\{ s,~{{v}_{0}},~{{v}_{1}},...~,~~{{v}_{j}},t~ \right\}$. Já que $p$ é um caminho simples, logo $j<\left| V \right|$. Com $i = \{0, 1, …, j-1\}$, temos a aresta $\left( {{v}_{i}},~{{v}_{i+1}} \right)$. Como $h$ é uma função de altura, temos que $h\left( {{v}_{i}} \right)\le h\left( {{v}_{i+1}} \right)+1$ com $i = {0, 1, … , j-1}$. Aplicando essa desigualdade sobre o caminho $p$, temos $h\left( s \right)\le h\left( t \right)$. Porém, como $h(t) = 0$, temos que $h\left( {{v}_{i}} \right)\le ~j<\left| V \right|$, o que contradiz a restrição de $h\left( s \right)=\left| V \right|$ na função de altura. Logo, o caminho $p$ não existe.

4. Se o algoritmo terminar ao ser executado sobre um fluxo de rede $G=(V,E)$ com fonte $s$ e sumidouro $t$, então o pré-fluxo $f$ que ele calcula será um fluxo máximo para $G$.  
**Demonstração:** A inicialização por *preflow* faz com que $f$ seja um pré-fluxo. As únicas operações durante a execução são as de *push* e *relabel*. Se $f$ for um pré-fluxo antes das operações de *push* ou *relabel*, então ainda será um pré-fluxo depois.
Ao término do algoritmo, cada vértice em $V-\{s,t\}$ deve ter um excesso de $0$, pois caso contrário ele seria selecionado para *push* e como $f$ é um pré-fluxo, não há nenhum vértice com *overflow*. Logo, $f$ é um fluxo. Como $h$ é uma função de altura, *(3)* nos diz que não existe nenhum caminho residual de $s$ até $t$ na rede residual $G_f$. Logo, pelo teorema do fluxo máximo e corte mínimo, $f$ é um fluxo máximo.

5. Seja $G = (V, E)$ um fluxo de rede com fonte $s$ e sumidouro $t$, e seja $f$ um pré-fluxo em $G$. Então, para qualquer $x \in G$, existe um caminho de $x$ para $s$ no grafo residual $G_f$.  
**Demonstração:** Para um vértice $x$ tal que $e(x) > 0$, seja $U$ o conjunto contendo vértice $v$ tal que existe um caminho em $G_f$, e suponha por contradição  que $s \notin U$.  
${\sum\limits_{u \in U} {e(u)}  = \sum\limits_{u \in U} {\left( {\sum\limits_{v \in V} {f(v,u)}  - \sum\limits_{v \in \{ V - U\} } {f(u,v)} } \right)} }$  
${ = \sum\limits_{u \in U} {\left( {\left( {\sum\limits_{v \in U} {f(v,u)}  + \sum\limits_{v \in \{ V - U\} } {f(v,u)} } \right) - \left( {\sum\limits_{v \in U} {f(u,v)}  + \sum\limits_{v \in \{ V - U\} } {f(u,v)} } \right)} \right)} }$  
${ = \sum\limits_{u \in U} {\sum\limits_{v \in U} {f(v,u)} }  + \sum\limits_{u \in U} {\sum\limits_{v \in \{ V - U\} } {f(v,u)} }  - \sum\limits_{u \in U} {\sum\limits_{v \in U} {f(u,v)} }  - \sum\limits_{u \in U} {\sum\limits_{v \in \{ V - U\} } {f(u,v)} } }$  
${ = \sum\limits_{u \in U} {\sum\limits_{v \in \{ V - U\} } {f(v,u)} }  - \sum\limits_{u \in U} {\sum\limits_{v \in \{ V - U\} } {f(u,v)} } }$  
