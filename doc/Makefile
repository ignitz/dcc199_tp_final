# Aqui vocẽ adiciona os arquivos de entrada
# em formato Markdown separados por espaços.
INPUT_FILES=md/header.md \
md/desc_problem.md \
md/relacao_problemas.md \
md/math_desc.md \
md/corretude.md \
md/corretude2.md \
md/complexidade.md \
md/estruturas.md \
md/referencias.md

# Nome do Arquivo PDF de saída
OUTPUT_NAME=DCC199_TPFinal_YuriNiitsuma_BrenoMarques.pdf

all:
	@make clean
	@make open

$(OUTPUT_NAME):
	@echo 'Converting to PDF'
	@pandoc $(INPUT_FILES) -s -V geometry:margin=1in --mathjax -o "$(OUTPUT_NAME)"

clean:
	@echo 'Removing files'
	@if [ -f "$(OUTPUT_NAME)" ]; \
	then \
		rm "$(OUTPUT_NAME)" ; \
	fi

open: $(OUTPUT_NAME)
	@echo 'Opening PDF'
	@(xdg-open "$(OUTPUT_NAME)" > /dev/null)
