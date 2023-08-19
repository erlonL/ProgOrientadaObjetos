#include <iostream>
#include <cstring>

#define TAM_NOME 40
#define TAM_DATA 9
#define TAM_CPF 11

using std::cout, std::cin, std::endl;

// Sistema de farmácia

class produto{
    char nome[TAM_NOME];
    float preco;
    int qtd_estoque;
public:
    produto(const char* n, float p, int q){
        strcpy(nome, n);
        preco = p;
        qtd_estoque = q;
    }
    produto(){}
    // gets, sets e print_info()
    float get_preco(){ return preco; }
    int get_qtd(){ return qtd_estoque; }
};

class cliente{
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
public:
    cliente(const char* n, const char* c){
        strcpy(nome, n);
        strcpy(cpf, c);
    }
    // gets, sets e print_info()
};

class venda{
    cliente *c;
    produto *ps; /*produto **ps ?? (Array de referências)*/
    int qtd_produtos;
    char data[TAM_DATA];
public:
    venda(cliente *cc, produto *pp, int q, const char* d){
        c = cc;
        ps = pp;
        qtd_produtos = q;
        strcpy(data, d);
    }
    // gets, sets e print_info()
};

class estoque{
    produto **ps;
    int qtd;
public:
    estoque(produto **pp, int q){
        ps = pp;
        qtd = q;
    }
    // produto** get_produto(int idx){
    //     return ps[idx];
    // }
    // add / remove
};

class produtoVenda{
    produto *p;
    int qtd_venda;
    int valido;
public:
    produtoVenda(produto* pp, int q){
        p = pp;
        qtd_venda = q;

        int qtd_estoque = p->get_qtd();

        if(qtd_estoque >= qtd_venda){
            valido = 1;
        }else{
            valido = 0;
        }
    }
    int get_valido(){ return valido; }
    int get_qtd(){ return qtd_venda; }
    produto* get_produto(){ return p; }
};


int main(void){
    cliente c1("XYZ", "1011");

    produto p1("AS", 5.50, 10); // ATS
    produto p2("ZW", 10.20, 50);

    produto* pr[2];

    pr[0] = &p1;
    pr[1] = &p2;

    estoque e1(pr, 2);

    produtoVenda pv(/*e1.get_produto(0)*/pr[0], 2);

    // cout << (pv.get_valido()) << endl;

    if(pv.get_valido()){
        produto* produto_venda = pv.get_produto();
        float preco_total = produto_venda->get_preco() * pv.get_qtd();
        cout << "Preço total da compra:\n" << preco_total << "R$" << endl;
        
        cout << "Deseja Confirmar a compra? (S/n)\n>>" << endl;
        char confirm;
        cin >> confirm;

        switch(confirm){
            case('s'):{
                cout << "Confirmando compra..." << endl;
                // Remover a quantidade do estoque
                // Adicionar lucros do dia
                break;
            }
            case('n'):{
                cout << "Compra negada..." << endl;
                // Voltar para o menu e perguntar se o cliente
                // gostaria de trocar os produtos
                break;
            }
            default:{
                cout << "Por favor, tente novamente." << endl;
                break;
            }
        }


    }

    // delete[] pr;

    return 0;
}