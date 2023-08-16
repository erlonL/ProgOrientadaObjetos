#include <iostream>

#define MAX_NOME 100
#define MAX_DATA 10
#define MAX_NACIONALIDADE 50
#define MAX_LIVROS 3
#define MAX_GENERO 30

using namespace std;

class Pessoa{
    char nome[MAX_NOME];
    char data_de_nascimento[MAX_DATA];
public:
    Pessoa(){}
    Pessoa(const char* n, const char* dn){
        strcpy(nome, n);
        strcpy(data_de_nascimento, dn);
    }
    void setNome(const char* n){ nome = n; }
    void setDataNascimento(const char* dn){ data_de_nascimento = dn; }
};


class Autor : public Pessoa{
    char nacionalidade[MAX_NACIONALIDADE];
    int numLivros = 0;
    Livro* livros[MAX_LIVROS];
public:
    Autor(){}
    Autor(const char* n, const char* dn, const char* nc){
        strcpy(nome, n);
        strcpy(data_de_nascimento, dn);
        strcpy(nacionalidade, nc);
    }
    void setLivros(Livro* ll[], int nL){
        if(nL > MAX_LIVROS){
            cout << "Erro! Número de livros excede o limite." << endl;
            return;
        }

        for(int i = 0 ; i < nL; i++){
            livros[i] = ll[i];
        }
        numLivros = nL;
    }
};

class Livro{
    Autor* autor;
    char titulo[MAX_NOME];
    char lancamento[MAX_DATA];
    char editora[MAX_NOME];
    char generos[MAX_GENERO][3];
public:
    Livro(){}
    Livro(const char* t, const char* a, const char* l, const char* e, const char* gs[3]){
        strcpy(titulo, t);
        strcpy(autor, a);
        strcpy(lancamento, l);
        strcpy(editora, e);
        for(int i = 0; i < 3; i++)
            strcpy(generos[i], gs[i]);
    }

};

class Leitor : public Pessoa{};

class Emprestimo{};

class Acervo{};

// Sistema de Gerenciamento de Biblioteca
int main(){

    return 0;

}