#include <stdio.h>
#include <string.h>

void print_string(char *str) {
/*Imprime o conteúdo de uma string separando cada caractere com um espaço.*/
	int i = 0;
	while (str[i] != '\0') {
		printf("%c ", str[i]);
		i++;
	}	
	printf("\n");
}

void print_string_reversed(char *str) {
/*Imprime uma string em ordem reversa sem usar strlen().*/
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	while (len >= 0) {
		printf("%c", str[len]);
		len--;
	}
	printf("\n");
}

void print_string_reversed2(char *str) {
/*Imprime uma string em ordem reversa usando strlen().*/
	int len = strlen(str); 
	while (len >= 0) {
		printf("%c", str[len]);
		len--;
	}
	printf("\n");
}

void string_report(char *str) {
/*Imprime a quantidade de letras, dígitos e outros símbolos presentes em uma string*/
	int letra = 0, digito = 0, simb = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] > 31 && str[i] < 127) {
			if (str[i] >= 48 && str[i] < 58) {
				digito++;
			} else if (str[i] >= 65 && str[i] < 91 || str[i] >= 97 && str[i] < 123) {
				letra++;
			} else {
				simb++;
			}
		}
	}
	printf("letras: %d\ndígitos: %d\nsímbolos: %d\n", letra, digito, simb);
}

void string_to_upper(char *str) {
/*Converte as letras minusculas de uma string em maiusculas.*/
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 97 && str[i] < 123) {
			str[i] -= 32;
		}
	}
	//printf("%s\n", str);
} 

int strcmp_plus(const char *s1, const char *s2) {
/*Retorna o valor de grandeza entre duas strings, independente do texto maiusculo ou minusculo.*/
	char str1[255], str2[255];

	strcpy(str1, s1); 
	strcpy(str2, s2);
	
	string_to_upper(str1);
	string_to_upper(str2);

	return strcmp(str1, str2); 
}

int count_words_plus(const char *s) {
/*Conta o número de palavras em uma string.*/
	int numWord = 0;
	int bool = 0;

	char str[255];
	strcpy(str, s);
	string_to_upper(str);

	for (int i = 0; str[i] != 0; i++) {
		if (str[i] >= 65 && str[i] < 91 && bool == 0){
			bool = 1;
			numWord++;
		} else if (str[i] == ' ') {
			bool = 0;
		}
	}

	return numWord;
}

void string_capitalize(const char *str) {
/*Capitaliza o texto de uma string.*/
	char s[255];
	strcpy(s, str);

	for (int i = 0; s[i] != '\0'; i++) {
		if (i == 0) {
			if (s[i] >= 97 && s[i] < 123) {
				s[i] -= 32;
			}
		} else {
			if (s[i] >= 65 && s[i] < 91) {
				s[i] += 32;
			}
			if (s[i] >= 97 && s[i] < 123 && s[i-1] == ' ') {
				s[i] -= 32;
			}
		}
	}
	printf("%s\n", s);
}

int string_compare(const char *str1, const char *str2) {
/**Emula o funcionamento da função strcmp(), comparando a grandeza entre duas strings*/
	for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
		if (str1[i] < str2[i]) {
			return -1;
		} else if (str1[i] > str2[i]) {
			return 1;
		} else if (str1[i] == '\0') {
			return 0;
		}
	}	
}

void string_count(const char str[]) {
/*Imprime o numero de ocorrencias de cada letra ASCII e o percentual sobre o todo do conteudo textual.*/
	char s[255];
	strcpy(s, str);
	string_to_upper(s);
	
	int cnt = 0;
	int abc_cnt[26] = {0};

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] > 64 && s[i] < 91) {
			int x = s[i] - 65;
			abc_cnt[x]++;
			cnt++;
		}
	}

	for (int j = 0; j < 26; j++) {
		if (abc_cnt[j] > 0) {
			char car = j + 65;
			float per = ((float)abc_cnt[j] / cnt) * 100;
			printf("%c x%d (%.1f%c)\n", car, abc_cnt[j], per, 37);
		}
	}
	
	
}

void string_trim(char *str) {
/*Remove os espaços em banco anteriores e posteriores de uma string.*/
	int first = -1;
	int last = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123) {
			if (first == -1) {
				first = i;
			}	
			last = i+1;		
		}
	}
	for (int k = 0, j = first; j <= last; k++, j++) {
		str[k] = str[j];	
	}
	str[last-first+1] = '\0';
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

void cut_string(char *str, const char *word) {
/*Corta o conteudo de uma dada string apos encontrar certa palavra.*/
	int k = 0;
	int last = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == word[k]) {
			k++;
			if (word[k] == '\0') {
				last = i;		
				break;		
			}
		} else {
			k = 0;
		}
	}
	if (last > 0) {
		str[last+1] = '\0';
	}
	printf("%s\n", str);
}

void int_to_string(int num, char *conv) {
/*Converte um valor inteiro para uma string*/
	int k = 0;
	while (num / 10 > 0) {
		if (num % 10 <= 9) {
			conv[k] = (num % 10) + 48;
			k++;
			num /= 10;
		}

	}
	conv[k] = num + 48;
	for (int i = 0, j = strlen(conv) - 1; i <= j / 2; i++, j--) {
		int tmp = conv[j];
		conv[j] = conv[i];
		conv[i] = tmp;
	}
	printf("%s\n", conv);
} 

int string_to_int(const char *str) {
/*Converte uma string para um numero inteiro*/
	int num = 0;
	int pow = 1;
	for (int k = strlen(str) - 1; k > -1; k--) {
		num += (str[k] - 48) * pow;
		pow *= 10;
	}
	printf("%d\n", num);
	return num;
}

int main() {
//NOTE:Crie suas strings e descomente as funções para usar-las
	char str[13] = "Hello World!";
	char texto[] = "  Hello World!  ";
	char str2[255] = " first things first, second things latter ";
	char txt[] = "WELCOME To COMPUTER programming!!";
	char voidStr[16];
	char num[5] = "1024";
	//print_string(str);
	//print_string_reversed(str);
	//print_string_reversed2(str);
	//string_report(str);
	//string_to_upper(str);
	//printf("%d\n", strcmp_plus(str, str2));
	//printf("%d\n", count_words_plus(" first things first, second things latter "));
	//string_capitalize(txt);
	//printf("%d\n", string_compare(str, str2));
	//string_count("Hello World!");
	//string_trim(texto);
	//find_substring(texto, str);
	//cut_string(str2, "second");
	//int_to_string(512, voidStr);
	//string_to_int(num);
	return 0;
}
