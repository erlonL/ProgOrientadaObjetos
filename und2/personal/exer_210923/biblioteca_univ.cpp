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
    usuario** users;
    int qtd_users;
    material** materials;
    int qtd_materials;
    emprestimo** emprestimos;
    int qtd_emprestimos;
public:
    biblioteca(){
        qtd_users = 0;
        qtd_materials = 0;
        qtd_emprestimos = 0;
        users = nullptr;
        materials = nullptr;
        emprestimos = nullptr;
    }
    // G & S
    usuario** get_users() const { return users; }
    int get_qtd_users() const { return qtd_users; }
    material** get_materials() const { return materials; }
    int get_qtd_materials() const { return qtd_materials; }
    emprestimo** get_emprestimos() const { return emprestimos; }
    int get_qtd_emprestimos() const { return qtd_emprestimos; }
    void set_users(usuario** u) { users = u; }
    void set_qtd_users(int q) { qtd_users = q; }
    void set_materials(material** m) { materials = m; }
    void set_qtd_materials(int q) { qtd_materials = q; }
    void set_emprestimos(emprestimo** e) { emprestimos = e; }
    void set_qtd_emprestimos(int q) { qtd_emprestimos = q; }

    void add_user(usuario* u){
        usuario** n_users = new usuario*[qtd_users + 1];
        int i;
        for(i = 0; i < qtd_users; i++){
            n_users[i] = users[i];
        }
        n_users[i] = u;
        delete[] users;
        users = n_users;
        qtd_users++;
        // cout << "Usuario adicionado na biblioteca" << endl;
    }
    void add_material(material* m){
        material** n_materials = new material*[qtd_materials + 1];
        int i;
        for(i = 0; i < qtd_materials; i++){
            n_materials[i] = materials[i];
        }
        n_materials[i] = m;
        delete[] materials;
        materials = n_materials;
        qtd_materials++;
        // cout << "Material adicionado na biblioteca" << endl; 
    }
    void exibir_users(){
        for(int i = 0; i < qtd_users; i++){
            cout << *users[i] << endl;
        }
    }
    void exibir_materials(){
        for(int i = 0; i < qtd_materials; i++){
            cout << *materials[i] << endl;
        }
    }
    void emprestar_material(usuario* usr, material* mat, const string& data, int qtd){
        emprestimo** n_emprestimos = new emprestimo*[qtd_emprestimos + 1];
        int i;
        for(i = 0; i < qtd_emprestimos; i++){
            n_emprestimos[i] = emprestimos[i];
        }
        n_emprestimos[i] = new emprestimo(usr, mat, data, qtd);
        delete[] emprestimos;
        emprestimos = n_emprestimos;
        qtd_emprestimos++;
    }
    void devolver_material(usuario* usr, material* mat){
        for(int i = 0; i < sizeof(users)/sizeof(usuario*); i++){
            if(emprestimos[i]->get_user() == usr && emprestimos[i]->get_mat() == mat){
                emprestimos[i]->set_qtd_m(emprestimos[i]->get_qtd_m() - 1);
                if(emprestimos[i]->get_qtd_m() == 0){
                    emprestimo** n_emprestimos = new emprestimo*[sizeof(emprestimos)/sizeof(emprestimo*) - 1];
                    int j;
                    for(j = 0; j < sizeof(emprestimos)/sizeof(emprestimo*); j++){
                        if(j != i){
                            n_emprestimos[j] = emprestimos[j];
                        }
                    }
                    delete[] emprestimos;
                    emprestimos = n_emprestimos;
                }
            }
        }
    }
    void exibir_emprestimos(){
        for(int i = 0; i < qtd_emprestimos; i++){
            cout << *emprestimos[i] << endl;
        }
    }
    void desalocar_recursos(){
        delete[] users;
        delete[] materials;
        delete[] emprestimos;
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

    biblio->exibir_users();
    biblio->exibir_materials();
    biblio->exibir_emprestimos();

    biblio->devolver_material(usr1, mat1);
    biblio->devolver_material(usr2, mat2);

    biblio->exibir_emprestimos();

    biblio->desalocar_recursos();

    return 0;
}