#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

class Veiculo{
    string modelo;
    int ano;
    string placa;

public:
    Veiculo(string m, int a, string p){
        modelo = m;
        ano = a;
        placa = p;
    }
    string get_modelo(){ return modelo;}
    int get_ano(){ return ano; }
    string get_placa(){ return placa; }

    void print_info(){
        cout << "\033[1m" << "Informações do Veículo: " << "\033[0m"<< endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Ano: " << ano << endl;
        cout << "Placa: " << placa << endl;
    }
};


class Cliente{
    string nome;
    string telefone;
    int num_cadastro;
public:
    Cliente(){}
    Cliente(string n, string t, int nc){
        nome = n;
        telefone = t;
        num_cadastro = nc;
    }
    int get_num_cadastro(){ return num_cadastro; }
    void print_info(){
        cout << "\033[1m" << "Informações do Cliente: " << "\033[0m"<< endl;
        cout << "Nome: " << nome << endl;
        cout << "Telefone: " << telefone << endl;
        cout << "Número de cadastro: " << num_cadastro << endl;
        cout << endl;
    }
};

class Funcionario{
    string nome;
    string cargo;
    int id;
public:
    Funcionario(){}
    Funcionario(string n, string c, int i){
        nome = n;
        cargo = c;
        id = i;
    }
    string get_nome(){ return nome; }
    string get_cargo(){ return cargo; }
    int get_id(){ return id; }

    void print_info(){
        cout << "\033[1m" << "Informações do Funcionário: " << "\033[0m"<< endl;
        cout << "Nome: " << nome << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "ID: " << id << endl;
    }
};

// Todo serviço deve ser atrelado à um veículo, um cliente e um funcionário
// Veículo pois é um serviço
// Cliente pois ele está sendo prestado à alguém
// E o funcionário que está realizando (ou realizou para consulta futura) esse serviço.
class Servico{
    Veiculo* veiculo;
    Cliente* cliente;
    vector<Funcionario*> funcionarios;
    string descricao;
    float valor;
public:
    Servico(Veiculo* v, Cliente* c, vector<Funcionario*> fs, string d, float val){
        veiculo = v;
        cliente = c;
        funcionarios = fs;
        descricao = d;
        valor = val;
    }
    string get_descricao(){ return descricao; }
    float get_valor(){ return valor; }
    Veiculo* get_veiculo(){ return veiculo; }
    Cliente* get_cliente(){ return cliente; }
    vector<Funcionario*> get_funcionarios(){ return funcionarios; }

    void print_info(){
        // cout << "Veículo: " << endl;
        veiculo->print_info();
        cout << endl;

        // cout << "Cliente: " << endl;
        cliente->print_info();
        cout << endl;

        // cout << "Funcionários: " << endl;
        for(int i = 0; i < funcionarios.size(); i++){
            funcionarios[i]->print_info();
        }
        cout << endl;

        cout << "\033[1m" << "Descrição: \n" << "\033[0m" << descricao << endl;
        cout << endl;

        cout << "\033[1m" << "Valor: \n" << "\033[0m" << valor << endl;
        cout << endl;
    }

    ~Servico(){ funcionarios.clear(); }
};

class Patio{
    vector<Veiculo> veiculos;
public:
    Patio(){}
    Patio(vector<Veiculo> vs){
        veiculos = vs;
    }
    Veiculo* get_veiculo(string placa){
        for(int i = 0; i < veiculos.size(); i++){
            if(placa == veiculos[i].get_placa()){
                return &veiculos[i];
            }
        }
        return NULL;
    }
    void print_veiculos(){
        cout << "\033[1m" << "Veículos no pátio:\n" << "\033[0m" << endl;
        for(int i = 0; i < veiculos.size(); i++){
            veiculos[i].print_info();
        }
    }
    void add_veiculo(Veiculo v){
        veiculos.push_back(v);
    }
    ~Patio(){ veiculos.clear(); }
};

class Clientes{
    vector<Cliente*> clientes;

public:
    Clientes(vector<Cliente*> cls){
        clientes = cls;
    }
    Cliente* get_cliente(int num_cad){
        for(int i = 0; i < clientes.size(); i++){
            if(num_cad == clientes[i]->get_num_cadastro()){
                return clientes[i];
            }
        }
        return NULL;
    }
    void add_cliente(Cliente* c){
        clientes.push_back(c);
    }

    int get_size(){ return clientes.size(); }
    void print_info(){
        for(int i = 0; i < clientes.size(); i++){
            clientes[i]->print_info();
        }
    }
    ~Clientes(){ clientes.clear(); }
};

class Funcionarios{
    vector<Funcionario*> funcionarios;
public:
    Funcionarios(vector<Funcionario*> fs){
        funcionarios = fs;
    }
    Funcionario* get_funcionario(int id){
        for(int i = 0; i < funcionarios.size(); i++){
            if(id == funcionarios[i]->get_id()){
                return funcionarios[i];
            }
        }
        return NULL;
    }
    void add_funcionario(Funcionario* f){
        funcionarios.push_back(f);
    }
    int get_size(){ return funcionarios.size(); }
    void print_info(){
        for(int i = 0; i < funcionarios.size(); i++){
            funcionarios[i]->print_info();
        }
    }
    ~Funcionarios(){ funcionarios.clear(); }
};

Veiculo cadastraVeiculo(){
    string modelo, placa;
    int ano;

    cout << "\033[1mCadastro de Veículo\033[0m" << endl;
    cout << "Modelo: " << endl;
    cin >> modelo;
    cout << "Ano: " << endl;
    cin >> ano;
    cout << "Placa: " << endl;
    cin >> placa;

    return Veiculo(modelo, ano, placa);
}

Cliente cadastraCliente(int tam_vector){
    string nome, telefone;
    int num_cadastro;

    cout << "\033[1mCadastro de Cliente\033[0m" << endl;
    cout << "Nome: " << endl;
    cin >> nome;
    cout << "Telefone: " << endl;
    cin >> telefone;

    num_cadastro = tam_vector + 1;

    return Cliente(nome, telefone, num_cadastro);
}

Funcionario cadastraFuncionario(int tam_vector){
    string nome, cargo;

    cout << "\033[1mCadastro de Funcionário\033[0m" << endl;
    cout << "Nome: " << endl;
    cin >> nome;
    cout << "Cargo: " << endl;
    cin >> cargo;

    int id = tam_vector + 1;

    return Funcionario(nome, cargo, id);
}




int main(void){
    vector<Veiculo> veiculos;
    Patio patio1(veiculos);

    vector<Cliente*> clientes;
    Clientes clientes1(clientes);

    vector<Funcionario*> funcionarios;
    Funcionarios funcionarios1(funcionarios);

    vector<Servico> servicos;

    for(int i = 0; i < 3; i++){
        Veiculo novoVeiculo = cadastraVeiculo();
        patio1.add_veiculo(novoVeiculo);
    }
    patio1.print_veiculos();

    return 0;
}