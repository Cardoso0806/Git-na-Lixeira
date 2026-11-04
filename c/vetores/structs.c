#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct point {
	float x;
	float y;
};
typedef struct point Point;

struct nearest {
	float x1;
	float x2;
	float y1;
	float y2;
	float d;
};
typedef struct nearest Nearest;

struct contact {
	int id;
	char name[64];
	char email[72];
	int type;
};
typedef struct contact Contact;

struct employee {
	char name[64];
	float salary;
	int type; // 0 - dev, 1 - designer, 2 - manager, 3 - support
};
typedef struct employee Employee;

struct best {
	Employee first;
	Employee second;
	Employee third;
};
typedef struct best Best;

void print_point(Point p) {
/*Recebe um ponto (x,y) e o imprime com 2 casas de precisão.*/
	printf("x = %.2f\ny = %.2f\n", p.x, p.y);
}

float distance2D(Point p1, Point p2) {
/*Retorna a distância entre dois pontos.*/
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;
	float d = (float) sqrt((dx*dx) + (dy*dy));
	return d;
}

void distance_vector(int n, Point v[]) {
/*Recebe um vetor de pontos e retorna a distância entre dois pontos consecutivos.*/
	for (int i = 1; i < n; i++) {
		Point p2 = v[i];
		Point p1 = v[i-1];
		float dx = p2.x - p1.x;
		float dy = p2.y - p1.y;
		float d = (float) sqrt((dx*dx) + (dy*dy));
		printf("dp%d = %.2f\n", i, d);
	}
}

void random_points(int n, Point v[]) {
/*Recebe um vetor de pontos e os inicia com valores float aleatórios.*/
	for (int i = 0; i < n; i++) {	
		v[i].x = rand() / (float) RAND_MAX * 100 - 50;
		v[i].y = rand() / (float) RAND_MAX * 100 - 50;
	}
}

void nearest_points(int n, Point v[]) {
/*Encontra os dois pontos mais próximos em umm vetor de pontos.*/
	Nearest menor = {v[0].x, v[1].x, v[0].y, v[1].y, distance2D(v[0], v[1])}; 
	for(int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			float d = distance2D(v[i], v[j]);
			printf("%f\n", d);
			if (menor.d > d) {
				menor.x1 = v[i].x;
				menor.x2 = v[j].x;
				menor.y1 = v[i].y;
				menor.y2 = v[j].y;
				menor.d = d;
			}
		}
	}
	printf("p1 = (%f,%f)\np2 = (%f,%f)\ndistance = %f\n", menor.x1, menor.y1, menor.x2, menor.y2, menor.d);
}

void print_contact(Contact c, int n, char type_names[n][64]) {
/*Imprime os valores contidos no struct contact recebido.*/
	printf("id: %i\nnome: %s\nemail: %s\ntipo: %s\n", c.id, c.name, c.email, type_names[c.type]);	
}

void print_contact_list(int n1, Contact list[n1], int n2, char types[n2][64]) {
/*Imprime os contatos agrupados por tipo*/
	for (int i = 0; i < n2; i++) {
		int first = 0;
		for (int j = 0; j < n1; j++) {
			if (list[j].type == i) {
				if (first == 0) {
					printf("%s\n", types[i]);
					first = 1;
				}
				printf("\t%s\n", list[j].name);
			}
		}
	}
}

void print_best3(int n, Employee v[n]) {
/*Retorna os três funcionários de maior salário em um vetor.*/
	Best melhores; 
	for (int i = 0; i < n; i++) {
		if (i < 1) {
			melhores.first = v[i];  
			continue;
		}
		if (melhores.first.salary < v[i].salary) {
			melhores.third = melhores.second;
			melhores.second = melhores.first;
			melhores.first = v[i];
			continue;
		} 
		if (melhores.second.salary < v[i].salary) {
			melhores.third = melhores.second;
			melhores.second = v[i];
			continue;
		}
		if (melhores.third.salary < v[i].salary) {
			melhores.third = v[i];
			continue;
		}
	}
	printf("Maiores salários\nPrimeiro%s\nSegunfo%s\nTerceiro%s\n", melhores.first.name, melhores.second.name, melhores.third.name);
}

void income_report(int n, Employee v[n]) {
/*Calcula e imprime a media salarial total, por cargo e o total em salarios*/
	float total = 0.0;
	char cargos[4][32] = {"Developer","Designer", "Manager", "Support"};
	float cargos_salario[4] = {0.0,0.0,0.0,0.0};
	for (int i = 0; i < 4; i++) {
		int equipe = 0;
		for (int j = 0; j < n; j++) {
			if (v[j].type == i) {
				total += v[j].salary;
				cargos_salario[i] += v[j].salary;
				equipe++;
			}
		}
		printf("%s: %.2f\n", cargos[i], cargos_salario[i] / equipe);
	}
	printf("Média Salarial Geral: %.2f\n", total / n);
	printf("Total em Salários: %.2f\n", total);
}

