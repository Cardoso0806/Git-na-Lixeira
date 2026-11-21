/*O 19/11/2026: Polimorfismo na prática e Tratamento de Exceções
por LUCIO GERONIMO VALENTIN - quinta-feira, 19 nov. 2026, 15:38  
O professor explicou o processo de alocação de memória para os objetos e para o ponteiros e quais operações são válidas entre eles levando em consideração a análise da natureza das variáveis.

O professor explicou sobre a Tabela Virtual para ativação do comportamento polimórfico em C++, que por padrão é desativado! Usando a palavra reservada virtual. Aproveitando o professor explicou método abstrato, que em C++ é um método virtual puro, ou seja um método sinalizado com virtual, sem corpo e com =0 no final de sua declaração.

Por fim, o professor trabalho a técnica de tratamento de erros por ERROR_LEVEL e depois explicou a técnica de tratamento de exceções incorporada à linguagem C++... Lembrou também que no livro do Borges e Clinio tem o capítulo Polimorfismo e Tratamento de Exceção. Leiam, ou peçam para seu assistente ler pra você :)*/

#include <iostream>

class Animal {
	float peso;
	public:

 	virtual void emitaUmSom()=0;

};

class Gato : public Animal {

	public:

 	void emitaUmSom() { 
		std::cout << "Miauuuu..." << std::endl;
	}
};



int main() {
	int i;
	Animal *pa = 0;
	Gato *pg = new Gato();
	if(pa)
		pa->emitaUmSom();

	 pg->emitaUmSom();



	 pa = pg;

	 pg = (Gato *)pa;



	 pa->emitaUmSom();



	 delete pa;

	 delete pg;

}

//Tratamento de Exceção

int divida(int x, int y){
	// if(y!=0)

	 return x/y;

	 throw "Y não pode ser ZERO";

}



int main(){

	 int a = 10, b = 0;

	 try{
	 	std::cout << divida(a,b);
	 }catch(char const* erro){
	 	std::cout << "Alguma coisa aconteceu:"<< erro;
	 }
}
