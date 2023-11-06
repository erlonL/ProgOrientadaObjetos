#include <iostream>
#include <map>

using std::map, std::cout, std::endl, std::string;

class estoque{
    map<string, int> produtos;
public:
    estoque(){ }
    void addProduto(string nome, int q){
        produtos[nome] = q;
    }
    void addQuantidade(string nome, int q){
        produtos[nome] += q;
    }
    void listarProdutos(){
        for(auto it = produtos.begin(); it != produtos.end(); it++){
            cout << it->first << ": " << it->second << endl;
        }
    }
};

int main(void){
    estoque e;
    e.addProduto("Arroz", 10);
    e.addProduto("Feijão", 20);
    e.addProduto("Macarrão", 30);
    e.addQuantidade("Arroz", 5);
    e.addQuantidade("Feijão", 10);

    e.listarProdutos();


    return 0;
}