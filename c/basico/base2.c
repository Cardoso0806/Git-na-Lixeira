#include <stdio.h>

void print_lines(int n){
/*1 - Imprime N linhas de texto, exibindo o número da linha em contagem decre 1scente.*/
	for (int i = n; i > 0; i--){
		printf("Linha %d\n", i);
	}	
}

void print_ascii_slice(int first, int last) {
/*2 - Imprime todos os caracteres ASCII, bem como seu valor numérico correspondente, dentro de um dado intervalo, estando ele dentro do intervalo [33, 126].*/
	if (first < 33) {
		first = 33;
	}
	if (last > 126) {
		last = 126;
	}
	printf("DEC OCT HEX CHR\n");
	for (int i = first; i <= last; i++) {
		printf("%03d %03o %03X %c\n", i, i, i, (char)i);
	}
}

int odd_square(int n) {
/*3 - Calcula e retorna o quadrado de n usando a soma de n ímpares.*/
	if (n == 1){
		printf("1 = 1");
	}
	int acm = 1;
	printf("1 ");
	for (int i = 3; i < n * 2; i += 2) {
		printf("+ %d ", i);
		acm += i;
	}
	printf("= %d\n", acm);
	return acm;
}

int multiply(int a, int b){
/*4 - Calcula a multiplicação de dois números sem o operador '*'.*/
	int ta = a;
	for (int i = 1; i < b; i++){
		a += ta;
	}
	printf("%d\n", a);
	return a;
}

int resto(int a, int b) {
/*5 - Calcula o resto da divisão inteira de dois números sem os operadores '/' ou '%'.*/
	while (a >= b) {
		a -= b;
	}
	printf("%d\n", a);
	return a;
}

void scan_calc() {
/*6 - Le continnuamente os valores até que se digite 0 e retorna a soma e a média aritmetica simples desses números.*/
	int input;
	int soma = 0;
	int n_digitados = 0;
	while (1) {
		printf("> ");
		scanf("%d", &input);
		if (input == 0) {
			break;
		} else {
			soma += input;
			n_digitados++;
		}
	}
	float media = (float) soma / n_digitados;
	printf("Soma: %d\nMedia: %.2f\n", soma, media);
}

void scan_minmax() {
/*7 - Le continuamente os valores até que se digite 0 e retorna o minimo e o maximo dos valores.*/
	int idx = 0;
	int input;
	int max;
	int min;
	while (1) {
		printf("> ");
		scanf("%d", &input);
		if (input == 0) {
			break;
		}
		if (idx == 0) {
			max = input;
			min = input;
		}
		if (input < min && input != 0){
			min = input;
		} else if(input > max && input != 0) {
			max = input;
		}
		idx++;
	}
	printf("Max: %d\nMin: %d\n", max, min);
}

int nth_fib(int n) {
/*8 - Calcula o n-ésino termo da sequência de Fibonacci. É uma versão do algortimo que já implementei em 'https://github.com/Cardoso0806/Algoritmos-de-Fibonacci'.*/ 
	if (n == 0){
		printf("0");
		return 0;
	} else if (n == 1) {
		printf("1");

	} else {
		int a = 0;
		int b = 1;
		int ac = 0;
		for (int i = 0; i < n; i++) {
			ac = a + b;
			a = b;
			b = ac;
		}
		printf("%d\n", ac);
		return ac;
	}
}

void print_digits(int n) {
/*9 - Decompõe e imprime os dígitos de um número n*/
	int v = 1000000000;
	while (v > n){ //calibra a potencia de 10 do digito mais significante
		v /= 10;
	}
	if (v == 0) { //garante que v nunca será 0
		v = 1;
	}

	while (v > 0) {
		int d = n / v;
		n -= (d * v);
		v /= 10;
		printf("%d\n", d);
	}
}

