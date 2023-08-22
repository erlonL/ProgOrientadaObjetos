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
    Cliente(string n, string t, int nc){
        nome = n;
        telefone = t;
        num_cadastro = nc;
    }
    int get_num_cadastro(){ return num_cadastro; }
    void print_info(){
        cout << "Nome: " << nome << endl;
        cout << "Telefone: " << telefone << endl;
        cout << "Número de cadastro: " << num_cadastro << endl;
    }
};

class Funcionario{
    string nome;
    string cargo;
public:
    Funcionario(){}
    Funcionario(string n, string c){
        nome = n;
        cargo = c;
    }
    string get_nome(){ return nome; }
    string get_cargo(){ return cargo; }

    void print_info(){
        cout << "Nome: " << nome << endl;
        cout << "Cargo: " << cargo << endl;
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
        cout << "Veículo: " << endl;
        veiculo->print_info();
        cout << endl;

        cout << "Cliente: " << endl;
        cliente->print_info();
        cout << endl;

        cout << "Funcionários: " << endl;
        for(int i = 0; i < funcionarios.size(); i++){
            funcionarios[i]->print_info();
        }
        cout << endl;

        cout << "Descrição: \n" << descricao << endl;
        cout << endl;

        cout << "Valor: \n" << valor << endl;
        cout << endl;
    }

    ~Servico(){ funcionarios.clear(); }
};

class Patio{
    vector<Veiculo*> veiculos;
public:
    Patio(vector<Veiculo*> vs){
        veiculos = vs;
    }
    Veiculo* get_veiculo(string placa){
        for(int i = 0; i < veiculos.size(); i++){
            if(placa == veiculos[i]->get_placa()){
                return veiculos[i];
            }
        }
        return NULL;
    }
    void print_veiculos(){
        cout << "\033[1m" << "Veículos no pátio:\n" << "\033[0m" << endl;
        for(int i = 0; i < veiculos.size(); i++){
            veiculos[i]->print_info();
        }
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
    ~Clientes(){ clientes.clear(); }
};



int main(void){
    // Sistema de Gerenciamento de Oficina Mecânica
    
    // Cadastrando veículos
    Veiculo v1("Volkswagen Gol", 2012, "JGF-4052");
    Veiculo v2("Audi A4", 2018, "GHF-8421");
    Veiculo v3("Chevrolet Camaro", 1995, "KFS-1631");

    Patio patio1({&v1, &v2, &v3});

    // Mostra Todos os veículos no Pátio
    // patio1.print_veiculos();

    // Cadastrando clientes
    Cliente c1("José da Silva", "5583987215412", 1);
    Cliente c2("Elon Musk", "5583981212174", 2);
    Cliente c3("Barack Obama", "5583984125312", 3);

    Clientes cls1({&c1, &c2, &c3});

    /*
    // Mostra todos os clientes
    cout << "\033[1m" << "Clientes cadastrados:\n" << "\033[0m" << endl;
    for(int i = 0; i < Clientes.size(); i++){
        Clientes[i]->print_info();
        cout << endl;
    }
    */

    Funcionario f1("Funcionário 1", "Mecânico");
    Funcionario f2("Funcionário 2", "Mecânico");
    Funcionario f3("Funcionário 3", "Mecânico");

    vector<Funcionario*> Funcionarios;

    Funcionarios = {&f1, &f2, &f3};

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
        cout << "(5) - Ver Serviços" << endl;
        cout << "(-1) - Sair" << endl;
        cin >> opcao;

        switch(opcao){
            case 1:{
                // TBD
                // Cadastro de veículo pedindo informações como placa
                // Modelo e ano
                break;
            }
            case 2:{
                // TBD
                // Lógica de cadastro pedindo informações do usuário
                // Como nome e telefone, o num_cadastro seria obtido
                // através do tamanho do vector

                break;
            }
            case 3:{
                // TBD
                // Cadastro de funcionário pedindo nome e cargo
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

                Cliente* novoCliente;

                cout << "Qual o número de cadastro do cliente? " << endl;
                cin >> num_cad;

                if(cls1.get_cliente(num_cad) == NULL){
                    cout << "\033[1;31m" << "Erro! Cliente não encontrado.\n" << "\033[0m" << endl;
                    break;
                }else{
                    novoCliente = cls1.get_cliente(num_cad);
                }

                int qtd_funcionarios;
                cout << "Quantos funcionários farão o serviço? " << endl;
                cin >> qtd_funcionarios;

                vector<Funcionario*> funcs;

                int pos_funcionario;

                for(int i = 0; i < qtd_funcionarios; i++){
                    cout << "Qual o número do funcionário? " << endl;
                    cin >> pos_funcionario;

                    funcs.push_back(Funcionarios[pos_funcionario-1]);
                }

                string descricao;

                cout << "Dê uma descrição do serviço: " << endl;
                cin >> descricao;

                float valor;
                cout << "Qual será o valor do serviço? " << endl;
                cin >> valor;
                

                // Instanciamento do Serviço Servico
                Servico novoServico(veiculo, novoCliente, funcs, descricao, valor);
                servicos.push_back(novoServico);
                break;

                funcs.clear();
            }
            case 5:{
                for(int i = 0; i < servicos.size(); i++){
                    servicos[i].print_info();
                }
                break;
            }
            default:{
                if(opcao != -1)
                    cout << "Opção inválida! Tente novamente.\n" << endl;
                break;
            }
        }

    }while(opcao != -1);
    
    servicos.clear();
    Funcionarios.clear();


    return 0;
}