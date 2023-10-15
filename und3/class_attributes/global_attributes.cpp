#include <iostream>
#include <string>

using std::cout, std::endl, std::string;
/*Podemos ter atributos globais que serão inerentes a todas as classes,
podendo, inclusive, serem modificados por essas classes.
Ex.: Se gostariamos de contar quantas pessoas, mesmo com várias
subclasses de pessoas existentes, podemos ter um atributo global
`count` que fará isso.*/

int count = 0;

class pessoa{
    string nome;
    int idade;
public:
    pessoa(string n, int i) : nome(n), idade(i) { count++; }
    ~pessoa() { count--; }
    /* Funciona, mas não é uma boa prática para o estudo
    de POO. Atributos globais devem ser evitados.*/
};

