#include <iostream>
#include <string>


using std::cout, std::endl, std::string;

class excecao_conta{
    string msg;
public:
    excecao_conta(const string& s){
        msg =  s;
    }
    string get_msg(){ return msg; }
    virtual void print_info()=0;
};

class excecao_saldo : public excecao_conta{
    float excedente;
public:
    excecao_saldo(const string& s, float v) : excecao_conta(s), excedente(v){ }

    void print_info(){
        cout << "Exceção! Saldo insuficiente!" << endl;
        cout << "MSG: " << get_msg() << endl;
        cout << "Diferença: " << excedente << endl;
    }
};

class excecao_valor : public excecao_conta{
    int codigo;
public:
    excecao_valor(const string& s, int c) : excecao_conta(s), codigo(c){ }

    void print_info(){
        cout << "Exceção! Valor inválido!" << endl;
        cout << "MSG: " << get_msg() << endl;
        cout << "Código: " << codigo << endl;
    }
};

class conta_corrente{
    int cpf;
    float saldo;
public:
    conta_corrente(int c, float s) : saldo(s) { }
    void sacar(float v){
        if (v < 0)
            throw new excecao_valor("VAL", 1);
        if(v <= saldo)
            saldo -= v;
        else
            throw new excecao_saldo("INS", (saldo - v));
    }
    void depositar(float v){
        if (v < 0)
            throw new excecao_valor("VAL", 2);
        saldo += v;
    }
};


int main(void){

    conta_corrente c1(1234, 15);

    try{
        c1.sacar(15);
        cout << "Saque realizado!" << endl;

        c1.depositar(1000);
        cout << "Depósito realizado!" << endl;

        c1.sacar(10000);
        cout << "Saque realizado!" << endl;

    } catch (excecao_valor* e){
        cout << "Operação com valor inválido! " << endl;
        e->print_info();
    } catch (excecao_saldo* e){
        cout << "Operacao incompativel com o saldo!" << endl;
        e->print_info();
    }
    return 0;
}