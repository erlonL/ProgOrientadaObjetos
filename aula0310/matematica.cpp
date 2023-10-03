#include <iostream>

using std::cout, std::cin, std::endl, std::string;

class matematica{
public:
    static double soma(double a, double b){
        return a + b;
    }
    static double subtracao(double a, double b){
        return a - b;
    }
    static double multiplicacao(double a, double b){
        return a * b;
    }
    static double divisao(double a, double b){
        if(b != 0){
            return a / b;
        }else {
            throw std::invalid_argument("Division by zero");
        }
    }
};


int main(void){
    float a, b, c;
    char op;

    input_values:
    cout << "Digite o valor de a: ";
    cin >> a;
    cout << "Digite o valor de b: ";
    cin >> b;
    cout << "Digite a operação: ";
    cin >> op;

    switch (op){
        case '+':{
            c = matematica::soma(a,b);
            break;
        }
        case '-':{
            c = matematica::subtracao(a,b);
            break;
        }
        case '*':{
            c = matematica::multiplicacao(a,b);
            break;
        }
        case '/':{
            try{
                c = matematica::divisao(a,b);
                break;
            }catch(std::invalid_argument e){
                // cout << e << endl;
                goto input_values;
            }
        }
        default:{
            cout << "Operação inválida!" << endl;
            goto input_values;
        }
    }

    cout << "Resultado: " << c << endl;

    return 0;
}