/*Gerenciamento de estoque*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using std::endl, std::cout, std::string, std::map, std::vector, std::stringstream;

class produto{
    string nome;
    string descricao;
    int numSerie;
    float preco;
    int quantidade;
public:
    produto(const string& n, const string& d, int ns, float p, int q){
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
    string getDescricao() const{ return descricao; }
    int getNumSerie() const{ return numSerie; }
    float getPreco() const{ return preco; }
    int getQuantidade() const{ return quantidade; }
    void printInfo(){
        cout << "** PRODUTO **" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Descrição: " << descricao << endl;
        cout << "Número de Série: " << numSerie << endl;
        cout << "Preço: " << preco << endl;
        cout << "Quantidade: " << quantidade << endl;
    }
};

class gerenciador_estoque{
    // vector<produto*> estoqueGeral;
    map<string, produto*> produtos; /* Produto / Quantidade */
    int numProdutos;
    float valorTotal;
    produto* produtoMaisCaro; /*Produto Mais Caro*/
public:
    gerenciador_estoque(){
        produto placeholder("", "", 0, 0, 0);
        numProdutos = 0;
        valorTotal = 0;
        produtoMaisCaro = &placeholder;
    }
    void addProduto(produto p){
        int qtd = p.getQuantidade();
        string nome = p.getNome();

        numProdutos += qtd;
        /*Método para calcular o valor total do estoque*/
        valorTotal += qtd * p.getPreco();
        produtos[nome] = &p;

        /*Método para determinar o produto mais caro em estoque*/
        if(p.getPreco() > produtoMaisCaro->getPreco()){
            produtoMaisCaro = &p;
        }
    }
    void listarProdutos(){
        cout << "** PRODUTOS EM ESTOQUE **" << endl;
        for(auto it = produtos.begin(); it != produtos.end() ; it++){
            produto* p = it->second;
            p->printInfo();
        } 
    }
    void mudarQtdProduto(produto p, int q){
        string nome = p.getNome();
        produtos[nome]->addUnd(q);
        numProdutos += q;
        /*Método para calcular o valor total do estoque*/
        valorTotal += q * p.getPreco();
    }
    ~gerenciador_estoque(){
        for(auto it = produtos.begin(); it != produtos.end() ; it++){
            delete it->second;
        }
        delete produtoMaisCaro; 
    }
};

class cliente{
    string nome;
    int id;
    vector<string> historicoCompras;
    map<produto*, int> carrinho;
    gerenciador_estoque* lojaAtrelada;
public:
    cliente(string n, int i, gerenciador_estoque* g){
        nome = n;
        id = i;
        historicoCompras = vector<string>();
        carrinho = map<produto*, int>();
        lojaAtrelada = g;
    }
    void addProduto(produto p, int qtd){
        carrinho[&p] += qtd;
    }
    void finalizarCompra(){
        float total = 0;
        for(auto it = carrinho.begin() ; it != carrinho.end(); it++){
            stringstream ss;
            produto* prod = it->first;
            int qtd = it->second;
            total += prod->getPreco() * qtd;
            ss << "Nome: " << prod->getNome() << endl;
            ss << "Número de Série: " << prod->getNumSerie() << endl;
            ss << "Quantidade: " << qtd << endl;
            ss << "Total: " << prod->getPreco() * qtd << endl;

            string infosdaCompra = ss.str(); 

            historicoCompras.push_back(infosdaCompra);
        }
        for(auto it = carrinho.begin() ; it != carrinho.end(); it++){
            produto* prod = it->first;
            int qtd = it->second;
            lojaAtrelada->mudarQtdProduto(*prod, -qtd);
            // limpa carrinho
            carrinho.erase(it);
        }
        cout << "Total da compra: " << total << endl;
    }
};

int main(void){
    gerenciador_estoque* g = new gerenciador_estoque();

    produto p1("Arroz", "Arroz branco", 1, 10, 10);
    produto p2("Feijão", "Feijão carioca", 2, 5, 20);
    produto p3("Macarrão", "Macarrão espaguete", 3, 3, 30);

    g->addProduto(p1);
    g->addProduto(p2);
    g->addProduto(p3);

    g->listarProdutos();

    cliente c1("João", 1, g);
    c1.addProduto(p1, 2);
    // c1.addProduto(p2, 3);

    // c1.finalizarCompra();


    return 0;
}