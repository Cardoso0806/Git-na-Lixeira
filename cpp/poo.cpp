#include <iostream>

class Animal{
	float massa;
	
	public: 
		void emitirSom() {
			std::cout << "Som" << std::endl;
		}
};

class Gato: public Animal {
	public: 
		void emitirSom() {
			std::cout << "MIAU!" << std::endl;
		}
};

int main() {
	Gato *Garfield = new Gato();
	Animal *Zubumafu = new Animal();
	(*Garfield).emitirSom();
	(*Zubumafu).emitirSom();

	delete Garfield;
	delete Zubumafu;
}
