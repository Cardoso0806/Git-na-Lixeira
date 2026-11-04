#include <stdio.h>
#include <math.h>
#include <limits.h>

void print_all(int n, int *vet){
/*Função interna de Debug. Recebe um vetor e seu tamanho e imprime todos os seus elementos.*/
	for (int i = 0; i < n; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}

void print_even(int n, int vet[]){
/*Recebe um vetor e seu tamanho e imprime somennte os valores pares.*/
	for (int i = 0; i < n; i++){
		if (vet[i] % 2 == 0) {
			printf("%d\n", vet[i]);
		}
	}
}

void set_positive(int n, int *vet){
/*Recebe um vetor de valores inteiros e modifica os valores negativos para positivos.*/
	for (int i = 0; i < n; i++){
		if (vet[i] < 0) {
			vet[i] *= -1;
		}	
	printf("%d\n", vet[i]);
	}
}

int find_max(int n, int *vet) {
/*Recebe um vetor e seu tamanho e retorna o maior valor nele contido.*/
	int max = vet[0];
	for (int i = 1; i < n; i++){
		if (vet[i] > max){
			max = vet[i];
		}
	}
	printf("%d\n", max);
	return max;
}

void replace_all(int n, int *vet, int elem) {
/*Recebe um vetor, seu tamanho e um elemento n, procura as ocorrencias do elemento n e o substitui por -1.*/
	for (int i = 0; i < n; i++){
		if (vet[i] == elem){
			vet[i] = -1;
		}
	printf("%d\n", vet[i]);
	}
}

void read_vector(int n, int *vet) {
/*Recebe um vetor vazio e seu tamanho n, lê n inteiros e os adiciona ao vetor.*/
	int input;
	for (int i = 0; i < n; i++){
		printf("> ");
		scanf("%d", &input);
		vet[i] = input;
	}
	print_all(n, vet);
}

int is_sorted(int n, int *vet) {
/*Verifica se os elementos de um dado vetor estão em ordem crescente.*/
	for (int i = 0; i < n - 1; i++){
		if (vet[i] > vet[i+1]){
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");
	return 1;
}

void distances(int n, int points[]){
/*Recebe um vetor com pares de coordenadas e calcula a distância entre dois pares consecutivos. Note que em uma situação real, utilizar uma matriz n,2 seria mais recomendado.*/
//NOTE: por algum motivo que eu desconheço, o compilador só aceita sqrt() como válido se a flag -lm for especificada. 
	for (int i = 2; i < n; i += 2) {
		int dx = points[i] - points[i-2];
		int dy = points[i + 1] - points[i - 1];
		float tmp = (float) dx * dx + (float) dy * dy;
		float distance = sqrt(tmp);
		printf("dx = %d\ndy = %d\ndistance = %f\n", dx, dy, distance);
	}
}

void reverse(int n, int *vet) {
/*Recebe um vetor e inverte a ordem de seus elementos.*/
	for (int i = 0; i < n / 2; i++){
		int opst = n - 1 - i;
		int tmp = vet[i];
		vet[i] = vet[opst];
		vet[opst] = tmp;
	}
	print_all(n, vet);
}

void vector_copy(int n, int *vetA, int *vetB) {
/*Copia os elementos de um vetor A para um vetor B de igual tamanho.*/
	for (int i = 0; i < n; i++) {
		vetB[i] = vetA[i];
	}
	print_all(n, vetA);
	print_all(n, vetB);
}

int vector_insert(int n, int *vet, int elem) {
/*Recebe um vetor e um elemento n, insere n na primeira ocorrencia de um espaço disponível - denotada por -1 - e retorna se o valor foi inserido com sucesso.*/
	for (int i = 0; i < n; i++) {
		if (vet[i] == -1) {
			vet[i] = elem;
			printf("1\n");
			return 1;
		}
	}
	printf("0\n");
	return 0;
}

int vector_remove(int n, int *vet, int pos) {
/*Recebe um vetor e uma posição n, remove o elemento de vet[n] - denotando a disponibilidade com -1 - e retorna se o valor foi removido com sucesso.*/
	if (pos >= 0 && pos < n) {
		vet[pos] = -1;
		return 1;
	}
	return 0;
}

void vector_defrag(int n, int *vet){
/*Recebe um vetor e move seus elementos de modo a trazer todos os elementos válidos em sequência.*/
	for (int i = 0; i < n; i++) {
		if (vet[i] == -1) {	
		for (int j = 1; i+j < n; j++) {
			if (vet[i+j] != -1){	
				vet[i] = vet[i+j];
				vet[i+j] = -1;
				break;
			}
		}
		}
	}
}

void vector_concat(int n1, int *v1, int n2, int *v2, int *v3) {
/*Concatena os vetores A e B em vetor C de tamanho tA + tB.*/
	for (int i = 0; i < n1; i++) {
		v3[i] = v1[i];
	}
	for (int i = n1, j = 0; i < (n1 + n2); i++, j++) {
		v3[i] =  v2[j];
	}
}

void merge(int n1, int *v1, int n2, int *v2, int * v3) {
/*Mescla dois vetores em ordem crescente.*/
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n1 && j < n2) {
		if (v1[i] <= v2[j]) {
			v3[k] = v1[i];
			k++;
			i++;
		} else {
			v3[k] = v2[j];
			k++; 
			j++;
		}
	}
	while (i < n1) {
		v3[k] = v1[i];
		k++; i++;
	}
	while (j < n2) {
		v3[k] = v2[j];
		k++; j++;
	}
}

int max_sum_slice2(int n, int *v) {
/*Determina o segmento de soma máxima em um vetor.*/
	int maxSum = INT_MIN;
	for (int largura = 1; largura < n; largura++) {		
		for (int j = 0; j + largura < n; j++) {
			int sum = 0;
			for (int i = j; i <= j + largura; i++) {
				sum += v[i];
			}
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}
	printf("%d\n", maxSum);
	return maxSum;
} 

void count_elements(int n, int *v) {	
/*Realiza a contagem de aparições de um elemento em dado vetor.*/
	unsigned char count[255] = {0};
	for (int i = 0; i < n; i++) {
		count[v[i]]++;
	}
}

void selectionSort(int n, int *v) {
/*Função de apoio para min_bills. Ordena os elementos de um vetor em ordem decrescente.*/
	for (int i = 0; i < n - 1; i++) {
       
        	int max_idx = i;
        	for (int j = i + 1; j < n; j++) {
            	if (v[j] > v[max_idx]) {
                	max_idx = j;
            	}
        	} 
        	int temp = v[i];
        	v[i] = v[max_idx];
		v[max_idx] = temp;
    	}
}

void min_bills(int value, int n, int *bills) {
/*Retorna a quantidade minima de notas para acumular certa quantia monetária, mas só em Reais...*/
	selectionSort(n, bills);
	for (int i = 0; i < n && value > 0; i++) {
		int qtd = value / bills[i];
		if (qtd > 0) {
			printf("%d x R$%d,00\n", qtd, bills[i]);
			value %= bills[i];
		}
	}
	if (value > 0) {
		printf("Sobraram R$%d,00\n", value);
	}
}

void vector_union(int n1, int *v1, int n2, int *v2, int *v3) {
/*Realiza a União entre dois vetores.*/
	//WARNING: ALTO EM AÇÚCAR!
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n1; j++) {
			if (v2[i] == v1[j]) {
				v2[i] = -1;
				break;
			}
		}
	}
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n1 && j < n2) {
		if (v2[j] >= 0) {
			if (v1[i] <= v2[j]) {
				v3[k] = v1[i];
				k++;
				i++;
			} else {
				v3[k] = v2[j];
				k++; 
				j++;
			}
		} else {
			v3[k] = v1[i];
			k++;
			j++;
			i++;
		}
	}
	while (i < n1) {
		v3[k] = v1[i];
		k++; i++;
	}
	while (j < n2) {
		v3[k] = v2[j];
		k++; j++;
	}
}

void vector_intersection(int n1, int *v1, int n2, int *v2, int *v3) {
/*Calcula a Intersecção entre dois vetores.*/
	int k = 0;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n1; j++) {
			if (v2[i] == v1[j]) {
				v3[k] = v2[i];
				k++;
				break;
			}
		}
	}
}

int main() {
	//NOTE: é necessário criar os vetores e chamar a função manualmente. 

	//print_all(4, vet2);
	
	//print_even(8, vet);
	//set_positive(8, vet);
	//find_max(8, vet);
	//replace_all(8, vet, 1);
	//read_vector(8, voidVet);
	//is_sorted(8, vet);
	//distances(8, vet);
	//reverse(9, vet);
	//vector_copy(8, vet, voidVet);
	//vector_insert(8, vet, 9);
	//vector_remove(8, vet, 5);
	//vector_defrag(8, vet);
	//vector_concat(8, vet, 4, vet2, voidVet);	
	//merge(8, vet, 4, vet2, voidVet);
	//max_sum_slice2(12, vet);
	//count_elements(12, vet);
	//min_bills(209, 5, vet2);
	//vector_union(5, vet, 3, vet2, voidVet);
	//vector_intersection(5, vet, 3, vet2, voidVet);
	return 0;
}
