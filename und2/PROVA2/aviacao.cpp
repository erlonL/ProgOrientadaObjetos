#include <iostream>
#include <string>
#include <ostream>
#include <vector>

using std::cout, std::endl, std::vector, std::string, std::ostream;


class Pessoa{/*abstrata*/
    string nome;
    string cpf;
public:
    Pessoa(const string& n, const string& c) : nome(n), cpf(c) { }

    // G & S
    string get_nome() const{ return nome; }
    string get_cpf() const{ return cpf; }

    virtual void exibir_detalhes() = 0; // virtual puro

    friend ostream& operator<<(ostream& os, Pessoa& p){
        os << "Informações da Pessoa: " << endl;
        os << "Nome: " << p.nome << endl;
        os << "CPF: " << p.cpf << endl;
        return os;
    }
    // Compara se as strings cpf da classe da esquerda
    // e da direita são iguais
    // (ex.: p1 == p2)
    Pessoa& operator==(Pessoa& op){
        if(cpf == op.cpf){
            cout << "São a mesma pessoa." << endl;
            return op;
        }else{
            cout << "Não são a mesma pessoa." << endl;
        }
    }
};

class Passageiro : public Pessoa{
    string cartao_fidelidade;
public:
    Passageiro(const string& n, const string& c, const string& cf) : Pessoa(n, c), cartao_fidelidade(cf) {}

    void exibir_detalhes(){
        /*\033 é um estilizador para adicionar cores (nesse caso
        caracteres em negrito).*/
        cout << "\033[1m" <<"Informações do Passageiro" << "\033[0m" << endl;
        // Precisa ser get's pois não temos acesso aos atributos
        // privados 'nome' e 'cpf' da classe abstrata 'Pessoa'
        cout << "Nome: " << Pessoa::get_nome() << endl;
        cout << "CPF: " << Pessoa::get_cpf() << endl;
        cout << "Cartão Fidelidade: " << cartao_fidelidade << endl;
    }
    friend ostream& operator<<(ostream& os, Passageiro& p){
        /*\033 é um estilizador para adicionar cores.*/
        os << "\033[1m" <<"Informações do Passageiro" << "\033[0m" << endl;
        // Como Passageiro herda publicamente de Pessoa
        // temos acesso aos métodos públicos de Pessoa.
        os << "Nome: " << p.get_nome() << endl;
        os << "CPF: " << p.get_cpf() << endl;
        os << "Cartão Fidelidade: " << p.cartao_fidelidade << endl;
        return os;
    }
};

class Voo{
    int numero_voo;
    string origem;
    string destino;
    string data;
    string horario;
public:
    Voo(int nv, const string& o, const string& de, const string& da, const string& h):
    numero_voo(nv), origem(o), destino(de), data(da), horario(h) { }

    void exibir_detalhes(){
        cout << "Detalhes do Voo" << endl;
        cout << "Número do voo: " << numero_voo << endl;
        cout << "Origem: " << origem << endl;
        cout << "Destino: " << destino << endl;
        cout << "Data: " << data << endl;
        cout << "Horário: " << horario << endl;
    }
    friend ostream& operator<<(ostream& os, Voo& v){
        os << "Detalhes do Voo" << endl;
        os << "Número do voo: " << v.numero_voo << endl;
        os << "Origem: " << v.origem << endl;
        os << "Destino: " << v.destino << endl;
        os << "Data: " << v.data << endl;
        os << "Horário: " << v.horario << endl;
        return os;
    }
};

class Reserva{
    Passageiro* passageiro;
    Voo* voo;
    string classe;
    string assento;
public:
    Reserva(Passageiro* p, Voo* v, string c, string a) : passageiro(p), voo(v), classe(c), assento(a) { }

    Passageiro* get_passageiro() const{ return passageiro; }

    void exibir_detalhes(){
        cout << "\033[1m" << "Informações sobre a reserva" << "\033[0m" << endl;
        passageiro->exibir_detalhes();
        voo->exibir_detalhes();
        cout << "Classe: " << classe << endl;
        cout << "Assento: " << assento << endl;
    }
    friend ostream& operator<<(ostream& os, Reserva& r){
        os << "\033[1m" << "Informações sobre a reserva" << "\033[0m" << endl;
        r.passageiro->exibir_detalhes();
        r.voo->exibir_detalhes();
        os << "Classe: " << r.classe << endl;
        os << "Assento: " << r.assento << endl;
        return os;
    }
};

class Companhia_Aerea{
    vector<Voo*> voos;
    vector<Reserva*> reservas;
public:
    Companhia_Aerea(){
        // Construtor vazio pois adicionaremos
        // as informações à medida que forem criadas
    }

    void adicionar_voo(Voo* v){
        voos.push_back(v);
    }
    void fazer_reserva(Passageiro* pas, Voo* v, const string& c, const string& a){
        int noVoo = 0;
        // Para checar se o passageiro já está no voo,
        // poderíamos checar todas as reservas para um certo
        // voo, comparando o passageiro atual com cada passageiro
        // de um certo voo que se queira fazer a reserva
        for(const auto& reserva : reservas){
            /* a sobrecarga utilizada será a de comparar 
            CPF.*/
            if(pas == reserva->get_passageiro()){
                noVoo = 1;
            }
        }
        if(noVoo){
            cout << "Passageiro já está no voo." << endl;
        }else{
            Reserva* nova_Reserva = new Reserva(pas, v, c, a);
            reservas.push_back(nova_Reserva);
            cout << "Reserva adicionada! " << endl;
        }
    }
    void listar_voos_disponiveis(){
        cout << "Todos os voos disponíveis" << endl;
        for(const auto& voo : voos){
            voo->exibir_detalhes();
        }
    }
    void listar_reservas(){
        cout << "Reservas feitas" << endl;
        for(const auto& reserva : reservas){
            reserva->exibir_detalhes();
        }
    }
};



int main(void){
    Passageiro p1("José", "001.001.213-53", "001");
    Passageiro p2("João", "001.001.213-53", "002");

    Voo v1(1, "Bahia", "João Pessoa", "26/09/23", "23:99");
    Voo v2(2, "João Pessoa", "Bahia", "27/09/23", "12:59");
    Voo v3(3, "Miami", "João Pessoa", "27/09/23", "23:49");

    Reserva r1(&p1, &v1, "Primeira", "L23");
    Reserva r2(&p2, &v3, "Estudante", "A12");

    cout << "Informações\n\n" << endl;
    
    cout << r1 << endl;
    cout << r2 << endl;

    cout << "Informações Gerais\n\n" << endl;

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    
    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}