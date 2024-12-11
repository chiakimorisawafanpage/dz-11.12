#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string caesarCipher(const string& text, int shift) {
    string result = text;
    shift = (shift % 26 + 26) % 26;
    for (char& c : result) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = base + (c - base + shift) % 26;
        }
    }
    return result;
}

bool isPalindrome(const string& text) {
    string filtered;
    filtered.reserve(text.size());
    for (char c : text) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }
    return equal(filtered.begin(), filtered.begin() + filtered.size() / 2, filtered.rbegin());
}

int main() {
    int shift;
    string text;

    cout << "сдвиг: ";
    cin >> shift;
    cin.ignore();

    cout << "текст для шифрования: ";
    getline(cin, text);

    string ttext = caesarCipher(text, shift);
    cout << "зашифрованный текст: " << ttext << endl;

    cout << "проверка на палиндром: ";
    getline(cin, text);
    if (isPalindrome(text)) {
        cout << "палиндром" << endl;
    }
    else {
        cout << "не палиндром" << endl;
    }

    return 0;
}
