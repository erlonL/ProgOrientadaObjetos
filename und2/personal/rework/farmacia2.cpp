#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cout, std::cin, std::endl, std::string, std::vector, std::map, std::getline;

// Sistema de farmácia

class Produto{
    string nome;
    float preco;
public:
    Produto(const string& n, float p) : nome(n), preco(p) {}

    // sets
    void set_nome(const string& n) { nome = n; }
    void set_preco(float p) { preco = p; }

    // gets
    string get_nome() const { return nome; } // const sinaliza que o método não
                                             // modifica o atributo do objeto
    float get_preco() { return preco; }
};

class Pessoa{ // Classe abstrata
    string nome;
    string endereco;
public:
    Pessoa(const string& n, const string& e) : nome(n), endereco(e) {}

    // sets
    void set_nome(const string& n) { nome = n; }
    void set_endereco(const string& e) { endereco = e; }

    // gets
    string get_nome() const { return nome; }
    string get_endereco() const { return endereco; }

    virtual void print_info() = 0; // virtual puro
};

class Cliente : public Pessoa{
    string cpf;
    int numCad; //número de cadastro
public:
    Cliente(const string& n, const string& e, const string& c, int nc) : Pessoa(n, e){
        cpf = c;
        numCad = nc;
    }

    // sets 
    void set_cpf(const string& c) { cpf = c; }
    void set_numCad(int nc) { numCad = nc; }

    // gets
    string get_cpf() const { return cpf; }
    int get_numCad() { return numCad; }

    virtual void print_info(){
        cout << "\033[1m" << "DADOS DO CLIENTE" << "\033[0m" << endl;
        cout << "Nome: " << get_nome() << endl;
        cout << "Endereço: " << get_endereco() << endl;
        cout << "CPF: " << cpf << endl;
        cout << "Número de cadastro: " << numCad << endl;
    }
};

class Funcionario : public Pessoa{
    string cargo;
    float salario;
public:
    Funcionario(const string& n, const string& e, const string& c, float s) : Pessoa(n, e){
        cargo = c;
        salario = s;
    }

    // sets
    void set_cargo(const string& c) { cargo = c; }
    void set_salario(float s) { salario = s; }

    // gets
    string get_cargo() const { return cargo; }
    float get_salario() const { return salario; }

    virtual void print_info(){
        cout << "\033[1m" << "DADOS DO FUNCIONÁRIO" << "\033[0m" << endl;
        cout << "Nome: " << get_nome() << endl;
        cout << "Endereço: " << get_endereco() << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Salário: " << salario << endl;
    }
};

class Estoque{
    map<Produto*, int> produtos;
    map<Produto*, int>::iterator it;
public:
    Estoque() {}

    int get_qtd_produto(Produto* p){
        it = produtos.find(p);

        if(it != produtos.end()){
            return it->second;
        }else{
            cout << "Produto não encontrado" << endl;
            return -1;
        }
    }

    void add_produto(Produto* p, int qtd){
        produtos[p] = qtd;
    }

    void add_produtos(map<Produto*, int> ps){
        for(it = ps.begin(); it != ps.end(); it++){
            produtos[it->first] = it->second;
        }
    }

    bool remove_produto(Produto* p, int qtd){
        it = produtos.find(p);
        
        if(it != produtos.end())
        {
            if(it->second /*second = (segundo campo) representa o valor*/ >= qtd)
            {
                it->second -= qtd; /*subtrai inteiro quantidade se tiver produtos suficientes no estoque*/
                return true;
            }else
            {
                cout << "\033[1m" << "**ERRO**" << "\033[0m" << endl;
                cout << "Não há produtos suficientes no estoque\npara o produto " << it->first->get_nome() << " (" << it->second << " - " << qtd << " = " << (int)(it->second) - qtd << ")" << endl;
                return false;
            }
        }else
        {
            cout << "Produto não encontrado" << endl;
            return false;
        }
    }

    void print(){
        cout << "\033[1mPRODUTOS NO ESTOQUE" << "\033[0m" << endl;
        for(it = produtos.begin(); it != produtos.end(); it++){
            cout << "Produto: " << it->first->get_nome() << endl;
            cout << "Quantidade: " << it->second << endl;
            cout << endl;
        }
    }

