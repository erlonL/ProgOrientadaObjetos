#include <iostream>
#include <cstring>

#define TAM_MAX_NOME 100
#define TAM_TITULO 100
#define TAM_DATA 8
#define MAX_LIVROS 100

using std::cin;
using std::cout;
using std::endl;

// using namespace std;

class Autor {
    char nome[TAM_MAX_NOME];
    int idade;
    char nacionalidade[2];
public:
    Autor(const char* no, int i, const char* na){
        strcpy(nome, no);
        idade = i;
        strcpy(nacionalidade, na);
    }
    // Gets e Sets
    char* get_nome() { return nome; }
    int get_idade() { return idade; }
    char* get_na() { return nacionalidade; }
    void set_nome(char* n) { strcpy(nome, n); }
    void set_idade(int i) { idade = i; }
    void set_nac(char* na) { strcpy(nacionalidade, na); }
};

class Livro {
    char titulo[TAM_TITULO];
    int ano_lancamento;
    int ISBN;
    Autor* autores;
    int qtd_autores;
public:
    livro(const char* t, int al, int is, Autor* au, int qtd_au){
        strcpy(titulo, t);
        ano_lancamento = al;
        ISBN = is;
        autores** = au;
        qtd_autores = qtd_au;
    }
};

class Emprestimo {
    char data_inicio[TAM_DATA];
    char data_fim[TAM_DATA];
    livro* livros;
    int qtd_livros;
    leitor* cliente;

};

class Acervo {
    livro* estoque[MAX_LIVROS];
    int copias_disponiveis[MAX_LIVROS];
    int copias_emprestadas[MAX_LIVROS];
};

class Leitor{
    char nome[TAM_MAX_NOME];
    int CPF;
public:
    Leitor(const char* n, int c){
        strcpy(nome, n);
        CPF = c;
    }
    void print_info(){
        cout << nome << endl;
        cout << CPF << endl;
    }
};

int main(){

    Leitor* jose = new Leitor("José", 125552344);
    jose->print_info();

    


    return 0;
}