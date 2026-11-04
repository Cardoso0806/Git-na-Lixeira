#include <stdio.h>

int hello(){
/*Imprime um texto*/
	printf(" ------------------------\n");
	printf("[   PROGRAMANDO EM C!   ]\n");
	printf(" ------------------------\n");
	return 0;
}

int somaSub(){
/*Imprime a soma e a subtração de dois valores indicados pelo usuario*/
	int a, b;
	printf("Insira dois valores decimais: ");
	scanf("%d %d", &a, &b);
	printf("a + b = %d\na - b = %d\n", a + b, a - b);
	return 0;
}

int perArea() {
/*Imprime o perimetro e a area de um retangulo informado pelo usuario*/
	int la, lb;
	printf("Informe as laterais do retângulo: ");
	scanf("%d %d", &la, &lb);
	int pr = (int)((la + lb) * 2);
	int ar = (int)(la * lb);
	printf("O perímetro do retângulo é %d\nA área do retângulo é %d\n", pr, ar);
	return 0;
}

int mulDiv(){
/*Imprime o produto, a razão e o modulo de dois numeros informados pelo usuario*/
	int a, b;
	printf("Defina dois valores: ");
	scanf("%d %d", &a, &b);
	int mult = a * b;
	int dvi = a/b;
	float dvf = (float)a/b;
		
	printf("a * b = %d\na // b = %d\na / b = %f\n", mult, dvi, dvf);
	return 0;
}

int grauRad() {
/*Converte graus para radiano*/
	const float PI = 3.141593;
	int input;
	printf("Graus: ");
	scanf("%d", &input);
	float rad = (((float)input) * PI) / 180;
	printf("Radiano: %.2fπ\n", rad / PI);
	return 0;
}

int diaCir() {
/*Imprime o diametro e a circunferencia de um circulo informado pelo usuario*/
	const float PI = 3.141593;
	float raio;
	printf("Raio: ");
	scanf("%f", &raio);
	float diametro = 2 * raio;
	float circunferencia = 2 * PI * raio;
	float area = PI * (raio * raio);
	printf("Diametro = %.2f\nCircunferencia = %.2f\nArea = %.2f\n", diametro, circunferencia, area);
	return 0;
}

int medias(){
/*Imprime a media aritmetica e ponderada de tres valores informados pelo usuario*/
	int a, b, c;
	printf("Informe três valores: ");
	scanf("%d %d %d", &a, &b, &c);

	float mdArt = (a + b + c) / 3.0;
	float mdPond = ((a * 0.1) + (b * 0.5) + (c * 0.4));
	printf("Média Aritmética: %f\nMédia Ponderada: %f\n", mdArt, mdPond);
	return 0;
}

int medias2() {
/*Imprime as medias aritmetica e ponderada de tres valores informados pelo usuario, junto dos pesos tambem informados*/
	int a, b, c;
	float pa, pb, pc;
	printf("Informe três valores (int, int, int): ");
	scanf("%d %d %d", &a, &b, &c);

	printf("Informe três pesos (float, float, float): ");
	scanf("%f %f %f", &pa, &pb, &pc);

	float mdArt = (a + b + c) / 3.0;
	float mdPond = ((a * pa) + (b * pb) + (c * pc));
	printf("Média Aritmética: %f\nMédia Ponderada: %f\n", mdArt, mdPond);
	return 0;
}

int resto() {
/*Imprime o resto da divisão de dois numeros informados pelo usuario*/
	int a, b;
	printf("Insira dois numeros inteiros (int / int): ");
	scanf("%d %d", &a, &b);

	printf("Resto: %d\n", a % b);
	
	int div = a / b;
	a -= (div * b);

	printf("Resto: %d\n", a);
	return 0;
}

int tabuada() {
/*Imprime a tabuada de um numero informado pelo usuario*/
	
	int numero;
	scanf("%d", &numero);

	printf("%d * 1 = %2d\n", numero, numero * 1);
	printf("%d * 2 = %2d\n", numero, numero * 2);
	printf("%d * 3 = %2d\n", numero, numero * 3);
	printf("%d * 4 = %2d\n", numero, numero * 4);
	printf("%d * 5 = %2d\n", numero, numero * 5);
	printf("%d * 6 = %2d\n", numero, numero * 6);
	printf("%d * 7 = %2d\n", numero, numero * 7);
	printf("%d * 8 = %2d\n", numero, numero * 8);
	printf("%d * 9 = %2d\n", numero, numero * 9);

	return 0;
	//Comenrario foda
}

