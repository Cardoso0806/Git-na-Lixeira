#include <stdio.h>

typedef struct Product {
	int id;
	int stock;
	char name[100];
} Product;

void fill(int* vec, int n) {
	int *end = vec + n;
	int num = 1;
	while (vec < end) {
		*vec = num; 
		printf("%d\n", *vec);
		num += 2;
		vec++;
	} 
}

void check_stock(const Product* prods, int n_prods, int* orders, int* n_order) {
	const Product* item = prods;
	const Product* end = item + n_prods;
	while (item < end) {
		if ((*item).stock < 0) {
			*orders = (*item).id;
			orders++;
			n_order++;
			printf("%s\n", (*item).name);
		}
		item++;	
	}
}

typedef struct {
	char name[100];
	float price;
	int type;
} Produto;


void count_types(const Produto* vec, int n, int* count) {
	int *count_pnt = count;
	const Produto *end = vec+n;
	while (vec < end) {
		count_pnt += (*vec).type;
		*count_pnt += 1;
		count_pnt = count;
		vec++;
	}
}



int main() {
	int vec[10];
	fill(vec, 10);
	
	Produto produtos2[] = {
		{"Maça",10,0},
		{"Laranja",20,0},
		{"Carne",30,2},
		{"Linguiça",30,2},
		{"Leite",5,1}
	};

	Product produtos[] = {
		{0,5,"Madeira"},
		{1,23,"Ferro"},
		{2,64,"Carvão"},
		{3,-32,"Pedra"}
	};
	
	int pedidos[4];
	int n_orders = 0;

	check_stock(produtos, 4, pedidos, &n_orders);

	int count[] = {0,0,0,0,0,0,0,0,0,0};

	count_types(produtos2, 5, count);
	
	for (int i = 0; i < 5; i++) {
		printf("%d\t", count[i]);
	}

	printf("\n");

	return 0;
}
