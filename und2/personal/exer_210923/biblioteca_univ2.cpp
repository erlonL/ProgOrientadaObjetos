#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cout, std::cin, std::endl, std::string, std::vector, std::ostream, std::map;

class usuario{ /*abstrata*/
    int idade;
    string nome;
public:
    usuario(int i, string n) : idade(i), nome(n) {
        // cout << "Usuario criado" << endl;
    }
    usuario(){
        idade = 0;
        nome = "";
    }
    // G & S
    int get_idade() const { return idade; }
    string get_nome() const { return nome; }
    void set_idade(int i) { idade = i; }
    void set_nome(string n) { nome = n; }

    virtual void exibir() = 0;
    friend ostream& operator<<(ostream& os, const usuario &u){
        os << "Informações do usuario: " << endl;
        os << "Nome: " << u.nome << endl;
        os << "Idade: " << u.idade << endl;
        return os;
    }
    virtual void tipo_usuario(){
        cout << "Usuario" << endl; 
    }
};

class estudante : public usuario{
    int mat;
    int curso;
public:
    estudante(int i, string n, int m, int c) : usuario(i, n), mat(m), curso(c) {
        // cout << "Estudante criado" << endl;
    }
    estudante() : usuario() {
        mat = 0;
        curso = 0;
    }
    // G & S
    int get_mat() const { return mat; }
    int get_curso() const { return curso; }
    void set_mat(int m) { mat = m; }
    void set_curso(int c) { curso = c; }
    
    void exibir(){
        cout << "Informações do estudante: " << endl;
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Matricula: " << mat << endl;
        cout << "Curso: " << curso << endl;
    }
    friend ostream& operator<<(ostream& os, const estudante &e){
        os << "Informações do estudante: " << endl;
        os << "Nome: " << e.get_nome() << endl;
        os << "Idade: " << e.get_idade() << endl;
        os << "Matricula: " << e.mat << endl;
        os << "Curso: " << e.curso << endl;
        return os;
    }
    void tipo_usuario(){
        cout << "Estudante" << endl;
    }
};

class professor : public usuario{
    int dep;
public:
    professor(int i, string n, int d) : usuario(i, n), dep(d) {
        // cout << "Professor criado" << endl;
    }
    professor() : usuario() {
        dep = 0;
    }
    // G & S
    int get_dep() const { return dep; }
    void set_dep(int d) { dep = d; }
    
    void exibir(){
        cout << "Informações do professor: " << endl;
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Departamento: " << dep << endl;
    }
    friend ostream& operator<<(ostream& os, const professor &p){
        os << "Informações do professor: " << endl;
        os << "Nome: " << p.get_nome() << endl;
        os << "Idade: " << p.get_idade() << endl;
        os << "Departamento: " << p.dep << endl;
        return os;
    }
    void tipo_usuario(){
        cout << "Professor" << endl;
    }
};

class material { /*abstrata*/
    string titulo;
public:
    material(string t) : titulo(t) {
        // cout << "Material criado" << endl;
    }
    material(){
        titulo = "";
    }
    // G & S
    string get_titulo() const { return titulo; }
    void set_titulo(string t) { titulo = t; }

    virtual void exibir() = 0;
    friend ostream& operator<<(ostream& os, const material &m){
        os << "Titulo: " << m.titulo << endl;
        return os;
    }
};

class livro : public material{
    string autor;
    int ano;
public:
    livro(string t, string a, int an) : material(t), autor(a), ano(an) {
        // cout << "Livro criado" << endl;
    }
    livro() : material() {
        autor = "";
        ano = 0;
    }
    // G & S
    string get_autor() const { return autor; }
    int get_ano() const { return ano; }
    void set_autor(string a) { autor = a; }
    void set_ano(int an) { ano = an; }

    void exibir(){
        cout << "Informações do livro: " << endl;
        cout << "Titulo: " << get_titulo() << endl;
        cout << "Autor: " << autor << endl;
        cout << "Ano: " << ano << endl;
    }
    friend ostream& operator<<(ostream& os, const livro &l){
        os << "Informações do livro: " << endl;
        os << "Titulo: " << l.get_titulo() << endl;
        os << "Autor: " << l.autor << endl;
        os << "Ano: " << l.ano << endl;
        return os;
    }
};

class revista : public material{
    int edicao;
public:
    revista(string t, int e) : material(t), edicao(e) {
        // cout << "Revista criada" << endl;/
    }
    revista() : material() {
        edicao = 0;
    }
    // G & S
    int get_edicao() const { return edicao; }
    void set_edicao(int e) { edicao = e; }