void number_in_words(int n) {
/*10 - Escreve o nome por extenso de um número.*/
	if (n < 999 && n > -999) {
		int sg = 0;
		if (n < 0) {
			n *= -1;
			sg = 1;
		} else if (n == 0) {
			printf("Zero\n");
			return;
		} else {
			int x = n;
			int y = n;
			int v = 100;
				
//HACK: O código abaixo é tipo Errorex, é feio mas faz resolve seu problema. São 95 linhas de if-else para algo que se resolveria em 30 usando um struct de vetores com os nomes dos números
			while (y > 0) {
				x = y / v;
				if (v == 100) {
					if (x == 1) {
						if (n % 100 == 0){
							printf("Cem");
							break;
						} else {
							printf("Cento");
						}
					} else if (x == 2) {
						printf("Duzentos");

					} else if (x == 3) {
						printf("Trezentos");
					} else if (x == 4) {
						printf("Quatrocentos");
					} else if (x == 5) {
						printf("Quinhentos");
					} else if (x == 6) {
						printf("Seiscentos");
					} else if (x == 7) {
						printf("Setecentos");
					} else if (x == 8) {
						printf("Oitocentos");
					} else if (x == 9) {
						printf("Novecentos");
					} else {
						y -= x * v;
						v /= 10;
						continue;
					}
				} else if (v == 10) {
					if (x == 1) {
						if (y == 10) {
							printf("Dez");
						} else if (y == 11) {
							printf("Onze");
						} else if (y == 12) {
							printf("Doze");
						} else if (y == 13) {
							printf("Treze");
						} else if (y == 14) {
							printf("Catorze");
						} else if (y == 15) {
							printf("Quinze");
						} else if (y == 16) {	
							printf("Dezesseis");
						} else if (y == 17) {
							printf("Dezessete");
						} else if (y == 18) {
							printf("Dezoito");
						} else if (y == 19) {
							printf("Dezenove");
						}
					} else if (x == 2) {
						printf("Vinte");
					} else if (x == 3) {
						printf("Trinta");
					} else if (x == 4) {
						printf("Quarenta");
					} else if (x == 5) {
						printf("Cinquenta");
					} else if (x == 6) {
						printf("Sessenta");
					} else if (x == 7) {
						printf("Setenta");
					} else if (x == 8) {
						printf("Oitenta");
					} else if (x == 9) {
						printf("Noventa");
					} else {
						y -= x * v;
						v /= 10;
						continue;
					}
				} else {
					if (x == 1) {
						printf("Um");
					} else if (x == 2) {
						printf("Dois");
					} else if (x == 3) {
						printf("Tres");
					} else if (x == 4) {
						printf("Quatro");
					} else if (x == 5) {
						printf("Cinco");
					} else if (x == 6) {
						printf("Seis");
					} else if (x == 7) {
						printf("Sete");
					} else if (x == 8) {
						printf("Oito");
					} else if (x == 9) {
						printf("Nove");
					}
				}
					
				if (v != 0 && y % v != 0) {
					printf(" e ");
				}
				y -= (x * v);
				v /= 10;
			}
			if (sg == 1) {
				printf(" (negativo)\n");
			} else {
				printf(" (positivo)\n");
			}
		}
	} else {
		printf("Erro: valor fora do limite permitido [-999 - 999].\n");
	}
}

int is_palindrome(int n) {
/*11 - Verifica se um número é um palindromo*/
	int v = 1000000000;
    	while (v > n) { //calibra a potencia de 10 do digito mais significante
        	v /= 10;
    	}
    	if (v == 0){
		v = 1;// caso especial: n == 0
	}

	int m = n;
	while (v > 0) {
		//Calcula o número invertido
		int d = m / v;
		int b = n % 10;
		//Compara o valor invertido com o valor comum
		if (b != d) {
			return 0;
		}

		n /= 10;
		m -= (d * v);
		v /= 10;
	}
	return 1;
}

int is_prime(int n) {
/*12 - Verifica se dado número é primo. */
	if (n == 2) {
		return 1;
	} else if (n <= 0 || n % 2 == 0) {
		return 0;
	} else {
		for (int i = 3; i < n; i += 2){
			if (n % i == 0) {
				return 0;
			}
		}
		return 1;
	}
}

void prime_factors(int n) {
/*13 - Decompõe um número em seus fatores primos*/
	if (n == 0) {
		printf("0 não possui fatores primos.\n");
	} else {
		int max = n;
		for (int i = 2; i < n + 1; i++) {
			int vzs = 0;
			
			while(n % i == 0){
				n /= i;
				vzs += 1;
			}
			if (vzs > 0) {
				printf("%d x fator %d.\n", vzs, i);
			}
		}
	}
}

int get_gcd(int a, int b) {
/*14 - Calcula o MDC de dois valores*/
	if (is_prime(a) && is_prime(b)) {
		printf("Não há divisores comuns\n");
		return -1;
	} else if (a == b){
		return a;
	} else if (a == 0 || b == 0){
		printf("Não é possível dividir por 0.");
		return -1;
	} else {
		int max;	int mdc = 1;
		int ta = 0; 	int tb = 0;
		if (a > b) {
			max = a;
		} else {
			max = b;
		}
		for (int i = 2; i < max; i++){	
			while (a % i == 0 || b % i ==0) {
				ta = a; tb = b;
				if (ta % i == 0) {
					a /= i;
				}
				if (tb % i == 0) {
					b /= i;
				}
				if (ta % i == 0 && tb % i == 0){
					mdc *= i;
				}
			}	
		}
		printf("%d\n", mdc);
		return mdc;
	}
}

int get_scm(int a, int b) {
/*15 - Calcula o MMC de dois números.*/
	int i = 2;	
	int mmc = 1;
	while (a > 1 || b > 1) {	
		while (a % i == 0 || b % i == 0) {
			if (a % i == 0) {
				a /= i;
			} 
			if (b % i == 0) {
				b /= i;
			}
			mmc *= i;
		}
		i++;
	}
	printf("%d\n", mmc);
	return mmc;
}

void main() {
	print_lines(5);
	print_ascii_slice(33,36);
	odd_square(5);
	multiply(2, 6);
	resto(5, 2);
	scan_calc();
	scan_minmax();
	nth_fib(15);
	print_digits(256);
	number_in_words(572);
	is_palindrome(12321);
	is_prime(7);
	prime_factors(132);
	get_gcd(30, 12);
	get_scm(15, 13);		
}
