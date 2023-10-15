#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>

#define TAM_NOME 40
#define TAM_TITULO 100
#define TAM_DATA 9
#define MAX_LIVROS 100

using std::cin;
using std::cout;
using std::endl;

// using namespace std;

class autor {
	char nome[TAM_NOME];
	int idade;
	char nacionalidade[2];
public:
	autor(const char* no, int i, const char* na) { 
		strcpy(nome, no); 
		idade = i; 
		strcpy(nacionalidade, na);
	}
	// GETS
	char* get_nome() { return nome; }
	int get_idade() { return idade; }
	char* get_nacionalidade() { return nacionalidade; }
	// SETS
	void set_nome(char* no) { strcpy(nome, no); }
	void set_idade(int i) { idade = i; }
	void set_nacionalidade(char* na) { strcpy(nacionalidade, na); }
	
	void print_info() {
                cout << "Nome: " << get_nome() << endl;
                cout << "Idade: " << get_idade() << endl;
                cout << "Nacionalidade: " << get_nacionalidade() << endl;		
	}
};

class livro {
	char titulo[TAM_TITULO];
	int ano_lancamento;
	int isbn;
	autor** autores;
	int qtd_autores;
public:
	livro(const char* t, int al, int is, autor** au, int qtd_au) {
		strcpy(titulo, t);
		ano_lancamento = al;
		isbn = is;
		autores = au;
		qtd_autores = qtd_au;
	}
	// GETS
	char* get_titulo() { return titulo; }
	int get_ano_lancamento() { return ano_lancamento; }
	int get_isbn() { return isbn; }
	int get_qtd_autores() { return qtd_autores; }
	autor** get_autores() { return autores; }
	
	// SETS
	void set_titulo(char* t) { strcpy(titulo, t); }
	void set_ano_lancamento(int al) { ano_lancamento = al; }
	void set_isbn(int i) { isbn = i;}
	void set_autores(autor** au, int qtd_au) { autores = au; qtd_autores = qtd_au; }
	
	void print_info() {
		cout << "Titulo: " << titulo << endl;
		cout << "Ano lancamento: " << ano_lancamento << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "Autores: " << endl;
		for (int i = 0; i < qtd_autores; i++) {
			autores[i]->print_info();
		}
	}

};

class leitor {
	char nome[TAM_NOME];
	int idade;
	char cpf[16];
public:
	leitor(const char* n, int i, const char* c) {
		strcpy(nome, n);
		idade = i;
		strcpy(cpf, c);
	}
	// GETS
	char* get_nome() { return nome; }
	int get_idade() { return idade; }
	char* get_cpf() { return cpf; }
	
	// SETS
	void set_nome(char* n) { strcpy(nome, n); }
	void set_idade(int i) { idade = i; }
	void set_cpf(char* c) { strcpy(cpf, c); }
	
	void print_info() {
                cout << "Nome: " << get_nome() << endl;
                cout << "Idade: " << get_idade() << endl;
		cout << "Cpf: " << get_cpf() << endl;
	}
};

class emprestimo {
	char data_inicio[TAM_DATA];
	char data_fim[TAM_DATA];
	livro** livros;
	int qtd_livros;
	leitor* cliente;
public:
	emprestimo(const char* di, const char* df, livro** ls, int qtdl, leitor* c) {
		strcpy(data_inicio, di);
		strcpy(data_fim, df);
		livros = ls;
		qtd_livros = qtdl;
		cliente = c;
	}

	void print_info() {
		cout << "Data inicio: " << data_inicio << endl;
		cout << "Data fim: " << data_fim << endl;
		cout << "Livros: " << endl;
		for (int i = 0; i < qtd_livros; i++) {
			livros[i]->print_info();
		}
		cout << "Cliente: " << endl;
		cliente->print_info();
	}
};

class copia_acervo{
	livro* copia;
	int copias_disponiveis;
	int copias_emprestadas;
public:
	copia_acervo(livro* l, int cd = 0, int ce = 0){
		copias_disponiveis = cd;
		copias_emprestadas = ce;
		copia = l;
	}
	// gets
	livro* get_livro(){ return copia; }
	int get_copias_disponiveis(){ return copias_disponiveis; }
	int get_copias_emprestadas(){ return copias_emprestadas; }
	
