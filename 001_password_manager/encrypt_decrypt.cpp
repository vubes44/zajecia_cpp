#include <iostream>
using namespace std;

string encrypt(string password, int key) {
    string encrypted_password = "";

    for (auto c : password) {
        encrypted_password += char((int(c) - int('!') + key) % 94 + int('!'));
    }

    return encrypted_password;
}

string decrypt(string password, int key) {
    return encrypt(password, -key);
} 