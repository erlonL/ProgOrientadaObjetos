#include <iostream>

class singleton {
private:
    int contador;

    static singleton* _instance;

    singleton() {
        contador = 0;
        std::cout << "Instância criada." << std::endl;
    }

public:
    static singleton* get_instance() {
        if (_instance == nullptr) {
            _instance = new singleton();
        }
        return _instance;
    }

    void mensagem() {
        std::cout << "Olá do Singleton!" << std::endl;
    }

    void add_contador() {
        contador++;
    }

    void print_contador() {
        std::cout << contador << std::endl;
    }

    static void destroy() {
        if (_instance != nullptr) {
            delete _instance;
            _instance = nullptr;
            std::cout << "Instância destruída." << std::endl;
        }
    }
};

singleton* singleton::_instance = nullptr;

int main() {
    singleton* s1 = singleton::get_instance();
    singleton* s2 = singleton::get_instance();

    s1->mensagem();
    s2->mensagem();

    // Verifica se s1 e s2 apontam para a mesma instância
    std::cout << "s1 e s2 são a mesma instância: " << (s1 == s2) << std::endl;

    s1->print_contador();
    s2->print_contador();

    s1->add_contador();
    s2->add_contador();

    s1->print_contador();
    s2->print_contador();

    singleton::destroy();

    return 0;
}