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
    vector<Cliente> clientes;

public:
    Clientes(vector<Cliente> cls){
        clientes = cls;
    }
    Cliente* get_cliente(int num_cad){
        for(int i = 0; i < clientes.size(); i++){
            if(num_cad == clientes[i].get_num_cadastro()){
                return &clientes[i];
            }
        }
        return NULL;
    }
    void add_cliente(Cliente c){
        clientes.push_back(c);
    }

    int get_size(){ return clientes.size(); }
    void print_info(){
        for(int i = 0; i < clientes.size(); i++){
            clientes[i].print_info();
        }
    }
    ~Clientes(){ clientes.clear(); }
};

class Funcionarios{
    vector<Funcionario> funcionarios;
public:
    Funcionarios(vector<Funcionario> fs){
        funcionarios = fs;
    }
    Funcionario* get_funcionario(int id){
        for(int i = 0; i < funcionarios.size(); i++){
            if(id == funcionarios[i].get_id()){
                return &funcionarios[i];
            }
        }
        return NULL;
    }
    void add_funcionario(Funcionario f){
        funcionarios.push_back(f);
    }
    int get_size(){ return funcionarios.size(); }
    void print_info(){
        for(int i = 0; i < funcionarios.size(); i++){
            funcionarios[i].print_info();
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
    cin.ignore();
    cout << "Nome: " << endl;
    std::getline(cin, nome);

    cout << "Telefone: " << endl;
    cin >> telefone;

    num_cadastro = tam_vector + 1;
    cout << "Número de cadastro: " << num_cadastro << endl;

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
    // Sistema de Gerenciamento de Oficina Mecânica
    
    // Cadastrando veículos
    Veiculo v1("Volkswagen Gol", 2012, "JGF-4052");
    Veiculo v2("Audi A4", 2018, "GHF-8421");
    Veiculo v3("Chevrolet Camaro", 1995, "KFS-1631");

    vector<Veiculo> veiculos;
    veiculos.push_back(v1);
    veiculos.push_back(v2);
    veiculos.push_back(v3);

    Patio patio1(veiculos);

    // Mostra Todos os veículos no Pátio
    patio1.print_veiculos();

    // Cadastrando clientes
    Cliente c1("José da Silva", "5583987215412", 1);
    Cliente c2("Elon Musk", "5583981212174", 2);
    Cliente c3("Barack Obama", "5583984125312", 3);

    vector<Cliente> clientes;
    clientes.push_back(c1);
    clientes.push_back(c2);
    clientes.push_back(c3);

    Clientes cls1(clientes);
    

    // Mostra todos os clientes
    cout << "\033[1m" << "Clientes cadastrados:\n" << "\033[0m" << endl;
    cls1.print_info();
    

    Funcionario f1("Funcionário 1", "Mecânico", 1);
    Funcionario f2("Funcionário 2", "Mecânico", 2);
    Funcionario f3("Funcionário 3", "Mecânico", 3);

    vector<Funcionario> funcionarios;
    funcionarios.push_back(f1);
    funcionarios.push_back(f2);
    funcionarios.push_back(f3);
    
    Funcionarios Funcionarios1(funcionarios);

    /*
    // Mostra todos os Funcionarios
    cout << "\033[1m" << "Funcionários cadastrados:\n" << "\033[0m" << endl;
    for(int i = 0; i < Funcionarios.size(); i++){
        Funcionarios[i]->print_info();
        cout << endl;
    }
    */

    Servico s1(&v1, &c1, {&f1, &f2}, "TROCA (4) pneus, TROCA óleo", 1550.0);

    Servico s2(&v2, &c2, {&f3}, "Revisão Geral", 1000.0);

    Servico s3(&v3, &c3, {&f1, &f2, &f3}, "TROCA DE MOTOR, CARENAGEM, SISTEMA ELÉTRICO", 15000);

    vector<Servico> servicos;
    
    servicos.push_back(s1);
    servicos.push_back(s2);
    servicos.push_back(s3);
    

    /*
    // MOSTRA TODOS OS SERVIÇOS
    for(int i = 0; i < servicos.size(); i++){
        servicos[i].print_info();
        cout << endl;
    }
    */

    // servicos[0].print_info();


    cout << "Seja bem vindo ao Sistema de Gerenciamento de Mecânica" << endl;
    int opcao;

    do{
        cout << "(1) - Cadastro de Veículo" << endl;
        cout << "(2) - Cadastro de Cliente" << endl;
        cout << "(3) - Cadastro de Funcionário" << endl;
        cout << "(4) - Novo Serviço" << endl;
        cout << "\033[1;36m" << "(5) - Ver Serviços" << "\033[0m" << endl;
        // cout << "(-1) - Sair" << endl;
        cin >> opcao;

        switch(opcao){
            case 1:{
                Veiculo novoVeiculo = cadastraVeiculo();
                patio1.add_veiculo(novoVeiculo);
                break;
            }
            case 2:{
                Cliente novoCliente = cadastraCliente(cls1.get_size());
                cls1.add_cliente(novoCliente);
                break;
            }
            case 3:{
                Funcionario novoFuncionario = cadastraFuncionario(Funcionarios1.get_size());
                Funcionarios1.add_funcionario(novoFuncionario);
                break;
            }
            case 4:{
                cout << endl;

                string placa;
                cout << "Qual a placa do Veículo? " << endl;
                cin >> placa;
                
                Veiculo* veiculo;

                if(patio1.get_veiculo(placa) == NULL){
                    cout << "\033[1;31m" << "Erro! Placa não encontrada.\n" << "\033[0m" << endl;
                    break;
                }else{
                    veiculo = patio1.get_veiculo(placa);
                }

                int num_cad;

                Cliente* cliente;

                cout << "Qual o número de cadastro do cliente? " << endl;
                cin >> num_cad;

                if(cls1.get_cliente(num_cad) == NULL){
                    cout << "\033[1;31m" << "Erro! Cliente não encontrado.\n" << "\033[0m" << endl;
                    break;
                }else{
                    cliente = cls1.get_cliente(num_cad);
                }

                int qtd_funcionarios;
                cout << "Quantos funcionários farão o serviço? " << endl;
                cin >> qtd_funcionarios;

                int id_funcionario;
                vector<Funcionario*> funcs;

                for(int i = 0; i < qtd_funcionarios; i++){
                    cout << "Qual o ID do funcionário " << i + 1 << "?" << endl;
                    cin >> id_funcionario;
                    cin.ignore();

                    if(Funcionarios1.get_funcionario(id_funcionario) == NULL){
                        cout << "\033[1;31m" << "Erro! Funcionário não encontrado. Tente novamente.\n" << "\033[0m" << endl;
                        i--;
                    }else{
                        funcs.push_back(Funcionarios1.get_funcionario(id_funcionario));

                    }
                }

                cout << endl;
                

                string descricao;

                cout << "Dê uma descrição do serviço: " << endl;
                std::getline(cin, descricao);

                float valor;
                cout << "Qual será o valor do serviço? " << endl;
                cin >> valor;
                

                // Instanciamento do Serviço Servico
                Servico novoServico(veiculo, cliente, funcs, descricao, valor);
                servicos.push_back(novoServico);
                
                // funcs.clear();
                // delete novoServico;
                // delete novoCliente;
                
                break;
            }
            case 5:{
                for(int i = 0; i < servicos.size(); i++){
                    cout << "\033[1;34m" << "Serviço " << i+1 << "\033[0m" << endl;
                    servicos[i].print_info();
                }
                break;
            }
            default:{
                cout << "Opção inválida!\n" << endl;
                break;
            }
        }

    }while(opcao > 0 && opcao < 6);
    
    // servicos.clear();
    // delete s1, s2, s3;


    return 0;
}