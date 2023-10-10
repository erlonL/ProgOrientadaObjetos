#include <iostream>
#include <list>
#include <string>

using std::cout, std::endl, std::list, std::string, std::ostream;

class coisa{
    int atributo;
public:
    coisa(int a = 0){ atributo = a; }
    int get_atributo(){ return atributo; }
    void set_atributo(int a){ atributo = a; }
    friend ostream& operator<<(ostream& out, const coisa& c){
        out << "coisa(" << c.atributo << ")";
        return out;
    }
};

int main(void){
    list<string> palavras;
    list<coisa> coisas;

    palavras.push_back("abacaxi");
    palavras.push_back("laranja");
    palavras.push_front("limao");
    palavras.push_front("abacate");

    for(const string palavra : palavras){
        cout << palavra << " ";
    }
    
    cout << endl;

    coisas.push_back(coisa(10));
    coisas.push_back(coisa(20));
    coisas.push_back(coisa(30));
    coisas.push_back(coisa(40));

    for(const coisa coisa_ : coisas){
        cout << coisa_ << " ";
    }

    cout << endl;


    return 0;
}