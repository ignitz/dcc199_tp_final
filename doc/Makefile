# Aqui vocẽ adiciona os arquivos de entrada
# em formato Markdown separados por espaços.
INPUT_FILES=00_head.md

# Nome do Arquivo PDF de saída
OUTPUT_NAME=DCC199_TPFinal_YuriNiitsuma_BrunoMarques.pdf

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
