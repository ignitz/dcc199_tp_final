# Estruturas dos dados

A estrutura do grafo foi implementada através de uma lista de arestas, já que o algoritmo busca arestas específicas.

O código fonte está disponível em:  

- [https://github.com/ignitz/dcc199_tp_final/blob/master/src/main.c](https://github.com/ignitz/dcc199_tp_final/blob/master/src/main.c)

# Testes

Foi criado grafos conexos aleatórios de tamanhos variados para efetuarmos testes de execução.

Os testes de encontram em:

- [https://github.com/ignitz/dcc199_tp_final/tree/master/src/tests](https://github.com/ignitz/dcc199_tp_final/tree/master/src/tests)

Seguem as saídas no saida de fluxo máximo e tempo de execução em segundos.

\setlength\parindent{0pt}
$|V| = 10$
```
318
.001270531
```
```
571
.001553841
```

$|V| = 100$
```
322
.005501648
```
```
319
.063763368
```
```
91
.002576342
```
```
386
.055882479
```

$|V| = 200$
```
451
.505722545
```
```
581
.491276133
```
```
393
.575241899
```
```
243
.566083337
```

$|V| = 1000$
```
887
.355961284
```
```
167
.236621816
```
```
918
.405924430
```
```
721
71.945276677
```

$|V| = 2000$
```
953
587.119914111
```

$|V| = 3000$
```
255
3.961093684
```
\setlength\parindent{24pt}

Observe que nos dois últimos há tempos inversos do que esperado, a característica em que o grafo gerado pode influênciar na velocidade do algoritmo. Por exemplo, se o diâmetro entre a fonte e o sumidouro for pequeno.
