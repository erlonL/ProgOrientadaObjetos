#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::ostream;

class coisa{
    int atributo;
public:
    coisa(int a = 0) { atributo = a; }
    int get_atributo() { return atributo; }

    void set_atributo(int a){ atributo = a; }

    friend ostream& operator<<(ostream& out, const coisa& c){
        out << "coisa(" << c.atributo << ")";
        return out;
    }
    friend bool operator<(const coisa& a, const coisa& b){
        return ((a.atributo) < (b.atributo));
    }
};

int main(void){
    vector<int> numeros = {3, 1, 4, 2, 5, 9, 7, 11, 14, 21, 12, 0 };
    vector<coisa> coisas;

    coisa a(10), b(20), c(30);

    coisas.push_back(c);
    coisas.push_back(b);
    coisas.push_back(a);
    coisas.push_back(b);

    std::sort(numeros.begin(), numeros.end());

    for(int num : numeros){
        cout << num << " ";
    }
    cout << endl;

    std::sort(coisas.begin(), coisas.end());

    for(auto c : coisas){
        cout << c << " ";
    }

    return 0;
}