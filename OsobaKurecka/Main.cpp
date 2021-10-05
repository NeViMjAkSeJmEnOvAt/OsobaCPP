#include <iostream>
#include <cstring>
#include "Osoba.h"

using std::cout;
using std::endl;
using std::cin;

void vypis(const Osoba& o, const char* text) {
    cout << text << endl;
    for (int i = 0; i < strlen(text); i++) {
        cout << "-";
    }
    cout << endl;
    cout << o << endl;
    return;
}

bool konec() {
    std::string ukonceni;
    cout << "Pro ukonceni programu stisknete klavesu \'k\': ";
    cin >> ukonceni;
    if (ukonceni == "k") {
        return true;
    }
    else
        return false;
}

int main(int argc, char** argv) {
    Osoba o1;
    Osoba o2("6462191472");
    Osoba o3(o2);
    std::string rc;
    vypis(o1, "Objekt o1 vytvoreny vychozim konstruktorem");
    vypis(o2, "Objekt o2 vytvoreny konstruktorem s parametrem");
    vypis(o3, "Objekt o3 vytvoreny kopirovacim konstruktorem");
    do {
        cout << "Zadej rodne cislo:";
        cin >> rc;
        cout << endl;
        if (o3.SetRodneCislo(rc)) {
            vypis(o3, "Objekt o3 po zmene");
            o1 = o3;
            vypis(o1, "Objekt o1 po zmene o1 = o3");
            cout << "Objekty o2 a o3 " << (o2 == o3 ? "jsou" : "nejsou")
                << " shodne." << endl << endl;
        }
        else {
            cout << "Chybne rodne cislo." << endl;
        }
    } while (!konec());
    return 0;
}


