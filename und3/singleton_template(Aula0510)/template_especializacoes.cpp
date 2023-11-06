#include <iostream>
// #include <cstring>
#include <string.h>

using std::cout;
using std::endl;


template <typename T>
T max(T a, T b){
    // A é maior que b? Se sim retorne a, se não retorne b
    return (a > b) ? a : b;
    // Não serve para char*
}


template <> // Indica que terá uma especialização
const char* max(const char* a, const char* b){
    return (strcmp(a, b) > 0) ? a : b;
}

int main(void){
    int res_max_int = max(100,99);

    double res_max_double = max(0.7374, 9.2345);

    const char* res_max_str = max("ABACAXI", "BATATA");

    cout << "Maior inteiro: " << res_max_int << endl;
    cout << "Maior double: " << res_max_double << endl;
    cout << "Maior string: " << res_max_str << endl;

    return 0;
}