int floats() {
/*Imprime um float em diferentes formas*/
	float numero;
	printf("Informe um valor (float): ");
	scanf("%f", &numero);
	
	printf("Duas casas de precisão: %.3g\n", numero);
	printf("Parte inteira: %d\n", (int)numero);
	printf("Parte decimal: %f\n", (numero - (int)numero));
	printf("N. Científica: %e\n", numero);
	return 0;
}

int dias() {
/*converte dias em anos/semanas/dias*/
	int input;
	printf("Informe a quantidade de dias: ");
	scanf("%d", &input);
	int dias = input;
	int anos = (dias / 365);
	dias -= anos * 365;
	int semanas = dias / 7;
	dias -= semanas * 7;
	printf("Dias: %d = %d ano(s), %d semana(s) e %d dia(s)\n", input, anos, semanas, dias);
	return 0;
}

int mod() {
/*Imprime o modulo de um valor informado pelo usuario*/
	int valor;
	printf("Insira algum valor: ");
	scanf("%d", &valor);
	
	if (valor >= 0){
		printf("|%d| = %d\n", valor, valor);
	}else if (valor < 0){
		printf("|%d| = %d\n", valor, valor * -1);
	}

	return 0;
}

int extenso() {
/*Imprime o nome de um numero por extenso*/
    int valor;
	printf("Insira um valor entre 0 e 9: ");
	scanf("%d", &valor);
	if (valor < 9 && valor > 0){
		if (valor == 0) {
			printf("zero\n");
		} else if (valor == 1) {
			printf("um\n");
		} else if (valor == 2) {
			printf("dois\n");
		} else if (valor == 3) {
			printf("três\n");
		} else if (valor == 4) {
			printf("quatro\n");
		} else if (valor == 5) {
			printf("cinco\n");
		} else if (valor == 6) {
			printf("seis\n");
		} else if (valor == 7) {
			printf("sete\n");
		} else if (valor == 8) {
			printf("oito\n");
		} else {
			printf("nove\n");
		}
	} else {
		printf("ERRO: Valor %d esta fora do conjunto {0 <= x <= 9}\n", valor);
	}
	return 0;
}

int paridade(){
/*Verifica se um numero é par ou impar*/
    int valor;
	printf("Insira um valor: ");
	scanf("%d", &valor);
	if (valor % 2 == 0){
		printf("%d é par\n", valor);
	} else {
		printf("%d é ímpar\n", valor);
	}
	return 0; 
}

int e_bissexto(){
/*Verifica se um numero é bissexto*/
	int ano;
	printf("Insira um ano: ");
	scanf("%d", &ano);

	if (ano % 400 == 0 || ano % 4 == 0 && ano % 100 != 0){
		printf("%d é um ano bissexto\n", ano);
	} else {
		printf("%d não é um ano bissexto\n", ano);
	}
	return 0;
}

int notas() {
/*Calcula o conceito de um aluno com base em sua nota*/
	float n1, n2, n3;
	printf("Insira as notas do aluno (f f f): ");
	scanf("%f %f %f", &n1, &n2, &n3);
	
	float media = (float)(n1 + n2 + n3) / 3;

	if (media <= 10.0 && media >= 8.5) {
		printf("Média = %.2f, Conceito A\n", media);
	} else if (media < 8.5 && media >= 7.0) {
		printf("Média = %.2f, Conceito B\n", media);
	} else if (media < 7.0 && media >= 5.5) {
		printf("Média = %.2f, Conceito C\n", media);
	} else if (media < 5.5) {
		printf("Média = %.2f, Conceito F\n", media);
	} else {
		printf("ERRO: média fora dos limites esperados!\n");
	}
	return 0;
}

int maior() {
/*Verifica o maior entre quatro valores indicados pelo usuario*/
	int a,b,c,d;
	printf("Insira quatro valores (a b c d): ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (a > b){
		if (a > c) {
			if (a > d) {
				printf("%d é o maior\n", a);
			} else {
				printf("%d é o maior\n", d);
			}
		} else {
			if (c > d) {
				printf("%d é o maior\n", c);
			} else {
				printf("%d é o maior\n", d);
			}
		}
	} else {
		if (b > c) {
			if (b > d) {
				printf("%d é o maior\n", b);
			} else {
				printf("%d é o maior\n", d);
			}
		} else {
			if (c > d) {
				printf("%d é o maior\n", c);
			} else {
				printf("%d é o maior\n", d);
			}
		}
	}

	return 0;
}


