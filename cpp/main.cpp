#include <iostream>

class Exception {
    
    private:
        int code;

    public:
        Exception(int code) {
            this->setCode(code);
        } 
        
        void setCode(int code) {
            if (code > 0) 
                this->code = code;
            throw "Codigo invalido: codigo precisa ser maior que 0";
        }

        int getCode() {
            return this->code;
        }
    
};

int divida(int x, int y){

    if(y!=0)
        return x/y;

    throw new Exception(1);
}

int main(){

    int a = 10, b = 0;

    try{
        std::cout << divida(a,b);
    }catch(Exception *erro){
        std::cout << "Algo deu errado: "<< erro->getCode() << std::endl;
    }

}
