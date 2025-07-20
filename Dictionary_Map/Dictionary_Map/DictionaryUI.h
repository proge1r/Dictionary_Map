#ifndef DICTIONARYUI_H
#define DICTIONARYUI_H
#include "Dictionary.h"
#include <string>
using namespace std;

class DictionaryUI {
public:
    DictionaryUI();

    void run();

private:
    Dictionary dict;
    const string filename = "dictionary.txt";

    void menu();
    void addWord();
    void removeWord();
    void editWord();
    void findWord();
    void showAll();
    void saveToFile();
    void loadFromFile();
};

#endif
