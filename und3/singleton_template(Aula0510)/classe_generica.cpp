#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::string, std::begin, std::end;

template <typename T>
class container{
    vector<T> elementos;
public:
    container(){
        elementos = vector<T>();
    }
    void inserir(const T& el){
        elementos.push_back(el);
    }
    void remover(const T& el){
        elementos.erase(std::remove(elementos.begin(), elementos.end(), el), elementos.end());
    }
    bool busca(const T& el){
        return std::find(elementos.begin(), elementos.end(), el) != elementos.end();
    }
    T& get_elemento(int index){
        return elementos[index];
    }
    int tamanho(){ return ((int)elementos.size()); }

    vector<T> get_elementos() const{ return elementos; }

    void print_elementos(){
        for(const T& elemento : elementos){
            cout << elemento << " ";
        }
        cout << endl;
    }
};

template <typename T>
void print_elementos(const container<T>& cont){
    vector<T> elementos = cont.get_elementos();
    cout << elementos[0];
    for(int i = 0; i < cont.tamanho() ; i++){
        cout << elementos[i] << " ";
    }
    cout << endl;
}

int main(void){
    container<int> cont_int;
    
    cont_int.inserir(1);
    cont_int.inserir(2);
    cont_int.inserir(3);
    cont_int.inserir(4);
    cont_int.inserir(5);

    cont_int.remover(5);

    cont_int.print_elementos();
    print_elementos(cont_int);

    container<string> cont_str;

    cont_str.inserir("Hello World!");
    cont_str.inserir("Alo Brasil!");
    cont_str.inserir("POO!");

    cont_str.remover("POO!");

    cont_str.print_elementos();
    cont_str.tamanho();
    print_elementos(cont_str);


    return 0;
}