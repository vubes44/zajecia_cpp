#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // wczytanie danych
    ifstream wejscie;
    ofstream wyjscie;
    wejscie.open("data.txt");
    wyjscie.open("wyjscie.txt");

    vector<pair<string, string>> dane;
    string user, password;

    while (wejscie >> user) {
        wejscie >> password;
        dane.push_back({user, password});
    }

    // obsługa poleceń
    while (true) {
        string polecenie;
        cin >> polecenie;

        if (polecenie == "exit")
            break;

        if (polecenie == "add") {
            cin >> user >> password;
            dane.push_back({user, password});
        }

        if (polecenie == "help") {
            cin >> user;
            cout << password;
        }

        if (polecenie == "delete") {
            cin >> user;
            if (user == "tak")
            {
                dane.erase(dane.end() - 1);
            }
        }
    }
    
    // zapisanie do pliku
    cout << "Zapisuje do pliku...\n";
    for (auto [k, s] : dane) {
        wyjscie << k << " -> " << s << "\n";
    }
}
