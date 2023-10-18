#include <iostream>

using std::cout, std::endl, std::ostream;

// função genérica
class ponto{
    int x;
    int y;
public:
    ponto(int xx, int yy) : x(xx), y(yy) {}
    ponto operator+(const ponto& b){
        return ponto(x + b.x, y + b.y);
    }
    friend ostream& operator<<(ostream& os, const ponto& p){
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};


template <typename T>
// T pode ser qualquer tipo, até tipos definidos pelo usuário
// template precisa estar próximo a função que será utilizada
T soma(T a, T b){
    return a + b;
}

int main(void){
    int _soma_int = soma(10, 50);
    double _soma_double = soma(100.882, 245.3452);

    ponto p1(10, 20);
    ponto p2(20, 30);

    ponto _soma_ponto = soma(p1, p2);

    cout << "Soma de inteiros: " << _soma_int << endl; 
    cout << "Soma de doubles: " << _soma_double << endl;
    cout << "Soma de pontos: " << _soma_ponto << endl;



    return 0;
}