#include <iostream>
#include <string>
#include <fstream>
using namespace std;
namespace nm {
    class Music {
    private:
        std::string artist;
        std::string titles;
        std::string album;
    public:
        string getArtist() const { return artist; }
        string getTitles() const { return titles; }
        string getAlbum() const { return album; }
        void setArtist(string a) { artist = a; }
        void setTitles(string t) { titles = t; }
        void setAlbum(string al) { album = al; }
        Music() : artist(""), titles(""), album("") {}
        Music(std::string artist, std::string titles, std::string album)
            : artist(artist), titles(titles), album(album) {
        }
    };
    void input(Music** m, int& n);
    void print(Music* m, int n);
    void save(Music* m, int n);
    void load(Music* m, int n);
    void delet(Music*& m, int& n);
    void add(Music** m, int n);
    void edit(Music** m, int n);
    void search(Music* m, int n);
}