# Source Code

- **Makefile**: Este Makefile é o [GenericMakefile][GenericMakefile].
Nele você pode se preocupar em apenas adicionar arquivos e headers contanto que exista apenas uma função **main** entre eles.

## Comandos disponíveis

- **make**: Compila todos os objetos no arquivo executável binário. Se os objetos já estiverem compilados e os arquivos fonte não forem modificados, ele reaproveita apenas linkando os arquivos "*.o*".

- **make run**: TODO  
Obviamente no intuito de rodar o código. Caso seja necessário, colocamos um alias para rodar cada algoritmo desejado. Ex: **make <name_algorithm>**

- **make clean**: Limpa tudo. Até as pastas contendo os arquivos objetos.

[GenericMakefile]: https://github.com/ignitz/GenericMakefile
