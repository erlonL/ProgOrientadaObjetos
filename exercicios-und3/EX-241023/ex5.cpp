#include <iostream>
#include <map>

using std::map, std::cout, std::endl, std::string, std::multimap, std::pair;

class Autor{
    string nome;
    int ano_nasc;
public:
    Autor(string n, int an) : nome(n), ano_nasc(an) { }
    string get_nome() const { return nome; }
    int get_ano_nasc() const { return ano_nasc; }

    void print_info() const{
        cout << "** INFORMAÇÕES DE AUTOR **" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Ano de nascimento: " << ano_nasc << endl;
    }
};

class Livro{
    string titulo;
    Autor* autor;
    int ano;
public:
    Livro(string t, Autor* a, int y) : titulo(t), autor(a), ano(y) { }
    string get_titulo() { return titulo; }
    Autor* get_autor() { return autor; }
    int get_ano() { return ano; }

    void print_info() const{
        cout << "** INFORMAÇÕES DE LIVRO **" << endl;
        cout << "Título: " << titulo << endl;
        cout << "Autor: " << autor->get_nome() << endl;
        cout << "Ano: " << ano << endl;
    }
};

class Biblioteca{
    map<string, multimap<Autor*, Livro>> biblioteca; // map<titulo, multimap<autor, livro>>
public:
    Biblioteca() { }
    void addLivro(Livro l){
        biblioteca[l.get_titulo()].insert(pair<Autor*, Livro>(l.get_autor(), l));
    }

    void printLivros() const{
        for(auto it = biblioteca.begin(); it != biblioteca.end(); it++){
            // cout << "Título: " << it->first << endl;
            for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
                it2->second.print_info();
                it2->first->print_info();
            }
            cout << endl;
        }
    }
};

int main(void){
    Autor a1("Isaac Asimov", 1990);
    Autor a2("Edgar Allan Poe", 1991);

    Livro l1("Eu, Robô", &a1, 2000);
    Livro l2("Contos Extraordinários", &a2, 2001);

    Biblioteca b1;

    b1.addLivro(l1);
    b1.addLivro(l2);

    b1.printLivros();
    return 0;
}