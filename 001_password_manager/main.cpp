#include <iostream>
#include <fstream>
#include <unordered_map>
#include "encrypt_decrypt.h"
using namespace std;

int main() {
    // Reading data from file data.txt
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

    // queries
    while (true) {
        string command;
        cin >> command;

        if (command == "exit") {
            break;
        }
        else if (command == "add") {
            cin >> user >> password;

            if (data.find(user) == data.end()) {
                data[user] = password;
            }
            else {
                cout << "[ERROR] " << user << " already exists.\n";
            }
        }
        else if (command == "help") {
            cout << "User: ";
            cin >> user;

            if (data.find(user) != data.end()) {
                cout << "Password for " << user << " -> " << data[user] << "\n";
            }
            else {
                cout << "[ERROR] " << user << " not found.\n";
            }
        }
        else if (command == "delete") {
            cin >> user;

            data.erase(user);
        }
        else if (command == "update") {
            cin >> user >> password;
            
            if (data.find(user) != data.end()) {
                data[user] = password;
            }
            else {
                cout << "[ERROR] " << user << " not found.\n";
            }
        }
        else if (command == "encript") {
            cin >> user;
            data[user] = encrypt(data[user], 5); // Assuming a key of 5 for encryption
            cout << "Encripted!";
        }
        else if (command == "decript") {
            cin >> user;
            data[user] = decrypt(data[user], 5);
            cout << "Decripted!";
        }
    }

    // Writing updated data back to file
    output.open("data.txt");
    for (const auto& pair : data) {
        output << pair.first << " " << pair.second << "\n";
    }
    output.close();

    return 0;
}
