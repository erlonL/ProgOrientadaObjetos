#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl, std::vector, std::string;


int main(void){
    vector<int> numeros;
    vector<string> palavras;

    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);
    numeros.push_back(40);
    // aprenderemos depois sobre iteradores
    // numeros.insert(numeros.begin(), 20);

    if(numeros.empty()){
        cout << "vector de numeros esta vazio!" << endl;
    } else {
        cout << "vector de numeros nao esta vazio!" << endl;
    }

    for(int num : numeros){
        cout << num << " ";
    }
    cout << endl;

    palavras.push_back("abacate");
    palavras.push_back("laranja");
    palavras.push_back("abacaxi");

    for(const string palavra : palavras){
        cout << palavra << " ";
    }

    cout << endl;

    if(palavras.empty()){
        cout << "vector de palavras esta vazio!" << endl;
    } else {
        cout << "vector de palavras nao esta vazio!" << endl;
    }

    return 0;
}