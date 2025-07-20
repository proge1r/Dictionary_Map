#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <map>
#include <string>
using namespace std;

class Dictionary {
private:
    map<string, string> data;

public:
    void addWord(const string& word, const string& translation);
    bool removeWord(const string& word);
    bool editWord(const string& word, const string& newTranslation);
    bool findWord(const string& word) const;
    void printWord(const string& word) const;
    void printAll() const;

    bool loadFromFile(const string& filename);
    bool saveToFile(const string& filename) const;
};

#endif