    void exibir(){
        cout << "Informações da revista: " << endl;
        cout << "Titulo: " << get_titulo() << endl;
        cout << "Edicao: " << edicao << endl;
    }
    friend ostream& operator<<(ostream& os, const revista &r){
        os << "Informações da revista: " << endl;
        os << "Titulo: " << r.get_titulo() << endl;
        os << "Edicao: " << r.edicao << endl;
        return os;
    }
};


class emprestimo{
    usuario* user;
    material* mat;
    int qtd_m;
    string data;
public:
    emprestimo(usuario* u, material* m, string d, int qm) : user(u), mat(m), data(d), qtd_m(qm) {
        // cout << "Emprestimo criado" << endl;
    }
    emprestimo(){
        user = nullptr;
        mat = nullptr;
        data = "";
        qtd_m = 0;
    }
    // G & S
    usuario* get_user() const { return user; }
    material* get_mat() const { return mat; }
    string get_data() const { return data; }
    int get_qtd_m() const { return qtd_m; }
    void set_user(usuario* u) { user = u; }
    void set_mat(material* m) { mat = m; }
    void set_data(string d) { data = d; }
    void set_qtd_m(int qm) { qtd_m = qm; } 

    void exibir(){
        cout << "Informações do emprestimo: " << endl;
        cout << "Usuario: " << user->get_nome() << endl;
        cout << "Material: " << mat->get_titulo() << endl;
        cout << "Quantidade: " << qtd_m << endl;
        cout << "Data: " << data << endl;
    }
    emprestimo& operator+(const emprestimo& outro){
        if(user == outro.user && mat == outro.mat){
            qtd_m += outro.qtd_m;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const emprestimo &e){
        os << "Informações do emprestimo: " << endl;
        os << "Usuario: " << e.user->get_nome() << endl;
        os << "Material: " << e.mat->get_titulo() << endl;
        os << "Quantidade: " << e.qtd_m << endl;
        os << "Data: " << e.data << endl;
        return os;
    }
};

class biblioteca{
    vector<usuario*> users;
    vector<material*> materials;
    vector<emprestimo*> emprestimos;
public:
    biblioteca(){
        users = {};
        materials = {};
        emprestimos = {};
    }

    void add_user(usuario* u){
        users.push_back(u);
    }
    void add_material(material* m){
        materials.push_back(m);
    }
    void listar_users(){
        for(auto u : users){
            cout << *u << endl;
        }
    }
    void listar_materials(){
        for(auto m : materials){
            cout << *m << endl;
        }
    }
    void emprestar_material(usuario* u, material* m, string d, int qm){
        emprestimo* emp = new emprestimo(u, m, d, qm);
        emprestimos.push_back(emp);
    }
    void devolver_material(usuario* u, material* m){
        for(auto it = emprestimos.begin(); it != emprestimos.end(); it++){
            if((*it)->get_user() == u && (*it)->get_mat() == m){
                emprestimos.erase(it);
                break;
            }
        }
    }
    void listar_emprestimos(){
        for(auto emp : emprestimos){
            cout << *emp << endl;
        }
    }
    void desalocar_recursos(){
        for(auto u : users){
            delete u;
        }
        for(auto m : materials){
            delete m;
        }
        for(auto emp : emprestimos){
            delete emp;
        }
    }
};

int main(void){

    biblioteca* biblio = new biblioteca();

    usuario* usr1 = new estudante(20, "Joao", 123, 1);
    usuario* usr2 = new professor(30, "Maria", 1);

    material* mat1 = new livro("Livro 1", "Autor 1", 2000);
    material* mat2 = new livro("Livro 2", "Autor 2", 2001);
    material* mat3 = new revista("Revista 1", 1);
    material* mat4 = new revista("Revista 2", 2);

    biblio->add_user(usr1);
    biblio->add_user(usr2);

    // biblio->exibir_users();
    biblio->add_material(mat1);
    biblio->add_material(mat2);
    biblio->add_material(mat3);
    biblio->add_material(mat4);

    biblio->emprestar_material(usr1, mat1, "23/09/2021", 1569);
    biblio->emprestar_material(usr2, mat2, "23/09/2021", 15);

    biblio->listar_users();
    biblio->listar_materials();
    biblio->listar_emprestimos();

    biblio->devolver_material(usr1, mat1);
    biblio->devolver_material(usr2, mat2);

    biblio->listar_emprestimos();

    biblio->desalocar_recursos();

    return 0;
}