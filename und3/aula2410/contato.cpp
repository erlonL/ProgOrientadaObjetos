#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl, std::vector, std::string, std::cin;

class contato{
    string nome;
    string telefone;
    string email;
public:
    contato(const string& n, const string& t, const string& e) : nome(n), telefone(t), email(e) { }

    string get_nome() { return nome; }
    string get_telefone() { return telefone; }
    string get_email() { return email; }
    /*sets*/
    // friend std::ostream& operator<<(std::ostream& os, const contato& c){
    //         os << "Nome: " << c->get_nome() << endl;
    //         os << "Telefone: " << c.get_telefone() << endl;
    //         os << "Email: " << c->get_email() << endl;
    //         return os;
    // }
};

class agenda{
    vector<contato> contatos;
public:
    void adicionar_contato(const contato& c){
        contatos.push_back(c);
    }
    void listar_contatos(){
        for(contato& c : contatos){
            cout << "Nome: " << c.get_nome() << endl;
            cout << "Telefone: " << c.get_telefone() << endl;
            cout << "Email: " << c.get_email() << endl;
        }
    }
    void remover_contato(const string& n){
        // contatos.erase(std::remove_if(contatos.begin(), contatos.end(),[nome](const contato& c){
        //         return c.get_nome() == nome;
        //     }), contatos.end());
        // )
        for(auto it = contatos.begin() ; it != contatos.end();){ 
            if((it)->get_nome() == n){
                it = contatos.erase(it); // remove elemento
                                         // e avança o iterador
            } else{
                ++it;
            }
        }
    }
};


int main(void){
    agenda minha_agenda;

    minha_agenda.adicionar_contato(contato("Ana", "00000", "Ana@email.com"));
    minha_agenda.adicionar_contato(contato("Bob", "9999999", "bob@example.com"));
    minha_agenda.adicionar_contato(contato("Oscar", "9382839", "oscar@aa.com"));

    minha_agenda.listar_contatos();

    cout << "\nRemovendo Bob..." << endl;

    cout << endl;

    minha_agenda.remover_contato("Bob");
    minha_agenda.listar_contatos();

    return 0;
}