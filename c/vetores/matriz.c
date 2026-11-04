#include <stdio.h>
#include <stdlib.h>

void print_matrix(int rows, int cols, int m[rows][cols]) {
/*Imprime os elementos de uma matriz*/
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
}

void print_reversed(int rows, int cols, int m[rows][cols]) {
/*Imprime os elementos de uma matrix em ordem reversa*/
	for (int i = rows-1; i > -1; i--) {
		for (int j = cols-1; j > -1; j--) {
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
}

void print_min_max(int rows, int cols, int m[rows][cols]) {
/*Encontra e imprime o maior e o menor valor de uma matriz*/
	int min = 2147483647;
	int max = -2147483648;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (m[i][j] > max) {
				max = m[i][j];
			}
			if (m[i][j] < min) {
				min = m[i][j];
			}
		}
	}
	printf("MIN: %d\nMAX: %d\n", min, max);
}

float average(int rows, int cols, int m[rows][cols]) {
/*Retorna a média aritmética simples de todos os elementos da matriz*/
	int sum = 0;
	int terms = 0;
	for (int i = 0; i < rows; i++ ) {
		for (int j = 0; j < cols; j++) {
			sum += m[i][j];
			terms++;
		}		
	}
	float result = (float)sum / terms;
	return result;
}

void init_values(int rows, int cols, int m[rows][cols], int start, int step) {
/*Inicia uma matriz com valores inteiros, iniciando em 'start' e progredindo com 'step'*/
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m[i][j] = start;
			start += step;
		}
	}
}

void init_random(int rows, int cols, int m[rows][cols], int min, int max) {
/*Inicia uma matriz com valores aleatorios*/
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int num = (rand() % (max-min+1)) + min; //Gera números aleatórios entre [min,max]
			m[i][j] = num;
		}
	}
}

int max_line(int rows, int cols, int m[rows][cols]) {
/*Retorna o total da linha de maior valor*/
	int max = -2147483648;
	for (int i = 0; i < rows; i++) {
		int sum = 0;
		for (int j = 0; j < cols; j++) {
			sum += m[i][j];	
		}
		if (sum > max) {
			max = sum;
		}
	}
	return max;
}

void put_totals(int rows, int cols, int m[rows][cols]) {
/*Recebe uma matriz e coloca as somas de cada linha na ultima coluna*/
	for (int i = 0; i < rows; i++) {
		int sum = 0;
		for (int j = 0; j < cols; j++) {
			sum += m[i][j];
		}
		m[i][cols-1] = sum;
	}
}

int matrix_equals(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){
/*Verifica a igualdade entre duas matrizes*/
	if (r1 != r2 || c1 != c2) {
		return 0;
	}
	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c1; j++) {
			if (m1[i][j] != m2[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

void sum(int rows, int cols, int m1[rows][cols], int m2[rows][cols], int m3[rows][cols]) {
/*Realiza a soma de duas matrizes*/
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m3[i][j] = m1[i][j] + m2[i][j];
		}
	}
}

void transpose(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]) {
/*Monta a transposta da matriz m1 em m2*/
	if (r1 != r2 || c1 != c2) {
		for (int i = 0; i < r1; i++) {
			for (int j = 0; j < c1; j++) {
				m2[j][i] = m1[i][j];
			}
		}
	}
} 

void switch_diagonals(int d, int m[d][d]) {
/*Troca as diagonais de uma matriz*/
	for (int i = 0, j = 0; i < d; i++, j++) {
		int tmp = m[i][j];
		m[i][j] = m[i][d-j-1];
		m[i][d-j-1] = tmp;
	}
}

void pascal_triangle(int n) {
/*Cria e imprime o triangulo de pascal*/
	int triangle[n][n+1];
	for (int t = 0; t < n+1; t++) {
		if (t == 1) {
			triangle[0][t] = 1;
		} else {
			triangle[0][t] = 0;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n+1; j++) {
			if (j == 0) {
				triangle[i][j] = 0;
				continue;
			} 
			triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n+1; j++) {
			printf("%d\t", triangle[i][j]);
		}
		printf("\n");
	}
}

