#include <iostream>

class Exception{

	private: 
		int code;
		int level;

	public:

	Exception():Exception(0,0){

		std::cout << "Estou contruindo() um exception..." << std::endl;

	}

	Exception(int code):Exception(code, 0){

		std::cout << "Estou contruindo(code) um exception..." << std::endl;

	}

	Exception(int code, int level){

		std::cout << "Estou contruindo(code, level) um exception..." << std::endl;
		this->setCode(code);
		this->setLevel(level);

	}



	void setCode(int code){

		if(code >= 0) {
			this->code = code;
		} else {
			throw "Code must be positive!";
		}
	}

	int getCode(){
		return this->code;
	}

	void setLevel(int level){
		this->level = level;
	}



	int getLevel(){

		return this->level;

	}

	~Exception(){

		std::cout << "Estou DESTRUINDO um exception..." << std::endl;

	}

};

int divida(int x, int y) {
	std::cout << "Iniciando divida()..." << std::endl;
 	if (y != 0)
		return x / y;
 	throw Exception(1);
}

void f(Exception e){
	std::cout << "Executando f(e)..." << e.getCode() << std::endl;
}

void pf(Exception *e){
	std::cout << "Executando f(*e)..." << e->getCode() << std::endl;
}

void rf(Exception &e){
	std::cout << "Executando f(&e)..." << e.getCode() << std::endl;
}

void testePassagemPorReferencia(){

	Exception e;
 	f(e);
 	pf(&e);
 	rf(e); 
 	exit(0);
}

int main() {

	std::cout << "Iniciando o main()..." << std::endl;
	// testePassagemPorReferencia();
	int a = 10, b = 0;

	try {
		std::cout << divida(a, b);
	} catch (char const *erro) {
		std::cout << "Alguma coisa aconteceu:" << erro << std::endl;
	} catch (int erro) {
		std::cout << "Alguma coisa aconteceu:" << erro << std::endl;
	} catch (Exception &erro) {
		std::cout << "Aconteceu o erro:" << erro.getCode() << std::endl;
	}
	std::cout << "Encerrando o main()..." << std::endl;
}
