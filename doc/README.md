# Documentação

A documentação será escrita no formato PDF utilizando o [Pandoc][Pandoc].

## Programas essenciais

Se estiver utilizando algum derivado do Debian será necessário instalar alguns pacotes.

*Caso precise de mais algo, me avise. O Google também é seu amigo.*

### Pandoc

Ele é um conversor quase que universal de arquivos de texto. Nele vamos escrever em formato [Markdown][Markdown] para ter como saída um arquivo PDF originao do [LaTeX][LaTeX]

```
$ sudo apt-get install pandoc
```

### LaTeX

Linguagem para textos ciêntíficos. Vantagem é que suporta fórmulas em TeX e creio que vou desenhar os grafos por ele.

```
$ sudo apt-get install texlive
```

## Makefile

O Makefile é simples de ser usado, se estiver em ambiente GNU/Linux e os pacotes mencionados estiverem instalados, basta rodar **make** que ele compilará e abrirá o PDF automaticamente.

[Pandoc]: http://pandoc.org/
[Markdown]: https://pt.wikipedia.org/wiki/Markdown
[LaTeX]: https://pt.wikipedia.org/wiki/LaTeX
