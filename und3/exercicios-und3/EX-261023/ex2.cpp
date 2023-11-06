/*Gerenciamento de estoque*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using std::endl, std::cout, std::string, std::map, std::vector, std::stringstream;

template <typename D>
class produto{
    string nome;
    D descricao;
    int numSerie;
    float preco;
    int quantidade;
public:
    produto(string n, D d, int ns, float p, int q){
        nome = n;
        descricao = d;
        numSerie = ns;
        preco = p;
        quantidade = q;
    }
    void setPreco(float p){
        preco = p;
    }
    void addUnd(int q){
        quantidade += q;
    }
    float venderProduto(int q){
        if(q > quantidade){
            cout << "Quantidade insuficiente" << endl;
            return 0;
        }
        quantidade -= q;
        return q*preco;
    }
    string getNome() const{ return nome; }
    D getDescricao() const{ return descricao; }
    int getNumSerie() const{ return numSerie; }
    float getPreco() const{ return preco; }
    int getQuantidade() const{ return quantidade; }
};

template <typename D>
class gerenciador_estoque{
    static map<produto<D>, int> produtos; /* Produto / Quantidade */
    static int numProdutos;
    static float valorTotal;
    static produto<D>* produtoMaisCaro; /*Produto Mais Caro*/

    static gerenciador_estoque<D>* _instance;
    gerenciador_estoque(){
        numProdutos = 0;
        valorTotal = 0;
    }
public:
    static gerenciador_estoque<D>* getInstance(){
        if(_instance == nullptr){
            _instance = new gerenciador_estoque<D>();
        }
        return _instance;
    }
    void addProduto(produto<D> p){
        int qtd = p.getQuantidade();

        produtos[p] += qtd;
        numProdutos += qtd;
        /*Método para calcular o valor total do estoque*/
        valorTotal += qtd * p.getPreco();

        /*Método para determinar o produto mais caro em estoque*/
        if(p.getPreco() > produtoMaisCaro->getPreco()){
            produtoMaisCaro = &p;
        }
    }
    void listarProdutos(){
        cout << "** PRODUTOS EM ESTOQUE **" << endl;
        for(auto it = produtos.begin(); it != produtos.end(); it++){
            cout << "Nome: " << it->first.getNome() << endl;
            cout << "Descrição: " << it->first.getDescricao() << endl;
            cout << "Número de Série: " << it->first.getNumSerie() << endl;
            cout << "Preço: " << it->first.getPreco() << endl;
            cout << "Quantidade: " << it->second << endl;
            cout << endl;
        }
    }
    void mudarQtdProduto(produto<D> p, int q){
        produtos[p] += q;
        numProdutos += q;
        /*Método para calcular o valor total do estoque*/
        valorTotal += q * p.getPreco();
    }
};

template <typename D>
class cliente{
    string nome;
    int id;
    vector<string> historicoCompras;
    map<produto<D>*, int> carrinho;
public:
    cliente(string n, int i) : nome(n), id(i){ }
    // void addProduto(produto<D> p, int qtd){
    //     carrinho[&p] += qtd;
    // }
    // void finalizarCompra(){
    //     float total = 0;
    //     for(auto it = carrinho.begin() ; it != carrinho.end(); it++){
    //         stringstream ss;
    //         produto<D>* prod = it->first;
    //         int qtd = it->second;
    //         total += prod->getPreco() * qtd;
    //         ss << "Nome: " << prod->getNome() << endl;
    //         ss << "Número de Série: " << prod->getNumSerie() << endl;
    //         ss << "Quantidade: " << qtd << endl;
    //         ss << "Total: " << prod->getPreco() * qtd << endl;

    //         string infosdaCompra = ss.str(); 

    //         historicoCompras.push_back(infosdaCompra);
    //     }
    //     for(auto it = carrinho.begin() ; it != carrinho.end(); it++){
    //         produto<D>* prod = it->first;
    //         int qtd = it->second;
    //         gerenciador_estoque<D>::getInstance()->mudarQtdProduto(*prod, -qtd);
    //         // limpa carrinho
    //         carrinho.erase(it);
    //     }
    //     cout << "Total da compra: " << total << endl;
    // }
};
template <typename D>
gerenciador_estoque gerenciador_estoque::_instance = nullptr;

int main(void){
    gerenciador_estoque<string>* g = gerenciador_estoque<string>::getInstance();

    produto<string> p1("Arroz", "Arroz branco", 1, 10, 10);
    produto<string> p2("Feijão", "Feijão carioca", 2, 5, 20);
    produto<string> p3("Macarrão", "Macarrão espaguete", 3, 3, 30);

    g->addProduto(p1);
    g->addProduto(p2);
    g->addProduto(p3);

    g->listarProdutos();

    cliente<string> c1("João", 1);
    c1.addProduto(p1, 2);
    c1.addProduto(p2, 3);

    // c1.finalizarCompra();


    return 0;
}