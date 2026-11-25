#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long get_size(const char *filepath) {
/*Função apoio: retorna tamanho de um arquivo*/
	FILE *file = fopen(filepath, "r");
	if (!file) {
		return 0;
	}
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fclose(file);
	return size;
}

char* fill_buffer(const char* filepath, long size) {
/*Função apoio: retorna um buffer com o texto de um arquivo*/
	char* buffer = malloc(size * sizeof(char));
	FILE* file = fopen(filepath, "r");
	
	char c;
	int i = 0;
	while ((c = fgetc(file)) != EOF) {
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	fclose(file);
	return buffer;
}

int fill_file(char* buffer, const char* filepath) {
/*Função apoio: preenche um arquivo com o conteudo de um buffer*/
	FILE* file = fopen(filepath, "w");
	if (!file) {
		return 0;
	}
	char c;
	int i = 0;
	while (buffer[i] != '\0') {
		c = fputc(buffer[i], file);
		i++;
	}
	fclose(file);
	return 1;
}

int count_word(const char* filepath, const char* word) {
/*Função apoio: Conta a ocorrencia de dada palavra em um arquivo*/
	FILE* file = fopen(filepath, "r");
	if (!file) {
		return -1;
	}
	int count = 0;
	char c;
	int i = 0;
	while ((c = fgetc(file)) != EOF) {
		if (c == word[i]) {
			i++;
			if (word[i] == '\0') {
				count++;
				i = 0;
			} 
		} else {
			i = 0;
		}
	}
	fclose(file);
	return count;
}

int replace_word(const char* filepath, const char* old_str, const char* new_str) {
/*Substitui todas as ocorrências de uma dada palavra por outra em um arquivo, retornando o número de substituições*/

	//NOTE: De longe o exercício mais difícil das listas, gastei umas 3h somente nele. Chega dar orgulho ver ele funcionando.
	//Por sua complexidade, vou documenta-lo aqui mesmo (Meu eu do futuro agradece)
	
	//Aqui temos as preliminares da função. Até ln88, verificamos se o arquivo existe e se faremos substituições
	long sizef = get_size(filepath);
	if (sizef == 0) {
		return 0;
	}

	int subs = count_word(filepath, old_str);
	if (subs < 0) {
		return 0;
	}

	//Definimos as variaveis de tamanho e alocamos dois buffers, um de leitura e outro de escrita
	int sizeOld = strlen(old_str);
	int sizeNew = strlen(new_str);

	long margin = (long)(subs * sizeNew); //Uma Margem extra para inserir as palavras novas quando elas forem maiores que a antiga
	char* rbuf = fill_buffer(filepath, sizef); //Aloca e preenche o buffer de leitura com o conteudo do arquivo
	char* wbuf = malloc((sizef + margin) * sizeof(char)); //Aloca o buffer de escrita e retorno

	//Aqui o loop que realiza a substituição
	int wchkpnt = 0; //Ultima posição de escrita no buffer de escrita
	int rchkpnt = 0; //Ultima posição de leitura no buffer de leitura
	int i = 0;
	int k = 0;
	while(rbuf[i] != '\0') {
		//Verifica se achamos uma substituição
		if (rbuf[i] == old_str[k]) {
			k++;
			if (old_str[k] == '\0') {
				int j = wchkpnt; //cursor de escrita do buffer de retorno
				//Preenche rtbuf com o conteudo não substtituido
				for (int p = rchkpnt; p <= (i-sizeOld); p++) {
					wbuf[j] = rbuf[p];
					j++;
				}
				//Preeche rtbuf com a palavra substituida
				int l = 0;
				while (new_str[l] != '\0') {
					wbuf[j] = new_str[l];
					j++;
					l++;
				}
				//Atualiza as ultimas posições de leitura e escrita
				wchkpnt = j;
				rchkpnt = i + 1;
				k = 0;
			}
		} else {
			k = 0;
		}
		i++;
	}
	
	//Preenche o buffer de retorno com os ultimos caracteres não substituidos
	int j = wchkpnt; //cursor de escrita do buffer de retorno
	for (int p = rchkpnt; rbuf[p] != '\0'; p++) {
		wbuf[j] = rbuf[p];
		j++;
	}
	wbuf[j] = '\0';
		
	//printf("%s\n", rtbuf);

	//Escreve o arquivo com o novo conteúdo e desaloca os buffers
	fill_file(wbuf, filepath);	
	free(wbuf);
	free(rbuf);

	return subs;
}


