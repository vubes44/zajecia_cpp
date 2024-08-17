#include <iostream>
#include <fstream>
#include <unordered_map>
#include "encrypt_decrypt.h"
using namespace std;

string encrypt(string password, int key) {
    string encrypted_password = "";

    for (auto c : password) {
        encrypted_password += char((int(c) - int('!') + key) % 94 + int('!'));
    }

    return encrypted_password;
}

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
        else if (command == "encript")
        {
            cin >> user;
            data[user] = encrypt(data[user]);
        }
        else {
            cout << "[ERROR] Unknown command.\n";
        }
    }

    output.open("data.txt");
    
    // Saving back to file data.txt
    cout << "Saving in file...\n";
    for (auto [k, s] : data) {
        output << k << " " << s << "\n";
    }

    output.close();
}