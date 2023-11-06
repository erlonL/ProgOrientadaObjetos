#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl, std::string;

class Contato{
    string nome;
    string telefone;
    string email;
public:
    Contato(string n, string t, string e) : nome(n), telefone(t), email(e) { }
    string get_nome() const { return nome; }
    string get_telefone() const { return telefone; }
    string get_email() const { return email; }
};

class Agenda{
    vector<Contato> contatos;
public:
    Agenda(){ }
    void inserirContato(Contato c){
        contatos.push_back(c);
    }
    void removerContato(string nome){
        auto it = contatos.begin();

        for(it ; it != contatos.end(); it++){
            if(it->get_nome() == nome){
                contatos.erase(it);
                cout << "Contato removido com sucesso!" << endl;
                break;
            }
        }
        if (it == contatos.end())
            cout << "Contato " << nome << " não encontrado!" << endl;
    }
    void listarContatos(){
        cout << " **CONTATOS NA AGENDA** " << endl;
        for(auto it = contatos.begin(); it != contatos.end(); it++){
            cout << "Nome: " << it->get_nome() << endl;
            cout << "Telefone: " << it->get_telefone() << endl;
            cout << "Email: " << it->get_email() << endl;
        }
    }
};


int main(void){

    Agenda agenda;

    agenda.inserirContato(Contato("João", "99999-9999", "Joao@email.com"));
    agenda.inserirContato(Contato("Maria", "88888-8888", "maria@example.com"));
    agenda.inserirContato(Contato("José", "77777-7777", "jose@email.com"));

    agenda.listarContatos();

    cout << endl;

    cout << "Removendo Maria..." << endl;

    agenda.removerContato("Maria");

    cout << "Listando contatos...\n" << endl;

    agenda.listarContatos();

    cout << "\nTentando remover contato inexistente..." << endl;

    agenda.removerContato("Jaspion");

    cout << "Listando contatos...\n" << endl;

    agenda.listarContatos();

    cout << endl;

    return 0;
}