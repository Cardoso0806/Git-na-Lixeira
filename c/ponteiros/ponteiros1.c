#include <stdio.h>

struct rect {
	int x, y, width, height;
}; 
typedef struct rect Rect;

struct point {
	int x, y;
	char symbol;
};
typedef struct point Point;

void varias_variaveis() {
/*Declara tres variaveis e imprime o endereço delas*/
	char letra = 'A';
	int num = 16;
	double e = 2.7182818284;
	printf("char: %p\nint: %p\ndouble: %p\n", &letra, &num, &e);
}

void add(int* a, int* b) {
/*Recebe dois endereços e soma os valores nessas posições*/
	*a += *b;
	printf("%d\n", *a);
}

void print_vector(int n, const int *v) {
/*Imprime um vetor*/
	while (*v < n) {
		printf("%d\n", *v);
		v++;
	}
}

void print_vector_reverse(int n, const int* v) {
/*Imprime o vetor em ordem reversa*/
	int p = *(v+n-1);
	while (p > -1) {
		printf("%d\n", p);
		p--;
	}
}

void get_min_max(int n, const int *v, int *min, int *max) {
/*Verifica o menor e o maior valor dentro de uma string*/
	int p = *v;
	while (p < n) {
		if (p > *max) {
			*max = p;
		}
		if (*min > p) {
			*min = p;
		}
		p++;
	}
	printf("min: %d\nmax: %d\n", *min, *max);
}

void print_vec2(int rows, int cols, const int *v) {
/*Imprime os valores contidos em uma matriz*/
	const int *pr = v; 
	const int *end = v + rows * cols;
	while (pr < end) {
		const int *pc = pr;
		const int *row_end = pr + cols;
		while (pc < row_end) {
			printf("%d ", *pc);
			pc++;
		}
		pr += cols;
		printf("\n");
	}
}

void make_mirrored(char* str) {
/*Adiciona o espelhamento da string ao final da string*/
	char *last = str;
	while (*last != 0) {
		last++; 
	}
	char *mirror_pnt = last - 1;
	*last = 124; //torna o '\0' em '|'
	last++;
	while (mirror_pnt >= str){
		*last = *mirror_pnt;
		last++;
		mirror_pnt--;
	}
	last++;
	*last = '\0';
}

int get_hamming_distance(const char* str1, const char* str2) {
/*Verifica a distancia de Hamming entre duas palavras*/
	const char *ptr1 = str1;
	const char *ptr2 = str2;
	int hamming = 0;
	
	while (*ptr1 != '\0') {
		if (*ptr1 != *ptr2) {
			hamming++;
		}
		ptr1++;
		ptr2++;
	}

	return hamming;
}

char* find_most_similar(const char* str, int n, char *list) {
/*Encontra a palavra mais similar a str dentro de um vetor de strings*/
	char *str2 = list;
	char *end = list + (n * 50);
	int min_dhum = 50;
	char *most_similar; 
	while (str2 < end) {
		int dhum = get_hamming_distance(str, str2);
		if (dhum < min_dhum) {
			min_dhum = dhum;
			most_similar = str2;
		}
		str2++;
	}
	return most_similar;
}

void print_board(Rect* board) {
/*Imprime um retangulo na tela*/
	printf("\033[2J"); // limpa o terminal
	int y_cursor = 0;	
	while (y_cursor < (*board).height) {
		int x_cursor = 0;
		while (x_cursor < (*board).width) {
			if (x_cursor >= (*board).x && y_cursor >= (*board).y) {
				printf("░░");
			} else {
				printf("  ");
			}
			x_cursor++;
		}
		printf("\n");
		y_cursor++;
	}
}

void print_board2(Point* point, Rect* board) {
/*Imprime o caractere de point dentro tabulado*/
	printf("\033[2J"); // limpa o terminal
	int y_cursor = 0;	
	while (y_cursor < (*board).height) {
		int x_cursor = 0;
		while (x_cursor < (*board).width) {
			if (x_cursor >= (*board).x && y_cursor >= (*board).y) {
				if ((x_cursor - (*board).x) == (*point).x && (y_cursor - (*board).y) == (*point).y) {
					printf("%c%c", (*point).symbol, (*point).symbol);
				} else {
					printf("░░");
				}
			} else {
				printf("  ");
			}
			x_cursor++;
		}
		printf("\n");
		y_cursor++;
	}
}

void print_board3(Point* points, Rect* board) {
/*Imprime todos os pontos dentro do tabulado*/
	printf("\033[2J"); // limpa o terminal
	int y_cursor = 0;	
	Point* ponto = points;
	while (y_cursor < (*board).height) {
		int x_cursor = 0;
		while (x_cursor < (*board).width) {
			if (x_cursor >= (*board).x && y_cursor >= (*board).y) {
				if ((x_cursor - (*board).x) == (*ponto).x && (y_cursor - (*board).y) == (*ponto).y) {
					printf("%c%c", (*ponto).symbol, (*ponto).symbol);
					ponto++;
				} else {
					printf("░░");
				}
			} else {
				printf("  ");
			}
			x_cursor++;
		}
		printf("\n");
		y_cursor++;
	}
}

int main() {
	int a = 5;
	int b = 5;
	int *pa = &a;
	int *pb = &b;
	int vector[] = {0,1,2,3,4,5,6,7,8,9};

	//varias_var1iaveis();
	//add(pa, pb);
	//print_vector(10, vector);
	//print_vector_reverse(10, vector);
	
	int min = 255;
	int max = -256;

	//get_min_max(10, vector, &min, &max);

	int matrix[3][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8}
	};

	//print_vec2(3, 3, (int*)matrix);
	
	char name[64] = "Juscelino Kubitschek";
	//make_mirrored(name);
	//printf("%s\n", name);
	
	char banana[7] = "banana";
	char cabana[7] = "cabana";
	char words[][50] = {
		"cabana",
		"savana",
		"bacana",
		"halana"
	};	

	//char* list = words[0];
	//get_hamming_distance(banana, cabana);
	
	//char* most_similar = find_most_similar(banana, 4, list);
	//printf("%s\n", most_similar);

	Rect board = {15,15,30,30};
	Point point = {0,0,'@'};

	Point points[] = {
		{0,0,'A'},
		{2,7,'B'},
		{9,9,'C'}
	};

	//print_board(&board);
	//print_board2(&point, &board);
	print_board3((Point*)points, &board);
	return 0;
}

/*Tomo esse final de arquivo como nota de insatisfação quanto a sintaxe de  ponteiros. Demorei 1h so para acostumar com '*p' sendo tanto declaração quanto acesso de valor de um endereço. Ritchie, o que custava tornar a declaração de ponteiro algo como '&p'?*/
/*Dito isso, nunca esqueça de desalocar os ponteiros, aqui não fiz pois não foi abordado em aula ainda.*/