void fix_name(char name[]) {
/*Recebe e corrige, se necessário, um nome*/
	//Remove tudo que não é espaço ou letra
	for (int i = 0; name[i] != '\0'; i++) {
		if ((name[i] < 65 && name[i] != 32) || (name[i] >  90 && name[i] < 97) || name[i] > 122) {
			name[i] = 32;
		}
	}
	//Capitaliza o nome
	for (int j = 0; name[j] != '\0'; j++) {
		if (name[j] > 64 && name[j] < 91) {
			name[j] += 32;
		}
		if ((name[j] > 96 && name[j] < 123) && (j == 0 || name[j-1] == 32)) {
			name[j] -= 32;
		}
	}
	//Remove os espaços anteriores
	int size = 0;
	for (int k = 0; name[k] != '\0'; k++) {
		if (name[k] != 32) {
			name[k-size] = name[k];
		} else {
			if (name[k+1] != 32 && k > 0) {	
				continue;
			} else {
				size++;
			}
		}
	}
	//Corta o fim da string
	int last = 0;
	for (int t = 0; name[t] != 0; t++) {
		if (name[t] != 32) {
			last = t+1;
		}
	}
	name[last] = '\0';
}

Contact create_contact(int id, char name[], int type) {
/*Preenche um struct contato com base nos parametros*/
	Contact new;
	new.id = id;
	fix_name(name);
	strcpy(new.name, name);
	new.type = type;
	char email[64];

	int i = 0;
	while (name[i] != '\0') {
		if (name[i] == ' ') {
			name[i] = '.';
		}
		if (name[i] > 64 && name[i] < 91) {
			name[i] += 32;
		}
		email[i] = name[i];
		i++;
	}
	email[i+1] = '\0';
	strcat(email, "@mail.br");
	strcpy(new.email, email);
	return new;
}

int find_substring(const char *s1, const char *s2) { 
/*Informa se uma string esta contida dentro de outra.*/
	int k = 0;
	for (int i = 0; s1[i] != '\0'; i++) {
		if (s1[i] == s2[k]) {
			k++; 
			if (s2[k] == 0) {
				return 1;	
			}
		} else {
			k = 0;
		}
	} 
	return 0;
}

void fill_contact_list(int n, Contact list[n]) {
/*Preenche um vetor de contatos com dados aleatorios*/
	char names[5][64] = {
		"Ana Doe",
		"Bruno Santos",
		"Carolina Ferreira",
		"Daniel Doe",
		"Eduardo Silva"
	};
	for (int i = 0; i < n; i++) {
		int name = rand() % 5;
		int type = rand() % 5;
		char nome[64];
		strcpy(nome, names[name]);
		if (find_substring(nome, "Doe") == 1) {
			type = 1;
		}
		Contact new = create_contact(i+1, nome, type);
		list[i] = new;
	}
}

int find_by_name(int n1, Contact list[n1], int n2, char names[n2][64]) {
/*Retorna as ocorrencias de certos nomes na lista de contato*/
	int matchs = 0;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n1; j++) {
			if (find_substring(list[j].name, names[i]) == 1) {
				matchs++;
			}
		}
	}
	printf("%d\n", matchs);
	return matchs;
}

int main() {
	Point prime = {3.14159, 2.71828};
	Point p1 = {1.0, 1.0};
	Point p2 = {5.0, 4.0}; 
	Point d[] = {{0.0, 0.0},{0.0, 1.0},{1.0, 0.0},{0.0, 0.0}};
	Point voidV[16];
	//print_point(prime);
	//printf("%.2f\n", distance2D(p1, p2));
	//distance_vector(4, d);
	//random_points(16, voidV);
	//nearest_points(16, voidV);

	char types[5][64] = {"Familia","Amigos","Trabalho","Escola","Outros"};
	Contact c = {1, "João Silva", "joao123@email.com", 2};
	Contact list[] = {
		{1, "Ada Lovelace", "Lovelace@email.com", 1},
		{2, "Alan Turing", "Turing@email.com", 3},
		{3, "Dennis Ritche", "DRitche@email.com", 0},
		{4, "Linus Torvalds", "torvalds@email.com", 4},
		{5, "GabeN", "gaben@valvesoftware.com", 2}
	};
	//print_contact(c, 5, types);
	//print_contact_list(5, list, 5, types);
	
	Employee func[] = {
		{"Ana", 1024.00, 1},
		{"João", 9000.00, 2},
		{"Maria", 1024.00, 3},
		{"Bruno", 2048.00, 0},
		{"Carolina", 4096.00, 0},
		{"Daniel", 8192.00, 2}
	};
	//print_best3(6, func);
	//income_report(6, func);
	
	char name[64] = " JoHN  DOE# 23!    ";
	Contact lista[15];

	//fix_name(name);
	//print_contact(create_contact(1, name, 0), 5, types);
	//fill_contact_list(15, lista);
	//print_contact_list(15, lista, 5, types);

	char names[5][64] = {
		"Ana",
		"Bernardo",
		"Carlos",
		"Douglas",
		"Eduardo"
	};

	//find_by_name(15, lista, 5, names);

	return 0;
}
