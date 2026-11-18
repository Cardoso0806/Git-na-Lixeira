#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void print_vec(int size, int *vec) {
/*Função Debug: imprime os elementos de um vetor*/
	for (int i = 0; i < size; i++) {
		printf("%d\t", *(vec + i));
	}
	printf("\n");
}

void print_str(const char* str){
/*Função Debug: imprime os elementos de uma string*/
	int i = 0;
	while (*(str + i) != 0) {
		printf("%c", *(str+i));
		i++;
	}
	printf(".\n");
}

int* create_vector(int n) {
/*Aloca na Heap  um array de n elementos, e os inicializa com 0*/
	int *vec = malloc(n * sizeof(int)); // alternativamente, poderia se utilizar calloc
	for (int i = 0; i < n; i++) {
		*(vec + i) = 0;
	}
	return vec;
}

int* get_largest(int n, int* v, int max) {
/*Recebe um vetor de inteiros e seu tamanho e retorna um novo vetor na heap contendo os maiores valores encontrados*/
	int *max_vec = malloc(max * sizeof(int));
	int *max_vec_pos = max_vec;
	for (int j = 0; j < max; j++) {
		int maior = INT_MIN;
		for (int i = 0; i < n; i++) {
			if (j == 0) {
				if (*(v + i) > maior) {
					maior = *(v + i);
					*(max_vec_pos) = maior;
				}
			} else {	
			if (*(v + i) > maior && *(v + i) < *(max_vec_pos - 1)){
				maior = *(v + i);
				*(max_vec_pos) = maior;
			}
			}
		}
		max_vec_pos++;
	}
	return max_vec;
}

char* copy_string(const char* str) {
/*Recebe uma string e copia para a heap*/
	int size = strlen(str) + 1;
	char* newStr = malloc(size * sizeof(char));
	int i = 0;
	while (i < size) {
		*(newStr + i) = *(str + i);
		i++;
	}
	*(newStr + i + 1) = '\0';
	return newStr;
}

char* copy_reverse(const char* str) {
/*Recebe uma string e copia para a heap em ordem reversa*/
	int size = strlen(str) + 1;
	char* newStr = malloc(size * sizeof(char));
	int i = size - 2;
	int j = 0;
	while (*(str+j) != 0) {
		*(newStr+i) = *(str+j);
		i--;
		j++;
	}
	*(newStr + size - 1) = 0;
	return newStr;
}

char* concat_string(const char* str1, const char* str2) {
/*Concatena duas strings e retorna o resultado em uma noma string na heap*/
	int size = strlen(str1) + strlen(str2) + 1;
	char* concat = malloc(size * sizeof(char));
	int i = 0;
	for (int j = 0; *(str1 + j) != 0; j++) {
		*(concat + i) = *(str1 + j);
		i++;
	}
	for (int k = 0; *(str2 + k); k++) {
		*(concat + i) = *(str2 + k);
		i++;
	}
	*(concat + i + 1) = 0;
	return concat;
}

int* array_union(int n1, const int* v1, int n2, const int* v2) {
/*Realiza a uniao entre dois vetores e retorna o valor em um vetor na heap*/
	int size = n1 + n2;
	int* uniao = malloc(size * sizeof(int));
	int i = 0;
	for (int j = 0; j < n1; j++) {
		*(uniao + i) = *(v1 + j);
		i++;
	}
	for (int j = 0; j < n2; j++) {
		int repeat = 0;
		for (int k = 0; k < n1; k++) {
			if (*(v2 + j) == *(v1 + k)) {
				repeat = 1;
			}
		}
		if (repeat != 1) {
			*(uniao + i) = *(v2 + j);
			i++;
		} 
	}
	return uniao;
}

int* array_intersection(int n1, const int* v1, int n2, const int* v2) {
/*Aloca os elementos da intersecção v1 e v2 em um array na heap*/
	int size;
	if (n1 > n2) {
		size = n2;
	} else {
		size = n1;
	}
	int* interseccao = malloc(size * sizeof(int));
	int k = 0;
	for (int i = 0; i < n1; i++) {
		int repeat = 0;
		for (int j = 0; j < n2; j++) {
			if (*(v1 + i) == *(v2 + j)) {
				repeat = 1;
			}
		}
		if (repeat) {
			*(interseccao + k) = *(v1 + i);
			k++;
		}
	}
	return interseccao;
}