int maior2() {
/*imprime os valores informados pelo usuario em ordem crescente*/
	int a, b, c;
	printf("Insira três valores(d d d): ");
	scanf("%d %d %d", &a, &b, &c);

	if (a > b) {
		if (b > c) {
			printf("%d %d %d\n", c, b, a);
		} else {
			if (c > a){
				printf("%d %d %d\n", b, a, c);
			} else{
				printf("%d %d %d\n", b, c, a);
		
			}
		}
	} else {
		if (a > c) {
			printf("%d %d %d\n", c, a, b);
		} else {
			if (b > c){
				printf("%d %d %d\n", a, c, b);
			} else {
				printf("%d %d %d\n", a, b, c);
			}
		}
	}
	return 0;
}

int decompor() {
/*Decompoe um numero em un milhar, centena, dezena e unidade*/
	int valor;
	printf("Insira um valor decimal de 4 dígitos: ");
	scanf("%d", &valor);

	if (valor > 9999 || valor < -9999) {
		printf("Valor não aceito, valores maiores que 9999 ou menores que -9999 não são válidos\n");
	} else {
		int un = valor % 10;
		int dz = (valor % 100) / 10;
		int cn = (valor % 1000) / 100;
		int ml = (valor % 10000) / 1000 ;

		if (valor < 0){
			un *= -1;
			dz *= -1;
			cn *= -1;
			ml *= -1;
			printf("%d unidades de milhar, %d centenas, %d dezenas e %d unidades negativo\n", ml, cn, dz, un);	
		} else {
			printf("%d unidades de milhar, %d centenas, %d dezenas e %d unidades\n", ml, cn, dz, un);	
		}
	}
	return 0;
}

int reduz() {
/*reduz um numero pela base 10*/
	int valor, num;
	printf("Insira um valor de 5 dígitos: ");
	scanf("%d", &valor);
	for (int idx = 0; idx < 5; idx++){
		num = valor % 10; 
		printf("%d\n", num);
		valor /= 10;
	}
	return 0;
}

int Capslock() {
/*Torna uma letra minuscula em maiuscula*/
	char foo;
	printf("Insira um caractere: ");
	scanf("%c", &foo);
	//letras ASCII = [65, 90] e [97, 122]

	if (foo >= 65 && foo <= 90){
		printf("%c\n", foo);
	} else if (foo >= 97 && foo <= 122) {
		printf("%c\n", foo - 32);
	} else {
		printf("Não é uma letra ASCII\n");
	}

	return 0;
}

int main() {
/*Verifica o tipo de um caractere*/
	char foo;
	printf("Insira um caractere: ");
	scanf("%c", &foo);
	//letras ASCII = [65, 90] e [97, 122]
	//numeros ASCII = [48, 57]
	//vogais ASCII = [65,69,73,79,85,97,101,105,111,117]

	if (foo >= 65 && foo <= 90 || foo >= 97 && foo <= 122) {
		if (foo == 65 || foo == 69 || foo == 73 || foo == 79 || foo == 85 || foo == 97 || foo == 101 || foo == 105 || foo == 111 || foo == 117) {
			printf("%c é uma vogal ASCII\n", foo);
		} else {
			printf("%c é uma consoante ASCII\n", foo);
		}
	} else if (foo >= 48 && foo <= 57) {
		printf("%c é um número ASCII\n", foo);
	} else {
		printf("%c é um símbolo ASCII\n", foo);
	}

	return 0;
}

int calculador() {
/*Calculadora cli*/
	int A, B;
	char op;

	printf("[ CALCULADORA TABAJARA ]");

	printf("Operador> ");
	scanf("%c", &op);	
			
	printf("Numero01> ");
	scanf("%d", &A);

	printf("Numero02> ");
	scanf("%d", &B);
	//numeros ASCII = [48, 57]
	//operadores = [
	// % 37
	// * 42
	// + 43
	// - 45
	// / 47
	//] 
	
	printf("Expressão:\n");

	if (op == 37){
		printf("%d %c %d = %d\n", A, 37, B, A % B);
	} else if (op == 42) {
		printf("%d * %d = %d\n", A, B, A * B);
	} else if (op == 43) {
		printf("%d + %d = %d\n", A, B, A + B);
	} else if (op == 45) {
		printf("%d - %d = %d\n", A, B, A - B);
	} else if (op == 47) {
		printf("%d / %d = %d\n", A, B, A / B);
	} else {
		printf("Não foi possível reconhecer o operador\n");
	}

	return 0;
}