#include <iostream>

using std::cout, std::endl;

class vendedor{
    double meta;
public:
    vendedor(double m): meta(m) {}

    double get_meta() { return meta; }
    void set_meta(double m) { meta = m; }

    void print_info(){
        cout << "vendedor: " << endl;
        cout << "meta: " << meta << endl;
    }
};

class gerente{
    int departamento;
public:
    gerente(int d):departamento(d) {}
    int get_departamento() { return departamento; }
    void set_departamento(int d) { departamento = d; }

    void print_info(){
        cout << "gerente" << endl;
    }
};

class vendedor_gerente : public vendedor, public gerente {
    int codigo;
public:
    vendedor_gerente(int c, double m, int d): codigo(c), vendedor(m), gerente(d) {}

    int get_codigo(){ return codigo; }
    void set_codigo(int c){ codigo = c; }
};