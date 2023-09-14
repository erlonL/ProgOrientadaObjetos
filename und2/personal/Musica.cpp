// Musica.cpp

#include "Musica.hpp"

#include <iostream>
#include <string>

using std::string;


Musica::Musica(const string& t, const string& a){
    titulo = t;
    artista = a;
}
string Musica::get_titulo() const{
    return titulo;
}
string Musica::get_artista() const{
    return artista;
}