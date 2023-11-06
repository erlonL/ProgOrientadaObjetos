// Gerenciamento de funcionários
#include <iostream>
#include <vector>
#define SALARY_NUMBER 1000


using std::cout, std::endl, std::string, std::vector;

template <typename T>
class Funcionario{
    string nome;
    int id;
    T salario;
public:
    Funcionario(string n, int i, T s): nome(n), id(i), salario(s) { }
    
    string getNome() const{ return nome; }
    int getId() const{ return id; }
    T getSalario() const{ return salario; }
    
    void setNome(string n){ nome = n; }
    void setId(int i){ id = i; }
    void setSalario(T s){ salario = s; }
    void printInfo(){
        cout << "Informações do funcionário:" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Id: " << id << endl;
        cout << "Salário: " << salario << endl;
    }
};

template <typename T>
class EmpregadoRegular : public Funcionario<T>{
public:
    EmpregadoRegular(string n, int i): Funcionario<T>(n, i, SALARY_NUMBER) { }
};

template <typename T>
class Gerente : public Funcionario<T>{
public:
    Gerente(string n, int i): Funcionario<T>(n, i, SALARY_NUMBER * 2) { }
};

template <typename T>
class Estagiario : public Funcionario<T>{
public:
    Estagiario(string n, int i): Funcionario<T>(n, i, SALARY_NUMBER / 2) { }
};

template <typename T>
class EmpregadoGerente : public EmpregadoRegular<T>, public Gerente<T>{
public:
    EmpregadoGerente(string n, int i): EmpregadoRegular<T>(n, i), Gerente<T>(n, i) { }
};

// Singleton
template <typename T>
class Empresa{
    string nome;
    vector<Funcionario<T>*> funcionarios;
    int numFuncionarios;
    static Empresa* _instance;
    Empresa(){
        numFuncionarios = 0;
        // cout << "Instância criada." << endl;
    }
public:
    static Empresa* getInstance(){
        if(_instance == nullptr){
            _instance = new Empresa();
        }
        return _instance;
    }
    void addFuncionario(Funcionario<T>* f){
        funcionarios.push_back(f);
        numFuncionarios++; 
    }
    void calcularSalarios(){
        float soma = 0;
        for(const auto& f : funcionarios){
            soma += f->getSalario();
        }
        cout << "Total de salários: " << soma << endl;
        cout << "Média de salários: " << soma / numFuncionarios << endl;
    }
    void listarFuncionarios(){
        for(const auto& f : funcionarios){
            f->printInfo();
        }
    }
    void aumentarSalarios(T aumento){
        for(const auto& f : funcionarios){
            f->setSalario(f->getSalario() + aumento);
        }
    }
};

template <typename T>
Empresa<T>* Empresa<T>::_instance = nullptr;

int main(void){
    Empresa<int>* e = Empresa<int>::getInstance();

    
    return 0;
}