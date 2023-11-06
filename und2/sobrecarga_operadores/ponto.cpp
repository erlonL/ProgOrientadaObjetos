#include <iostream>

using std::cout, std::endl, std::ostream;


class ponto{
    double x;
    double y;
public:
    ponto(double xx, double yy): x(xx), y(yy) {}
    
    double get_x() { return x; }
    double get_y() { return y; }
    void set_x(double xx) { x = xx; }
    void set_y(double yy) { y = yy; }

    void print_info(){
        cout << "ponto(" << x << ", " << y << ")" << endl;
    }

    ponto operator+(const ponto& outro){
        double xr = x + outro.x;
        double yr = y + outro.y;
        ponto r(xr, yr);
        return r;
    }

    ponto operator-(const ponto& outro){
        double xr = x - outro.x;
        double yr = y - outro.y;
        ponto r(xr, yr);
        return r;
    }

    bool operator==(const ponto& outro){
        return ((x == outro.x) && (y == outro.y));
    }

    bool operator!=(const ponto& outro){
        return((x != outro.x) || (y != outro.y));
    }
    friend ostream& operator<<(ostream& os, const ponto& p){
        os << "x: " << p.x << ", " << "y: " << p.y;
        return os;
    }

};


int main(void){
    ponto a(10,20), b(20,30), c(40,50), d(60,70);
    ponto k(10, 10);

/*
    cout << "ponto a: ";
    a.print_info();
    cout << "ponto b: ";
    b.print_info();
    cout << "ponto c: ";
    c.print_info();
    cout << "ponto d: ";
    d.print_info();
*/

    ponto e = a + b;

    ponto f = d - c;

    if(f == k){
        cout << "f == k";
    }else{

    }

    cout << a;

    return 0;
}