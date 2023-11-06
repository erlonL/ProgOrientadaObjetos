#include <iostream>

using std::cout, std::endl, std::string, std::ostream;



class coisa{
    int valor;
public:
    coisa(int v) : valor(v) {}
    friend ostream& operator<<(ostream& out, const coisa& c){
        out << "Coisa valor: " << c.valor << " ";
        return out;
    }
};

template <typename T>
class caixa{
    T valor;
public:
    caixa(T v) : valor(v) {}

    void print_info(){
        cout << "Valor na caixa: " << valor << endl;
    }
};

int main(void){
    caixa<int> caixa_int(99);
    caixa<string> caixa_str("Mensagem armazenada na caixa!");
    coisa c(10);
    caixa<coisa> caixa_coisa(c);

    caixa_int.print_info();
    caixa_str.print_info();
    caixa_coisa.print_info();

    return 0;
}