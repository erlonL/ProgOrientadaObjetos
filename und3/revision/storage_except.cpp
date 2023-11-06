#include <iostream>
#include <map>

using std::cout, std::endl, std::string, std::map;

class storage_exception{
    string msg;
public:
    storage_exception(const string& s){
        msg =  s;
    }
    string get_msg(){ return msg; }
    virtual void print_info()=0;
};

class quantity_exception : public storage_exception{
    int excedent;
public:
    quantity_exception(const string& m, int q) : storage_exception(m), excedent(q){ }
    int get_excedent(){ return excedent; }
    void print_info(){
        cout << "Exceção! Quantidade excedente!" << endl;
        cout << "MSG: " << get_msg() << endl;
        cout << "Diferença: " << excedent << endl;
    }
};

class not_found_exception : public storage_exception{
    string name;
public:
    not_found_exception(const string& m, const string& n) : storage_exception(m), name(n){ }
    string get_name(){ return name; }
    void print_info(){
        cout << "Exceção! Produto não encontrado!" << endl;
        cout << "MSG: " << get_msg() << endl;
        cout << "Produto: " << name << endl;
    }
};

class invalid_quantity_exception : public storage_exception{
    int quantity;
public:
    invalid_quantity_exception(const string& m, int qty) : storage_exception(m), quantity(qty){ }
    int get_quantity(){ return quantity; }
    void print_info(){
        cout << "Exceção! Quantidade inválida!" << endl;
        cout << "MSG: " << get_msg() << endl;
        cout << "Quantidade: " << quantity << endl;
    }
};


class product{
    string name;
    float price;
public:
    product(const string& n, float p) : name(n), price(p) { }
    string get_name() const{ return name; }
    float get_price() { return price; }

    void set_name(const string& n){ name = n; }
    void set_price(float p){ price = p; }
};

class storage{
    map<product*, int> products;
public:
    storage(){ }
    void add_product(product* p, int q){
        products[p] = q;
    }
    void _remove(product* p, int q){
        if(q < 0)
            throw new invalid_quantity_exception("Quantidade inválida para o produto '" + p->get_name() + "'!", q);

        if(products.find(p) == products.end())
            throw new not_found_exception("Produto '" + p->get_name() + "' não encontrado!", p->get_name());

        if(products[p] < q)
            throw new quantity_exception("Quantidade insuficiente para o produto '" + p->get_name() + "'!", (products[p] - q));

        // deu tudo certo se chegou aqui
        products[p] -= q;
    }
    void remove_product(const string& name, int q){
        product* p = new product(name, 0);
        for(auto product : products){
            if(product.first->get_name() == name)
                p = product.first;
        }
        try{
            _remove(p, q);
            cout << "Remoção de produto: " << name << endl;
            cout << "Quantidade: " << q << endl;
        }catch(storage_exception* e){
            e->print_info();
            // throw e;
        }
    }
    void list_products(){
        double sum = 0;
        cout << "**LISTAGEM DE PRODUTOS**" << endl;
        for(auto product : products){
            cout << "Produto: " << product.first->get_name() << endl;
            cout << "Quantidade: " << product.second << endl;
            cout << "Preço unitário: " << product.first->get_price() << endl;
            cout << "Valor total: " << (product.first->get_price() * product.second) << endl;
            cout << endl;
            sum += (product.first->get_price() * product.second);
        }
        cout << "Valor total do estoque: R$" << sum << endl;
    }
};

int main(void){
    storage s;
    product p1("Garrafa", 5.50);
    product p2("Caneta", 1.50);
    product p3("Camaro Amarelo", 550000.99);
    product p4("Arroz", 10.00);

    s.add_product(&p1, 10);
    s.add_product(&p2, 20);
    s.add_product(&p3, 1);
    s.add_product(&p4, 100);

    s.remove_product("Garrafa", 9);

    cout << endl;

    s.remove_product("Caneta", -1);

    cout << endl;

    s.remove_product("Camaro Azul", 1);

    cout << endl;
    
    s.remove_product("Arroz", 100);

    cout << endl;

    s.list_products();

    return 0;
}