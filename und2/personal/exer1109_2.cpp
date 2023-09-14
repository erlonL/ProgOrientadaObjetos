#include <iostream>
#include <string>
#include <vector>

using std::cout, std::cin, std::endl, std::string, std::vector, std::getline;

class Musica{
    string titulo;
    string artista;
protected:
    void tocarIntro(){
        cout << "O áudio está prestes a ser tocado..." << endl;
    }
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

class Podcast : public Musica{
    string apresentador;
    vector<string> episodios;
public:
    Podcast(const string& ap, const string& t, const string& a) : Musica(t, a), apresentador(ap){}

    string get_apresentador() const{
        return apresentador;
    }

    void adicionarEpisodio(){
        string episodio;
        cout << "Digite o nome do episodio: ";
        getline(cin, episodio);
        episodios.push_back(episodio);
    }
    void adicionarEpisodio(const string& ep){
        episodios.push_back(ep);
    }
    void tocarIntro(){
        Musica::tocarIntro();
        cout << "Apresentador: " << apresentador << endl;
    }
    virtual void tocar(){
        tocarIntro();
        cout << "Tocando podcast " << get_titulo() << " de " << get_artista() << " com " << apresentador << endl;
        for(auto& episodio : episodios){
            cout << "-> " << episodio << endl;
        }
    }
};

class PodcastPremium : private Podcast{
    float preco;
    vector<string> episodios;
public:
    PodcastPremium(const string& ap, const string& t, const string& a, float p) : Podcast(ap, t, a), preco(p){}
    void adicionarEpisodio(){
        Podcast::adicionarEpisodio();
    }
    void tocarIntro(){
        Podcast::tocarIntro();
        cout << "Este podcast é premium e custa R$" << preco << endl;
    }
    virtual void tocar(){
        tocarIntro();
        cout << "Tocando podcast " << Podcast::get_titulo() << " de " << Podcast::get_artista() << " com " << Podcast::get_apresentador() << endl;
    }
};


int main(void){

    Musica* playlist[3];

    playlist[0] = new Podcast("GugaCast", "Episodio 1", "Gustavo Guanabara");

    // playlist[1] = new PodcastPremium("GugaCast", "Episodio 2", "Gustavo Guanabara", 10.0);

    playlist[1] = new MusicaLocal("lalala", "bbno$", "C:\\Musicas\\lalala.mp3");

    playlist[2] = new MusicaStreaming("Beat It", "Michael Jackson", "https://www.youtube.com/watch?v=SaEC9i9QOvk");

    for(int i = 0; i < 3; i++){
        playlist[i]->tocar();
    }





    
    return 0;
}