	// sets
	void set_livro(livro* l){ copia = l; }
	void set_copias_disponiveis(int cd){ copias_disponiveis = cd; }
	void set_copias_emprestadas(int ce){ copias_emprestadas = ce; }
	
	void print_info(){
		cout << "Copias disponiveis: " << get_copias_disponiveis() << endl;
		cout << "Copias emprestadas: " << get_copias_emprestadas() << endl;
		livro->print_info();
	}

};

class acervo {
	vector<copia_acervo*> estoque;
	vector<emprestimo*> emprestimos;

	void add_emprestimo(emprestimo* e) {
		emprestimos.push_back(e);
	}
	void remove_emprestimo(int i) {
		emprestimos.erase(emprestimos.begin() + i);
	}
	emprestimo* get_emprestimo(int i) {
		return emprestimos[i];
	}

public:
	acervo(){
		estoque.reserve(MAX_LIVROS);
	}
	void add_livro(copia_acervo* ca) {
		estoque.push_back(ca);
	}
	void remove_livro(int i) {
		estoque.erase(estoque.begin() + i);
	}
	copia_acervo* get_livro(int i) {
		return estoque[i];
	}
	int get_qtd_livros() {
		return estoque.size();
	}
	void print_info() {
		cout << "Acervo: " << endl;
		cout << "Quantidade de livros: " << get_qtd_livros() << endl;
		for (int i = 0; i < estoque.size(); i++) {
			estoque[i]->print_info();
		}
		cout << "Emprestimos: " << endl;
		for (int i = 0; i < emprestimos.size(); i++) {
			emprestimos[i]->print_info();
		}
	}

	int emprestar(copia_acervo** ca, leitor* l, const char* di, const char* df) {
		livro** ls = new livro*[1];
		ls[0] = ca->get_livro();

		emprestimo* e = new emprestimo(di, df, ls, 1, l);
		add_emprestimo(e);
		ca->set_copias_disponiveis(ca->get_copias_disponiveis() - 1);
		ca->set_copias_emprestadas(ca->get_copias_emprestadas() + 1);
		return emprestimos.size() - 1;
	}

	void devolver(int i) {
		remove_emprestimo(i);
		ca->set_copias_disponiveis(ca->get_copias_disponiveis() + 1);
		ca->set_copias_emprestadas(ca->get_copias_emprestadas() - 1);
	}

};

int main(void) {
	/*
		Exercicio:
		Solicitar dados do usuario para que seja
		criado um emprestimo de dois livros; cada
		livro devera ter dois autores distintos;
		o emprestimo devera conter tambem o leitor;
	*/
	autor* a1 = new autor("Autor 1", 20, "BR");
	autor* a2 = new autor("Autor 2", 30, "BR");
	
	autor* a3 = new autor("Autor 3", 40, "BR");
	autor* a4 = new autor("Autor 4", 50, "BR");

	autor* au1[2] = {a1, a2};
	autor* au2[2] = {a3, a4};

	livro* l1 = new livro("Livro A", 2000, 123, au1, 2);
	livro* l2 = new livro("Livro B", 2001, 456, au2, 2);

	livro* ls[2] = {l1, l2};


	copia_acervo* ca1 = new copia_acervo(l1, 1, 0);
	copia_acervo* ca2 = new copia_acervo(l2, 1, 0);

	acervo* ac1 = new acervo();
	ac1->add_livro(ca1);
	ac1->add_livro(ca2);

	leitor* l = new leitor("Leitor 1", 20, "12345678910");

	ac1->print_info();

	char c;
	cout << "Pressione enter para continuar..." << endl;
	cin >> c;

	cout << "Emprestimo realizado: " << endl;
	
	int my_loan = ac1->emprestar(ca1, l, "01/01/2020", "01/02/2020");

	ac1->print_info();
	
	cout << "Pressione enter para continuar..." << endl;
	cin >> c;

	cout << "Devolucao realizada: " << endl;

	ac1->devolver(my_loan);

	ac1->print_info();




	return 0;
}
