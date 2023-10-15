#include <iostream>

/*Vamos utilizar o tipo variável estática, que tem
formas diferentes de se inicializar e acessar.*/
using std::cout, std::endl;

class pessoa{
    static int count; // não pode ter um valor padrão
public:
    pessoa() { count++; }
    ~pessoa() { count--; }
    static int get_count() { return count; }
};

int pessoa::count = 0; // deve ser inicializado fora da classe
                              // e antes do main()

int main(void){
    cout << pessoa::get_count() << endl;

    pessoa p1;
    pessoa* pp = new pessoa();
    cout << pessoa::get_count() << endl;

    delete pp;
    cout << pessoa::get_count() << endl;
    cout << p1.get_count() << endl;
    /*como a variável é global, seu valor
    será da classe, independente do objeto.*/
    return 0;
}