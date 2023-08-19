#include <iostream>

using std::cout, std::cin, std::endl;

class ponto{
    int x;
    int y;

public:
    ponto(int x = 0, int y = 0){
        this->x = x;
        this->y = y;
    }
    void set_y(int y){ this->y = y; }
    void set_x(int x){ this->x = x; }

    void print_info(){
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class poligono{
    int cor;
    ponto* pontos;
    int qtd_pontos;
    int dinamico;
public:
    poligono(int c, ponto *ps, int q){
        cor = c;
        pontos = ps;
        qtd_pontos = q;
        dinamico = 0;
    }
    poligono(int c, int q){
        cor = c;
        pontos = new ponto[q];
        qtd_pontos = q;
        dinamico = 1; // Construído dinamicamente
    }
    // GETS e SETS

    void print_info(){
        cout << "Cor: " << cor << endl;
        cout << (dinamico ? "Foi criado dinamicamente." : "Não é dinâmico") << endl;
        cout << "Pontos: " << endl;
        for(int i = 0; i < qtd_pontos; i++){
            pontos[i].print_info();
        }
    }
    // Método destrutor checa se o valor da variável dinâmico é igual a 1
    // se for, logo o poligono foi criado com new, ou seja, memória foi alocada
    // para ele, por isso precisa ser desalocada.
    ~poligono(){ if(dinamico) delete[] pontos; }
};

int main(void){
    ponto ps[4];

    ps[1].set_y(1);
    ps[2].set_x(1);
    ps[3].set_x(1);
    ps[3].set_y(1);

    poligono p1(10, ps, 4);

    p1.print_info();
    return 0;
}