#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::string, std::vector, std::to_string;

class Cliente{
    string nome;
    string cpf;
    string endereco;
public:
    Cliente(string n, string c, string e){
        nome = n;
        cpf = c;
        endereco = e;
    }
    ~Cliente(){}
    // gets, sets e print_info()
    string get_nome(){ return nome; }
    string get_cpf(){ return cpf; }
    string get_endereco(){ return endereco; }

    void set_nome(string n){ nome = n; }
    void set_cpf(string c){ cpf = c; }
    void set_endereco(string e){ endereco = e; }

    void print_info(){
        cout << "Nome: " << get_nome() << endl;
        cout << "CPF: " << get_cpf() << endl;
        cout << "Endereço: " << get_endereco() << endl;
    }
};

class Operacao{
    char tipo;
    float valor;
public:
    Operacao(char t, float v){
        tipo = t;
        valor = v;
    }
    ~Operacao(){}
    // gets, sets e print_info()
    char get_tipo(){ return tipo; }
    float get_valor(){ return valor; }

    void set_tipo(char t){ tipo = t; }
    void set_valor(float v){ valor = v; }

    void print_info(){
        if(get_tipo() == 'C'){
            cout << "\033[1;32m";
        }else if(get_tipo() == 'D'){
            cout << "\033[1;31m";
        }
        cout << get_tipo() << " " << "(" << get_valor() << ")" << endl;
        cout << "\033[0m";
    }
};

class Conta{
    int numero;
    Cliente* cliente;
    float saldo;
    vector<Operacao> operacoes;
    //Operacao** o; // array de ponteiros pois as operações podem existir
                  // fora de uma conta, imagine se uma conta for apagada
                  // por exemplo, perderíamos todas as transações que ela fez?
public:
    Conta(int n, Cliente* c, float s){
        numero = n;
        cliente = c;
        saldo = s;
    }
    ~Conta(){ operacoes.clear(); }
    // gets, sets e print_info()
    int get_numero(){ return numero; }
    Cliente* get_cliente(){ return cliente; }
    float get_saldo(){ return saldo; }

    void set_numero(int n){ numero = n; }
    void set_cliente(Cliente* c){ cliente = c; }
    void set_saldo(float s){ saldo = s; }

    void add_operacao(Operacao o){
        operacoes.push_back(o);
        if(o.get_tipo() == 'C'){
            saldo += o.get_valor();
        }else if(o.get_tipo() == 'D'){
            saldo -= o.get_valor();
        }
    }

    void print_info(){
        cout << "\nNúmero: " << get_numero() << endl;
        cout << "Cliente: " << get_cliente()->get_nome() << endl;
        cout << "Operações realizadas:" << endl;
        if(operacoes.size() == 0){
            cout << "\033[1m**Nenhuma.**\033[0m\n" << endl;
        }else{
            for(int i = 0; i < operacoes.size(); i++){
                operacoes[i].print_info();
            }
        }
        cout << "\033[1m";
        cout << "Saldo: ";
        cout << "\033[0m";

        if(get_saldo() < 0){
            cout << "\033[1;31m";
        }else{
            cout << "\033[1;32m";
        }
        cout << get_saldo() << endl;
        cout << "\033[0m" << endl;
    }


};

class Banco{
    vector<Conta> contas;
    int codigo;
public:
    Banco(int c){ codigo = c; }
    ~Banco(){ contas.clear(); }
    // gets, sets e print_info()
    void add_conta(Conta c){
        contas.push_back(c);
    }
    void remove_conta(int idx){
        contas.erase(contas.begin() + idx);
    }
    vector<Conta> get_contas(){ return contas; }

    int get_num_contas(){ return contas.size(); }

    int get_codigo(){ return codigo; }

    Conta* get_conta(int numero){
        for(int i = 0; i < contas.size(); i++){
            if(contas[i].get_numero() == numero){
                return &contas[i];
            }
        }
        return nullptr;
    }
    void transferir(int n1, int n2, float valor){
        if(get_conta(n1) == nullptr){
            cout << "\033[1;31m" << "Erro! Número de Conta '" << n1 << "' não encontrada" << "\033[0m" << endl;
            return;
        }
        if(get_conta(n2) == nullptr){
            cout << "\033[1;31m" << "Erro! Número de Conta '" << n2 << "' não encontrada" << "\033[0m" << endl;
            return;
        }
        Conta* c1 = get_conta(n1);
        Conta* c2 = get_conta(n2);
        // c1->set_saldo(get_conta(n1)->get_saldo() - valor); // ???????????????????
        // c2->set_saldo(get_conta(n2)->get_saldo() + valor);
        c1->add_operacao(Operacao('D', valor));
        c2->add_operacao(Operacao('C', valor));
    }

    void print_info(){
        
        cout << "\033[1;31mBanco " << get_codigo() << "\033[0m" << "\n" << endl;
        cout << "Contas cadastradas:" << endl;
        for(int i = 0; i < contas.size(); i++){
            contas[i].print_info();
        }
    }
};

string formatCPF(string cpf){
    // Verifique se a entrada tem 11 dígitos (CPF sem formatação)
    if (cpf.length() != 11) {
        cout << "CPF inválido. Deve conter 11 dígitos." << endl;
        return NULL;
    }

    // Formate o CPF com pontos e traço
    string formattedCPF = cpf.substr(0, 3) + "." + cpf.substr(3, 3) + "." + cpf.substr(6, 3) + "-" + cpf.substr(9, 2);

    return formattedCPF;
}


int main(void){
    // Criação do Banco Base (1)
    Cliente c1("João", "123.456.789-00", "Rua 1");
    Cliente c2("Maria", "987.654.321-00", "Rua 2");
    Conta conta1(1, &c1, 1000);
    Conta conta2(2, &c2, 2000);

    Banco *b = new Banco(1);
    b.add_conta(&conta1);
    b.add_conta(&conta2);
    // b->print_info();

    cout << "Seja Bem vindo ao Banco " << b->get_codigo() << endl;
    string nome;
    string cpf;
    string endereco;
    int opcao;
    do{
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Criar Conta" << endl;
        cout << "2 - Remover Conta" << endl;
        cout << "3 - Transferir" << endl;
        cout << "4 - Sair" << endl;
        cout << ">> " endl;
        cin >> opcao;

        switch(opcao){
            case 1:
                // Criar Conta
                cout << "Digite o nome do cliente: ";
                cin >> nome;

                // Formatar CPF
                cout << "Digite o CPF do cliente: ";
                cin >> cpf;
                cpf = formatCPF(cpf);

                cout << "Digite o endereço do cliente: ";
                cin >> endereco;

                Cliente* c = new Cliente(nome, cpf, endereco);
                Conta* conta = new Conta(b->get_num_contas() + 1, c, 0);
                b->add_conta(conta);
                break;
            case 2:
                // Remover Conta
                cout << "Digite o número da conta: ";
                int numero;
                cin >> numero;
                b->remove_conta(numero);
                break;
            case 3:
                // Transferir
                cout << "Digite o número da conta de origem: ";
                int numero1;
                cin >> numero1;
                cout << "Digite o número da conta de destino: ";
                int numero2;
                cin >> numero2;
                cout << "Digite o valor a ser transferido: ";
                float valor;
                cin >> valor;
                b->transferir(numero1, numero2, valor);
                break;
        }
    }while(opcao > 0 && opcao < 4);
    
    return 0;
}