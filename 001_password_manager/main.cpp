#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include "encrypt_decrypt.h"
using namespace std;

int main() {
    std::hash<std::string> hash_fn_str;
    
    // Security
    string ACCESS_PASSWORD;
    cout << "Please input Access Password: ";

    while (cin >> ACCESS_PASSWORD) {
        string hash = to_string(hash_fn_str(ACCESS_PASSWORD));
        if (hash == "13149121421387636708")
            break;
        else
            cout << "Ups.. Please try again: ";
    }

    int SECURITY_KEY;
    cout << "Please input Security Key: ";
    cin >> SECURITY_KEY;

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
                data[user] = encrypt(password, SECURITY_KEY);
            }
            else {
                cout << "[ERROR] " << user << " already exists.\n";
            }
        }
        else if (command == "help") {
            cin >> user;

            if (data.find(user) != data.end()) {
                cout << "Password for " << user << " -> " << decrypt(data[user], SECURITY_KEY) << "\n";
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
                data[user] = encrypt(password, SECURITY_KEY);
            }
            else {
                cout << "[ERROR] " << user << " not found.\n";
            }
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