#include <iostream>

using std::cout, std::endl;

class calculadora{
public:
    int operator()(int x, int y, char op){
        switch(op){
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':{
                if(y!=0){
                    return x/y;
                }else{
                    cout << "divisão por zero" << endl;
                    return 0;
                }
            }
            default:{
                cout << "operador inválido" << endl;
                return 0;
            }
        }
    }
};

int main(void){

    calculadora calc;

    int result1 = calc(5, 3, '+');
    int result2 = calc(30, 20, '-');
    int result3 = calc(10, 2, '*');
    int result4 = calc(10, 0, '/');

    cout << "result1: " << result1 << endl;
    cout << "result2: " << result2 << endl;
    cout << "result3: " << result3 << endl;
    cout << "result4: " << result4 << endl;


    return 0;
}