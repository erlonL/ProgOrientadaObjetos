#include <iostream>

using std::cout, std::cin, std::endl, std::string;

class poligono{
    static int contador;
    string cor;
public:
    poligono(const string& c):cor(c) { contador++; }
    ~poligono() { contador--; }
    static int get_contador() { return contador;}
    virtual float get_area()=0;
};

class retangulo : public poligono{
    float base;
    float altura;
public:
    retangulo(const string& c, float b, float a) : poligono(c), base(b), altura(a){}
    float get_area() {
        return base*altura.
    }
};