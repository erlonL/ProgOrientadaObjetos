#include <iostream>
#include <string>
#include <ostream>
#include <vector>

using std::cout, std::endl, std::string, std::ostream, std::vector;

class Pessoa{
    string nome;
    int idade;
public:
    Pessoa(const string& n, int i): nome(n), idade(i) { }
    virtual void exibir_detalhes() = 0; // Virtual puro

    /*const pois não serão modificados*/
    string get_nome() const{ return nome; }
    int get_idade() const{ return idade; }

    friend ostream& operator<<(ostream& os, const Pessoa& p){
        os << "\033[1m" <<"Informações da Pessoa" << "\033[0m" << endl;
        os << "Nome: " << p.nome << endl;
        os << "Idade: " << p.idade << endl;
        return os;
    }
};

class Paciente : public Pessoa{
    int numero_paciente;
    string condicao;
public:
    Paciente(const string& n, int i, int np, const string& c) : Pessoa(n, i), numero_paciente(np), condicao(c) { }
    /* Se não houvesse sobrecarga do `<<` nessa classe: 
    Utilizando o ponteiro para a própria classe,
        podemos chamar o operador sobrescrito `<<`
        para que imprima as informações de Pessoa.
        
        Ou seja, ao invés de 1 e 2, teríamos
        `cout << *this << endl;` */
    void exibir_detalhes(){
        /*\033 é um estilizador para adicionar cores.*/
        cout << "\033[1m" <<"Informações do Paciente" << "\033[0m" << endl;
        cout << "Nome: " << Pessoa::get_nome() << endl; // 1
        cout << "Idade: "<< Pessoa::get_idade() << endl; // 2
        cout << "Número do Paciente: " << numero_paciente << endl;
        cout << "Condição: " << condicao << endl;
    }
    friend ostream& operator<<(ostream& os, Paciente& pc){
        os << "\033[1m" <<"Informações do Paciente" << "\033[0m" << endl;
        os << "Nome: " << pc.get_nome() << endl;
        os << "Idade: " << pc.get_idade() << endl;
        os << "Número do Paciente: " << pc.numero_paciente << endl;
        os << "Condição: " << pc.condicao << endl;
        return os;
    }
};

class Medico : public Pessoa{
    string especialidade;
    int crm;
public:
    Medico(const string& n, int i, const string& e, int c) : Pessoa(n, i), especialidade(e), crm(c){ }

    void exibir_detalhes(){
        /*\033 é um estilizador para adicionar cores.*/
        cout << "\033[1m" <<"Informações do Médico" << "\033[0m" << endl;
        cout << "Nome: " << Pessoa::get_nome() << endl;
        cout << "Idade: "<< Pessoa::get_idade() << endl;
        cout << "Especialidade: " << especialidade << endl;
        cout << "CRM: " << crm << endl;
    }
    friend ostream& operator<<(ostream& os, const Medico& m){
        os << "\033[1m" <<"Informações do Médico" << "\033[0m" << endl;
        os << "Nome: " << m.get_nome() << endl;
        os << "Idade: "<< m.get_idade() << endl;
        os << "Especialidade: " << m.especialidade << endl;
        os << "CRM: " << m.crm << endl;
        return os;
    }
};

class Procedimento{
    string descricao;
    string data;

public:
    Procedimento(const string& de, const string& da) : descricao(de), data(da) { }

    void exibir_detalhes(){
        /*\033 é um estilizador para adicionar cores.*/        
        cout << "\033[1m" << "Detalhes sobre o Procedimento" << "\033[0m" << endl;
        cout << "Descrição: " << descricao << endl;
        cout << "Data: " << data << endl;
    }
    friend ostream& operator<<(ostream& os, const Procedimento& p){
        os << "\033[1m" << "Detalhes sobre o Procedimento" << "\033[0m" << endl;
        os << "Descrição: " << p.descricao << endl;
        os << "Data: " << p.data << endl;
        return os;
    }
};

class Procedimento_Registrado{
    Medico* medico;
    Paciente* paciente;
    Procedimento* procedimento;
public:
    Procedimento_Registrado(Medico* m, Paciente* pa, Procedimento* pr) : medico(m), paciente(pa), procedimento(pr){}

    void exibir_detalhes(){
        /*\033 é um estilizador para adicionar cores.*/        
        cout << "\033[1m" << "Detalhes sobre o Procedimento Registrado: " << "\033[0m" << endl;
        medico->exibir_detalhes();
        paciente->exibir_detalhes();
        procedimento->exibir_detalhes();
    }
};

class Hospital{
    vector<Paciente*> pacientes;
    vector<Medico*> medicos;
    vector<Procedimento_Registrado*> procedimentos;
public:
    Hospital(){
        // Só seria necessário se estivéssemos usando o new
        // /*Inicializando com ponteiros nulos*/
        // pacientes = nullptr;
        // medicos = nullptr;
        // procedimentos = nullptr;
    }
    void adicionar_paciente(Paciente* pac){
        pacientes.push_back(pac);
    }
    void adicionar_medico(Medico* med){
        medicos.push_back(med);
    }
    void listar_pacientes(){
        for(const auto& paciente : pacientes){
            cout << *paciente << endl;
        }
    }
    void listar_medicos(){
        for(const auto& medico : medicos){
            cout << *medico << endl;
        }
    }
    void registrar_procedimento(Medico* med, Paciente* pac, Procedimento* proc){
        Procedimento_Registrado* novo_procedimento = new Procedimento_Registrado(med, pac, proc);

        procedimentos.push_back(novo_procedimento);
    }
    void listar_procedimentos(){
        for(const auto& procedimento : procedimentos){
            procedimento->exibir_detalhes();
        }
    }
    // Não precisamos usar delete nos vectors
    // pois já será cuidado pelo sistema operacional
    ~Hospital(){}
};



int main(void){

    Paciente p1("José", 18, 1, "Consciente e Orientado.");
    Paciente p2("Maria", 25, 2, "Estável.");
    Paciente p3("Lucas", 67, 3, "Sob atenção.");

    Medico m1("João", 29, "Cérebros", 10);
    Medico m2("Medico", 45, "Ortopedia", 20);

    Procedimento pr1("Troca de Cérebro", "26/09/23");
    Procedimento pr2("Cirurgia no Joelho", "26/09/23");

    // Feito com alocação dinâmica
    // para facilitar na desalocação dos
    // arrays em `~Hospital()`
    Hospital* h1 = new Hospital();

    h1->adicionar_paciente(&p1);
    h1->adicionar_paciente(&p2);
    h1->adicionar_paciente(&p3);

    h1->adicionar_medico(&m1);
    h1->adicionar_medico(&m2);

    h1->registrar_procedimento(&m1, &p1, &pr1);
    h1->registrar_procedimento(&m2, &p3, &pr2);

    cout << "Pacientes:\n" << endl;
    h1->listar_pacientes();
    cout << endl;

    cout << "Médicos:\n" << endl;
    h1->listar_medicos();
    cout << endl;

    cout << "Procedimentos:\n" << endl;
    h1->listar_procedimentos();
    cout << endl;

    delete h1;
    return 0;
}