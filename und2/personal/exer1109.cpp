#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string;

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

class MusicaLocal : public Musica{
    string caminhoArquivo;
public:
    MusicaLocal(const string& t, const string& a, const string& c) : Musica(t, a), 
                                                                    caminhoArquivo(c){}
    virtual void tocar(){
        cout << "Tocando " << get_titulo() << " de " << get_artista() << " de " << caminhoArquivo << endl;
    }
};

class MusicaStreaming : public Musica{
    string url;
public:
    MusicaStreaming(const string& t, const string& a, const string& u) : Musica(t, a), url(u){}
    virtual void tocar(){
        cout << "Tocando " << get_titulo() << " de " << get_artista() << " de " << url << endl;
    }
};

int main(void){

    Musica* playlist[3];

    playlist[0] = new MusicaLocal("Billie Jean", "Michael Jackson", "C:\\Musicas\\BillieJean.mp3");
    playlist[1] = new MusicaStreaming("Beat It", "Michael Jackson", "https://www.youtube.com/watch?v=SaEC9i9QOvk");
    playlist[2] = new MusicaLocal("lalala", "bbno$", "C:\\Musicas\\lalala.mp3");

    for(int i = 0; i < 3; i++){
        playlist[i]->tocar();
    }
    return 0;
}