int** create_vector2d(int row, int cols) {
/*Aloca uma nova matriz na heap e retorna seu endereço*/
	int** matrix = malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		*(matrix + i) = malloc(cols * sizeof(int));
	}
	return matrix;
}

void free_matrix(int row, int** matrix) {
/*Função auxiliar: libera os elementos de uma matrix*/
	for (int i = 0; i < row; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void print_vector2d(int rows, int cols, int** v) {
/*Imprime os elementos de uma matriz alocada na heap*/
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d\t", v[i][j]);
		}
		printf("\n");
	}
}

int** transpose(int row, int col, int v[row][col]) {
/*Aloca a transposta de uma matriz na heap*/
	int** transposta = create_vector2d(col, row);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			transposta[j][i] = v[i][j];
		}
	}
	return transposta;
}

char** split(const char* str, int* n) {
/*Recebe o endereço de uma string contendo palavras separadas por espaços e retorna o endereço de um vetor de strings contendo as palavras separadas.
 * Além disso, retorna via parâmetro, o número de palavras encontradas.*/

	//NOTE: Quando escrevi esta função, fiz as três operações na mesma função. 

	//conta o número de palavras encontradas na string
	int letras = 0;
	int k = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] != ' ') {
			if (k == 0) {
				*n += 1;
			}
			k = 1;
			letras++;
		} else {
			k = 0;
		}
	}
	

	//Aloca um vetor de strings na heap
	char** table = malloc(*n * sizeof(char*));
	for (int i = 0; i < *n; i++) {
		table[i] = malloc(letras * sizeof(char));
	}

	//Adiciona as palavras em cada linha da matriz 
	k = 0;
	int i = 0;
	int j = 0;
	for (int t = 0; str[t] != '\0'; t++) {
		if (str[t] != ' ') {
			k = 1;
			table[i][j] = str[t];
			j++;
		} else {
			if (k == 1) {
				table[i][j] = '\0';
				i++;
				j = 0;
			}
			k = 0;
		}
	}	

	return table;
}

int main() {
/*	int *v1 = create_vector(7);
	print_vec(7, v1);
	free(v1);
*/
/*
	int v0[] = {6,10,2,1,2,3,9};
	int* max_vec = get_largest(7, v0, 3);
	print_vec(3, max_vec);
	free(max_vec);
*/
/*
	char txt[] = "Hello World!";
	char *cpyTxt = copy_string(txt);
	print_str(cpyTxt);
	free(cpyTxt);
*/
/*
	char txt[] = "Ada Lovelace";
	char* txt_reverse = copy_reverse(txt);
	print_str(txt_reverse);
	free(txt_reverse);
*/
/*
	char txt_1[] = "Rapadura é doce";
	char txt_2[] = " mas não é mole não";
	char* concat = concat_string(txt_1, txt_2);
	print_str(concat);
	free(concat);
*/
/*
	int conj_A[] = {0,1,2,3,4,5};
	int conj_B[] = {4,5,6,7,8,9};
	int *uniao = array_union(6, conj_A, 6, conj_B);
	print_vec(12, uniao);
	free(uniao);
*/
/*
	int conj_A[] = {4,5,6};
	int conj_B[] = {1,2,3,4,5};
	int* interseccao = array_intersection(3, conj_A, 5, conj_B);
	print_vec(3, interseccao);
	free(interseccao);
*/
/*
	int **matrix = create_vector2d(3, 4);
	print_vector2d(3, 4, matrix);
	free_matrix(3, matrix);
*/
/*
	int **matrix = create_vector2d(3,4);
	free_matrix(3, matrix)
*/	
/*
	int matrix[3][4] = {
		{0,1,2,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	int** transposta = transpose(3, 4, matrix);
	print_vector2d(4, 3, transposta);
	free_matrix(4, transposta);
*/
	char str[] = "   Agora, nós vamos  invadir sua  praia!  ";
	int size = 0;
	char** tokens = split(str, &size);
	for (int i = 0; i < size; i++) {
		printf("%s\n", tokens[i]);
	}
	for (int i = 0; i < size; i++) {
		free(tokens[i]);
	}
	free(tokens);
}

//heap é uma memória de paz e amor
