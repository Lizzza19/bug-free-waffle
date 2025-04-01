
#include <iostream>
#include <string>
#include <fstream>
#include "f.h"
using namespace nm;
int main() {
    int n = 0;
    Music* m = nullptr;
    int a;
    do {
        std::cout << "1.Add a song" << std::endl;
        std::cout << "2.Delete a song" << std::endl;
        std::cout << "3.Displaying a list of songs" << std::endl;
        std::cout << "4.Song search" << std::endl;
        std::cout << "5.Change the information about the song" << std::endl;
        std::cout << "6.Exit" << std::endl;
        std::cout << "Your choice:" << std::endl;
        std::cin >> a;
        switch (a) {
        case 1:
            input(&m, n);
            print(m, n);
            save(m, n);
            break;
        case 2:
            delet(m, n);
            print(m, n);
            save(m, n);
            break;
        case 3:
            print(m, n);
            break;
        case 4:
            search(m, n);
            break;
        case 5:
            edit(&m, n);
            save(m, n);
            print(m, n);
            break;
        case 6:
            break;
        default:
            while (a > 6 || !(cin >> a)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "Wrong choice.Try again" << std::endl;
                std::cout << "Your choice:";
                std::cin >> a;
            }
            break;
        }
    } while (a != 6);
    delete[] m;
    return 0;
}
