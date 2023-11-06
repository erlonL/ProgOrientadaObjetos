#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::string;

int main(void){
    vector<int> numeros = {1,2,3,4,5,6,7,8,9,0};

    auto itera = std::find(numeros.begin(), numeros.end(), 9);

    if(itera != numeros.end()){
        cout << "Valor encontrado: " << *itera << endl;
    }else{
        cout << "Valor não encontrado!" << endl;
    }

    return 0;
}