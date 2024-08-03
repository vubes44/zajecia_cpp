#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main() {
    // wczytanie danych
    ifstream input;
    ofstream output;
    input.open("data.txt");

    unordered_map<string, string> data;
    string user, password;

    while (input >> user) {
        input >> password;
        data[user] = password;
    }

	input.close();

    // obsługa poleceń
    while (true) {
        string command;
        cin >> command;

        if (command == "exit")
            break;

        else if (command == "add") {
            cin >> user >> password;
            if (mp.find(user) = mp.end())
            {
                data[user] = password;
            }
            else
            {
                cout << user << " exists";
            }
        }

        else if (command == "help") {
            cin >> user;
            if (data[user] != "")
            {
                cout << data[user] << "\n";
            }
        }

        else if (command == "delete") {
            cin >> user;
			data.erase(user);
        }

        else if (command == "update")
        {
            cin >> user;
            cin >> password;
            if (data[user] != "")
            {
                data[user] = password;
            }
        }
        
        else if (command == "finish")
        {
            break;
        }
        
        else
        {
            cout << "ERR";
        }
    }

	output.open("data.txt");
    
    // zapisanie do pliku
    cout << "Saving in file...\n";
    for (auto [k, s] : data) {
        output << k << " " << s << "\n";
    }

	output.close();
}