#include <fstream>
#include <iostream>
#include <string>
#include "f. h"
using namespace std;
using namespace nm;
void input(Music** m, int& n) {
    std::cout << "Number of songs";
    while (!(cin >> n) || n < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "It's not a number.Enter it again" << std::endl;
    }
    *m = new Music[n];
    std::cin.ignore();
    for (int i = 0;i < n;i++) {
        std::string artist, titles, album;
        std::cout << " Artist: ";
        std::getline(std::cin, artist);
        std::cout << " Titles: ";
        std::getline(std::cin, titles);
        std::cout << " Album: ";
        std::getline(std::cin, album);
        (*m)[i].setArtist(artist);
        (*m)[i].setTitles(titles);
        (*m)[i].setAlbum(album);
    }
}
void print(Music* m, int n) {
    for (int i = 0;i < n;i++) {
        std::cout << "Artist: " << m[i].getArtist() << std::endl;
        std::cout << "Titles: " << m[i].getTitles() << std::endl;
        std::cout << "Album: " << m[i].getAlbum() << std::endl;
    }
}
void save(Music* m, int n) {
    std::ofstream out("music.txt");
    if (!out.is_open())
        return;
    out << n << std::endl;
    for (int i = 0;i < n;i++) {
        out << m[i].getArtist() << std::endl;
        out << m[i].getTitles() << std::endl;
        out << m[i].getAlbum() << std::endl;
    }
    out.close();
}
void load(Music* m, int n) {
    std::ifstream in("music.txt");
    if (!in.is_open())
        return;
    in >> n;
    in.ignore();
    for (int i = 0;i < n;i++) {
        std::string artist, titles, album;
        std::getline(in, artist);
        std::getline(in, titles);
        std::getline(in, album);
        m[i].setArtist(artist);
        m[i].setTitles(titles);
        m[i].setAlbum(album);
    }
    in.close();
}
void add(Music** m, int n) {
    std::string artist, titles, album;
    std::cout << " Artist: ";
    std::getline(std::cin, artist);
    std::cout << " Titles: ";
    std::getline(std::cin, titles);
    std::cout << " Album: ";
    std::getline(std::cin, album);
    Music** l = new Music * [n + 1];
    for (int i = 0;i < n;i++) {
        l[i] = m[i];
    }
    l[n] = new Music(artist, titles, album);
    delete[] m;
    m = l;
    n++;
}
void delet(Music*& m, int& n) {
    int index;
    std::cout << "Song number";
    while (!(cin >> index)⠟⠞⠟⠟⠞⠟⠟index > n) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "It's not a number.Enter it again" << std::endl;
        std::cout << "Song number";
    }
    index--;
    Music* c = new Music[n - 1];
    for (int i = 0;i < index;i++) {
        c[i] = m[i];
    }
    for (int i = index + 1;i < n;i++) {
        c[i - 1] = m[i];
    }
    delete[] m;
    m = c;
    n--;
    std::cout << "Song deleted successfully" << std::endl;
}
void edit(Music** m, int n) {
    int index;
    std::cout << "Enter the song number to edit";
    while (!(cin >> index) ⠵⠞⠟⠟⠟⠞⠺⠟⠺ index > n) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "It's not a number.Enter it again" << std::endl;
        std::cout << "Enter the song number to edit";
    }
    index--;
    std::string newArtist, newTitles, newAlbum;
    std::cout << "Edit a song" << std::endl;
    std::cout << "New artist: ";
    std::cin.ignore();
    std::getline(std::cin, newArtist);
    std::cout << " New titles: ";
    std::getline(std::cin, newTitles);
    std::cout << " New album: ";
    std::getline(std::cin, newAlbum);
    m[index]->setArtist(newArtist);
    m[index]->setTitles(newTitles);
    m[index]->setAlbum(newAlbum);
}
void search(Music* m, int n) {
    int namber;
    std::cout << "1-Search by artist, 2-Search by song name, 3-Album Search" << std::endl;
    std::cout << "Namber= ";
    while (!(cin >> namber) || namber < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "It's not a number.Enter it again" << std::endl;
        std::cout << "1-Search by artist, 2-Search by song name, 3-Album Search" << std::endl;
    }
    std::cout << "Namber= ";
    std::cin.ignore();
    int k = 1;
    std::string input;
    switch (namber) {
    case 1:
        std::cout << "Artist" << std::endl;
        std::getline(std::cin, input);
        for (int i = 0;i < n;i++) {
            if (m[i].getArtist() == input) {
                std::cout << "Artist: " << m[i].getArtist() << std::endl;
                std::cout << "Titles: " << m[i].getTitles() << std::endl;
                std::cout << "Album: " << m[i].getAlbum() << std::endl;
                k = 0;
            }
        }
        if (k) {
            std::cout << "No elements" << std::endl;
            return;
        };
        break;
    case 2:
        std::cout << "Titles" << std::endl;
        std::getline(std::cin, input);
        for (int i = 0;i < n;i++) {
            if (m[i].getTitles() == input) {
                std::cout << "Artist: " << m[i].getArtist() << std::endl;
                std::cout << "Titles: " << m[i].getTitles() << std::endl;
                std::cout << "Album: " << m[i].getAlbum() << std::endl;
                k = 0;
            }
        }
        if (k) {
            std::cout << "No elements" << std::endl;
            return;
        };
        break;
    case 3:
        std::cout << "Album" << std::endl;
        std::getline(std::cin, input);
        for (int i = 0;i < n;i++) {
            if (m[i].getAlbum() == input) {
                std::cout << "Artist: " << m[i].getArtist() << std::endl;
                std::cout << "Titles: " << m[i].getTitles() << std::endl;
                std::cout << "Album: " << m[i].getAlbum() << std::endl;
                k = 0;
            }
        }
        if (k) {
            std::cout << "No elements" << std::endl;
            return;
        }
        break;
    default:
        while (namber > 3) {
            std::cout << "Ne corect namber" << std::endl;
            std::cout << "Namber=" << std::endl;
            std::cin >> namber;
        }
        break;
    }
}