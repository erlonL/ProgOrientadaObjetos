#include <iostream>

class singleton_static {
private:
    static int contador;

public:

    static void mensagem() {
        std::cout << "Olá do Singleton com atributos e métodos estáticos!" << std::endl;
    }

    static void add_contador() {
        contador++;
    }

    static void print_contador() {
        std::cout << contador << std::endl;
    }
};

int singleton_static::contador = 0;

int main() {

    singleton_static::mensagem();

    singleton_static::add_contador();
    singleton_static::add_contador();

    singleton_static::print_contador();
    
    return 0;
}