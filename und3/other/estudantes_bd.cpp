#include <iostream>
#include <map>

using std::cout, std::endl, std::map, std::cin, std::string;

class estudante{
    string nome;
    int idade;
    string matricula;
    // map<string, int>
public:
    estudante(){ }
    estudante(const string& n, int i, const string& m): nome(n), idade(i), matricula(m) { }

    string& get_nome() { return nome; }
    int get_idade() { return idade; }
    string& get_matricula() { return matricula; }
    void print_info(){
        cout << "Nome: " << nome << endl;
        cout << "Matrícula: " << matricula << endl;
        cout << "Idade: " << idade << endl;
        cout << endl;
    }
};

class bancoDeDados{
    map<string, estudante*> estudantes;
public:
    void adicionar_estudante(const string& index, const estudante& e){
        estudantes[index] = e;
    }
    void listar_estudantes(){
        for(const auto& par : estudantes){
            string index = par.first;
            estudante e = par.second;
            cout << "Index: " << index << endl;
            e.print_info();
        }
    }
    void remover_estudante(const string& index){
        estudantes.erase(index);
    }
    estudante* buscar_estudante(const string& index){
        auto it = estudantes.find(index);
        if(it != estudantes.end()){
            return &it->second;
        }
        return nullptr;
    }
};


int main(void){
    bancoDeDados bd;
    string rm_est, sr_est;

    bd.adicionar_estudante("ana", estudante("Ana Silva", 25, "1234"));
    bd.adicionar_estudante("bob", estudante("Bob Ferreira", 33, "3245"));
    bd.adicionar_estudante("joe", estudante("Joe Antunes", 32, "3455"));

    bd.listar_estudantes();

    cout << "Digite o índice de um estudante para remover: ";
    cin >> rm_est;

    bd.remover_estudante(rm_est);

    bd.listar_estudantes();

    cout << "Digite o índice de um estudante para localizar: ";
    cin >> sr_est;

    estudante* my_est = bd.buscar_estudante(sr_est);

    if(my_est){
        cout << "Estudante encontrado!" << endl;
        my_est->print_info();
    }else{
        cout << "Estudante não encontrado" << endl;
    }
    return 0;
}