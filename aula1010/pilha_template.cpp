#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector, std::ostream;

template <typename T>

class pilha{
    vector<T> p;
public:
    pilha() { }
    void push(T elemento){
        p.push_back(elemento);
    }
    void pop(){
        if(!is_empty()){
            p.pop_back();
        }
    }
    T top(){
        if(!is_empty()){
            return p.back();
        }
        return NULL;
    }
    bool is_empty(){
        return p.empty();
    }
};

class coisa{
    int atributo;
public:
    coisa(int a = 0) { atributo = a; }
    int get_atributo() { return atributo; }

    void set_atributo(int a){ atributo = a; }

    friend ostream& operator<<(ostream& out, const coisa& c){
        out << "coisa(" << c.atributo << ")";
        return out;
    }
};

int main(void){
    pilha<int> pilha_int;
    pilha<coisa> pilha_coisa;

    pilha_int.push(50);
    pilha_int.push(100);

    cout << "Top da pilha de inteiros: " << pilha_int.top();
    cout << endl;
    pilha_int.pop();

    cout << "Top da pilha de inteiros (apos pop): " << pilha_int.top();
    cout << endl;

    coisa a(10), b(20), c(30);

    pilha_coisa.push(a);
    pilha_coisa.push(b);
    pilha_coisa.push(c);
    
     




    return 0;
}