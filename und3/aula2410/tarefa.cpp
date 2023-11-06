#include <iostream>
#include <string>
#include <list>

using std::cout, std::cin, std::endl, std::string, std::list;

class tarefa{
    string descricao;
    string deadline;
    bool concluida;
public:
    tarefa (const string& desc, const string& dead, bool c) : descricao(desc), deadline(dead), concluida(c) { }
    tarefa(const string& desc){
        descricao = desc;
        deadline = "Amanhã";
        concluida = false;
    }
    const string& get_descricao() { return descricao; }
    const string& get_deadline() { return deadline; }

    bool is_concluida() { return concluida; }
    void set_concluida(bool c){
        concluida = c;
    }
};
class gerenciador{
    list<tarefa> tarefas;
public:
    void adicionar_tarefa(const tarefa& t){
        tarefas.push_back(t);
    }
    void listar_tarefas(){
        int counter;
        for(tarefa& t : tarefas){
            cout << "(" << counter++ << ") " << endl;
            cout << "Descrição: " << endl;
            cout << t.get_descricao() << endl;
            cout << "Deadline: " << t.get_deadline() << endl;
            cout << (t.is_concluida()? "[Concluída]":"[Pendente]");
            cout << endl;
        }
    }
    void remover_tarefa(int n){
        if(n >= 1 && n <= tarefas.size()){
            auto it = tarefas.begin();
            std::advance(it, n - 1);
            tarefas.erase(it);
        }
    }
    void definir_concluida(int n){
        if(n >= 1 && n <= tarefas.size()){
            auto it = tarefas.begin();
            std::advance(it, n - 1);
            it->set_concluida(true);
        }
    }
};