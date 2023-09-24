// Musica.hpp

#ifndef MUSICA_HPP
#define MUSICA_HPP

#include <iostream>
#include <string>

using std::string;

class Musica{
    string titulo;
    string artista;
public:
    Musica(const string& t, const string& a){
        titulo = t;
        artista = a;
    }
    string get_titulo() const{
        return titulo;
    }
    string get_artista() const{
        return artista;
    }
    virtual void tocar() = 0; // virtual puro
};

#endif