int check_upper_triangle(int d, int m[d][d]) {
/*Verifica se uma função contem um triangulo superior*/
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < i; j++) {
			if (m[i][j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

int check_identity(int rows, int cols, int m[rows][cols]) {
/*Verifica se uma matriz é identidade*/
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (j == i) {
				if (m[i][j] != 1) {
					return 0;
				}
			} else {
				if (m[i][j] != 0) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int check_symmetric(int d, int m[d][d]) {
/*Verifica se uma matriz é simetrica*/
	for (int i = 0; i < d; i++) {
		for (int j = 1; i+j < d; j++) {
			if (m[i][i+j] != m[i+j][i]) {
				return 0;
			}
		}
	}
	return 1;
}

void print_strings(int n, int len, char list[n][len]) {
/*Imprime uma array de N strings até len-1*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len -1; j++) {
			printf("%c", list[i][j]);
		}
		printf("\n");
	}
}

void print_strings_minmax(int n, int len, char list[n][len]) {
/*Imprime as palavras de maior e menor tamanho em uma array de n strings até len-1*/
	int max = 0;
	int min = len;
	//Seria muito mais interessante salvar diretamente o ponteiro para a posição das palavras recordistas, mas não quero estender esse exercicio. Deixe ponteiros para a atividade de ponteiros
	int min_idx = 0;
	int max_idx = 0;
	int min_word[8] = {0};
	int max_word[8] = {0};
	for (int i = 0; i < n; i++) {
		int char_num = 0;
		for (int j = 0; j < len -1; j++) {
			if (list[i][j] != '\0') {
				char_num++;
			}
		}	
		if (char_num >= max) {
			if (char_num > max) {
				//Se a palavra é maior que o recorde, limpa a array de recordistas
				for (int k = 0; k < 8; k++) {
					max_word[k] = 0;
				}
				max_idx = 0;
			}
			max = char_num;
			max_word[max_idx] = i;
			max_idx++;
		}
		if (char_num <= min) {
			if (char_num < min) {
				//Se a palavra for menor que o recorde, limpa a array de recordistas
				for (int k = 0; k < 8; k++) {
					min_word[k] = 0;
				}
				min_idx = 0;
			}
			min = char_num;
			min_word[min_idx] = i;
			min_idx++;
		}
	}
	printf("Menor: ");
	for (int i = 0; i < 8; i++) {
		if (min_word[i] != 0) {
			int k = min_word[i];
			for (int j = 0; list[k][j] != '\0'; j++) {
				printf("%c", list[k][j]);
			}
			printf("; ");
		}
	}
	printf("\nMaior: ");
	for (int i = 0; i < 8; i++) {
		if (max_word[i] != 0) {
			int k = max_word[i];
			for (int j = 0; list[k][j] != '\0'; j++) {
				printf("%c", list[k][j]);
			}
			printf("; ");
		}
	}
	printf("\n");
}

int count_words(int n, int len, char lines[n][len]) {
/*Retorna a quantidade de palavras em um array de N linhas de texto*/
	int words_counted = 0;
	int bool = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len-1 && lines[i][j] != '\0'; j++) {
			if (((lines[i][j] >= 65 && lines[i][j] < 91) || (lines[i][j] >= 97 && lines[i][j] < 123)) && bool == 0) {
				bool = 1;
				words_counted++;
			} else if (lines[i][j] == ' ') {
				bool = 0;
			}

		}
	}
	return words_counted;
}

int count_ocorrences(int n, int len, char lines[n][len], char *word) {
/*Conta o  numero de ocorrencias de dada palavra em um texto*/
	int count = 0;
	int idx_word = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len && lines[i][j] != '\0'; j++) {
			if (lines[i][j] == word[idx_word]) {
				idx_word++;
				if (word[idx_word] == '\0') {
					count++;
				}
			} else {
				idx_word = 0;
			}
		}
	}
	return count;
}

int main() {
//NOTE: Para testar as funções, é necessario descomentar as chamadas de função e - caso necessario - atualizar os parâmetros
	int matrix[3][3] = {
		{1,2,3},
		{2,4,5},
		{3,5,8}
	};

	int matriz[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
	};

	int mat[4][5] = {
		{1,2,3,4,0},
		{2,4,6,8,0},
		{3,6,9,12,0},
		{4,8,12,16,0}
	};
	int sqr[3][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8}
	};
	int trg[3][3] = {
		{1,1,1},
		{0,1,1},
		{0,0,1}
	};
	int idn[4][4] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
	};
	char names[6][20] = {
		"John",
		"Mary",
		"Jake",
		"Bob",
		"Ada",
		"Michael"
	};

	char text[2][200] = {
		" Computer programming is the process of designing and building an executable computer program for accomplishing a specific computing task.",
		" Programming involves tasks such as analysis, generating algorithms, profiling algorithms accuracy and resource consumption, and the implementation of algorithms in a chosen programming language."
};

	char text2[5][200] = {
		"computer programming is the process of designing and building an executable computer program for accomplishing a specific computing task.",
"programming involves tasks such as analysis, generating algorithms, profiling algorithms accuracy and resource consumption, and the implementation of algorithms in a chosen programming language.",
"the source code of a program is written in one or more programming languages.","the purpose of programming is to find a sequence of instructions that will automate the performance of a task for solving a given problem.",
"the process of programming thus often requires expertise in several different subjects, including knowledge of the application domain, specialized algorithms, and formal logic."
	};

	char word[] = "programming";	

	int voidMatrix[4][3];
	//print_matrix(3, 4, matrix);
	//print_reversed(3,4, matrix);
	//print_min_max(3,4,matrix);
	//average(3,4,matrix);
	//init_value:s(4,6,voidMatrix, 10, 2);
	//init_random(4,6,voidMatrix, 5, 50);
	//max_line(3, 4, matrix);
	//put_totals(4,5,mat);
	//matrix_equals(3,4,matrix, 3,4,matriz);
	//sum(4,6, matrix, matriz, voidMatrix);
	//transpose(3,4,matrix,4,3,voidMatrix);
	//switch_diagonals(3, sqr);
	//pascal_triangle(5);
	//check_upper_triangle(3,trg);
	//printf("%d\n",check_identity(4,4,idn));
	//printf("%d\n",check_symmetric(3, matrix));
	//print_strings(6,20,names);
	//print_strings_minmax(6,20,names);
	//printf("Numero de Palavras: %d\n",count_words(2, 200, text));
	//printf("Ocorrencias encontradas: %d\n", count_ocorrences(5, 200, text2, word));

	return 0;
}

//Aqui é o fundo da toca do coelho Neo