    void print_simples(){
        int uniqueCount = 0;
        for(it = produtos.begin(); it != produtos.end(); it++){
            uniqueCount++;
            cout << uniqueCount << ") "<< it->first->get_nome() << " " << it->second << endl;
        }
    }
};

class Venda{
    Estoque* estoque;
    Cliente* cliente;
    Funcionario* funcionario;
    Produto* produto;
    int qtd;
    string data;
public:
    Venda(Estoque* e, Cliente* c, Funcionario* f, Produto* p, int q, const string& d) : estoque(e), cliente(c), funcionario(f), produto(p), qtd(q), data(d) 
    {}

    void dados_venda(){
        cout << "\033[1m" << "DADOS DA VENDA" << "\033[0m" << endl;
        cout << "Cliente: " << cliente->get_nome() << endl;
        cout << "Funcionário: " << funcionario->get_nome() << endl;
        cout << "Produto: " << produto->get_nome() << " (" << estoque->get_qtd_produto(produto) << ")" << endl;
        cout << "Quantidade: " << qtd << endl;
        cout << "Data: " << data << endl;
        cout << "Valor total: " << produto->get_preco() * qtd << endl;
        cout << endl;
    }

    void confirmar_venda(){
        if(estoque->remove_produto(produto, qtd)){
            cout << "Venda finalizada!" << endl;
            cout << endl;
            dados_venda();
        }else{
            cout << "Venda não finalizada!" << endl;
            cout << endl;
        }
    }

    // sets
    void set_cliente(Cliente* c) { cliente = c; }
    void set_funcionario(Funcionario* f) { funcionario = f; }
    void set_produto(Produto* p) { produto = p; }
    void set_qtd(int q) { qtd = q; }
    void set_data(const string& d) { data = d; }

    // gets
    Cliente* get_cliente() const { return cliente; }
    Funcionario* get_funcionario() const { return funcionario; }
    Produto* get_produto() const { return produto; }
    int get_qtd() const { return qtd; }
    string get_data() const { return data; }
};



int main(void){

    Produto* p1 = new Produto("Paracetamol", 5.0);
    Produto* p2 = new Produto("Dipirona", 3.0);
    Produto* p3 = new Produto("Dorflex", 10.0);
    Produto* p4 = new Produto("Novalgina", 7.0);

    Estoque e1;

    map<Produto*, int> ps;
    ps[p1] = 10;
    ps[p2] = 5;


    e1.add_produtos(ps);
    e1.add_produto(p3, 2);
    e1.add_produto(p4, 3);

    Cliente* c1 = new Cliente("João", "Rua X", "123", 1);
    Cliente* c2 = new Cliente("Maria", "Rua Y", "456", 2);

    Funcionario* f1 = new Funcionario("José", "Rua Z", "Gerente", 1000.0);
    Funcionario* f2 = new Funcionario("Ana", "Rua W", "Atendente", 800.0);
    

    // e1.print();

    // e1.print_simples();

    // cout << endl;

    Venda* v1 = new Venda(&e1, c1, f2, p1, 2, "01/01/2020");
    Venda* v2 = new Venda(&e1, c2, f1, p2, 6, "02/01/2020");

    // cout << "Seja bem vindo ao Sistema de Farmácia" << endl;

    v1->confirmar_venda();
    v2->confirmar_venda();

    e1.print_simples();

    cout << endl;

    cout << "Trocando a quantidade de v2 (Dipirona)" << endl;

    v2->set_qtd(5);

    v2->confirmar_venda();

    e1.print_simples();

    cout << endl;

    Pessoa* pessoas[4];

    pessoas[0] = c1;
    pessoas[1] = c2;
    pessoas[2] = f1;
    pessoas[3] = f2;

    for(int i = 0; i < 4; i++){
        pessoas[i]->print_info();
        cout << endl;
    }

    cout << endl;

    Produto* p5 = new Produto("Doril", 2.0);

    e1.add_produto(p5, 10);

    Venda* v3 = new Venda(&e1, c1, f2, p5, 2, "01/01/2020");

    v3->dados_venda();



    return 0;
}