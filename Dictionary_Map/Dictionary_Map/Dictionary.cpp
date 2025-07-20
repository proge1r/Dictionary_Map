#include "Dictionary.h"
#include <fstream>
#include <iostream>
using namespace std;

void Dictionary::addWord(const string& word, const string& translation) {
    data[word] = translation;
}

bool Dictionary::removeWord(const string& word) {
    return data.erase(word) > 0;
}

bool Dictionary::editWord(const string& word, const string& newTranslation) {
    auto it = data.find(word);
    if (it != data.end()) {
        it->second = newTranslation;
        return true;
    }
    return false;
}

bool Dictionary::findWord(const string& word) const {
    return data.find(word) != data.end();
}

void Dictionary::printWord(const string& word) const {
    auto it = data.find(word);
    if (it != data.end()) {
        cout << word << " - " << it->second << endl;
    }
    else {
        cout << "Word not found.\n";
    }
}

void Dictionary::printAll() const {
    if (data.empty()) {
        cout << "Dictionary is empty.\n";
        return;
    }
    for (const auto& pair : data) {
        cout << pair.first << " - " << pair.second << endl;
    }
}

bool Dictionary::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) return false;

    data.clear();
    string line;
    while (getline(in, line)) {
        auto pos = line.find(" - ");
        if (pos != string::npos) {
            string word = line.substr(0, pos);
            string translation = line.substr(pos + 3);
            data[word] = translation;
        }
    }

    in.close();
    return true;
}

bool Dictionary::saveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out.is_open()) return false;

    for (const auto& pair : data) {
        out << pair.first << " - " << pair.second << '\n';
    }

    out.close();
    return true;
}
