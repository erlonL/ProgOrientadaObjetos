# Code definitions

For details look source code.

## Classes
```cpp
class product{
    string name;
    float price;
public:
    product(const string& n, float p){ }
    string get_name() const{}
    float get_price() {}
    void set_name(const string& n){}
    void set_price(float p){}
};

class storage{
    map<product*, int> products;
public:
    storage(){ }
    void add_product(product* p, int q){
    }
    void _remove(product* p, int q){
    }
    void remove_product(const string& name, int q){
    }
    void list_products(){
    }
};
```

## Exception Classes
```cpp
class storage_exception{
    string msg;
public:
    storage_exception(const string& s){
        msg =  s;
    }
    string get_msg(){  }
    virtual void print_info()=0;
};

class quantity_exception : public storage_exception{
    int excedent;
public:
    quantity_exception(const string& m, int q){ }
    int get_excedent(){  }
    void print_info(){
    }
};

class not_found_exception : public storage_exception{
    string name;
public:
    not_found_exception(const string& m, const string& n){ }
    string get_name(){  }
    void print_info(){
    }
};

class invalid_quantity_exception : public storage_exception{
    int quantity;
public:
    invalid_quantity_exception(const string& m, int qty){ }
    int get_quantity(){ }
    void print_info(){
    }
};
```


## Main
```cpp
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
```


# Output
```bash
User~/revision$ ./s
Remoção de produto: Garrafa
Quantidade: 9

Exceção! Quantidade inválida!
MSG: Quantidade inválida para o produto 'Caneta'!
Quantidade: -1

Exceção! Produto não encontrado!
MSG: Produto 'Camaro Azul' não encontrado!
Produto: Camaro Azul

Remoção de produto: Arroz
Quantidade: 100

**LISTAGEM DE PRODUTOS**
Produto: Garrafa
Quantidade: 1
Preço unitário: 5.5
Valor total: 5.5

Produto: Caneta
Quantidade: 20
Preço unitário: 1.5
Valor total: 30

Produto: Camaro Amarelo
Quantidade: 1
Preço unitário: 550001
Valor total: 550001

Produto: Arroz
Quantidade: 0
Preço unitário: 10
Valor total: 0

Valor total do estoque: R$550036
```