#include <stdio.h>
#include <stdlib.h>

int write(char* path, char* buf) {
/*Escreve o texto de um buffer em um arquivo*/
	FILE* file = fopen(path, "w");
	if (!file) {
		return 1;
	}
	for (int i = 0; buf[i] != '\0'; i++) {
		fputc(buf[i], file);
	}
	fclose(file);
	return 0;
}

char* read(char* path) {
	//Abre o arquivo
	FILE* file = fopen(path, "r");
	if (!file) {
		return NULL;
	}
	
	//Descobre o tamanho do arquivo
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);
	
	//Aloca na memória um buffer do tamanho do arquivo e adiciona nele os caracteres do arquivo
	int k = 0;
	char* buf = malloc(size * sizeof(char));
	char c = fgetc(file);
	while (c != EOF) {
		buf[k++] = c;
		c = fgetc(file);
	}
	buf[k] = '\0';
	
	fclose(file);
	return buf;
}

int main() {
	char* txt = read("./pie.txt");
	if (!txt) {
		printf("Arquivo não encontrado ou inacessível\n");
		return 1;
	}
	write("./matrix", txt);

	free(txt);
	return 0;
}
