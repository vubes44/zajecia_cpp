#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main() {
    // wczytanie danych
    ifstream wejscie;
    ofstream wyjscie;
    wejscie.open("data.txt");

    unordered_map<string, string> dane;
    string user, password;

    while (wejscie >> user) {
        wejscie >> password;
        dane[user] = password;
    }

	wejscie.close();

    // obsługa poleceń
    while (true) {
        string polecenie;
        cin >> polecenie;

        if (polecenie == "exit")
            break;

        if (polecenie == "add") {
            cin >> user >> password;
            dane[user] = password;
        }

        if (polecenie == "help") {
            cin >> user;
            cout << dane[user] << "\n";
        }

        if (polecenie == "delete") {
            cin >> user;
			dane.erase(user);
        }
    }

	wyjscie.open("data.txt");
    
    // zapisanie do pliku
    cout << "Zapisuje do pliku...\n";
    for (auto [k, s] : dane) {
        wyjscie << k << " " << s << "\n";
    }

	wyjscie.close();
}


